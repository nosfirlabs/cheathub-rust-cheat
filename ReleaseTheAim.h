#include <map>
inline float GetFov(LocalPlayer* Entity, BoneList Bone) {
	Vector2 ScreenPos;
	if (!LxcalPlayer.WorldToScreen(Entity->GetBoneByID(Bone), ScreenPos)) return 1000.f;
	return Math::Calc2D_Dist(Vector2(features::ScreenWidth / 2, features::ScreenHigh / 2), ScreenPos);
}

// 785728077 -1691396643 51984655
inline float GetGravity(int ammoid) {
	switch (ammoid) {
	case 14241751: // fire arrow
		return 1.f;
	case -1234735557: // arrow
		return 0.75f;                                                                //return Test::gravityTest;
	case 215754713: // bone arrow
		return 0.75f;
	case -1023065463: // HV arrow
		return 0.5f;


	case -2097376851: // nails
		return 0.75f;

	case 785728077: // pistol
		return 1.f;
	case -1691396643: // HV pistol
		return 1.f;
	case 51984655: // fire pistol
		return 1.f;

	case 1712070256: // HV 5.56
		return 1.f;
	case -1321651331: // inc 5.56
		return 1.f;
	case 605467368: // explo 5.56
		return 1.25f;
	default:
		return 1.f;
	}
}
inline float GetBulletSpeed() {
	switch (LxcalPlayer.lclPlayer->GetActiveWeapon()->GetNameHash()) {
	case 0:
		return 0.f;

	case 0x77E9:
		return 420.26f;
		break;

	case 0xCFA1:
		return 656.26f;
		break;

	case 0x573C:
		return 420.05f;
		break;

	case 0x6A09:
		return 960.05f;
		break;

	case 0x7983:
	case 0xE5EA:
	case 0x79C4:
		return 340.05f;
		break;

	case 0xE97D:
		return 192.05f;
		break;

	case 0x3511:
		return 190.05f;
		break;

	case 0x67DA:
		return 260.05f;
		break;

	case 0x62E5:
		return 260.05f;
		break;

	case 0x3146:
		return 250.05f;
		break;

	case 0x6B1:
		return 260.05f;
		break;

	case 0x5A9F:
		return 60.10f;
		break;

	case 0xC196:
		return 60.10f;
		break;

	case 0xB0A0:
		return 95.05f;
		break;

	case 0x746A:
		return 125.05f;
		break;

	default:
		return 250.05f;
	}
}

#define MAX_STRING_LEN 64

class Str {
	char zpad[0x10];
public:
	int size;
	wchar_t str[MAX_STRING_LEN + 1];
	Str(const wchar_t* st) {
		size = min(m_wcslen((wchar_t*)st), MAX_STRING_LEN);
		for (int i = 0; i < size; i++) {
			str[i] = st[i];
		}
		str[size] = 0;
	}
};

inline Vector3 Prediction(const Vector3& LP_Pos, LocalPlayer* Player, BoneList Bone) {
	WeaponData* active = LxcalPlayer.lclPlayer->GetActiveWeapon();
	Vector3 BonePos = Player->GetBoneByID(Bone);
	float Dist = Math::Calc3D_Dist(LP_Pos, BonePos);
	if (Dist > 0.001f) {
		Weapon tar = active->Info();
		int ammo = active->LoadedAmmo();
		printf("loaded ammo %d   ", ammo);
		//printf("Information %d", tar);
		float speed = GetBulletSpeed();
		float gravity = GetGravity(ammo);
		if (!speed) speed = 250.f;
		float BulletTime = Dist / speed;
		Vector3 vel = Player->GetVelocity();
		Vector3 PredictVel = vel * BulletTime * 0.75f;
		BonePos += PredictVel;
		BonePos.y += (4.905f * BulletTime * BulletTime) * gravity;
	}
	return BonePos;
}
inline void Normalize(float& Yaw, float& Pitch) {
	if (Pitch < -89) Pitch = -89;
	else if (Pitch > 89) Pitch = 89;
	if (Yaw < -360) Yaw += 360;
	else if (Yaw > 360) Yaw -= 360;
}
inline void GoToTarget(LocalPlayer* player) {
	Vector3 Local = LxcalPlayer.lclPlayer->GetBoneByID(neck);
	Vector3 PlayerPos = Prediction(Local, player, head);
	Vector2 Offset = Math::CalcAngle(Local, PlayerPos) - LxcalPlayer.lclPlayer->GetVA();
	Normalize(Offset.y, Offset.x);
	Vector2 AngleToAim = LxcalPlayer.lclPlayer->GetVA() + Offset;
	Normalize(AngleToAim.y, AngleToAim.x);
	LxcalPlayer.lclPlayer->SetVA(AngleToAim);
}

inline void Aim(LocalPlayer* AimEntity) {
	if (features::aimbot::AimbotActive && !LxcalPlayer.lclPlayer->IsTeamMate(AimEntity->GetSteamID())) {
		if (AimEntity && !LxcalPlayer.lclPlayer->IsMenu()) {
			if (GetAsyncKeyState(VK_RBUTTON))
				GoToTarget(AimEntity);
		}
	}
}