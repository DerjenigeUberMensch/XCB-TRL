#ifndef __XCB__PRIVATE__UTILS__H__
#define __XCB__PRIVATE__UTILS__H__

#include <xcb/xcb.h>

/*
 * void * returned is status or likely return.
 * ie if void * is non null the reply is safe to use.
 * else err was generated.
 */
void *
__xcb__private__handle__err(
        xcb_connection_t *display, 
        xcb_generic_error_t *err,
        void *reply
        );


/* gcc */
#if defined(__GNUC__) || defined(__clang__)

#ifndef __RETURN__NEVER__NULL__
#define __RETURN__NEVER__NULL__ __attribute__((returns_nonnull))
#endif

#ifndef __DEPRECATED__
#define __DEPRECATED__ __attribute__((deprecated))
#endif

/* Indicates that a function never returns (includes void).
 * What does this mean?;
 * A.) This function always results in a infinite loop;
 * b.) This function calls a variation of exit();
 */
#ifndef __FUNC__EXIT__POINT__
#define __FUNC__EXIT__POINT__ __attribute__((noreturn))
#endif

#ifndef __cplusplus
#define fallthrough __attribute__((fallthrough))
#endif

#ifndef UNREACHABLE
#define UNREACHABLE __builtin_unreachable();
#endif

#ifndef expect
#define expect(VARIABLE, EXPECTED_VALUE)    __builtin_expect(VARIABLE, EXPECTED_VALUE)
#endif

#ifndef likely
#define likely(X)    __builtin_expect(!!(X), 1)
#endif

#ifndef unlikely
#define unlikely(X) __builtin_expect(!!(X), 0)
#endif
#else

#ifndef __RETURN__NEVER__NULL__
#define __RETURN__NEVER__NULL__ 
#endif

#ifndef __DEPRECATED__
#define __DEPRECATED__ 
#endif

#ifndef __FUNC__EXIT__POINT__
#define __FUNC__EXIT__POINT__ 
#endif

#ifndef __cplusplus
#define fallthrough 
#endif

#ifndef UNREACHABLE
#define UNREACHABLE
#endif

#ifndef expect
#define expect(VARIABLE, EXPECTED_VALUE)    (VARIABLE == EXPECTED_VALUE)
#endif


#ifndef likely
#define likely(X)    X
#endif

#ifndef unlikely
#define unlikely(X) X
#endif
#endif

#endif

