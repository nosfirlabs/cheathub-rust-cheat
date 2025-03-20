#pragma once
#include "etc.h"
#include "math.h"

//#define oGameObjectManager 0x17a6ad8

#pragma region BasePlayer

#define oPlayerInput 0x4C8// public PlayerInput input;
#define oPlayerModel 0x4A8// public PlayerModel playerModel;
#define oPlayerFlags 0x5F8// public BasePlayer.PlayerFlags playerFlags;
#define oUserID 0x640// public ulong userID;
#define oDisplayName 0x658// protected string _displayName
#define oClientTickInterval 0x5C8// public float clientTickInterval;
#define oClActiveItem 0x570// private uint clActiveItem; 
#define oInventory 0x608// public PlayerInventory inventory;
#define oMovement 0x4D0// public BaseMovement movement;


#pragma endregion


	//*** Projectile ***//

#define oThickness 0x2C// public float thickness;

	//*** TOD_Sky ***//

#define oInstances 0x0// private static List<TOD_Sky> instances;
#define oCycle 0x38// public TOD_CycleParameters Cycle;

	//*** TOD_CycleParameters ***//

#define OHour 0x10// public float Hour;

#pragma region PlayerWalkMovement

#define oGroundAngle 0xB4// private float groundAngle;
#define oGroundAngleNew 0xB8// private float groundAngleNew;
#define oGravityMultiplier 0x74// public float gravityMultiplier;
#define oFlying 0x13C// private bool flying;
#define oGravityMultiplierSwimming 0x78 // public float gravityMultiplierSwimming;


#pragma endregion

#pragma region ItemDefinition

#define oShortname 0x20// public string shortname;
#define odisplayname 0x28// public Translate.Phrase displayName;
#define oID 0x18// public int itemid;

#pragma endregion


		//*** Item ***//
#define oUID 0x28// public uint uid;
#define ItemDefinition 0x20// public ItemDefinition info;
#define oHeldEntity 0x98// private EntityRef heldEntity;

		//*** Player Model ***//

#define oSmoothVelocity 0x1FC// private Vector3 newVelocity
#define oVisible 0x248// internal bool visible;

		//*** BaseProjectile ***//

#define oPrimaryMagazine 0x2A0// public BaseProjectile.Magazine primaryMagazine;

		//*** BaseNetworkable ***//

#define oNetworkable 0x50// public Networkable net;

		//*** HeldEntity ***//

#define oPunches 0x148// protected List<HeldEntity.PunchEntry> _punches;

		//*** Networkable ***//

#define oNetworkId 0x10//public uint ID;

		//*** PlayerAttack ***//

#define oAttack 0x18// public Attack attack;

		//*** Attack ***//

#define oHitID 0x2C// public uint hitID;
#define oHitPartID 0x64// public uint hitPartID;
#define oHitBone 0x30// public uint hitBone;  ? //HitInfo 
#define oHitMaterialID 0x68 // public uint hitMaterialID;
#define oPlayerAttack 0x18 // public PlayerAttack playerAttack;
#define oAttack 0x18 // public Attack attack;
#define oHitNormalWorld 0x4C // public Vector3 hitNormalWorld; ? //public class Attack : IDisposable, Pool.IPooled, IProto 


		//*** BaseCombatEntity ***///

#define oLifeState 0x204// public BaseCombatEntity.LifeState lifestate; 
#define oHealth 0x20C// private float _health;

	//*** PlayerInput ***//

#define oKeyFocus 0x94// private bool hasKeyFocus;
#define oBodyAngles 0x3C// private Vector3 bodyAngles;


				//***  ***//

#define oStancePenalty 0x304 //private float stancePenalty;
#define oAimconePenalty 0x308 //private float aimconePenalty;
#define oAimCone 0x2D0 //public float aimCone;
#define oHipAimCone 0x2D4 //public float hipAimCone;
#define oAimconePenaltyPerShot 0x2D8 //public float aimconePenaltyPerShot;

