#pragma once
#include "etc.h"

namespace features {


	inline float ScreenHigh = 1920;
	inline float ScreenWidth = 1080;

	inline int screenHigh = 1920;
	inline int screenWidth = 1080;
	inline float BoneToAim = 0.5;
	inline float BoneAimbot = 0.5;
	inline bool DrawFov = false;

	__declspec(selectany) uintptr_t gBase = (DWORD64)GetModuleHandleA("GameAssembly.dll");
	__declspec(selectany) uintptr_t closestPlayer = NULL;

	namespace aimbot
	{
		inline bool AimbotActive = false;
		inline bool RightMouseAim = false;
		inline bool NoRecoil = false;
		inline float RecoilSlider = 0.0f;
		inline bool SuperEokaa = true;
		inline bool FOVSliderInMe = false;
		inline bool DrawFOV = false;
		inline bool RCS = false;
		inline bool ShootRate = false;
		inline bool CustomNight = false;
		inline bool nightend = false;
		inline bool alwaysdaytime = false;
		inline bool FillFOVV2 = false;
		inline float AimbFov = 90.f;
		inline float Range = 0.f;
		inline bool ignoreTeam = false;
		inline bool crossss = false;
	}

	namespace Color {

		inline float CSnapColors[] = { 255.f,255.f,255.f,255.f };
		inline float SnapColors[] = { 255.f,255.f,255.f,255.f };
		inline bool SnapColor = false;
		inline bool CSnapColor = false;
		inline bool FovColor = false;
		inline bool boxs = false;
		//float box[] = { R / 255.f, G / 255.f, B / 255.f, A / 255.f };
		inline float Fov[] = { 255.f, 255.f, 255.f };
		inline float SkeletonColors[] = { 255.f, 255.f, 255.f };
		inline float BoxColors[] = { 255.f, 255.f, 255.f };
		inline float NameColors[] = { 255.f, 255.f, 255.f };
		inline float DistanceColors[] = { 255.f, 255.f, 255.f };
		inline float WeaponColors[] = { 255.f, 255.f, 255.f };
		inline float CrosshairColors[] = { 255.f, 255.f, 255.f };
		inline float Chams[] = { 0.45f, 0.55f, 0.60f, 1.00f };
		inline float VisibleEsp[] = { 0.45f, 0.55f, 0.60f, 1.00f };
		inline float noVisibleEsp[] = { 255.f, 0.55f, 0.60f, 1.00f };
		inline float InventoryESP[] = { 0.f, 0.f, 0.f, 0.f };
		inline float TabColors[] = { 0.f, 0.f, 0.f, 0.f };
		inline float BotColors[] = { 0.f, 0.f, 0.f, 0.f };
		inline float FillFovColors[] = { 0.f, 0.f, 0.f, 0.f };
	}

	namespace ColorSHIT {

