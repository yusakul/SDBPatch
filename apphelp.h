#pragma once
#include <Windows.h>
// apphelp.h
#define TAG_TYPE_LIST 28679  

typedef enum _PATH_TYPE {
    DOS_PATH,
    NT_PATH
} PATH_TYPE;

typedef HANDLE PDB;
typedef DWORD TAG;
typedef DWORD INDEXID;
typedef DWORD TAGID;

typedef struct tagATTRINFO {
    TAG  tAttrID;
    DWORD dwFlags;
    union {
        ULONGLONG ullAttr;
        DWORD   dwAttr;
        TCHAR* lpAttr;
    };
} ATTRINFO, * PATTRINFO;

typedef PDB(WINAPI* SdbCreateDatabasePtr)(LPCWSTR, PATH_TYPE);
typedef VOID(WINAPI* SdbCloseDatabasePtr)(PDB);
typedef VOID(WINAPI* SdbCloseDatabaseWritePtr)(PDB);
typedef BOOL(WINAPI* SdbDeclareIndexPtr)(PDB, TAG, TAG, DWORD, BOOL, INDEXID*);
typedef BOOL(WINAPI* SdbCommitIndexesPtr)(PDB);
typedef TAGID(WINAPI* SdbBeginWriteListTagPtr)(PDB, TAG);
typedef BOOL(WINAPI* SdbEndWriteListTagPtr)(PDB, TAGID);
typedef BOOL(WINAPI* SdbWriteQWORDTagPtr)(PDB, TAG, ULONGLONG);
typedef BOOL(WINAPI* SdbWriteStringTagPtr)(PDB, TAG, LPCWSTR);
typedef BOOL(WINAPI* SdbWriteDWORDTagPtr)(PDB, TAG, DWORD);
typedef BOOL(WINAPI* SdbWriteBinaryTagPtr)(PDB, TAG, PBYTE, DWORD);
typedef BOOL(WINAPI* SdbStartIndexingPtr)(PDB, INDEXID);
typedef BOOL(WINAPI* SdbStopIndexingPtr)(PDB, INDEXID);

typedef struct _APPHELP_API {
    SdbCreateDatabasePtr         SdbCreateDatabase;
    SdbCloseDatabasePtr          SdbCloseDatabase;
    SdbCloseDatabaseWritePtr     SdbCloseDatabaseWrite;
    SdbDeclareIndexPtr           SdbDeclareIndex;
    SdbCommitIndexesPtr          SdbCommitIndexes;
    SdbBeginWriteListTagPtr      SdbBeginWriteListTag;
    SdbEndWriteListTagPtr        SdbEndWriteListTag;
    SdbWriteQWORDTagPtr          SdbWriteQWORDTag;
    SdbWriteStringTagPtr         SdbWriteStringTag;
    SdbWriteDWORDTagPtr          SdbWriteDWORDTag;
    SdbWriteBinaryTagPtr         SdbWriteBinaryTag;
    SdbStartIndexingPtr          SdbStartIndexing;
    SdbStopIndexingPtr           SdbStopIndexing;
} APPHELP_API, * PAPPHELP_API;

#define PATCH_MATCH 0x4
#define PATCH_REPLACE 0x2
#define MAX_MODULE	32

typedef struct _PATCHBITS {
    DWORD	Opcode;
    DWORD	ActionSize;
    DWORD	PatternSize;
    DWORD	RVA;
    DWORD	Reserved;
    WCHAR	ModuleName[MAX_MODULE];
    BYTE	Pattern[1];
} PATCHBITS, * PPATCHBITS;


