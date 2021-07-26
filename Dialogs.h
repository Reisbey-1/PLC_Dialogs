

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Dialogs_h__
#define __Dialogs_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIO28_FWD_DEFINED__
#define __IIO28_FWD_DEFINED__
typedef interface IIO28 IIO28;

#endif 	/* __IIO28_FWD_DEFINED__ */


#ifndef __IMd500_FWD_DEFINED__
#define __IMd500_FWD_DEFINED__
typedef interface IMd500 IMd500;

#endif 	/* __IMd500_FWD_DEFINED__ */


#ifndef __IMd100_FWD_DEFINED__
#define __IMd100_FWD_DEFINED__
typedef interface IMd100 IMd100;

#endif 	/* __IMd100_FWD_DEFINED__ */


#ifndef __IEmbeddedConfigurator_FWD_DEFINED__
#define __IEmbeddedConfigurator_FWD_DEFINED__
typedef interface IEmbeddedConfigurator IEmbeddedConfigurator;

#endif 	/* __IEmbeddedConfigurator_FWD_DEFINED__ */


#ifndef __IMdxxMonitor_FWD_DEFINED__
#define __IMdxxMonitor_FWD_DEFINED__
typedef interface IMdxxMonitor IMdxxMonitor;

#endif 	/* __IMdxxMonitor_FWD_DEFINED__ */


#ifndef __IO28_FWD_DEFINED__
#define __IO28_FWD_DEFINED__

#ifdef __cplusplus
typedef class IO28 IO28;
#else
typedef struct IO28 IO28;
#endif /* __cplusplus */

#endif 	/* __IO28_FWD_DEFINED__ */


#ifndef __Md500_FWD_DEFINED__
#define __Md500_FWD_DEFINED__

#ifdef __cplusplus
typedef class Md500 Md500;
#else
typedef struct Md500 Md500;
#endif /* __cplusplus */

#endif 	/* __Md500_FWD_DEFINED__ */


#ifndef __Md100_FWD_DEFINED__
#define __Md100_FWD_DEFINED__

#ifdef __cplusplus
typedef class Md100 Md100;
#else
typedef struct Md100 Md100;
#endif /* __cplusplus */

#endif 	/* __Md100_FWD_DEFINED__ */


#ifndef __EmbeddedConfigurator_FWD_DEFINED__
#define __EmbeddedConfigurator_FWD_DEFINED__

#ifdef __cplusplus
typedef class EmbeddedConfigurator EmbeddedConfigurator;
#else
typedef struct EmbeddedConfigurator EmbeddedConfigurator;
#endif /* __cplusplus */

#endif 	/* __EmbeddedConfigurator_FWD_DEFINED__ */


#ifndef __MdxxMonitor_FWD_DEFINED__
#define __MdxxMonitor_FWD_DEFINED__

#ifdef __cplusplus
typedef class MdxxMonitor MdxxMonitor;
#else
typedef struct MdxxMonitor MdxxMonitor;
#endif /* __cplusplus */

#endif 	/* __MdxxMonitor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIO28_INTERFACE_DEFINED__
#define __IIO28_INTERFACE_DEFINED__

/* interface IIO28 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIO28;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28FB79DE-362E-49EE-AB20-64772D9500FC")
    IIO28 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIO28Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIO28 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIO28 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIO28 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIO28 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIO28 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIO28 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIO28 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IIO28 * This);
        
        END_INTERFACE
    } IIO28Vtbl;

    interface IIO28
    {
        CONST_VTBL struct IIO28Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIO28_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIO28_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIO28_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIO28_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIO28_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIO28_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIO28_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIO28_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIO28_INTERFACE_DEFINED__ */


#ifndef __IMd500_INTERFACE_DEFINED__
#define __IMd500_INTERFACE_DEFINED__

