#include "Visuals.h"
#include <d3d9.h>

/*
* Current Build Version
* version v5
*/

uintptr_t shader;

namespace ImGui
{
	IMGUI_API bool Tab(unsigned int index, const char* label, int* selected, float width = 0)
	{
		ImGuiStyle& style = ImGui::GetStyle();
		ImVec4 color = style.Colors[ImGuiCol_Button];
		ImVec4 colorActive = style.Colors[ImGuiCol_ButtonActive];
		ImVec4 colorHover = style.Colors[ImGuiCol_ButtonHovered];

		if (index > 0)
			ImGui::SameLine();

		if (index == *selected)
		{
			style.Colors[ImGuiCol_Button] = colorActive;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorActive;
		}
		else
		{
			style.Colors[ImGuiCol_Button] = color;
			style.Colors[ImGuiCol_ButtonActive] = colorActive;
			style.Colors[ImGuiCol_ButtonHovered] = colorHover;
		}

		if (ImGui::Button(label, ImVec2(width, 30)))
			*selected = index;

		style.Colors[ImGuiCol_Button] = color;
		style.Colors[ImGuiCol_ButtonActive] = colorActive;
		style.Colors[ImGuiCol_ButtonHovered] = colorHover;

		return *selected == index;
	}
}


D3DCOLOR FLOAT4TOD3DCOLOR(float Col[])
{
	ImU32 col32_no_alpha = ImGui::ColorConvertFloat4ToU32(ImVec4(Col[0], Col[1], Col[2], Col[3]));
	float a = (col32_no_alpha >> 24) & 255;
	float r = (col32_no_alpha >> 16) & 255;
	float g = (col32_no_alpha >> 8) & 255;
	float b = col32_no_alpha & 255;
	return D3DCOLOR_ARGB((int)a, (int)b, (int)g, (int)r);
}

D3DCOLOR rainbow() {

	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;

	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	}
	else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	}
	else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	}
	else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	}
	else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	}
	else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}

	x += features::GG::time;//�������� ��������� ������
	if (x >= 255.0f)
		x = 0.0f;

	y += features::GG::time; //�������� ��������� ������
	if (y > 1530.0f)
		y = 0.0f;


	return D3DCOLOR_ARGB((int)r, (int)g, (int)b, 255);
}


const char* CheatColorManager[] =
{
	"CrosshairColors", "Fov",
};