// TABLE 1
#define TAG_TYPE_LIST (0x7000)
#define TAG_DATABASE (0x1 | TAG_TYPE_LIST) //Database entry.
#define TAG_LIBRARY (0x2 | TAG_TYPE_LIST) //Library entry.
#define TAG_INEXCLUDE (0x3 | TAG_TYPE_LIST) //Include and exclude entry.
#define TAG_SHIM (0x4 | TAG_TYPE_LIST) //Shim entry that contains the name and purpose information.
#define TAG_PATCH (0x5 | TAG_TYPE_LIST) //Patch entry that contains the in-memory patching information.
#define TAG_APP (0x6 | TAG_TYPE_LIST) //Application entry.
#define TAG_EXE (0x7 | TAG_TYPE_LIST) //Executable entry.
#define TAG_MATCHING_FILE (0x8 | TAG_TYPE_LIST) //Matching file entry.
#define TAG_SHIM_REF (0x9| TAG_TYPE_LIST) //Shim definition entry.
#define TAG_PATCH_REF (0xA | TAG_TYPE_LIST) //Patch definition entry.
#define TAG_LAYER (0xB | TAG_TYPE_LIST) //Layer shim entry.
#define TAG_FILE (0xC | TAG_TYPE_LIST) //File attribute used in a shim entry.
#define TAG_APPHELP (0xD | TAG_TYPE_LIST) //Apphelp information entry.
#define TAG_LINK (0xE | TAG_TYPE_LIST) //Apphelp online link information entry.
#define TAG_DATA (0xF | TAG_TYPE_LIST) //Name-value mapping entry.
#define TAG_MSI_TRANSFORM (0x10 | TAG_TYPE_LIST) //MSI transformation entry.
#define TAG_MSI_TRANSFORM_REF (0x11 | TAG_TYPE_LIST) //MSI transformation definition entry.
#define TAG_MSI_PACKAGE (0x12 | TAG_TYPE_LIST) //MSI package entry.
#define TAG_FLAG (0x13 | TAG_TYPE_LIST) //Flag entry.
#define TAG_MSI_CUSTOM_ACTION (0x14 | TAG_TYPE_LIST) //MSI custom action entry.
#define TAG_FLAG_REF (0x15 | TAG_TYPE_LIST) //Flag definition entry.
#define TAG_ACTION (0x16 | TAG_TYPE_LIST) //Unused.
#define TAG_LOOKUP (0x17 | TAG_TYPE_LIST) //Lookup entry used for lookup in a driver database.
#define TAG_STRINGTABLE (0x801 | TAG_TYPE_LIST) //String table entry.
#define TAG_INDEXES (0x802 | TAG_TYPE_LIST) //Indexes entry that defines all the indexes in a shim database.
#define TAG_INDEX (0x803 | TAG_TYPE_LIST) //Index entry that defines an index in a shim database.