/* interface IMd500 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMd500;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AEC973F0-7978-4660-832D-73B9969D14F9")
    IMd500 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ int hParent,
            /* [in] */ int nProcessor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SerPort( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SerPort( 
            /* [in] */ IDispatch **newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sink( 
            /* [in] */ IUnknown **newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SinkBuffer( 
            /* [in] */ BYTE **newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMd500Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMd500 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMd500 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMd500 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMd500 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMd500 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMd500 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMd500 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IMd500 * This,
            /* [in] */ int hParent,
            /* [in] */ int nProcessor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SerPort )( 
            IMd500 * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SerPort )( 
            IMd500 * This,
            /* [in] */ IDispatch **newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sink )( 
            IMd500 * This,
            /* [in] */ IUnknown **newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SinkBuffer )( 
            IMd500 * This,
            /* [in] */ BYTE **newVal);
        
        END_INTERFACE
    } IMd500Vtbl;

    interface IMd500
    {
        CONST_VTBL struct IMd500Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMd500_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMd500_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMd500_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMd500_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMd500_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMd500_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMd500_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMd500_Execute(This,hParent,nProcessor)	\
    ( (This)->lpVtbl -> Execute(This,hParent,nProcessor) ) 

#define IMd500_get_SerPort(This,pVal)	\
    ( (This)->lpVtbl -> get_SerPort(This,pVal) ) 

#define IMd500_put_SerPort(This,newVal)	\
    ( (This)->lpVtbl -> put_SerPort(This,newVal) ) 

#define IMd500_put_Sink(This,newVal)	\
    ( (This)->lpVtbl -> put_Sink(This,newVal) ) 

#define IMd500_put_SinkBuffer(This,newVal)	\
    ( (This)->lpVtbl -> put_SinkBuffer(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMd500_INTERFACE_DEFINED__ */


#ifndef __IMd100_INTERFACE_DEFINED__
#define __IMd100_INTERFACE_DEFINED__

/* interface IMd100 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMd100;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F772002B-4A70-41DF-9EC5-183DB8F491E8")
    IMd100 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ int hParent,
            /* [in] */ int nProcessor) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SerPort( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SerPort( 
            /* [in] */ IDispatch **newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sink( 
            /* [in] */ IDispatch **newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SinkBuffer( 
            /* [in] */ BYTE **newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMd100Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMd100 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMd100 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMd100 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMd100 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMd100 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMd100 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMd100 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IMd100 * This,
            /* [in] */ int hParent,
            /* [in] */ int nProcessor);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SerPort )( 
            IMd100 * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SerPort )( 
            IMd100 * This,
            /* [in] */ IDispatch **newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sink )( 
            IMd100 * This,
            /* [in] */ IDispatch **newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SinkBuffer )( 
            IMd100 * This,
            /* [in] */ BYTE **newVal);
        
        END_INTERFACE
    } IMd100Vtbl;

    interface IMd100
    {
        CONST_VTBL struct IMd100Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMd100_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMd100_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMd100_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMd100_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMd100_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMd100_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMd100_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMd100_Execute(This,hParent,nProcessor)	\
    ( (This)->lpVtbl -> Execute(This,hParent,nProcessor) ) 

#define IMd100_get_SerPort(This,pVal)	\
    ( (This)->lpVtbl -> get_SerPort(This,pVal) ) 

#define IMd100_put_SerPort(This,newVal)	\
    ( (This)->lpVtbl -> put_SerPort(This,newVal) ) 

#define IMd100_put_Sink(This,newVal)	\
    ( (This)->lpVtbl -> put_Sink(This,newVal) ) 

#define IMd100_put_SinkBuffer(This,newVal)	\
    ( (This)->lpVtbl -> put_SinkBuffer(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMd100_INTERFACE_DEFINED__ */


#ifndef __IEmbeddedConfigurator_INTERFACE_DEFINED__
#define __IEmbeddedConfigurator_INTERFACE_DEFINED__

/* interface IEmbeddedConfigurator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IEmbeddedConfigurator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EDDF6935-E425-48BE-9457-9B587A46AAFC")
    IEmbeddedConfigurator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEmbeddedConfiguratorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEmbeddedConfigurator * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEmbeddedConfigurator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEmbeddedConfigurator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEmbeddedConfigurator * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEmbeddedConfigurator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEmbeddedConfigurator * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEmbeddedConfigurator * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IEmbeddedConfigurator * This);
        
        END_INTERFACE
    } IEmbeddedConfiguratorVtbl;

    interface IEmbeddedConfigurator
    {
        CONST_VTBL struct IEmbeddedConfiguratorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEmbeddedConfigurator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEmbeddedConfigurator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEmbeddedConfigurator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEmbeddedConfigurator_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEmbeddedConfigurator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEmbeddedConfigurator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEmbeddedConfigurator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEmbeddedConfigurator_Execute(This)	\
    ( (This)->lpVtbl -> Execute(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEmbeddedConfigurator_INTERFACE_DEFINED__ */


#ifndef __IMdxxMonitor_INTERFACE_DEFINED__
#define __IMdxxMonitor_INTERFACE_DEFINED__

/* interface IMdxxMonitor */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMdxxMonitor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E89509E-1F6C-4B00-8BD5-94E685F9E3C4")
    IMdxxMonitor : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Execute( 
            /* [in] */ int hParent,
            /* [in] */ int nVm) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SerPort( 
            /* [in] */ IDispatch **newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sink( 
            /* [in] */ IDispatch **newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Fabric( 
            /* [in] */ IDispatch **newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMdxxMonitorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMdxxMonitor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMdxxMonitor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMdxxMonitor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMdxxMonitor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMdxxMonitor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMdxxMonitor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMdxxMonitor * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Execute )( 
            IMdxxMonitor * This,
            /* [in] */ int hParent,
            /* [in] */ int nVm);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SerPort )( 
            IMdxxMonitor * This,
            /* [in] */ IDispatch **newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sink )( 
            IMdxxMonitor * This,
            /* [in] */ IDispatch **newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fabric )( 
            IMdxxMonitor * This,
            /* [in] */ IDispatch **newVal);
        
        END_INTERFACE
    } IMdxxMonitorVtbl;

    interface IMdxxMonitor
    {
        CONST_VTBL struct IMdxxMonitorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMdxxMonitor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMdxxMonitor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMdxxMonitor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMdxxMonitor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMdxxMonitor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMdxxMonitor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMdxxMonitor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMdxxMonitor_Execute(This,hParent,nVm)	\
    ( (This)->lpVtbl -> Execute(This,hParent,nVm) ) 

#define IMdxxMonitor_put_SerPort(This,newVal)	\
    ( (This)->lpVtbl -> put_SerPort(This,newVal) ) 

#define IMdxxMonitor_put_Sink(This,newVal)	\
    ( (This)->lpVtbl -> put_Sink(This,newVal) ) 

#define IMdxxMonitor_put_Fabric(This,newVal)	\
    ( (This)->lpVtbl -> put_Fabric(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMdxxMonitor_INTERFACE_DEFINED__ */



#ifndef __DIALOGSLib_LIBRARY_DEFINED__
#define __DIALOGSLib_LIBRARY_DEFINED__

/* library DIALOGSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DIALOGSLib;

EXTERN_C const CLSID CLSID_IO28;

#ifdef __cplusplus

class DECLSPEC_UUID("7CBD01EC-E25C-4232-B69D-3BD9A7EFE869")
IO28;
#endif

EXTERN_C const CLSID CLSID_Md500;

#ifdef __cplusplus

class DECLSPEC_UUID("725B09D1-CF94-477F-9240-196D8E705042")
Md500;
#endif

EXTERN_C const CLSID CLSID_Md100;

#ifdef __cplusplus

class DECLSPEC_UUID("52285FE7-29C1-4B71-93A8-34A91FC655AC")
Md100;
#endif

EXTERN_C const CLSID CLSID_EmbeddedConfigurator;

#ifdef __cplusplus

class DECLSPEC_UUID("83D8A77D-979E-4CAA-A279-51BD81299E8C")
EmbeddedConfigurator;
#endif

EXTERN_C const CLSID CLSID_MdxxMonitor;

#ifdef __cplusplus

class DECLSPEC_UUID("F2785D32-70A5-450C-8D05-59712646C7D4")
MdxxMonitor;
#endif
#endif /* __DIALOGSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