void Visuals::DrawMenu()
{

	if (features::Menu)
	{
		//temp shit
		static const char* cfgs[]{ "Legit", "Semi-Rage", "Tada-Mode" };
		static int selectedCfg = 0;

		static int ListBoxResultColor;


		ImGuiColorEditFlags ColorFlag = ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_AlphaBar;
		ImGuiWindowFlags ColorPicker = ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoSidePreview;
		ImGuiWindowFlags Flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar;

		//here for main tab yes
		static int mainTab = 0;
		//ImGui::SetNextWindowSizeConstraints(ImVec2(760, 480));
		ImGui::SetNextWindowSizeConstraints(ImVec2(760, 680), ImVec2(760, 680));
		ImGui::Begin("cheathub.ac " "[" __DATE__ "]", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

		static auto calculateChildWindowPosition = [](int num) -> ImVec2 {
			return ImVec2(ImGui::GetWindowPos().x + 120 + (ImGui::GetWindowSize().x / 3 - 31) * num + 20 * num, ImGui::GetWindowPos().y + 20);
		};

		static auto calculateChildWindowPositionDouble = [](int num) -> ImVec2 {
			return ImVec2(ImGui::GetWindowPos().x + 120 + (ImGui::GetWindowSize().x / 2 - 70) * num + 20 * num, ImGui::GetWindowPos().y + 20);
		};
		auto child_size = ImVec2(ImGui::GetWindowSize().x / 2 - 90, ImGui::GetWindowSize().y / 2 - 40);
		auto child_size_d = ImVec2(ImGui::GetWindowSize().x / 2 - 90, ImGui::GetWindowSize().y - 40);
		//ImGui::SetWindowSize(ImVec2((float)ImGuiWidth, (float)ImGuiHight));


		//make buttons for tab
		if (ImGui::Button("Aimbot", ImVec2(100.0f, 100.0f)))
			mainTab = 0;
		ImGui::Spacing();
		if (ImGui::Button("ESP", ImVec2(100.0f, 100.0f)))
			mainTab = 1;
		ImGui::Spacing();
		if (ImGui::Button("Farming ESP", ImVec2(100.0f, 100.0f)))
			mainTab = 2;
		ImGui::Spacing();
		if (ImGui::Button("Misc", ImVec2(100.0f, 100.0f)))
			mainTab = 3;
		//ImGui::Spacing();
	/*	if (ImGui::Button("JS", ImVec2(100.0f, 100.0f)))
			mainTab = 4;*/
		ImGui::Spacing();
		if (ImGui::Button("Config", ImVec2(100.0f, 100.0f)))
			mainTab = 5;
		ImGui::Spacing();





		//switch here for the main tab on left yes
		switch (mainTab)
		{
		case 0:
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(0));
			ImGui::BeginChild("Aimbot Settings", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("Aimbot Settings");
				ImGui::Spacing();
				ImGui::Checkbox("Enable Aimbot", &features::aimbot::AimbotActive);
				//("AimKey"), &features::Keys::aimKey, ImVec2(120.f, 0);
				ImGui::SliderFloat("Aim Distance", &features::aimbot::Range, 0.f, 400.f);
				ImGui::Checkbox("Target Line", &features::Visuals::playerLine);
				ImGui::Checkbox("Draw FOV", &features::DrawFov);
				ImGui::Checkbox("Fill FOV", &features::aimbot::FillFOVV2);
				ImGui::SliderFloat("Field Of View", &features::aimbot::AimbFov, 90.f, 300.f);
				ImGui::Checkbox("Draw Crosshair", &features::aimbot::crossss);
				ImGui::Text("Coloring"); // features::Color::Fov
				ImGui::Spacing();
				ImGui::Text("FOV Circle");
				ImGui::SameLine();
				ImGui::ColorEdit4("FOV Color", features::Color::Fov, ColorFlag);

			}
			ImGui::EndChild();
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(1));
			ImGui::BeginChild("Aimbot Settings 2", child_size_d);
			{
				ImGui::Spacing();
				//Put here shit for second tab ok



			}
			ImGui::EndChild();
			break;
		case 1:
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(0));
			ImGui::BeginChild("ESP Settings", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("Player ESP");
				ImGui::Spacing();
				ImGui::Checkbox("Player Box", &features::Visuals::ShowPlayerBox);
				//ImGui::Spacing();					
				//ImGui::Spacing();
				//ImGui::Checkbox("Name", &features::Visuals::ShowPlayerName);
				//ImGui::Spacing();
				ImGui::Checkbox("Distance", &features::Visuals::ShowPlayerDistance);
				//ImGui::Spacing();
				ImGui::Checkbox("Health Bar", &features::Visuals::HealthBarESP);
				ImGui::Checkbox("Fill Box", &features::Visuals::FillBoxESP);
				ImGui::Checkbox("Corner Box", &features::Visuals::ShowPlayerCornerBoxV5);
				ImGui::Checkbox("Player Name", &features::Visuals::ShowPlayerName);
				ImGui::Text("Player Box Color"); // features::ColorSHIT::BoxFilledColor
				ImGui::SameLine();
				ImGui::ColorEdit4("Player Color", features::ColorSHIT::BoxColors, ColorFlag);
				ImGui::Text("Box Filled Color");
				ImGui::SameLine();
				ImGui::ColorEdit4("Filled Color", features::ColorSHIT::BoxFilledColor, ColorFlag);
			}
			ImGui::EndChild();
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(1));
			ImGui::BeginChild("ESP Settings 2", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("AI ESP");
				ImGui::Spacing();
				//ImGui::Checkbox("Scientists", &features::Visuals_AI::ScientistESP);
				ImGui::Checkbox("Bradley", &features::Visuals_AI::BradleyESP);
				ImGui::Checkbox("Patrol Helicopter", &features::Visuals_AI::PatrolHelicopterESP);
			}
			ImGui::EndChild();
			break;
		case 2:
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(0));
			ImGui::BeginChild("Farming ESP Settings", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("Ore ESP");
				ImGui::Spacing();
				ImGui::Checkbox("Stone Ore", &features::Visuals_Ores::StoneOre);
				ImGui::Checkbox("Metal Ore", &features::Visuals_Ores::MetalOre);
				ImGui::Checkbox("Sulfur Ore", &features::Visuals_Ores::SulfurOre);

				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();

				ImGui::Text("Collectable ESP");
				ImGui::Spacing();
				ImGui::Checkbox("Show Distance (Collectables)", &features::Visuals_Collectables::showDistanceCollectables);
				ImGui::Checkbox("Hemp", &features::Visuals_Collectables::HempESP);
				ImGui::Checkbox("Mushroom", &features::Visuals_Collectables::MushroomESP);

				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();

				ImGui::Text("Animal ESP");
				ImGui::Spacing();
				ImGui::Checkbox("Bears", &features::Visuals_Animals::bearESP);
				ImGui::Checkbox("Boars", &features::Visuals_Animals::boarESP);
				ImGui::Checkbox("Chickens", &features::Visuals_Animals::chickenESP);
				ImGui::Checkbox("Deers", &features::Visuals_Animals::deerESP);
				ImGui::Checkbox("Horses", &features::Visuals_Animals::horseESP);
				ImGui::Checkbox("Wolves", &features::Visuals_Animals::wolfESP);

				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();

				ImGui::Text("Other ESP");
				ImGui::Spacing();
				//ImGui::Checkbox("Stashes (Not Implemented)", &activeyesno);
				// Might do Stash here instead
			}
			ImGui::EndChild();
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(1));
			ImGui::BeginChild("Farming ESP Settings 2", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("Crate ESP");
				ImGui::Spacing();
				ImGui::Checkbox("Barrels", &features::Visuals_Collectables::LootBarrel);
				ImGui::Checkbox("Food Crates", &features::Visuals_Collectables::foodCrate);
				ImGui::Checkbox("Medical Crates", &features::Visuals_Collectables::medicalCrate);
				ImGui::Checkbox("Small Wood Crates", &features::Visuals_Collectables::basicCrate);
				ImGui::Checkbox("Tools Crates", &features::Visuals_Collectables::toolsCrate);
				ImGui::Checkbox("Normal Crates", &features::Visuals_Collectables::normalCrate);
				ImGui::Checkbox("Military Crates", &features::Visuals_Collectables::militaryCrate);
				ImGui::Checkbox("Elite Crates", &features::Visuals_Collectables::eliteCrate);
				ImGui::Checkbox("Helicopter Crates", &features::Visuals_Collectables::helicopterCrate);
				ImGui::Checkbox("Bradley Crates", &features::Visuals_Collectables::bradleyCrate);
				ImGui::Checkbox("Hackable Crates", &features::Visuals_Collectables::codelockedCrates);

				ImGui::Spacing();
				ImGui::Separator();
				ImGui::Spacing();

				ImGui::Text("Underwater Crates");
				ImGui::Spacing();
				ImGui::Checkbox("UW Basic Crates", &features::Visuals_Collectables::underwaterBasicCrate);
				ImGui::Checkbox("UW Advanced Crates", &features::Visuals_Collectables::underwaterAdvancedCrate);
			}
			ImGui::EndChild();
			break;
		case 3:
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(0));
			ImGui::BeginChild("Misc", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("Misc");
				ImGui::Checkbox("No Recoil", &features::aimbot::NoRecoil);
				ImGui::SliderFloat("Recoil System", &features::aimbot::RecoilSlider, 0.f, 100.f);
				ImGui::Checkbox("Climb Walls", &features::GermanFighter::Spiders);
				ImGui::Checkbox("Swim On Land", &features::exploits::swimonland);
				ImGui::SliderFloat("Fov Changer", &features::exploits::SexyFuckingFovValue, 100.f, 150.f);

			}
			ImGui::EndChild();
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(1));
			ImGui::BeginChild("Aimbot Settings 2", child_size_d);
			{
				ImGui::Spacing();
				//Put here shit for second tab ok



			}
			ImGui::EndChild();
			break;

			/*case 4:
				ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(0));
				ImGui::BeginChild("Tada", child_size_d);
				{
					ImGui::Spacing();
					ImGui::Text("tada is a fucking black nigger");
					ImGui::Spacing();
					ImGui::Checkbox("Logo", &features::Useless::logoo);

					//ImGui::InputTextMultiline("", "", ImGuiInputTextFlags_AllowTabInput);
					//go add textbox or smth thx this is only a placeholder that wont work
				}*/

			ImGui::EndChild();
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(1));
			ImGui::BeginChild("Aimbot Settings 2", child_size_d);
			{
				ImGui::Spacing();
				//Put here shit for second tab ok



			}
			ImGui::EndChild();
			break;
		case 5:
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(0));
			ImGui::BeginChild("CFG", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("Create config");
				ImGui::Spacing();

				//ImGui::InputText( "", " ", 0);
				//go add textbox or smth thx this is only a placeholder that wont work
				ImGui::SameLine();
				ImGui::Button("Create");
				ImGui::Checkbox("Logo", &features::Useless::logoo);

				/*ImGui::Text("Color Manager");
				ImGui::Separator();
				ImGui::Spacing();
				ImGuiWindowFlags ColorPicker = ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoSidePreview;
				ImGui::SameLine(40.f, -2);
				switch (ListBoxResultColor)
				{
				case 0:
					ImGui::ColorPicker4(("1"), features::ColorSHIT::BoxFilledColor, ColorPicker);
					break;
				case 1:
					ImGui::ColorPicker4(("2"), features::Color::Fov, ColorPicker);
					break;
				}
				ImGui::SameLine(280.f, -2);
				ImGui::ListBox((""), &ListBoxResultColor, CheatColorManager, IM_ARRAYSIZE(CheatColorManager));*/

			}
			ImGui::EndChild();
			ImGui::SetNextWindowPos(calculateChildWindowPositionDouble(1));
			ImGui::BeginChild("CFG2", child_size_d);
			{
				ImGui::Spacing();
				ImGui::Text("Load config");
				ImGui::Spacing();

				ImGui::Combo("", &selectedCfg, cfgs, IM_ARRAYSIZE(cfgs));
				//go add textbox or smth thx this is only a placeholder that wont work
				ImGui::SameLine();
				ImGui::Button("Load");

			}
			ImGui::EndChild();
			break;
		}

		ImGui::End();
	}
}