// TABLE 2
#define TAG_TYPE_STRINGREF (0x6000)
#define TAG_NAME (0x1 | TAG_TYPE_STRINGREF) //Name attribute.
#define TAG_DESCRIPTION (0x2 | TAG_TYPE_STRINGREF) //Description entry.
#define TAG_MODULE (0x3 | TAG_TYPE_STRINGREF) //Module attribute.
#define TAG_API (0x4 | TAG_TYPE_STRINGREF) //API entry.
#define TAG_VENDOR (0x5 | TAG_TYPE_STRINGREF) //Vendor name attribute.
#define TAG_APP_NAME (0x6 | TAG_TYPE_STRINGREF) //Application name attribute that describes an application entry in a shim database.
#define TAG_COMMAND_LINE (0x8 | TAG_TYPE_STRINGREF) //Command line attribute that is used when passing arguments to a shim, for example.
#define TAG_COMPANY_NAME (0x9 | TAG_TYPE_STRINGREF) //Company name attribute.
#define TAG_DLLFILE (0xA | TAG_TYPE_STRINGREF) //DLL file attribute for a shim entry.
#define TAG_WILDCARD_NAME (0xB | TAG_TYPE_STRINGREF) //Wildcard name attribute for an executable entry with a wildcard as the file name.
#define TAG_PRODUCT_NAME (0x10 | TAG_TYPE_STRINGREF) //Product name attribute.
#define TAG_PRODUCT_VERSION (0x11 | TAG_TYPE_STRINGREF) //Product version attribute.
#define TAG_FILE_DESCRIPTION (0x12 | TAG_TYPE_STRINGREF) //File description attribute.
#define TAG_FILE_VERSION (0x13 | TAG_TYPE_STRINGREF) //File version attribute.
#define TAG_ORIGINAL_FILENAME (0x14 | TAG_TYPE_STRINGREF) //Original file name attribute.
#define TAG_INTERNAL_NAME (0x15 | TAG_TYPE_STRINGREF) //Internal file name attribute.
#define TAG_LEGAL_COPYRIGHT (0x16 | TAG_TYPE_STRINGREF) //Copyright attribute.
#define TAG_16BIT_DESCRIPTION (0x17 | TAG_TYPE_STRINGREF) //16-bit description attribute.
#define TAG_APPHELP_DETAILS (0x18 | TAG_TYPE_STRINGREF) //Apphelp details message information attribute.
#define TAG_LINK_URL (0x19 | TAG_TYPE_STRINGREF) //Apphelp online link URL attribute.
#define TAG_LINK_TEXT (0x1A | TAG_TYPE_STRINGREF) //Apphelp online link text attribute.
#define TAG_APPHELP_TITLE (0x1B | TAG_TYPE_STRINGREF) //Apphelp title attribute.
#define TAG_APPHELP_CONTACT (0x1C | TAG_TYPE_STRINGREF) //Apphelp vendor contact attribute.
#define TAG_SXS_MANIFEST (0x1D | TAG_TYPE_STRINGREF) //Side-by-side manifest entry.
#define TAG_DATA_STRING (0x1E | TAG_TYPE_STRINGREF) //String attribute for a data entry.
#define TAG_MSI_TRANSFORM_FILE (0x1F | TAG_TYPE_STRINGREF) //File name attribute of an MSI transformation entry.
#define TAG_16BIT_MODULE_NAME (0x20 | TAG_TYPE_STRINGREF) //16-bit module name attribute.
#define TAG_LAYER_DISPLAYNAME (0x21 | TAG_TYPE_STRINGREF) //Unused.
#define TAG_COMPILER_VERSION (0x22 | TAG_TYPE_STRINGREF) //Shim database compiler version.
#define TAG_ACTION_TYPE (0x23 | TAG_TYPE_STRINGREF) //Unused.
#define TAG_EXPORT_NAME (0x24 | TAG_TYPE_STRINGREF) //Export file name attribute.