#define oRecoil 0x2C0 // public RecoilProperties recoil;
#define oRecoilYawMin 0x18 // public float recoilYawMin;
#define oRecoilYawMax 0x1C // public float recoilYawMax;
#define oRecoilPitchMin 0x20 // public float recoilPitchMin;
#define oRecoilPitchMax 0x24  // public float recoilPitchMax;
#define oADSScale 0x30 // public float ADSScale; 
#define oMovementPenalty 0x34 // public float movementPenalty;
#define oAutomatic 0x270 // public bool automatic;
#define oSuccessFraction 0x340 // public float successFraction;
#define oAttackReady 0x340 // protected bool attackReady;
#define oArrowBack 0x344 // private float arrowBack;
#define oHornOrigin 0x1C8 // public GameObject hornOrigin;
#define oAttackRadius 0x27C //public float attackRadius;
#define oBlockSprintOnAttack 0x281 //public bool blockSprintOnAttack;
#define oNewVelocity 0x1FC // private Vector3 newVelocity;
#define oLastSentTickTime 0x5CC // private float lastSentTickTime;
#define oClientTeam 0x540 // public PlayerTeam clientTeam
#define oRecoilAngles 0x64 // public Vector3 recoilAngles;
#define oInventory 0x608// public PlayerInventory inventory;
#define oFrozen 0x4B0 // public bool Frozen;
#define oClothingWaterSpeedBonus 0x6B8 // public float clothingWaterSpeedBonus;
#define oClothingAccuracyBonus 0x6BC // public float clothingAccuracyBonus;
#define oClothingBlocksAiming 0x6B0 // public bool clothingBlocksAiming;
#define oClothingMoveSpeedReduction 0x6B4 // public float clothingMoveSpeedReduction;



#define g_BN 0x2fc4010
#define g_BN_Steam 0x2fc4010

typedef struct _UncStr
{
	char stub[0x10];
	int len;
	wchar_t str[1];
} *pUncStr;

class BaseProjectile
{
public:
	char pad_0x0[0x158]; //0x0
	bool isDeployed; //0x158
	char pad_0x159[0x3]; //0x159
	float hostileScore; //0x15c
	char pad_0x164[0x4]; //0x16
	float deployDelay; //0x170
	float repeatDelay; //0x174
	float nextAttackTime; //0x178
	float lastTickTime; //0x17c
	float nextTickTime; //0x180
	float timeSinceDeploy; //0x184
	bool catchup; //0x188
	char pad_0x189[0x7]; //0x189
	float damageScale; //0x1c8
	float distanceScale; //0x1cc
	float projectileVelocityScale; //0x1d0
	bool automatic; //0x1d4
	char pad_0x1d5[0x3]; //0x1d5
	float reloadTime; //0x1d8
	bool canUnloadAmmo; //0x1dc
	char pad_0x1dd[0x3]; //0x1dd
	float aimSway; //0x1e0
	float aimSwaySpeed; //0x1e4
	float aimCone; //0x1e8
	float hipAimCone; //0x1ec
	bool hasADS; //0x1f0
	bool noAimingWhileCycling; //0x1f1
	bool manualCycle; //0x1f2
	bool needsCycle; //0x1f3
	bool isCycling; //0x1f4
	bool aiming; //0x1f5
	char pad_0x1f6[0x2]; //0x1f6
	float nextReloadTime; //0x1f8
	bool isReloading; //0x1fc
	char pad_0x1fd[0x3]; //0x1fd
	float reloadPressTime; //0x200
};



