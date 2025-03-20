#pragma once
#pragma warning(disable : 4530)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

#include <Windows.h>
#include <iostream>
#include <psapi.h>
#include <d3d11.h>
#include <emmintrin.h>
#include "winternl.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include <string.h>

#include <Lmcons.h>

inline int isSteam = 0;
inline float width, height;
inline ULONG64 fpTransform;
inline ULONG64 fpTransform_Steam;

#include "minhook/include/MinHook.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_internal.h"

#include "scanner.h"
#include "detours.h"

#define FC_NTDLL(Name, ...) [&](){static DWORD64 FAddr;if(!FAddr)FAddr=GetExport(GetModBase(((const wchar_t*)1)), (#Name));return((decltype(Name(__VA_ARGS__))(*)(...))FAddr)(__VA_ARGS__);}()
#define FC(Mod, Name, ...) [&](){static DWORD64 FAddr;if(!FAddr)FAddr=GetExport(LoadLibUnc({sizeof(L#Mod)-2,sizeof(L#Mod),(PWSTR)((L#Mod))}), (#Name));return((decltype(Name(__VA_ARGS__))(*)(...))FAddr)(__VA_ARGS__);}()

namespace YEET {
	inline __declspec(noinline) DWORD64 GetExport(DWORD64 hDll, const char* Name)
	{
		//process image data
		PIMAGE_NT_HEADERS NT_Head = (PIMAGE_NT_HEADERS)(hDll + ((PIMAGE_DOS_HEADER)hDll)->e_lfanew);
		PIMAGE_EXPORT_DIRECTORY ExportDir = (PIMAGE_EXPORT_DIRECTORY)(hDll + NT_Head->OptionalHeader.DataDirectory[0].VirtualAddress);

		//process list
		for (DWORD i = 0; i < ExportDir->NumberOfNames; i++)
		{
			//get ordinal & name
			USHORT Ordinal = ((USHORT*)(hDll + ExportDir->AddressOfNameOrdinals))[i];
			const char* ExpName = (const char*)hDll + ((DWORD*)(hDll + ExportDir->AddressOfNames))[i];

			//check name
			for (int i = 0; ExpName[i] == Name[i]; i++) if (!ExpName[i])
				return hDll + ((DWORD*)(hDll + ExportDir->AddressOfFunctions))[Ordinal];
		} return 0;
	}

	inline __declspec(noinline) DWORD64 GetModBase(const wchar_t* Name) {
		PPEB_LDR_DATA Ldr = ((PTEB)__readgsqword(FIELD_OFFSET(NT_TIB, Self)))->ProcessEnvironmentBlock->Ldr;
		for (PLIST_ENTRY CurEnt = Ldr->InMemoryOrderModuleList.Flink; CurEnt != &Ldr->InMemoryOrderModuleList; CurEnt = CurEnt->Flink) {
			PLDR_DATA_TABLE_ENTRY pEntry = CONTAINING_RECORD(CurEnt, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
			if (((DWORD64)Name > 1 && !FC_NTDLL(_wcsicmp, Name, pEntry->BaseDllName.Buffer)) ||
				((DWORD64)Name == 1 && pEntry->BaseDllName.Length == 18 && *(DWORD64*)pEntry->BaseDllName.Buffer == 0x6C00640074006E) || !Name)
				return (DWORD64)pEntry->DllBase;
		} return 0;
	}

	inline __declspec(noinline) DWORD64 LoadLibUnc(UNICODE_STRING Mod) {
		typedef NTSTATUS(__stdcall* _LdrLoadDll)(PWCHAR, PULONG, PUNICODE_STRING, HMODULE*); static _LdrLoadDll LdrLoadDllFn = nullptr;
		if (!LdrLoadDllFn) LdrLoadDllFn = (_LdrLoadDll)GetExport(GetModBase((const wchar_t*)1), ("LdrLoadDll"));
		HMODULE hMod; LdrLoadDllFn(nullptr, nullptr, &Mod, &hMod); return (DWORD64)hMod;
	}
}

using namespace YEET;



#include "imp.h"
#include "Vectors.h"
#include "SafeMem.h"
#include "il2cpp.h"
#include "unity.h"
#include "features.h"
#include "sdk.h"
#include "GameSDK.h"
#include "Visuals.h"
#include "Render.h"
#include "miscfuncs.h"
#include "hooks.hpp"
#include "espp.h"
#include "MiscFucker.h"
#include "aimbot.h"
#include "CallHooks.h"
#include "ReleaseTheAim.h"