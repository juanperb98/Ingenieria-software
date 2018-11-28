/* src/macros/compiler.hpp
 *
 * Licenced under GPLv3
 * Authors:
 *	Diego Rodriguez Riera
 *
 * This file contains hints for the compiler.
 */


#ifndef __COMPILERHINTS__
#define __COMPILERHINTS__

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

#endif