bool mfound = false;

inline void FindMatrix(HMODULE mxdle) {
	static DWORD64 dwGameObjectManager = 0;
	if (!dwGameObjectManager)
		dwGameObjectManager = RVAA((DWORD64)g_Scanner->FindPattern(mxdle, "\x48\x8B\x15\x00\x00\x00\x00\x66\x39", "xxx????xx"), 7); //UnityPlayer.dll

	DWORD64 ObjMgr = readnew<uintptr_t>((uintptr_t)dwGameObjectManager);
	if (!ObjMgr) return;
	UINT64 end = readnew<uintptr_t>((uintptr_t)ObjMgr);
	for (UINT64 Obj = readnew<uintptr_t>((uintptr_t)ObjMgr + 0x8); (Obj && (Obj != end)); Obj = readnew<uintptr_t>((uintptr_t)Obj + 0x8))
	{
		UINT64 GameObject = readnew<uintptr_t>((uintptr_t)Obj + 0x10);
		WORD Tag = readnew<uintptr_t>((uintptr_t)GameObject + 0x54);
		if (Tag == 5)
		{
			UINT64 ObjClass = readnew<uintptr_t>((uintptr_t)GameObject + 0x30);
			UINT64	Entity = readnew<uintptr_t>((uintptr_t)ObjClass + 0x18);
			LxcalPlayer.pViewMatrix = (Matrix4x4*)(Entity + 0xDC); //0x2e4 | Matrix
			mfound = true;
			return;
		}
	}
}