/*enum BoneList : int
{
	pelvis = 0,
	l_hip = 1,
	l_knee = 2,
	l_foot = 3,
	l_toe = 4,
	l_ankle_scale = 5,
	penis = 6,
	GenitalCensor = 7,
	GenitalCensor_LOD0 = 8,
	Inner_LOD0 = 9,
	GenitalCensor_LOD1 = 11,
	GenitalCensor_LOD2 = 12,
	r_hip = 13,
	r_knee = 14,
	r_foot = 15,
	r_toe = 16,
	r_ankle_scale = 17,
	spine1 = 18,
	spine1_scale = 19,
	spine2 = 20,
	spine3 = 21,
	spine4 = 22,
	l_clavicle = 23,
	l_upperarm = 24,
	l_forearm = 25,
	l_hand = 26,
	l_index1 = 27,
	l_index2 = 28,
	l_index3 = 29,
	l_little1 = 30,
	l_little2 = 31,
	l_little3 = 32,
	l_middle1 = 33,
	l_middle2 = 34,
	l_middle3 = 35,
	l_prop = 36,
	l_ring1 = 37,
	l_ring2 = 38,
	l_ring3 = 39,
	l_thumb1 = 40,
	l_thumb2 = 41,
	l_thumb3 = 42,
	IKtarget_righthand_min = 43,
	IKtarget_righthand_max = 44,
	l_ulna = 45,
	neck = 46,
	head = 47,
	jaw = 48,
	eyeTranform = 49,
	l_eye = 50,
	l_Eyelid = 51,
	r_eye = 52,
	r_Eyelid = 53,
	r_clavicle = 54,
	r_upperarm = 55,
	r_forearm = 56,
	r_hand = 57,
	r_index1 = 58,
	r_index2 = 59,
	r_index3 = 60,
	r_little1 = 61,
	r_little2 = 62,
	r_little3 = 63,
	r_middle2 = 65,
	r_middle3 = 66,
	r_prop = 67,
	r_ring1 = 68,
	r_ring2 = 69,
	r_ring3 = 70,
	r_thumb1 = 71,
	r_thumb2 = 72,
	r_thumb3 = 73,
	IKtarget_lefthand_min = 74,
	IKtarget_lefthand_max = 75,
	r_ulna = 76,
	l_breast = 77,
	r_breast = 78,
	BoobCensor = 79,
	BreastCensor_LOD0 = 80,
	BreastCensor_LOD1 = 83,
	BreastCensor_LOD2 = 84
};*/

enum BoneList : int
{
	l_hip = 1,
	l_knee,
	l_foot,
	l_toe,
	l_ankle_scale,
	pelvis,
	penis,
	GenitalCensor,
	GenitalCensor_LOD0,
	Inner_LOD0,
	GenitalCensor_LOD1,
	GenitalCensor_LOD2,
	r_hip,
	r_knee,
	r_foot,
	r_toe,
	r_ankle_scale,
	spine1,
	spine1_scale,
	spine2,
	spine3,
	spine4,
	l_clavicle,
	l_upperarm,
	l_forearm,
	l_hand,
	l_index1,
	l_index2,
	l_index3,
	l_little1,
	l_little2,
	l_little3,
	l_middle1,
	l_middle2,
	l_middle3,
	l_prop,
	l_ring1,
	l_ring2,
	l_ring3,
	l_thumb1,
	l_thumb2,
	l_thumb3,
	IKtarget_righthand_min,
	IKtarget_righthand_max,
	l_ulna,
	neck,
	head,
	jaw,
	eyeTranform,
	l_eye,
	l_Eyelid,
	r_eye,
	r_Eyelid,
	r_clavicle,
	r_upperarm,
	r_forearm,
	r_hand,
	r_index1,
	r_index2,
	r_index3,
	r_little1,
	r_little2,
	r_little3,
	r_middle1,
	r_middle2,
	r_middle3,
	r_prop,
	r_ring1,
	r_ring2,
	r_ring3,
	r_thumb1,
	r_thumb2,
	r_thumb3,
	IKtarget_lefthand_min,
	IKtarget_lefthand_max,
	r_ulna,
	l_breast,
	r_breast,
	BoobCensor,
	BreastCensor_LOD0,
	BreastCensor_LOD1,
	BreastCensor_LOD2,
	collision,
	displacement
};


