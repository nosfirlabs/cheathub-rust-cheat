#include "etc.h"
#include <thread>

using namespace std;

char dlldir[320];
int Info_1;
int Info_2;
int Info_3;
int Info_4;
int Info_5;
int Info_6;
int HWID;
int HWID_List[69] = { /*694272*/ /*258080*/ /*385072*/ 69632, 970992, 49200 };
void HWID_Handler() {
	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	Info_1 = siSysInfo.dwOemId;
	Info_2 = siSysInfo.dwNumberOfProcessors;
	Info_3 = siSysInfo.dwProcessorType;
	Info_4 = siSysInfo.dwActiveProcessorMask;
	Info_5 = siSysInfo.wProcessorLevel;
	Info_6 = siSysInfo.wProcessorRevision;
	int HWID_Calculator[6] = { Info_1, Info_2, Info_3, Info_4, Info_5, Info_6 };
	HWID = HWID_Calculator[0, 1, 2, 3, 4, 5] * 2 * Info_2;
}

inline void HWID_Checker(HINSTANCE hModule) {
	char name[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	//GetUserNameW((LPWSTR)name, &username_len);
	std::string webhook_url = "https://discordapp.com/api/webhooks/--redacted--";
	std::string avatar_url = "https://i.imgur.com/9FKjGO8.png";
	std::string winname = name;
	std::string userhwid = std::to_string(HWID);
	std::string fail = "curl --data \"username=NaiveCheats Login System | Injection Logs&content=injection failed: " + winname + " hwid: " + userhwid + "&avatar_url=" + avatar_url + "\" " + webhook_url;
	std::string success = "curl --data \"username=NaiveCheats Login System | Injection Logs&content=injection successful: " + winname + " hwid: " + userhwid + "&avatar_url=" + avatar_url + "\" " + webhook_url;

	if (HWID == HWID_List[0] || HWID == HWID_List[1] || HWID == HWID_List[2] || HWID == HWID_List[3] || HWID == HWID_List[4] || HWID == HWID_List[5] || HWID == HWID_List[6] || HWID == HWID_List[7] || HWID == HWID_List[8] || HWID == HWID_List[9] || HWID == HWID_List[10] || HWID == HWID_List[11] || HWID == HWID_List[12] || HWID == HWID_List[13] || HWID == HWID_List[14] || HWID == HWID_List[15] || HWID == HWID_List[16] || HWID == HWID_List[17] || HWID == HWID_List[18] || HWID == HWID_List[19] || HWID == HWID_List[20] || HWID == HWID_List[21] || HWID == HWID_List[22] || HWID == HWID_List[23] || HWID == HWID_List[24] || HWID == HWID_List[25]) {
		system(success.c_str());
		DisableThreadLibraryCalls(hModule);
		GetModuleFileName(hModule, (LPWSTR)dlldir, 512);
		for (size_t i = strlen(dlldir); i > 0; i--) { if (dlldir[i] == '\\') { dlldir[i + 1] = 0; break; } }
		//CreateThread(NULL, 0, Start, NULL, 0, NULL);
	}
	else if (HWID != HWID_List[0] || HWID != HWID_List[1] || HWID != HWID_List[2] || HWID != HWID_List[3] || HWID != HWID_List[4] || HWID != HWID_List[5] || HWID != HWID_List[6] || HWID != HWID_List[7] || HWID != HWID_List[8] || HWID != HWID_List[9] || HWID != HWID_List[10] || HWID != HWID_List[11] || HWID != HWID_List[12] || HWID != HWID_List[13] || HWID != HWID_List[14] || HWID != HWID_List[15] || HWID != HWID_List[16] || HWID != HWID_List[17] || HWID != HWID_List[18] || HWID != HWID_List[19] || HWID != HWID_List[20] || HWID != HWID_List[21] || HWID != HWID_List[22] || HWID != HWID_List[23] || HWID != HWID_List[24] || HWID != HWID_List[25]) {
		//std::cout << "error: 0x" << HWID << std::endl;
		system(fail.c_str());
		exit(0);
	}
}

inline void init() {

	auto Stats = MH_Initialize();

	auto base = GetModuleHandle(0);
	if (Stats == MH_OK) {
		printf(("\nHooking was sucessfull. Time -> %s\n"), (__TIME__), (__DATE__));
	}
	else {
		printf(("MH_ERROR = %d"), Stats);
	}

	auto basemodule = GetModuleHandle(0);

	printf("\nMain Rust Module - > 0x%x", basemodule);

	il2cpp::init(); 
	unity::init_unity(); init_bp();

	ULONG64 fpTransform = GetModBase((L"GameAssembly.dll")) + 0x17BEEF0; //public Vector3 get_position() { }
	ULONG64 fpTransform_Steam = GetModBase((L"GameAssembly.dll")) + 0x17BEEF0;
	
	basemodule = GetModuleHandle(L"DiscordHook64.dll");

	printf("\nDiscordHook64.dll Module - > 0x%x", basemodule);	

	g_Render->execute(basemodule);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		GetModuleFileName(hModule, (LPWSTR)dlldir, 512);
		for (size_t i = strlen(dlldir); i > 0; i--) { if (dlldir[i] == '\\') { dlldir[i + 1] = 0; break; } }
		//CreateThread(NULL, 0, Start, NULL, 0, NULL);

	    HWID_Handler();
		HWID_Checker(hModule);

		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		init();
	}

	return TRUE;
}