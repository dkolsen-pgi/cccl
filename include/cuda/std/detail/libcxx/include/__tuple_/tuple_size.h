//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2022 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCUDACXX___TUPLE_TUPLE_SIZE_H
#define _LIBCUDACXX___TUPLE_TUPLE_SIZE_H

#ifndef __cuda_std__
#include <__config>
#include <cstddef>
#endif // __cuda_std__

#include "../__fwd/tuple.h"
#include "../__tuple_/tuple_types.h"
#include "../__type_traits/enable_if.h"
#include "../__type_traits/integral_constant.h"
#include "../__type_traits/is_const.h"
#include "../__type_traits/is_volatile.h"

#if defined(_LIBCUDACXX_USE_PRAGMA_GCC_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCUDACXX_BEGIN_NAMESPACE_STD

template <class _Tp> struct _LIBCUDACXX_TEMPLATE_VIS tuple_size;

#if !defined(_LIBCUDACXX_CXX03_LANG)
template <class _Tp, class...>
using __enable_if_tuple_size_imp = _Tp;

template <class _Tp>
struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<__enable_if_tuple_size_imp<
    const _Tp,
    __enable_if_t<!is_volatile<_Tp>::value>,
    integral_constant<size_t, sizeof(tuple_size<_Tp>)>>>
    : public integral_constant<size_t, tuple_size<_Tp>::value> {};

template <class _Tp>
struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<__enable_if_tuple_size_imp<
    volatile _Tp,
    __enable_if_t<!is_const<_Tp>::value>,
    integral_constant<size_t, sizeof(tuple_size<_Tp>)>>>
    : public integral_constant<size_t, tuple_size<_Tp>::value> {};

template <class _Tp>
struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<__enable_if_tuple_size_imp<
    const volatile _Tp,
    integral_constant<size_t, sizeof(tuple_size<_Tp>)>>>
    : public integral_constant<size_t, tuple_size<_Tp>::value> {};

#else
template <class _Tp> struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<const _Tp> : public tuple_size<_Tp> {};
template <class _Tp> struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<volatile _Tp> : public tuple_size<_Tp> {};
template <class _Tp> struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<const volatile _Tp> : public tuple_size<_Tp> {};
#endif

#ifndef _LIBCUDACXX_CXX03_LANG

template <class ..._Tp>
struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<tuple<_Tp...> >
    : public integral_constant<size_t, sizeof...(_Tp)>
{
};

template <class ..._Tp>
struct _LIBCUDACXX_TEMPLATE_VIS tuple_size<__tuple_types<_Tp...> >
    : public integral_constant<size_t, sizeof...(_Tp)>
{
};

#endif // _LIBCUDACXX_CXX03_LANG

_LIBCUDACXX_END_NAMESPACE_STD

#endif // _LIBCUDACXX___TUPLE_TUPLE_SIZE_H