#define TABLE 3
#define TAG_TYPE_DWORD (0x4000)
#define TAG_SIZE (0x1 | TAG_TYPE_DWORD) //File size attribute.
#define TAG_OFFSET (0x2 | TAG_TYPE_DWORD) //Unused.
#define TAG_CHECKSUM (0x3 | TAG_TYPE_DWORD) //File checksum attribute.
#define TAG_SHIM_TAGID (0x4 | TAG_TYPE_DWORD) //Shim TAGID attribute.
#define TAG_PATCH_TAGID (0x5 | TAG_TYPE_DWORD) //Patch TAGID attribute.
#define TAG_MODULE_TYPE (0x6 | TAG_TYPE_DWORD) //Module type attribute.
#define TAG_VERDATEHI (0x7 | TAG_TYPE_DWORD) //High-order portion of the file version date attribute.
#define TAG_VERDATELO (0x8 | TAG_TYPE_DWORD) //Low-order portion of the file version date attribute.
#define TAG_VERFILEOS (0x9 | TAG_TYPE_DWORD) //Operating system file version attribute.
#define TAG_VERFILETYPE (0xA | TAG_TYPE_DWORD) //File type attribute.
#define TAG_PE_CHECKSUM (0xB | TAG_TYPE_DWORD) //PE file checksum attribute.
#define TAG_PREVOSMAJORVER (0xC | TAG_TYPE_DWORD) //Major operating system version attribute.
#define TAG_PREVOSMINORVER (0xD | TAG_TYPE_DWORD) //Minor operating system version attribute.
#define TAG_PREVOSPLATFORMID (0xE | TAG_TYPE_DWORD) //Operating system platform identifier attribute.
#define TAG_PREVOSBUILDNO (0xF | TAG_TYPE_DWORD) //Operating system build number attribute.
#define TAG_PROBLEMSEVERITY (0x10 | TAG_TYPE_DWORD) //Block attribute of an Apphelp entry. This determines whether the application is hard or soft blocked.
#define TAG_LANGID (0x11 | TAG_TYPE_DWORD) //Language identifier of an Apphelp entry.
#define TAG_VER_LANGUAGE (0x12 | TAG_TYPE_DWORD) //Language version attribute of a file.
#define TAG_ENGINE (0x14 | TAG_TYPE_DWORD) //Unused.
#define TAG_HTMLHELPID (0x15 | TAG_TYPE_DWORD) //Help identifier attribute for an Apphelp entry.
#define TAG_INDEX_FLAGS (0x16 | TAG_TYPE_DWORD) //Flags attribute for an index entry.
#define TAG_FLAGS (0x17 | TAG_TYPE_DWORD) //Flags attribute for an Apphelp entry.
#define TAG_DATA_VALUETYPE (0x18 | TAG_TYPE_DWORD) //Data type attribute for a data entry.
#define TAG_DATA_DWORD (0x19 | TAG_TYPE_DWORD) //DWORD value attribute for a data entry.
#define TAG_LAYER_TAGID (0x1A | TAG_TYPE_DWORD) //Layer shim TAGID attribute.
#define TAG_MSI_TRANSFORM_TAGID (0x1B | TAG_TYPE_DWORD) //MSI transform TAGID attribute.
#define TAG_LINKER_VERSION (0x1C | TAG_TYPE_DWORD) //Linker version attribute of a file.
#define TAG_LINK_DATE (0x1D | TAG_TYPE_DWORD) //Link date attribute of a file.
#define TAG_UPTO_LINK_DATE (0x1E | TAG_TYPE_DWORD) //Link date attribute of a file. Matching is done up to and including this link date.
#define TAG_OS_SERVICE_PACK (0x1F | TAG_TYPE_DWORD) //Operating system service pack attribute for an executable entry.
#define TAG_FLAG_TAGID (0x20 | TAG_TYPE_DWORD) //Flags TAGID attribute.
#define TAG_RUNTIME_PLATFORM (0x21 | TAG_TYPE_DWORD) //Run-time platform attribute of a file.
#define TAG_OS_SKU (0x22 | TAG_TYPE_DWORD) //Operating system SKU attribute for an executable entry.
#define TAG_OS_PLATFORM (0x23 | TAG_TYPE_DWORD) //Operating system platform attribute.
#define TAG_APP_NAME_RC_ID (0x24 | TAG_TYPE_DWORD) //Application name resource identifier attribute for Apphelp entries.
#define TAG_VENDOR_NAME_RC_ID (0x25 | TAG_TYPE_DWORD) //Vendor name resource identifier attribute for Apphelp entries.
#define TAG_SUMMARY_MSG_RC_ID (0x26 | TAG_TYPE_DWORD) //Summary message resource identifier attribute for Apphelp entries.
#define TAG_VISTA_SKU (0x27 | TAG_TYPE_DWORD) //Windows Vista SKU attribute.
#define TAG_DESCRIPTION_RC_ID (0x28 | TAG_TYPE_DWORD) //Description resource identifier attribute for Apphelp entries.
#define TAG_PARAMETER1_RC_ID (0x29 | TAG_TYPE_DWORD) //Parameter1 resource identifier attribute for Apphelp entries.
#define TAG_TAGID (0x801 | TAG_TYPE_DWORD) //TAGID attribute.

#define TABLE 4
#define TAG_TYPE_STRING (0x8000)
#define TAG_STRINGTABLE_ITEM (0x801 | TAG_TYPE_STRING) //String table item entry.


#define TABLE 5
#define TAG_TYPE_NULL (0x1000)
#define TAG_INCLUDE (0x1 | TAG_TYPE_NULL) //Include list entry.
#define TAG_GENERAL (0x2 | TAG_TYPE_NULL) //General purpose shim entry.
#define TAG_MATCH_LOGIC_NOT (0x3 | TAG_TYPE_NULL) //NOT of matching logic entry.
#define TAG_APPLY_ALL_SHIMS (0x4 | TAG_TYPE_NULL) //Unused.
#define TAG_USE_SERVICE_PACK_FILES (0x5 | TAG_TYPE_NULL) //Service pack information for Apphelp entries.
#define TAG_MITIGATION_OS (0x6 | TAG_TYPE_NULL) //Mitigation at operating system scope entry.
#define TAG_BLOCK_UPGRADE (0x7 | TAG_TYPE_NULL) //Upgrade block entry.
#define TAG_INCLUDEEXCLUDEDLL (0x8 | TAG_TYPE_NULL) //DLL include/exclude entry.

