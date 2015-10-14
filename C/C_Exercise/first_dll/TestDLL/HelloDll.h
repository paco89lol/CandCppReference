#ifndef INDLL_H
#define INDLL_H
	#ifdef EXPORTING_DLL
		extern __declspec(dllexport) void HelloWorld();
	#else
		extern __declspec(dllexport) void HelloWorld();
	#endif
#endif
