//
// Types.h
// VGD Engine
//
// Created by Benjamin Arnold on 29 Aug 2015
//

/*! \file Types.h
* @brief Defines helpful types vor VGD engine.
*/

#pragma once

#include <cstdint>
#include "Vector.hpp"

/************************************************************************/
/* Integer values                                                       */
/************************************************************************/
typedef int8_t i8; ///< 8-bit signed integer
typedef int8_t sbyte; ///< 8-bit signed integer
typedef int16_t i16; ///< 16-bit signed integer
typedef int32_t i32; ///< 32-bit signed integer
typedef int64_t i64; ///< 64-bit signed integer
typedef uint8_t u8; ///< 8-bit unsigned integer
typedef uint8_t ubyte; ///< 8-bit unsigned integer
typedef uint16_t u16; ///< 16-bit unsigned integer
typedef uint32_t u32; ///< 32-bit unsigned integer
typedef uint64_t u64; ///< 64-bit unsigned integer
typedef unsigned int unt; ///< unsigned integer
typedef unsigned long ulong; ///< unsigned long
typedef unsigned long long ulong2; ///< unsigned long long

/************************************************************************/
/* Floating point values                                                */
/************************************************************************/
typedef float f32; ///< 32-bit floating point value (single)
typedef double f64; ///< 64-bit floating point value (double)

/************************************************************************/
/* VGD types                                                            */
/************************************************************************/
/*! @brief 8-bit signed integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<i8> i8v2;
/*! @brief 16-bit signed integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<i16> i16v2;
/*! @brief 32-bit signed integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<i32> i32v2;
/*! @brief 64-bit signed integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<i64> i64v2;
/*! @brief 8-bit unsigned integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<u8> u8v2;
/*! @brief 16-bit unsigned integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<u16> u16v2;
/*! @brief 32-bit unsigned integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<u32> u32v2;
/*! @brief 64-bit unsigned integer 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<u64> u64v2;
/*! @brief 32-bit floating point (single) 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<f32> f32v2;
/*! @brief 64-bit floating point (double) 2-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1]
*  x  ,  y
*  r  ,  g
*  s  ,  t
* </pre>
*/
typedef vorb::Vector2<f64> f64v2;
/*! @brief 8-bit signed integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<i8> i8v3;
/*! @brief 16-bit signed integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<i16> i16v3;
/*! @brief 32-bit signed integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<i32> i32v3;
/*! @brief 64-bit signed integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<i64> i64v3;
/*! @brief 8-bit unsigned integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<u8> u8v3;
/*! @brief 16-bit unsigned integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<u16> u16v3;
/*! @brief 32-bit unsigned integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<u32> u32v3;
/*! @brief 64-bit unsigned integer 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<u64> u64v3;
/*! @brief 32-bit floating point (single) 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<f32> f32v3;
/*! @brief 64-bit floating point (double) 3-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2]
*  x  ,  y  ,  z
*  r  ,  g  ,  b
*  s  ,  t  ,  p
* </pre>
*/
typedef vorb::Vector3<f64> f64v3;
/*! @brief 8-bit signed integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<i8> i8v4;
/*! @brief 16-bit signed integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<i16> i16v4;
/*! @brief 32-bit signed integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<i32> i32v4;
/*! @brief 64-bit signed integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<i64> i64v4;
/*! @brief 8-bit unsigned integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<u8> u8v4;
/*! @brief 16-bit unsigned integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<u16> u16v4;
/*! @brief 32-bit unsigned integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<u32> u32v4;
/*! @brief 64-bit unsigned integer 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<u64> u64v4;
/*! @brief 32-bit floating point (single) 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<f32> f32v4;
/*! @brief 64-bit floating point (double) 4-value vector.
*
* Elements can be accessed via: @n
* <pre>
* [0] , [1] , [2] , [3]
*  x  ,  y  ,  z  ,  w
*  r  ,  g  ,  b  ,  a
*  s  ,  t  ,  p  ,  q
* </pre>
*/
typedef vorb::Vector4<f64> f64v4;