inline void CornerBox(float Entity_x, float Entity_y, float Entity_w, float Entity_h, D2D1::ColorF color)
{
	VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / 3.5f, Entity_y }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / 3.5f, Entity_y }, color);
	VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / 3.5f, Entity_y }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / 3.5f }, color);

	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y }, color);
	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 3.5f }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 3.5f }, color);

	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y + Entity_h }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 3.5f, Entity_y + Entity_h }, color);
	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 3.5f }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 3.5f }, color);

	VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 3.5f, Entity_y + Entity_h }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 3.5f, Entity_y + Entity_h }, color);
	VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 3.5f }, D2D1::ColorF::White, 3.f);
	VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 3.5f }, color);
}

/* Start The ESP Rendering */
void Visuals::Entity()
{


	wchar_t watermark[64];
	static int cases = 0;
	static float r = 1.00f, g = 0.00f, b = 1.00f;
	switch (cases)
	{
	case 0: { r -= 0.05f; if (r <= 0) cases += 1; break; }
	case 1: { g += 0.05f; b -= 0.05f; if (g >= 1) cases += 1; break; }
	case 2: { r += 0.05f; if (r >= 1) cases += 1; break; }
	case 3: { b += 0.05f; g -= 0.05f; if (b >= 1) cases = 0; break; }
	default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
	}
	_swprintf(watermark, L"cheathub.ac");
	VisualHelper::Render.String(Vector2(100, 55), watermark, D2D1::ColorF(r, g, b, 1.f), true);

	//VisualHelper::Render.String(Vector2(100, 55), watermark, D2D1::ColorF(r, g, b, 1.f), true);
	Vector2 kek = VisualHelper::Render.CanvasSize();
	features::ScreenWidth = kek.x;
	features::ScreenHigh = kek.y;
	/*if (features::aimbot::crossss) {
		float xs = features::ScreenWidth / 2, ys = features::ScreenHigh / 2;
		VisualHelper::Render.Line(Vector2{ xs, ys }, Vector2{ xs + 4, ys + 4 }, D2D1::ColorF::White, 0.7f);
		VisualHelper::Render.Line(Vector2{ xs, ys }, Vector2{ xs + 4, ys - 4 }, D2D1::ColorF::White, 0.7f);
		VisualHelper::Render.Line(Vector2{ xs, ys }, Vector2{ xs - 4, ys - 4 }, D2D1::ColorF::White, 0.7f);
		VisualHelper::Render.Line(Vector2{ xs, ys }, Vector2{ xs - 4, ys + 4 }, D2D1::ColorF::White, 0.7f);

		VisualHelper::Render.Line(Vector2{ xs + 4, ys + 4 }, Vector2{ xs + 4 + 4, ys + 4 + 4 }, D2D1::ColorF::Black, 0.7f);
		VisualHelper::Render.Line(Vector2{ xs + 4, ys - 4 }, Vector2{ xs + 4 + 4, ys - 4 - 4 }, D2D1::ColorF::Black, 0.7f);
		VisualHelper::Render.Line(Vector2{ xs - 4, ys - 4 }, Vector2{ xs - 4 - 4, ys - 4 - 4 }, D2D1::ColorF::Black, 0.7f);
		VisualHelper::Render.Line(Vector2{ xs - 4, ys + 4 }, Vector2{ xs - 4 - 4, ys + 4 + 4 }, D2D1::ColorF::Black, 0.7f);
	}*/

	if (features::DrawFov) {
		float xs = features::ScreenWidth / 2, ys = features::ScreenHigh / 2;
		VisualHelper::Render.Circle(Vector2{ xs, ys }, FLOAT4TOD3DCOLOR(features::Color::Fov), features::aimbot::AimbFov, 1.f);

		VisualHelper::Render.FillCircle(Vector2{ xs , ys }, D2D1::ColorF(0.f, 0.f, 0.f, 0.3f), features::aimbot::AimbFov / features::aimbot::FillFOVV2);
	}

	if (features::closestPlayer != NULL)
	{
		auto* TargetPlayer = reinterpret_cast<LocalPlayer*>(features::closestPlayer);
		static float screenX = GetSystemMetrics(SM_CXSCREEN);
		static float screenY = GetSystemMetrics(SM_CYSCREEN);
		static Vector2 startPos = Vector2(screenX / 2.f, screenY - 200.f);
		Vector2 ScreenPos;
		if (features::Visuals::playerLine)
		{
			if (!(TargetPlayer->GetBoneByID(spine1).x == 0 && TargetPlayer->GetBoneByID(spine1).y == 0 && TargetPlayer->GetBoneByID(spine1).z == 0)) {
				if (LxcalPlayer.WorldToScreen(TargetPlayer->GetBoneByID(head), ScreenPos))
					VisualHelper::Render.Line(startPos, ScreenPos, D2D1::ColorF::Lime, 1.f);
				_swprintf(watermark, L"Locked On To Target");
				VisualHelper::Render.String(Vector2(860, 55), watermark, D2D1::ColorF(r, g, b, 1.f), true);
			}
		}
	}

	if (features::aimbot::AimbFov > (kek.y - 3)) features::aimbot::AimbFov = (kek.y - 3);

	float FOVV = features::FOV;
	float CurFOV;
	bool LP_isValid = false;

	bool LocalPlayerValid = false;
	DWORD64 BaseNetworkable;
	LocalPlayer* AimPlayer = nullptr;
	LocalPlayer* BP;
	LocalPlayer* LP;
	bool npc = false;
	D2D1::ColorF FillColor = D2D1::ColorF(0, 0, 0, 0.45);
	int CurPos = 0;
	if (isSteam == -1) BaseNetworkable = readnew<uintptr_t>((uintptr_t)GetModBase((L"GameAssembly.dll")) + g_BN); /* BaseNetworkable */ /* in Script -> BaseNetworkable_TypeInfo. */
	else BaseNetworkable = readnew<uintptr_t>((uintptr_t)GetModBase((L"GameAssembly.dll")) + g_BN_Steam); /* BaseNetworkable */
	DWORD64 EntityRealm = readnew<uintptr_t>((uintptr_t)BaseNetworkable + 0xB8);
	DWORD64 ClientEntities = readnew<uintptr_t>((uintptr_t)EntityRealm);
	DWORD64 ClientEntities_list = readnew<uintptr_t>((uintptr_t)ClientEntities + 0x10);
	DWORD64 ClientEntities_values = readnew<uintptr_t>((uintptr_t)ClientEntities_list + 0x28);
	if (!ClientEntities_values) return;
	int EntityCount = readnew<uintptr_t>((uintptr_t)ClientEntities_values + 0x10);
	DWORD64 EntityBuffer = readnew<uintptr_t>((uintptr_t)ClientEntities_values + 0x18);

	auto unityplayer = GetModuleHandle(L"UnityPlayer.dll");

	if (!LxcalPlayer.pViewMatrix || !mfound)
	{
		FindMatrix(unityplayer);
	}

	for (int i = 0; i <= EntityCount; i++)
	{
		DWORD64 Entity = readnew<uintptr_t>((uintptr_t)EntityBuffer + 0x20 + (i * 0x8));
		if (Entity <= 100000) continue;
		DWORD64 Object = readnew<uintptr_t>((uintptr_t)Entity + 0x10);
		if (Object <= 100000) continue;
		DWORD64 ObjectClass = readnew<uintptr_t>((uintptr_t)Object + 0x30);
		if (ObjectClass <= 100000) continue;
		pUncStr name = readnew<pUncStr>((uintptr_t)ObjectClass + 0x60);
		if (!name) continue;
		char* buff = name->stub;
		if (strstr(buff, ("Local"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);                                             /* offset = playermodel */
			if (!readnew<uintptr_t>((uintptr_t)Player + 0x50) || readnew<uintptr_t>((uintptr_t)Player + 0x18) || !readnew<uintptr_t>((uintptr_t)Player + 0x4A8)) continue;
			if (Player != LxcalPlayer.lclPlayer) {
				printf("LocalPlayer %lld\n", Player->GetSteamID());
				mfound = false;
			}
			Vector3 pos = Player->GetPosition();
			LxcalPlayer.lclPlayer = Player;
			LP_isValid = true;
		}



		if (features::Visuals_AI::BradleyESP && strstr(buff, ("bradleyapc"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256]; //90
				swprintf(res, L"Bradley");
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Red, true);
			}
		}

		if (features::Visuals_AI::PatrolHelicopterESP && strstr(buff, ("assets/prefabs/npc/patrol helicopter/patrolhelicopter.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			uintptr_t BaseObject = unsafe_read(Object + 0x30, uintptr_t);
			uintptr_t BaseEntity = unsafe_read(BaseObject + 0x18, uintptr_t);
			uintptr_t BaseHelicopter = unsafe_read(BaseEntity + 0x28, uintptr_t);
			Vector2 Pos;
			int health = (int)ceil(unsafe_read(BaseHelicopter + 0x20C, float));

			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256]; //90
				swprintf(res, L"Patrol Helicopter [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(head), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Red, true);
			}
		}

		// Animals
		if (features::Visuals_Animals::deerESP && strstr(buff, ("stag.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Deer [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Violet, true);
			}
		}
		if (features::Visuals_Animals::chickenESP && strstr(buff, ("chicken.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Chicken [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Violet, true);
			}
		}
		if (features::Visuals_Animals::bearESP && strstr(buff, ("bear.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Bear [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Violet, true);
			}
		}
		if (features::Visuals_Animals::boarESP && strstr(buff, ("boar.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Boar [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Violet, true);
			}
		}
		if (features::Visuals_Animals::wolfESP && strstr(buff, ("wolf.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Wolf [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Violet, true);
			}
		}
		if (features::Visuals_Animals::horseESP && strstr(buff, ("horse.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Horse [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Violet, true);
			}
		}
		// Underwater
		if (features::Visuals_Collectables::underwaterAdvancedCrate && strstr(buff, ("crate_underwater_advanced.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Underwater Advanced Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::WhiteSmoke, true);
			}
		}
		// Underwater
		if (features::Visuals_Collectables::underwaterBasicCrate && strstr(buff, ("crate_underwater_basic.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Underwater Basic Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::White, true);
			}
		}
		if (features::Visuals_Collectables::codelockedCrates && (strstr(buff, ("codelockedhackablecrate.prefab")) || strstr(buff, ("codelockedhackablecrate_oilrig.prefab")))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Hackable Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Red, true);
			}
		}

		if (features::Visuals_Collectables::bradleyCrate && strstr(buff, ("bradley_crate.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Bradley Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Red, true);
			}
		}
		if (features::Visuals_Collectables::helicopterCrate && strstr(buff, ("heli_crate.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Helicopter Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Red, true);
			}
		}
		if (features::Visuals_Collectables::eliteCrate && strstr(buff, ("crate_elite.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Elite Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::LightGoldenrodYellow, true);
			}
		}
		if (features::Visuals_Collectables::basicCrate && strstr(buff, ("crate_basic.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Basic Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Orange, true);
			}
		}
		if (features::Visuals_Collectables::normalCrate && strstr(buff, ("crate_normal_2.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Normal Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::LightBlue, true);
			}
		}
		if (features::Visuals_Collectables::militaryCrate && strstr(buff, ("crate_normal.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Military Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Blue, true);
			}
		}
		if (features::Visuals_Collectables::toolsCrate && strstr(buff, ("crate_tools.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Tools Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::LightBlue, true);
			}
		}
		if (features::Visuals_Collectables::medicalCrate && strstr(buff, ("crate_normal_2_medical.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Medical Crate [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Orange, true);
			}
		}
		if (features::Visuals_Collectables::foodCrate && strstr(buff, ("foodbox.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64);
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3);
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				_swprintf(res, L"Foodbox [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::LightGreen, true);
			}
		}
		if (features::Visuals_Collectables::LootBarrel && (strstr(buff, ("loot-barrel-2.prefab")) || strstr(buff, ("loot-barrel-1.prefab")) || strstr(buff, ("oil_barrel.prefab")))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64); //Tag 449
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {


				wchar_t res[256];//90
				_swprintf(res, L"Barrel [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));

				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Yellow, true);
			}
		}



		if (features::Visuals_Collectables::MushroomESP && strstr(buff, ("mushroom-cluster-5.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64); //Tag 449
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {


				wchar_t res[256];

				if (features::Visuals_Collectables::showDistanceCollectables) {
					swprintf(res, L"Mushroom [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				}
				else {
					swprintf(res, L"Mushroom");
				}

				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Yellow, true);
			}
		}


		if (features::Visuals_Collectables::HempESP && strstr(buff, ("hemp-collectable.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);                                              /* offset = playermodel */

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64); //Tag 449
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];

				if (features::Visuals_Collectables::showDistanceCollectables) {
					swprintf(res, L"Hemp [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				}
				else {
					swprintf(res, L"Hemp");
				}
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Lime, true);
			}
		}

		if (features::Visuals_Ores::StoneOre && strstr(buff, ("stone-ore.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);                                              /* offset = playermodel */

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64); //Tag 449
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				//_swprintf(res, L"Stone Ore [%d m]", (int)Math::Calc3D_Dist(Player->GetBoneByID(r_foot), pos)); // fix this fucking shit later (distance)
				_swprintf(res, L"Stone-Ore [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::RosyBrown, true);
			}
		}

		if (features::Visuals_Ores::MetalOre && strstr(buff, ("metal-ore.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64); //Tag 449
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				//_swprintf(res, L"Stone Ore [%d m]", (int)Math::Calc3D_Dist(Player->GetBoneByID(r_foot), pos)); // fix this fucking shit later (distance)
				swprintf(res, L"Metal-Ore [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Gray, true);
			}
		}

		if (features::Visuals_Ores::SulfurOre && strstr(buff, ("sulfur-ore.prefab"))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);

			DWORD64 Res = unsafe_read(Object + 0x28, DWORD64);
			DWORD64 gameObject = unsafe_read(ObjectClass + 0x30, DWORD64); //Tag 449
			DWORD64 Trans = unsafe_read(gameObject + 0x8, DWORD64);
			DWORD64 Vec = unsafe_read(Trans + 0x38, DWORD64);
			Vector3 pos = unsafe_read(Vec + 0x90, Vector3); ///public Vector3 PointEnd
			Vector2 Pos;
			if (LxcalPlayer.WorldToScreen(pos, Pos)) {
				wchar_t res[256];
				//_swprintf(res, L"Stone Ore [%d m]", (int)Math::Calc3D_Dist(Player->GetBoneByID(r_foot), pos)); // fix this fucking shit later (distance)
				swprintf(res, L"Sulfur-Ore [%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
				VisualHelper::Render.RenderString(Vector2{ Pos.x - 0.f, Pos.y - 0.f }, res, false, D2D1::ColorF::Gold, true);
			}
		}


		if (features::Visuals::Player && (strstr(buff, ("player.prefab")) || strstr(buff, ("playermodel")) || (strstr(buff, "scientist")) && (!strstr(buff, "prop") && !strstr(buff, "corpse")))) {
			LocalPlayer* Player = (LocalPlayer*)readnew<uintptr_t>((uintptr_t)Object + 0x28);                                              /* offset = playermodel */
			if (!readnew<uintptr_t>((uintptr_t)Player + 0x50) || readnew<uintptr_t>((uintptr_t)Player + 0x18) || !readnew<uintptr_t>((uintptr_t)Player + 0x4A8)) continue;


			Vector3 pos = Player->GetPosition();
			Vector2 tempFeetR, tempFeetL;
			Vector3 ro = Player->GetBoneByID(r_foot);
			if (ro.x == 0 && ro.y == 0 && ro.z == 0) return;

			if (Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(head), Player->GetBoneByID(head)) > features::aimbot::Range) continue;

			if (FOVV > (CurFOV = GetFov(Player, BoneList(features::BoneToAim))) && !Player->IsDead()) {
				FOVV = CurFOV; features::closestPlayer = (uintptr_t)Player;
			}
			if (LxcalPlayer.WorldToScreen(ro, tempFeetR) && LxcalPlayer.WorldToScreen(Player->GetBoneByID(l_foot), tempFeetL))
			{
				Vector2 tempHead;
				if (LxcalPlayer.WorldToScreen(Player->GetBoneByID(jaw) + Vector3(0.f, 0.16f, 0.f), tempHead))
				{
					Vector2 leftTopCorner = tempHead - Vector2(0.4f, 0.f);
					Vector2 rightBottomCorner = tempFeetR;

					Vector2 tempFeet = (tempFeetR + tempFeetL) / 2.f;
					float Entity_h = tempHead.y - tempFeet.y;
					float w = Entity_h / 4;
					float Entity_x = tempFeet.x - w;
					float Entity_y = tempFeet.y;
					float Entity_w = Entity_h / 2;

					if (features::Visuals::ShowPlayerBox) {
						VisualHelper::Render.Rectangle(Vector2{ Entity_x, Entity_y }, Vector2{ Entity_w, Entity_h }, { 0.f, 0.f, 0.f, 255.f }, 3.f);
						VisualHelper::Render.Rectangle(Vector2{ Entity_x, Entity_y }, Vector2{ Entity_w, Entity_h }, FLOAT4TOD3DCOLOR(features::ColorSHIT::BoxColors)); //D2D1::ColorF::YellowGreen
					}


					if (features::Visuals::FillBoxESP)
					{
						//VisualHelper::Render.FillRectangle(Vector2{ Entity_x, Entity_y }, Vector2{ Entity_w, Entity_h }, FillColor);
						VisualHelper::Render.FillARGB(ImVec2{ Entity_x, Entity_y }, ImVec2{ Entity_w, Entity_h }, FLOAT4TOD3DCOLOR(features::ColorSHIT::BoxFilledColor), 0, 0);
					}

					if (features::Visuals::HealthBarESP)
					{

						int health = (int)Player->GetHealth();
						float maxheal = (npc ? 300.f : 100.f);
						float minheal = (npc ? 300.f : 100.f);

						VisualHelper::Render.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF::OrangeRed); //8.f
						VisualHelper::Render.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / minheal) }, D2D1::ColorF::LimeGreen);
						VisualHelper::Render.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF::Green);
						VisualHelper::Render.Rectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF::Black, 0.5f);


						/*int health = (int)Player->GetHealth();
						float maxhealth = 100.f;
						if ((int)Player->GetHealth() <= 33)
						{
							VisualHelper::Render.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxhealth) }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f)); //red
						}
						if ((int)Player->GetHealth() >= 34 && (int)Player->GetHealth() <= 66)
						{
							VisualHelper::Render.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxhealth) }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f)); //yellow
						}
						if ((int)Player->GetHealth() >= 67)
						{
							VisualHelper::Render.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxhealth) }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f)); //lime
						}
						VisualHelper::Render.Rectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF::Black, 0.5f);*/
					}

					if (features::Visuals::ShowPlayerName || features::Visuals::ShowPlayerDistance)
					{
						wchar_t ress[64];
						if (wcslen(Player->GetName()) > 0)
						{

							if (features::Visuals::ShowPlayerDistance)
							{
								if (features::Visuals::ShowPlayerName)
								{
									swprintf(ress, L"%s [%dm]", Player->GetName(), (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
								}
								else { // Distance only
									swprintf(ress, L"[%dm]", (int)Math::Calc3D_Dist(LxcalPlayer.lclPlayer->GetBoneByID(r_foot), pos));
								}

							}
							else
							{
								_swprintf(ress, L"[%s]", Player->GetName());
							}
							VisualHelper::Render.String(Vector2{ Entity_x + Entity_w, Entity_y + Entity_h - 20.f }, ress, D2D1::ColorF(features::ColorsNShit::playercolors[0], features::ColorsNShit::playercolors[1], features::ColorsNShit::playercolors[2], features::ColorsNShit::playercolors[3]));
						}
					}


					if (features::Visuals::ShowPlayerCornerBoxV5)
					{
						if (features::GG::rainbow)
						{
							VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / 3.5f,Entity_y }, rainbow());
							VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / 3.5f }, rainbow());
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 3.5f,Entity_y }, rainbow());
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 3.5f }, rainbow());
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 3.5f,Entity_y + Entity_h }, rainbow());
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 3.5f }, rainbow());
							VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 3.5f,Entity_y + Entity_h }, rainbow());
							VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 3.5f }, rainbow());
						}
						else
						{
							VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / 3.5f,Entity_y }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
							VisualHelper::Render.Line({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / 3.5f }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / 3.5f,Entity_y }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / 3.5f }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / 3.5f,Entity_y + Entity_h }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
							VisualHelper::Render.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / 3.5f }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
							VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / 3.5f,Entity_y + Entity_h }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
							VisualHelper::Render.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / 3.5f }, FLOAT4TOD3DCOLOR(features::Color::BoxColors));
						}
					}

					if (features::Visuals::ShowPlayerCornerBox)
					{
						if ((int)Player->GetHealth() > 0)
						{
							if (LxcalPlayer.lclPlayer->IsTeamMate(Player->GetSteamID()))
							{
								CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::LimeGreen);
							}
							else
							{
								CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::White);
							}
						}
						else
						{
							CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::Red); //dead
						}
					}
				}
			}
		}
	}



	if (features::closestPlayer)
	{
		if (FOVV < (CurFOV = GetFov((LocalPlayer*)features::closestPlayer, BoneList(features::BoneAimbot))))
		{
			features::closestPlayer = 0;
		}
	}
	if (LP_isValid)
	{
		Aim((LocalPlayer*)features::closestPlayer);
	}
	else LxcalPlayer.lclPlayer = nullptr;



}
