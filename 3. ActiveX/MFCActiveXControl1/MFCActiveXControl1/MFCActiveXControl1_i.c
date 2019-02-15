

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for MFCActiveXControl1.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_MFCActiveXControl1Lib,0x0804CFE8,0xDB55,0x42FC,0x88,0x82,0x16,0x98,0x86,0xF4,0x46,0x8A);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveXControl1,0x6046BDAF,0x7F4E,0x44FF,0x95,0xCB,0x0A,0xB3,0x32,0xFB,0xD2,0x06);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveXControl1Events,0x9EDEA2EE,0xC23E,0x4BB4,0x9C,0xDA,0x59,0x04,0x3C,0x09,0xC9,0x45);


MIDL_DEFINE_GUID(CLSID, CLSID_MFCActiveXControl1,0xD41DA606,0x3F8D,0x4D4A,0x85,0xD5,0xC7,0x0F,0xD5,0xDE,0xC0,0xFF);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