#define TABLE 6
#define TAG_TYPE_QWORD (0x5000)
#define TAG_TIME (0x1 | TAG_TYPE_QWORD) //Time attribute.
#define TAG_BIN_FILE_VERSION (0x2 | TAG_TYPE_QWORD) //Bin file version attribute for file entries.
#define TAG_BIN_PRODUCT_VERSION (0x3 | TAG_TYPE_QWORD) //Bin product version attribute for file entries.
#define TAG_MODTIME (0x4 | TAG_TYPE_QWORD) //Unused.
#define TAG_FLAG_MASK_KERNEL (0x5 | TAG_TYPE_QWORD) //Kernel flag mask attribute.
#define TAG_UPTO_BIN_PRODUCT_VERSION (0x6 | TAG_TYPE_QWORD) //Bin product version attribute of a file. Matching is done up to and including this product version.
#define TAG_DATA_QWORD (0x7 | TAG_TYPE_QWORD) //ULONGLONG value attribute for a data entry.
#define TAG_FLAG_MASK_USER (0x8 | TAG_TYPE_QWORD) //User flag mask attribute.
#define TAG_FLAGS_NTVDM1 (0x9 | TAG_TYPE_QWORD) //NTVDM1 flag mask attribute.
#define TAG_FLAGS_NTVDM2 (0xA | TAG_TYPE_QWORD) //NTVDM2 flag mask attribute.
#define TAG_FLAGS_NTVDM3 (0xB | TAG_TYPE_QWORD) //NTVDM3 flag mask attribute.
#define TAG_FLAG_MASK_SHELL (0xC | TAG_TYPE_QWORD) //Shell flag mask attribute.
#define TAG_UPTO_BIN_FILE_VERSION (0xD | TAG_TYPE_QWORD) //Bin file version attribute of a file. Matching is done up to and including this file version.
#define TAG_FLAG_MASK_FUSION (0xE | TAG_TYPE_QWORD) //Fusion flag mask attribute.
#define TAG_FLAG_PROCESSPARAM (0xF | TAG_TYPE_QWORD) //Process param flag attribute.
#define TAG_FLAG_LUA (0x10 | TAG_TYPE_QWORD) //LUA flag attribute.
#define TAG_FLAG_INSTALL (0x11 | TAG_TYPE_QWORD) //Install flag attribute.

// TABLE 7
#define TAG_TYPE_BINARY (0x9000)
#define TAG_PATCH_BITS (0x2 | TAG_TYPE_BINARY) //Patch file bits attribute.
#define TAG_FILE_BITS (0x3 | TAG_TYPE_BINARY) //File bits attribute.
#define TAG_EXE_ID (0x4 | TAG_TYPE_BINARY) //GUID attribute of an executable entry.
#define TAG_DATA_BITS (0x5 | TAG_TYPE_BINARY) //Data bits attribute.
#define TAG_MSI_PACKAGE_ID (0x6 | TAG_TYPE_BINARY) //MSI package identifier attribute of an MSI package.
#define TAG_DATABASE_ID (0x7 | TAG_TYPE_BINARY) //GUID attribute of a database.
#define TAG_INDEX_BITS (0x801 | TAG_TYPE_BINARY) //Index bits attribute.

// TABLE 8
#define TAG_TYPE_WORD (0x3000)
#define TAG_MATCH_MODE (0x1 | TAG_TYPE_WORD) //Match mode attribute.
#define TAG_TAG (0x801 | TAG_TYPE_WORD) //TAG entry.
#define TAG_INDEX_TAG (0x802 | TAG_TYPE_WORD) //Index TAG attribute for an index entry.
#define TAG_INDEX_KEY (0x803 | TAG_TYPE_WORD) //Index key attribute for an index entry.