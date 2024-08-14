/*
*   Sonic Adventure Mod Tools (SA2B) - '/util/cpp_old.h'
*
*   Description:
*       Defines old C++ standard elements.
*
*   Contributors:
*     - kellnc
*     - MainMemory
*     - Shaddatic
*
*   Only for use with Sonic Adventure 2 for PC
*/
#ifndef _UTIL_CPP_UTF8_H_
#define _UTIL_CPP_UTF8_H_

#ifdef  __cplusplus

/************************/
/*  Includes            */
/************************/
#include <xstring>
#include <xmemory>

/************************/
/*  cppold              */
/************************/
namespace cppold::std
{
    struct _Container_base0 {};

    template <class _Elem, class _Alloc = ::std::allocator<_Elem>>
    struct _String_val : _Container_base0
    {
        union _Bxty
        {
            _Elem _Buf[16];
            _Elem* _Ptr;
            _Elem _Alias[16];
        } _Bx;
        unsigned int _Mysize;
        unsigned int _Myres;
        _Alloc _Alval;
    };

    template <class _Elem, class _Traits = ::std::char_traits<_Elem>, class _Alloc = ::std::allocator<_Elem>>
    struct basic_string : _String_val<_Elem, _Alloc>
    {
    };

    typedef basic_string<char> string;
    typedef basic_string<wchar_t> wstring;
}

#endif/*__cplusplus*/

#endif/*_UTIL_CPP_UTF8_H_*/
