//
// Decorators.h
// VGD Engine
//
// Created by Benjamin Arnold on 29 Aug 2015
//

/*! \file Decorators.h
* @brief Function decorators for clarity.
*/

#pragma once

#define OUT /*!< This pointer/reference will be modified as an extra return value */
#define OPT /*!< This pointer is optional (may be null) */

#define CALLEE_DELETE /*!< Function called will delete this resource */
#define CALLER_DELETE /*!< Function caller must manage this resource */

#define OPENVOX_INTERNAL /*!< Internal function not meant for an end-user */

#define UNIT_SPACE(SPACE_TYPE) /*!< The decorated value is found in <SPACE_TYPE> space */

/*! @brief Encloses M in an unnamed struct so it can be used inside a union.
*/
#define UNIONIZE(M) struct { M; }

/*! @brief This class may not be copied, so all copy and assignment constructors are hidden.
 */
#define VGD_NON_COPYABLE(CLASS) \
    CLASS(const CLASS& o) = delete; \
    CLASS& operator=(const CLASS& o) = delete

/*! @brief Declaration for a copy constructor and operator overload. It may be used as an inline definition too.
 */
#define VGD_COPYABLE_DECL(CLASS) \
    CLASS(const CLASS& o) { *this = o; } \
    CLASS& operator=(const CLASS& o)

/*! @brief Definition for the copy operator overload, which is used in the copy constructor as well.
 */
#define VGD_COPYABLE_DEF(CLASS, VAR_NAME) \
    CLASS& CLASS::operator=(const CLASS& VAR_NAME)

/*! @brief This class may not be moved, so all move constructors and operators are hidden.
 */
#define VGD_NON_MOVABLE(CLASS) \
    CLASS(CLASS&& o) = delete; \
    CLASS& operator=(CLASS&& o) = delete

/*! @brief Declaration for a move constructor and operator overload. It may be used as an inline definition too.
 */
#define VGD_MOVABLE_DECL(CLASS) \
    CLASS(CLASS&& o) { *this = std::move(o); } \
    CLASS& operator=(CLASS&& o)

/*! @brief Definition for the move operator overload, which is used in the move constructor as well.
 */
#define VGD_MOVABLE_DEF(CLASS, VAR_NAME) \
    CLASS& CLASS::operator=(CLASS&& VAR_NAME)