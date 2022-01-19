#include "MyAPI.h"

char* _strcpy_a(char* dest, const char* src)
{
	char* p;

	if ((dest == 0) || (src == 0))
		return dest;

	if (dest == src)
		return dest;

	p = dest;
	while (*src != 0) {
		*p = *src;
		p++;
		src++;
	}

	*p = 0;
	return dest;
}

wchar_t* _strcpy_w(wchar_t* dest, const wchar_t* src)
{
	wchar_t* p;

	if ((dest == 0) || (src == 0))
		return dest;

	if (dest == src)
		return dest;

	p = dest;
	while (*src != 0) {
		*p = *src;
		p++;
		src++;
	}

	*p = 0;
	return dest;
}



char* _strcat_a(char* dest, const char* src)
{
	if ((dest == 0) || (src == 0))
		return dest;

	while (*dest != 0)
		dest++;

	while (*src != 0) {
		*dest = *src;
		dest++;
		src++;
	}

	*dest = 0;
	return dest;
}

wchar_t* _strcat_w(wchar_t* dest, const wchar_t* src)
{
	if ((dest == 0) || (src == 0))
		return dest;

	while (*dest != 0)
		dest++;

	while (*src != 0) {
		*dest = *src;
		dest++;
		src++;
	}

	*dest = 0;
	return dest;
}


char* _strncpy_a(char* dest, size_t ccdest, const char* src, size_t ccsrc)
{
	char* p;

	if ((dest == 0) || (src == 0) || (ccdest == 0))
		return dest;

	ccdest--;
	p = dest;

	while ((*src != 0) && (ccdest > 0) && (ccsrc > 0)) {
		*p = *src;
		p++;
		src++;
		ccdest--;
		ccsrc--;
	}

	*p = 0;
	return dest;
}

wchar_t* _strncpy_w(wchar_t* dest, size_t ccdest, const wchar_t* src, size_t ccsrc)
{
	wchar_t* p;

	if ((dest == 0) || (src == 0) || (ccdest == 0))
		return dest;

	ccdest--;
	p = dest;

	while ((*src != 0) && (ccdest > 0) && (ccsrc > 0)) {
		*p = *src;
		p++;
		src++;
		ccdest--;
		ccsrc--;
	}

	*p = 0;
	return dest;
}



BOOL supRunProcess2(
	_In_ LPWSTR lpszProcessName,
	_In_opt_ LPWSTR lpszParameters,
	_In_opt_ LPWSTR lpVerb,
	_In_ BOOL fWait
)
{
	BOOL bResult;
	SHELLEXECUTEINFO shinfo;

	if (lpszProcessName == NULL)
		return FALSE;

	RtlSecureZeroMemory(&shinfo, sizeof(shinfo));
	shinfo.cbSize = sizeof(shinfo);
	shinfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	shinfo.lpFile = lpszProcessName;
	shinfo.lpParameters = lpszParameters;
	shinfo.lpDirectory = NULL;
	shinfo.nShow = SW_SHOW;
	shinfo.lpVerb = lpVerb;
	bResult = ShellExecuteEx(&shinfo);
	if (bResult) {
		if (fWait)
			WaitForSingleObject(shinfo.hProcess, 0x8000);
		CloseHandle(shinfo.hProcess);
	}
	return bResult;
}


BOOL supRunProcess(
	_In_ LPWSTR lpszProcessName,
	_In_opt_ LPWSTR lpszParameters
)
{
	return supRunProcess2(lpszProcessName, lpszParameters, NULL, TRUE);
}


void supCopyMemory(
	_Inout_ void* dest,
	_In_ size_t cbdest,
	_In_ const void* src,
	_In_ size_t cbsrc
)
{
	char* d = (char*)dest;
	char* s = (char*)src;

	if ((dest == 0) || (src == 0) || (cbdest == 0))
		return;
	if (cbdest < cbsrc)
		cbsrc = cbdest;

	while (cbsrc > 0) {
		*d++ = *s++;
		cbsrc--;
	}
}