const unsigned short Crc16Table[256] = {
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

/*enum entity_type
{
	lclPlayer,
	StorageContainer,
	SupplyDrop,
	VendingMachineMapMarker,
	ExcavatorArm,
	LightListener,
	BaseVehicleSeat,
	Boar,
	Bear,
	Deer,
	Chicken,
	Wolf,
	Horse,
	HotAirBalloon,
	MiniCopter,
	DroppedItemContainer,
	OreResourceEntity,
	ResourceEntity,
	StashContainer,
	DroppedItem,
	CollectibleEntity,
	BaseMelee,
	BaseProjectile,
	TreeEntity,
	OreHotSpot,
	LootContainer,
	FreeableLootContainer,
	Recycler,
	JunkPileWater,
	Keycard,
	HackableLockedCrate,
	ItemPickup,
	Undefined,
	WorldItem,
	BradleyAPC,
	PlayerCorpse,
	BaseHelicopter,
	Scientist,
	GunTrap,
	FlameTurret,
	Landmine,
	BearTrap,
	AutoTurret,
	Barricade,
};*/

enum PlayerFlags : int
{
	Unused1 = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304,
};


class WeaponData
{
private:
	unsigned short CRC(unsigned char* pcBlock, unsigned short len) {
		unsigned short crc = 0xFFFF;
		while (len--)
			crc = (crc << 8) ^ Crc16Table[(crc >> 8) ^ *pcBlock++];
		return crc;
	}
public:
	float Held() {
		return unsafe_read(this + oHeldEntity, float);//0x98
	}
	int GetID()
	{
		DWORD64 Info = unsafe_read((DWORD64)this + 0x20, DWORD64); // public ItemDefinition info;
		int ID = unsafe_read(Info + 0x18, int); // public int itemid;
		return ID;
	}
	char* ClassName() {
		return (char*)unsafe_read(unsafe_read(unsafe_read(this + oHeldEntity, DWORD64), DWORD64) + 0x10, DWORD64);
	}
	Weapon Info() {
		int ID = GetID();
		for (Weapon k : info) {
			if (k.id == ID) {
				return k;
			}
		}
		return Weapon{ 0 };
	}
	wchar_t* GetShortName(int* len)
	{
		DWORD64 Info = unsafe_read(this + ItemDefinition, DWORD64);
		pUncStr Str = ((pUncStr)unsafe_read(Info + oShortname, DWORD64));
		int leng = unsafe_read(Str + 0x10, int);
		if (!leng) return nullptr;
		if (len)*len = leng;
		return Str->str;
	}
	wchar_t* GetShortNameName()
	{
		DWORD64 Info = unsafe_read(this + ItemDefinition, DWORD64);
		pUncStr Str = ((pUncStr)unsafe_read(Info + oShortname, DWORD64));
		return Str->str;
	}
	int LoadedAmmo()
	{
		const auto Held = unsafe_read(this + oHeldEntity, DWORD64);
		printf("Held %lld\n", Held);
		if (Held <= 0)
			return 0;
		const auto Magazine = unsafe_read(Held + oPrimaryMagazine, DWORD64);
		if (Magazine <= 0 || Magazine == 0x3F000000)
		{
			return 0;
		}
		const auto ammoType = unsafe_read(Magazine + 0x20, DWORD64);
		if (ammoType <= 0 || ammoType == 0x3F000000)
		{
			return 0;
		}
		const int ammo = unsafe_read(ammoType + 0x18, int);
		return ammo;
	}
	USHORT GetNameHash() {
		int Len;
		UCHAR* ShortName = (UCHAR*)GetShortName(&Len);
		if (ShortName == nullptr) return 0;
		return CRC(ShortName, (Len * 2));
	}
	wchar_t* GetName() {
		DWORD64 Info = unsafe_read(this + ItemDefinition, DWORD64);
		DWORD64 DispName = unsafe_read(Info + odisplayname, DWORD64);
		pUncStr Str = ((pUncStr)unsafe_read(DispName + 0x18, DWORD64)); // default
		if (!Str) return nullptr; return Str->str;
	}
	int GetUID() {
		return unsafe_read(this + oUID, int);
	}

	void RapidFire() {
		if (features::aimbot::ShootRate) {
			DWORD64 heldentity = unsafe_read(this + 0x98, DWORD64);
			writenew<float>(heldentity + 0x1DC, 0.09f); // repeatDelay
		}
	}

	std::string GetAmmoType()
	{
		const auto Held = unsafe_read(this + oHeldEntity, DWORD64);
		const auto Magazine = unsafe_read(Held + oPrimaryMagazine, DWORD64);
		uint64_t item_def = unsafe_read(Magazine + 0x20, uint64_t);
		uint64_t short_name = unsafe_read(item_def + 0x20, uint64_t);
		std::wstring wide_name = unsafe_read(short_name + 0x14, std::wstring);

		if (!wide_name.empty())
			return std::string(wide_name.begin(), wide_name.end()).c_str();

		return "No Ammo";
	}
	/*void AntiSpread() {
		if (Weapons::AntiSpread) {
			DWORD64 Held = unsafe_read(this + oHeldEntity, DWORD64);
			write(Held + oStancePenalty, 0.f, float);
			write(Held + oAimconePenalty, 0.f, float);
			write(Held + oAimCone, 0.f, float);
			write(Held + oHipAimCone, 0.f, float);
			write(Held + oAimconePenaltyPerShot, 0.f, float);
		}
	}*/
	//readnew<uintptr_t>((uintptr_t)

	void NoRecoil() {
		if (features::aimbot::NoRecoil) {
			DWORD64 Held = readnew<DWORD64>((DWORD64)(this + oHeldEntity));
			DWORD64 recoil = readnew<DWORD64>(Held + oRecoil);
			writenew<float>(recoil + oRecoilYawMin, features::aimbot::RecoilSlider);
			writenew<float>(recoil + oRecoilYawMax, features::aimbot::RecoilSlider);
			writenew<float>(recoil + oRecoilPitchMin, features::aimbot::RecoilSlider);
			writenew<float>(recoil + oRecoilPitchMax, features::aimbot::RecoilSlider);
			writenew<float>(recoil + oADSScale, features::aimbot::RecoilSlider);
			writenew<float>(recoil + oMovementPenalty, features::aimbot::RecoilSlider);
		}
	}


	/*void SetAutomatic() {
		if (Weapons::Automatic) {
			DWORD64 Held = unsafe_read(this + oHeldEntity, DWORD64);
			write(Held + oAutomatic, 1, bool);
		}
	}*/

	void SuperEoka() {
		if (features::aimbot::SuperEokaa) {
			DWORD64 Held = unsafe_read(this + 0x98, DWORD64); // EntityRef heldEntity
			safe_write(Held + 0x340, 1.f, float); //public float successFraction;
			safe_write(Held + 0x350, true, bool);
		}
	}

};


__forceinline DWORD64 RVAA(DWORD64 Instr, DWORD InstructionSize) {
	if (!Instr) return 0; LONG RipOffset = *(PLONG)(Instr + (InstructionSize - 4));
	return (Instr + InstructionSize + RipOffset);
}

class LocalPlayer //BasePlayer
{

	typedef Vector3(__stdcall* Transform)(UINT64);
private:
	inline Vector3 GetBone(ULONG_PTR pTransform)
	{
		if (!isSteam) return Vector3();
		if (pTransform < 0xFFF) return Vector3();
		Transform original;
		if (isSteam == -1) original = (Transform)fpTransform;
		else original = (Transform)fpTransform_Steam;
		if (!readnew<uintptr_t>((uintptr_t)this + 0x50) || readnew<uintptr_t>((uintptr_t)this + 0x18) || !readnew<uintptr_t>((uintptr_t)this + 0x4A8)) return Vector3();

		Vector3 res = original(pTransform);
		//printf("[+] %llX -> %f %f %f\n", pTransform, res.x, res.y, res.z);
		return res;
	}


public:

	Vector3 GetPosition() {
		return GetBone(GetTransform(0.5));
	}

	void SetFov() {
		auto klass = unsafe_read(features::gBase + 0x2FC2D38, DWORD64); //ConVar_Graphics_c* | ConVar.Graphics_TypeInfo -> ConVar_Graphics_c*
		auto static_fields = unsafe_read(klass + 0xB8, DWORD64);
		safe_write(static_fields + 0x18, features::exploits::SexyFuckingFovValue, float); //features::exploits::SexyFuckingFovValue
	}

	void WaterFloat()
	{
		if (features::exploits::swimonland)
		{
			uintptr_t BaseNigga = readnew<uintptr_t>((uintptr_t)(this + 0x588)); //public ModelState modelState;
			writenew<float>(BaseNigga + 0x14, 0.65f); //public float waterLevel
		}
	}

	void SpiderMan() {
		DWORD64 Movement = readnew<DWORD64>((DWORD64)(this + oMovement));
		writenew<float>(Movement + oGroundAngle, 0.f);
		writenew<float>(Movement + oGroundAngleNew, 0.f);
	}

	DWORD64 GetTeammateByPos(int Id) {
		DWORD64 ClientTeam = unsafe_read(this + 0x540, DWORD64);
		DWORD64 members = unsafe_read(ClientTeam + 0x30, DWORD64);
		DWORD64 List = unsafe_read(members + 0x10, DWORD64);
		DWORD64 player = unsafe_read(List + 0x20 + (Id * 0x8), DWORD64);
		return unsafe_read(player + 0x20, DWORD64);
	}

	inline DWORD64 GetSteamID()
	{
		return readnew<uintptr_t>((uintptr_t)this + 0x28);//	public ulong userID;
	}

	bool IsTeamMate(DWORD64 SteamID) {
		bool ret = false;

		for (int i = 0; i < 8; i++) {
			if (GetTeammateByPos(i) == SteamID) {
				ret = true;
				break;
			}
		}
		return ret;
	}
	int GetTeamSize()
	{
		DWORD64 ClientTeam = unsafe_read(this + 0x540, DWORD64); // public PlayerTeam clientTeam
		DWORD64 members = unsafe_read(ClientTeam + 0x28, DWORD64);//	private ListHashSet`1<ILOD> members; // 0x28 ���  public List`1<PlayerTeam.TeamMember> members; // 0x28
		return unsafe_read(members + 0x18, DWORD64);
	}

	Vector3 GetVelocity()
	{
		DWORD64 PlayerModel = unsafe_read(this + 0x4A8, DWORD64); //	public PlayerModel playerModel;
		return unsafe_read(PlayerModel + 0x1FC, Vector3); // 	private Vector3 newVelocity;
		//обновил
	}

	Vector3 GetPosition(DWORD64 transform)
	{
		if (!transform) return Vector3{ 0.f, 0.f, 0.f };
		{

			struct Matrix34 { BYTE vec0[16]; BYTE vec1[16]; BYTE vec2[16]; };
			const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
			const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
			const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

			int Index = *(PINT)(transform + 0x40);
			DWORD64 pTransformData = readnew<uintptr_t>((uintptr_t)transform + 0x38);
			DWORD64 transformData[2];
			safe_memcpy(&transformData, (PVOID)(pTransformData + 0x18), 16);

			size_t sizeMatriciesBuf = 48 * Index + 48;
			size_t sizeIndicesBuf = 4 * Index + 4;

			int pIndicesBuf[100];
			Matrix34 pMatriciesBuf[1000];

			safe_memcpy(pMatriciesBuf, (PVOID)transformData[0], sizeMatriciesBuf);
			safe_memcpy(pIndicesBuf, (PVOID)transformData[1], sizeIndicesBuf);

			__m128 result = *(__m128*)((ULONGLONG)pMatriciesBuf + 0x30 * Index);
			int transformIndex = *(int*)((ULONGLONG)pIndicesBuf + 0x4 * Index);

			while (transformIndex >= 0)
			{
				Matrix34 matrix34 = *(Matrix34*)((ULONGLONG)pMatriciesBuf + 0x30 * transformIndex);
				__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x00));
				__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x55));
				__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x8E));
				__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xDB));
				__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xAA));
				__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x71));
				__m128 tmp7 = _mm_mul_ps(*(__m128*)(&matrix34.vec2), result);

				result = _mm_add_ps(
					_mm_add_ps(
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
									_mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
						_mm_add_ps(
							_mm_mul_ps(
								_mm_sub_ps(
									_mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
									_mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
								_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
							tmp7)), *(__m128*)(&matrix34.vec0));

				transformIndex = *(int*)((ULONGLONG)pIndicesBuf + 0x4 * transformIndex);
			}

			return Vector3(result.m128_f32[0], result.m128_f32[1], result.m128_f32[2]);
		}
	}
	DWORD64 GetTransform(int bone)
	{
		DWORD64 player_model = readnew<uintptr_t>((uintptr_t)this + 0x118);// public Model model;_public class BaseEntity : BaseNetworkable, IProvider, ILerpTarget, IPrefabPreProcess // TypeDefIndex: 8714
		DWORD64 boneTransforms = readnew<uintptr_t>((uintptr_t)player_model + 0x48);// public Transform[] boneTransforms;
		DWORD64 BoneValue = readnew<uintptr_t>((uintptr_t)(boneTransforms + (0x20 + (bone * 0x8))));
		return readnew<uintptr_t>((uintptr_t)BoneValue + 0x10);
	}
	Vector3 GetBoneByID(BoneList BoneID) {
		return GetPosition(GetTransform(BoneID));
	}
	const wchar_t* GetName()
	{
		pUncStr Str = ((pUncStr)(readnew<uintptr_t>((uintptr_t)(this + 0x658)))); //protected string _displayName;
		if (!Str) return L""; return Str->str;
	}
	float GetHealth() {
		///return readnew<float>(float)(this + 0x20C));
		return unsafe_read(this + 0x20C, float);
	}
	bool IsVisible()
	{
		if (features::Visuals::VisibleCheck)
		{
			DWORD64 PlayerModel = unsafe_read(this + 0x4A8, DWORD64); //public PlayerModel playerModel;
			return unsafe_read(PlayerModel + 0x248, bool); // internal bool visible;
		}
		else return true;
	}

	bool IsNpc() {
		DWORD64 PlayerModel = unsafe_read(this + 0x4A8, DWORD64); //	public PlayerModel playerModel;
		return unsafe_read(PlayerModel + 0x2C0, bool);
	}

	/*bool HasFlags(int Flg)
	{
		return (readnew<uintptr_t>((uintptr_t)this + 0x5F8) & Flg); //	public lclPlayer.PlayerFlags playerFlags;
	}*/

	bool HasFlags(int Flg) {
		return (unsafe_read(this + oPlayerFlags, int) & Flg); // public BasePlayer.PlayerFlags playerFlags;
	}


	unsigned short CRC(unsigned char* pcBlock, unsigned short len) {
		unsigned short crc = 0xFFFF;
		while (len--)
			crc = (crc << 8) ^ Crc16Table[(crc >> 8) ^ *pcBlock++];
		return crc;
	}

	float Held()
	{
		return unsafe_read(this + 0x98, float);
	}


	int GetID()
	{
		DWORD64 Info = unsafe_read((DWORD64)this + 0x20, DWORD64); // public ItemDefinition info;
		int ID = unsafe_read(Info + 0x18, int); // public int itemid;
		return ID;
	}


	char* ClassName() {
		return (char*)unsafe_read(unsafe_read(unsafe_read(this + oHeldEntity, DWORD64), DWORD64) + 0x10, DWORD64);
	}


	Weapon Info() {
		int ID = GetID();
		for (Weapon k : info) {
			if (k.id == ID) {
				return k;
			}
		}
		return Weapon{ 0 };
	}


	wchar_t* GetShortName(int* len)
	{
		DWORD64 Info = unsafe_read(this + ItemDefinition, DWORD64);
		pUncStr Str = ((pUncStr)unsafe_read(Info + oShortname, DWORD64));
		int leng = unsafe_read(Str + 0x10, int);
		if (!leng) return nullptr;
		if (len)*len = leng;
		return Str->str;
	}


	wchar_t* GetShortNameName()
	{
		DWORD64 Info = unsafe_read(this + ItemDefinition, DWORD64);
		pUncStr Str = ((pUncStr)unsafe_read(Info + oShortname, DWORD64));
		return Str->str;
	}

	int LoadedAmmo()
	{
		const auto Held = unsafe_read(this + oHeldEntity, DWORD64);
		if (Held <= 0)
			return 0;
		const auto Magazine = unsafe_read(Held + oPrimaryMagazine, DWORD64);
		if (Magazine <= 0 || Magazine == 0x3F000000)
		{
			return 0;
		}
		const auto ammoType = unsafe_read(Magazine + 0x20, DWORD64);
		if (ammoType <= 0 || ammoType == 0x3F000000)
		{
			return 0;
		}
		const int ammo = unsafe_read(ammoType + 0x18, int);
		return ammo;
	}

	USHORT GetNameHash()
	{
		int Len;
		UCHAR* ShortName = (UCHAR*)GetShortName(&Len);
		if (ShortName == nullptr) return 0;
		return CRC(ShortName, (Len * 2));
	}
	wchar_t* WeaponGetName()
	{
		DWORD64 Info = unsafe_read(this + ItemDefinition, DWORD64);
		DWORD64 DispName = unsafe_read(Info + odisplayname, DWORD64);
		pUncStr Str = ((pUncStr)unsafe_read(DispName + 0x18, DWORD64)); // default
		if (!Str) return nullptr; return Str->str;
	}
	int GetUID()
	{
		return unsafe_read(this + oUID, int);
	}
	Vector2 GetVA()
	{
		DWORD64 Input = unsafe_read(this + 0x4C8, DWORD64);//	public PlayerInput input;
		return unsafe_read(Input + 0x3C, Vector2);//private Vector3 bodyAngles;
	}
	Vector2 GetRA()
	{
		DWORD64 Input = unsafe_read(this + 0x4C8, DWORD64);//	public PlayerInput input;
		return unsafe_read(Input + 0x64, Vector2);//public Vector3 recoilAngles;
	}
	void SetVA(const Vector2& VA)
	{
		DWORD64 Input = unsafe_read(this + 0x4C8, DWORD64);//	public PlayerInput input;
		writenew<Vector2>(Input + 0x3C, VA); //private Vector3 bodyAngles;
	}
	void SetRA()
	{

		DWORD64 Input = unsafe_read(this + oPlayerInput, DWORD64);
		Vector2 RA = { 0.f, 0.f };
		writenew<Vector2>(Input + oRecoilAngles, RA);
	}
	bool IsMenu()
	{
		if (!this) return true;
		DWORD64 Input = unsafe_read(this + 0x4C8, DWORD64); //	public PlayerInput input;
		return !(unsafe_read(Input + 0x94, bool));// private bool hasKeyFocus;
	}

	void AddFlag(int flag)
	{
		DWORD64 mstate = unsafe_read(this + 0x588, DWORD64);
		int flags = unsafe_read(mstate + 0x24, int);
		writenew<int>(mstate + 0x24, flags |= flag);
	}

	void RemoveFlag(int flag)
	{
		DWORD64 mstate = unsafe_read(this + 0x588, DWORD64);
		int flags = unsafe_read(mstate + 0x24, int);
		writenew<int>(mstate + 0x24, flags &= ~flag);
	}

	bool IsDead() {
		if (!this) return true;
		return unsafe_read(this + oLifeState, bool);; // public BaseCombatEntity.LifeState lifestate; 
	}

	bool IsValid(bool LPlayer = false) {
		return (((LPlayer || features::Visuals::ignoresleeper) ? !HasFlags(16) : true) && !IsDead() && (GetHealth() >= 0.8f));
	}

	WeaponData* GetWeaponInfo(int Id) {
		DWORD64 Inventory = unsafe_read(this + oInventory, DWORD64);
		DWORD64 Belt = unsafe_read(Inventory + 0x28, DWORD64);
		DWORD64 ItemList = unsafe_read(Belt + 0x38, DWORD64);// public List<Item> itemList;
		DWORD64 Items = unsafe_read(ItemList + 0x10, DWORD64); //	public List<InventoryItem.Amount> items;
		return (WeaponData*)unsafe_read(Items + 0x20 + (Id * 0x8), DWORD64);
	}
	WeaponData* GetActiveWeapon() {
		int ActUID = unsafe_read(this + oClActiveItem, int);
		if (!ActUID) return nullptr;
		WeaponData* ActiveWeapon;
		for (int i = 0; i < 6; i++)
			if (ActUID == (ActiveWeapon = GetWeaponInfo(i))->GetUID())
				return ActiveWeapon;
		return nullptr;
	}
};



class LPlayerBase
{
public:
	LocalPlayer* lclPlayer = nullptr;
	Matrix4x4* pViewMatrix = nullptr;
	bool WorldToScreen(const Vector3& EntityPos, Vector2& ScreenPos)
	{
		if (!pViewMatrix) return false;
		Vector3 TransVec = Vector3(pViewMatrix->_14, pViewMatrix->_24, pViewMatrix->_34);
		Vector3 RightVec = Vector3(pViewMatrix->_11, pViewMatrix->_21, pViewMatrix->_31);
		Vector3 UpVec = Vector3(pViewMatrix->_12, pViewMatrix->_22, pViewMatrix->_32);
		float w = Math::Dot(TransVec, EntityPos) + pViewMatrix->_44;
		if (w < 0.098f) return false;
		float y = Math::Dot(UpVec, EntityPos) + pViewMatrix->_42;
		float x = Math::Dot(RightVec, EntityPos) + pViewMatrix->_41;
		ScreenPos = Vector2((width / 2) * (1.f + x / w), (height / 2) * (1.f - y / w));
		return true;
	}
};

inline LPlayerBase LxcalPlayer;