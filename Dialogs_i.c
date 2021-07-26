

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for Dialogs.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



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

MIDL_DEFINE_GUID(IID, IID_IIO28,0x28FB79DE,0x362E,0x49EE,0xAB,0x20,0x64,0x77,0x2D,0x95,0x00,0xFC);


MIDL_DEFINE_GUID(IID, IID_IMd500,0xAEC973F0,0x7978,0x4660,0x83,0x2D,0x73,0xB9,0x96,0x9D,0x14,0xF9);


MIDL_DEFINE_GUID(IID, IID_IMd100,0xF772002B,0x4A70,0x41DF,0x9E,0xC5,0x18,0x3D,0xB8,0xF4,0x91,0xE8);


MIDL_DEFINE_GUID(IID, IID_IEmbeddedConfigurator,0xEDDF6935,0xE425,0x48BE,0x94,0x57,0x9B,0x58,0x7A,0x46,0xAA,0xFC);


MIDL_DEFINE_GUID(IID, IID_IMdxxMonitor,0x5E89509E,0x1F6C,0x4B00,0x8B,0xD5,0x94,0xE6,0x85,0xF9,0xE3,0xC4);


MIDL_DEFINE_GUID(IID, LIBID_DIALOGSLib,0xCDB1AD1C,0x48B1,0x487D,0xAA,0xD4,0xCA,0x7E,0x88,0x6D,0x2B,0xF2);


MIDL_DEFINE_GUID(CLSID, CLSID_IO28,0x7CBD01EC,0xE25C,0x4232,0xB6,0x9D,0x3B,0xD9,0xA7,0xEF,0xE8,0x69);


MIDL_DEFINE_GUID(CLSID, CLSID_Md500,0x725B09D1,0xCF94,0x477F,0x92,0x40,0x19,0x6D,0x8E,0x70,0x50,0x42);


MIDL_DEFINE_GUID(CLSID, CLSID_Md100,0x52285FE7,0x29C1,0x4B71,0x93,0xA8,0x34,0xA9,0x1F,0xC6,0x55,0xAC);


MIDL_DEFINE_GUID(CLSID, CLSID_EmbeddedConfigurator,0x83D8A77D,0x979E,0x4CAA,0xA2,0x79,0x51,0xBD,0x81,0x29,0x9E,0x8C);


MIDL_DEFINE_GUID(CLSID, CLSID_MdxxMonitor,0xF2785D32,0x70A5,0x450C,0x8D,0x05,0x59,0x71,0x26,0x46,0xC7,0xD4);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