		inline float SleepersColor[] = { 255.f,255.f,255.f, 1.f };
		inline float WoundedColor[] = { 255.f, 255.f, 255.f, 1.f };
		inline float SnapColors[] = { 255.f,255.f,255.f,1.f };
		inline float Fov[] = { 0.f, 0.f, 255.f, 255.f };
		inline float SkeletonColors[] = { 255.f, 255.f, 255.f, 1.f };
		inline float BoxColors[] = { 255.f, 255.f, 255.f, 1.f };
		inline float BoxFilledColor[] = { 0.f, 0.f, 0.f, 0.3f };
		inline float WeaponColors[] = { 255.f, 255.f, 255.f, 1.f };
		inline float CrosshairColors[] = { 255.f, 255.f, 255.f, 1.f };
		inline float HpBar[] = { 0.f, 255.f, 0.f, 1.f };
		inline float EmptyHpBar[] = { 255.f, 0.f, 0.f, 1.f };
		inline float CorpseColor[] = { 0.f, 0.f, 0.f, 1.f };
		inline float PlayerRenderStringColor[] = { 1.f, 1.f, 1.f, 1.f };
		inline float BotBoxColors[] = { 0.f, 0.f, 0.f, 1.f };
		inline float FillFovColors[] = { 0.f, 0.f, 0.f, 0.3f };
		//    Resource Color
		inline float StoneColor[] = { 255.f,255.f,255.f, 1.f };
		inline float SulphurColor[] = { 255.f,255.f,255.f, 1.f };
		inline float MetalColor[] = { 255.f,255.f,255.f, 1.f };
		inline float PickUp_StoneColor[] = { 255.f,255.f,255.f, 1.f };
		inline float PickUp_SulfurColor[] = { 255.f,255.f,255.f, 1.f };
		inline float PickUp_MetalColor[] = { 255.f,255.f,255.f, 1.f };
		inline float PickUp_WoodColor[] = { 255.f,255.f,255.f, 1.f };
		inline float HempColor[] = { 255.f,255.f,255.f, 1.f };
		inline float MushroomsColor[] = { 255.f,255.f,255.f, 1.f };
		//    Building Color
		inline float CupboardColor[] = { 0.5f, 0.35f, 0.05f, 1.f };
		inline float LWBColor[] = { 0.500f, 0.200f, 0.05f, 1.f };
		inline float WSBColor[] = { 0.450f, 0.125f, 0.155f, 1.f };
		inline float CampFireCol[] = { 255.f,255.f,255.f, 1.f };
		inline float FurnaceCol[] = { 255.f,255.f,255.f, 1.f };
		//    Misc Esp Color
		inline float StashColor[] = { 255.f,255.f,255.f, 1.f };
		inline float MinicopterColor[] = { 255.f,255.f,255.f, 1.f };
		inline float TurretColor[] = { 255.f,255.f,255.f, 1.f };
		inline float GuntrapColor[] = { 255.f,255.f,255.f, 1.f };
		inline float BackpackColor[] = { 255.f,255.f,255.f, 1.f };
		inline float AirdropColor[] = { 255.f,255.f,255.f, 1.f };
		inline float SilentFovColor[] = { 0.f, 0.f, 0.f };
		inline float SilentColor[] = { 255, 255, 0 };
		inline float BagLootColor[] = { 255.f,255.f,255.f, 1.f };
		inline float BarrelCol[] = { 255.f,255.f,255.f, 1.f };
		inline float CargoCol[] = { 255.f,255.f,255.f, 1.f };
		inline float PatrolHeliCol[] = { 255.f,255.f,255.f, 1.f };
		//    Animals
		inline float WolfColor[] = { 255.f,255.f,255.f, 1.f };
		inline float DeerColor[] = { 255.f,255.f,255.f, 1.f };
		inline float HorseColor[] = { 255.f,255.f,255.f, 1.f };
		inline float ChickenColor[] = { 255.f,255.f,255.f, 1.f };
		inline float BoarColor[] = { 255.f,255.f,255.f, 1.f };
		inline float BearsColor[] = { 255.f,255.f,255.f, 1.f };
		//    Tech
		inline float CarsCol[] = { 255.f,255.f,255.f, 1.f };
		inline float RowboatCol[] = { 255.f,255.f,255.f, 1.f };
		inline float RHIBCol[] = { 255.f,255.f,255.f, 1.f };
		inline float KayakCol[] = { 255.f,255.f,255.f, 1.f };
		//   Food
		inline float PumpkinColor[] = { 255.f,255.f,255.f, 1.f };
		inline float PotatoColor[] = { 255.f,255.f,255.f, 1.f };
		inline float CornColor[] = { 255.f,255.f,255.f, 1.f };
		inline float BerryColor[] = { 255.f,255.f,255.f, 1.f };
	}

	namespace GG {

		inline bool rainbow = false;
		inline float  time = 0.f;


	}

	namespace Visuals
	{

		inline bool Player = true;
		inline bool ShowPlayerBox = true;
		inline bool ShowPLAYERS = true;
		inline bool ShowPlayerName = false;
		inline bool ShowPlayerDistance = false;
		inline bool ShowPlayerCornerBox = false;
		inline bool ShowPlayerCornerBoxV5 = false;
		inline bool HealthBarESP = false;
		inline bool SkeletonESP = false;
		inline bool ignoresleeper = false;
		inline bool ShowPlayerHP = false;
		inline bool playerLine = false;
		inline bool FillBoxESP = false;
		inline bool VisibleCheck = false;
	}




	namespace Visuals_Ores {

		inline bool StoneOre = false;
		inline bool MetalOre = false;
		inline bool SulfurOre = false;

	}

