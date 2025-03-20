#include "etc.h"

#pragma once
typedef void(__fastcall* clientinput_fn)(DWORD64, DWORD64);
inline clientinput_fn original_clientinput;

typedef bool(__fastcall* sendclienttick)(void*);
inline sendclienttick original_sendclienttick;

typedef uintptr_t(__fastcall* create_projectile_fn)(void*, void*, Vector3, Vector3, Vector3);
inline create_projectile_fn original_create_projectile{ };

typedef Vector3(__fastcall* modifiedaimconedirection)(float, Vector3, bool);
inline modifiedaimconedirection original_aimconedirection;

typedef void(__fastcall* HandleRunning_fn)(void*, void*, bool);
inline HandleRunning_fn original_handleRunning{};


inline bool waslagging = false;

__declspec(selectany) uintptr_t TargetSilentPlayer = NULL;


inline void __fastcall ClientInput(DWORD64 baseplayah, DWORD64 ModelState) {
	if (!waslagging && features::aimbot::AimbotActive) {
		safe_write(LxcalPlayer.lclPlayer + 0x5C8, 0.4f, float);
		waslagging = true;
	}
	else if (waslagging && !features::aimbot::AimbotActive) {
		safe_write(LxcalPlayer.lclPlayer + 0x5C8, 0.05f, float);
		waslagging = false;
	}

	typedef void(__stdcall* ClientInput)(DWORD64, DWORD64);
	((ClientInput)original_clientinput)(baseplayah, ModelState);
	if (features::exploits::FakeLag)
		LxcalPlayer.lclPlayer->AddFlag(32);
	if (features::exploits::FakeLag)
		LxcalPlayer.lclPlayer->RemoveFlag(4);
}



inline uintptr_t __fastcall CreateProjectile(void* BaseProjectile, void* prefab_pathptr, Vector3 pos, Vector3 forward, Vector3 velocity) {
	uintptr_t projectile = original_create_projectile(BaseProjectile, prefab_pathptr, pos, forward, velocity);
	auto* TargetPlayer = reinterpret_cast<LocalPlayer*>(features::closestPlayer);
	safe_write(projectile + 0x114, true, bool);
	if (features::exploits::FatBoolet) {
		safe_write(projectile + 0x2C, 1.f, float);
	}
	else {
		safe_write(projectile + 0x2C, 0.1f, float);
	}
	return projectile;
}



typedef Vector4(__fastcall* GetSkinColor)(void*);
inline GetSkinColor Orig_GetSkinColor{ };
inline Vector4 __fastcall Hook_GetSkinColor(void* ecx)
{
	if (features::exploits::SkinChanger)
		return Vector4(5.988f, 0.f, 5.909f, 1.f); //5.988f, 0.f, 5.909f, 1.f
	return Orig_GetSkinColor(ecx);
}

typedef Vector4(__fastcall* SetSkinColor)(void*, float);
inline SetSkinColor Orig_SetSkinColor{ };
inline Vector4 __fastcall Hook_SetSkinColor(void* ecx, float skinNumber)
{
	if (features::exploits::SkinChanger)
		return Vector4(5.988f, 0.f, 5.909f, 1.f); //5.988f, 0.f, 5.909f, 1.f
	return Orig_SetSkinColor(ecx, skinNumber);
}


inline Vector3 __fastcall GetModifiedAimConeDirection(float aimCone, Vector3 inputVec, bool anywhereInside = true) { // wanna hang myself
	auto* TargetPlayer = reinterpret_cast<LocalPlayer*>(features::closestPlayer);
	Vector3 Prediction(const Vector3 & LP_Pos, LocalPlayer * Player, BoneList Bone);
	Vector3 dir = (Prediction(LxcalPlayer.lclPlayer->GetBoneByID(head), TargetPlayer, head) - LxcalPlayer.lclPlayer->GetBoneByID(head)).Normalized();
	if (features::exploits::pSilent && features::closestPlayer != NULL) {
		inputVec = dir;
	}
	if (features::exploits::AntiSpread) {
		aimCone = 0.f;
	}
	return original_aimconedirection(aimCone, inputVec, anywhereInside);
}

inline void __fastcall HandleRunning(void* a1, void* a2, bool wantsRun) {
	wantsRun = GetAsyncKeyState(0x10) && !GetAsyncKeyState(0x41) && !GetAsyncKeyState(0x53) && !GetAsyncKeyState(0x44);
	if (features::exploits::SprintAnyware)
		wantsRun = true;
	return original_handleRunning(a1, a2, wantsRun);
}

inline bool __fastcall SendClientTick(void* baseplayer) {
	if (features::exploits::AntiAim) {
		auto input = unsafe_read(baseplayer + 0x4C8, uintptr_t);
		if (!input) {
			return original_sendclienttick(baseplayer);
		}
		auto state = unsafe_read(input + 0x20, uintptr_t);
		if (!state) {
			return original_sendclienttick(baseplayer);
		}
		auto current = unsafe_read(state + 0x10, uintptr_t);
		if (!current) {
			return original_sendclienttick(baseplayer);
		}
		writenew<Vector3>(current + 0x18, Vector3(100, rand() % 999 + -999, rand() % 999 + -999));
	}
	return original_sendclienttick(baseplayer);
}



inline void InjectFunction(void* Function, void** Original, void* Detour, bool autoEnable = true) {
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) { printf("Failed to initialize MinHook"); return; }
	MH_CreateHook(Function, Detour, Original);
	if (autoEnable)
		MH_EnableHook(Function);
}


inline void InitHookLol()
{
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) {
		return;
	}

	InjectFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x30DBB0), (void**)&original_sendclienttick, SendClientTick); //internal void SendClientTick() { }
	InjectFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x76F980), (void**)&original_create_projectile, CreateProjectile); //private Projectile CreateProjectile(string prefabPath, Vector3 pos, Vector3 forward, Vector3 velocity) { }
	InjectFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0xB29AF0), (void**)&Orig_GetSkinColor, Hook_GetSkinColor); //public Color GetSkinColor() { }
	InjectFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x43B120), (void**)&Orig_SetSkinColor, Hook_SetSkinColor); //internal Color GetSkinColor(float skinNumber) { }
	InjectFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x2F8660), (void**)&original_clientinput, ClientInput); // internal virtual void ClientInput(InputState state) { }
	InjectFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x9161E0), (void**)&original_aimconedirection, GetModifiedAimConeDirection); //public static Vector3 GetModifiedAimConeDirection(float aimCone, Vector3 inputVec, bool anywhereInside = True) { }
	InjectFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0xB36FE0), (void**)&original_handleRunning, HandleRunning); // private void HandleRunning(ModelState state, bool wantsRun) { }
}