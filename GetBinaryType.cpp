// GetBinaryType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// SCS_32BIT_BINARY    0
// SCS_DOS_BINARY      1
// SCS_WOW_BINARY      2
// SCS_PIF_BINARY      3
// SCS_POSIX_BINARY    4
// SCS_OS216_BINARY    5
// SCS_64BIT_BINARY    6

LPCTSTR szBinaryTypes[] = {
    _T("32-bit Windows"),
    _T("MS-DOS"),
    _T("16-bit Windows"),
    _T("MS-DOS PIF"),
    _T("POSIX"),
    _T("16-bit OS/2"),
    _T("64-bit Windows"),
    _T("Unknown")
};

int _tmain(int argc, _TCHAR* argv[])
{
    if (argc != 2)
    {
        CPath szPath = argv[0];
        szPath.StripPath();

        ::_tprintf(_T("Usage: %s [file]\n"), szPath);

        return 1;
    }

    DWORD dwBinaryType = 7;
    if (::GetBinaryType(argv[1], &dwBinaryType))
        ::_tprintf(szBinaryTypes[dwBinaryType]);
    else
        ::_tprintf(_T("GetBinaryType(): Error %ld.\n"), ::GetLastError());

    return 0;
}