	namespace Visuals_Collectables {
		inline bool showDistanceCollectables = true;
		// Collectable Resources
		inline bool HempESP = false;
		inline bool MushroomESP = false;
		inline bool wood = false;
		inline bool stone = false;
		inline bool metal = false;
		inline bool sulfur = false;
		/*         DIFFERENT MENU SECTION       */
		inline bool LootBarrel = false;
		inline bool foodCrate = false; // assets/bundled/prefabs/radtown/crate_normal_2_food.prefab + assets/bundled/prefabs/radtown/foodbox.prefab
		inline bool medicalCrate = false; // assets/bundled/prefabs/radtown/crate_normal_2_medical.prefab
		inline bool toolsCrate = false; // assets/bundled/prefabs/radtown/crate_tools.prefab
		inline bool militaryCrate = false; // assets/bundled/prefabs/radtown/crate_normal.prefab
		inline bool normalCrate = false; // assets/bundled/prefabs/radtown/crate_normal_2.prefab
		inline bool basicCrate = false; // assets/bundled/prefabs/radtown/crate_basic.prefab
		inline bool eliteCrate = false; // assets/bundled/prefabs/radtown/crate_elite.prefab
		inline bool helicopterCrate = false; // assets/prefabs/npc/patrol helicopter/heli_crate.prefab
		inline bool bradleyCrate = false; // assets/prefabs/npc/m2bradley/bradley_crate.prefab
		inline bool codelockedCrates = false; // assets/prefabs/deployable/chinooklockedcrate/codelockedhackablecrate.prefab + assets/prefabs/deployable/chinooklockedcrate/codelockedhackablecrate_oilrig.prefab
		inline bool supplydrops = false; // supply_drop.prefab
		// Underwater Crates
		inline bool underwaterBasicCrate = false; // assets/bundled/prefabs/radtown/crate_underwater_basic.prefab
		inline bool underwaterAdvancedCrate = false; // assets/bundled/prefabs/radtown/crate_underwater_advanced.prefab
	}

	namespace Visuals_Animals {
		inline bool bearESP = false;
		inline bool boarESP = false;
		inline bool chickenESP = false;
		inline bool deerESP = false;
		inline bool horseESP = false;
		inline bool wolfESP = false;
	}
	namespace Visuals_Vehicles { // Add Modular Car support??
		inline bool minicopter = false;
		inline bool scrapheli = false;
		inline bool boat = false;
		inline bool rhib = false;
	}
	namespace Visuals_Traps {
		inline bool autoturret = false;
		inline bool flameturret = false;
		inline bool shotgunturret = false;
		inline bool landmine = false;
		inline bool beartrap = true; // Leave enabled by default? Cuz everyone hates em - specific
	}

	namespace Visuals_Others {
		inline bool stashESP = false;
		inline bool playerCorpses = false;
		inline bool playerBackpacks = false;
	}


	namespace Visuals_AI {
		inline bool ScientistESP = false;
		inline bool BradleyESP = false;
		inline bool PatrolHelicopterESP = false;
	}


	namespace MiscFeatures
	{
		inline bool SpiderMonkey = false;
	}


	namespace Useless
	{
		inline bool logoo = false;
	}

	namespace Keys
	{
		inline int terrainShootKey{ 0x4E };
		inline int aimKey{ 0x58 }; // VK_RMOUSE
		inline int gravityKey{ 0x04 };
		inline int walkonWaterKey{ 0x06 };
		inline int zoomKey{ 0x42 };
	}

	namespace Weapon
	{
		inline float RCSs = 0.f;
	}

	namespace exploits
	{
		inline float SexyFuckingFovValue = 100.f;
		inline float FakeLag = false;
		inline bool AntiAim = false;
		inline bool pSilent = false;
		inline bool AntiSpread = false;
		inline bool FatBoolet = false;
		inline bool SkinChanger = false;
		inline bool swimonland = false;
		inline bool SprintAnyware = false;
	}

	inline float FOV = 100.f;
	inline float FOVVV = 90.f;
	inline bool Menu = false;

	namespace GermanFighter /* Misc Functions */
	{
		inline bool Spiders = false;
	}

	namespace ColorsNShit
	{
		inline float playercolors[4] = { 1,1,1,1 };
		inline float crosshairfovcolors[4] = { 1,1,1,1 };
		inline float tracercolors[4] = { 1,1,1,1 };
		inline float wR, wG, wB = 0;
		inline float boxRoundness = 0;
	}

	namespace PlayerColor
	{
		inline static float PlayerRenderStringColor[] = { 1,0,0,1 };
		inline static float PlayerSkeletonColor[] = { 1,1,1,1 };
		inline static float PlayerBoxColor[] = { 1,0,0,1 };
		inline static float PlayerSleeperColor[] = { 0,0,1,1 };
		inline static float PlayerWoundedColor[] = { 1,0,1,0 };
		inline static float PlayerFillBoxColor[] = { 0,0,0,0.45 };
		inline static float PlayerDeadColor[] = { 0,1,1,1 };
		inline static float PlayerBackpackColor[] = { 0.6,0.3,0,1 };
	}

}