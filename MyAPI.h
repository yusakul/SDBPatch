#pragma once
#include <Windows.h>
#include <ntstatus.h>

char* _strcpy_a(char* dest, const char* src);

wchar_t* _strcpy_w(wchar_t* dest, const wchar_t* src);

char* _strcat_a(char* dest, const char* src);

wchar_t* _strcat_w(wchar_t* dest, const wchar_t* src);

char* _strncpy_a(char* dest, size_t ccdest, const char* src, size_t ccsrc);

wchar_t* _strncpy_w(wchar_t* dest, size_t ccdest, const wchar_t* src, size_t ccsrc);


void supCopyMemory(
	_Inout_ void* dest,
	_In_ size_t cbdest,
	_In_ const void* src,
	_In_ size_t cbsrc
);


BOOL supRunProcess2(
	_In_ LPWSTR lpszProcessName,
	_In_opt_ LPWSTR lpszParameters,
	_In_opt_ LPWSTR lpVerb,
	_In_ BOOL fWait
);

BOOL supRunProcess(
	_In_ LPWSTR lpszProcessName,
	_In_opt_ LPWSTR lpszParameters
);

BOOLEAN supIsProcess32bit(
	_In_ HANDLE hProcess
);


typedef struct _UACME_CONTEXT {
	BOOL                    IsWow64;
	PVOID                   ucmHeap;
	ULONG                   dwBuildNumber;
	WCHAR                   szSystemRoot[MAX_PATH + 1]; //with end slash
	WCHAR                   szSystemDirectory[MAX_PATH + 1];//with end slash
	WCHAR                   szTempDirectory[MAX_PATH + 1]; //with end slash
	WCHAR                   szOptionalParameter[MAX_PATH + 1]; //limited to MAX_PATH
} UACMECONTEXT, * PUACMECONTEXT;
extern UACMECONTEXT g_ctx;


#define SDBINST_EXE                 L"sdbinst.exe"
#define ISCSICLI_EXE                L"iscsicli.exe"
#define PRINTUI_EXE                 L"printui.exe"
#define BINARYPATH_TAG              L"binarypatch01"
#define MSFT_FULL                   L"Microsoft Corporation"
#define MSFT_MIN                    L"Microsoft"