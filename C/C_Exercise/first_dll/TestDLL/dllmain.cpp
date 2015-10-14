// dllmain.cpp : 定義 DLL 應用程式的進入點。
#include "stdafx.h"
#include "HelloDll.h"
//.dll
		//compiler		//linker
		//compile       //linking
//		.h + +.cpp -> .lib -> .dll
void HelloWorld(){
	::MessageBox(0, L"TEST", L"TEST2", 0);
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		HelloWorld();
	}
	case DLL_THREAD_ATTACH:
	{

	}
	case DLL_THREAD_DETACH:
	{

	}
	case DLL_PROCESS_DETACH:
	{

	}
		break;
	}
	return TRUE;
}
