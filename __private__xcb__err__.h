#ifndef __XCB__PRIVATE__ERROR__H__
#define __XCB__PRIVATE__ERROR__H__


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "xcb_trl_types.h"
#include "safebool.h"

#ifdef XCB_TRL_ENABLE_DEBUG
    #define _xcb_push_func(XCB_PUSH_COOKIE) XCBDebugPushID(__func__, XCB_PUSH_COOKIE.sequence)
    #define _xcb_convert_id(XCB_COOKIE) XCBCookie ret = { .sequence = XCB_COOKIE.sequence }
#else
    #define _xcb_push_func(XCB_PUSH_COOKIE) ((void)XCB_PUSH_COOKIE)
#endif

#define _xcb_convert_id(XCB_COOKIE) XCBCookie ret = { .sequence = XCB_COOKIE.sequence }
#define _xcb_standardize(XCB_COOKIE) \
    _xcb_convert_id(XCB_COOKIE); \
    _xcb_push_func(ret); \
    return ret
#define _xcb_standardize_validate(COOKIE_CAST, RET_CAST, FUNC, DISPLAY, COOKIE) \
    XCBGenericError *err = NULL; \
    void *reply; \
    reply = FUNC(DISPLAY, (COOKIE_CAST) { .sequence = COOKIE.sequence }, &err); \
    __XValidateReply(display, NULL, err); \
    return (RET_CAST) reply


/*
 * RETURN: true on valid format.
 * RETURN: false on invalid format.
 */
bool 
__XValidFormat(
        uint8_t x
        );
/* X11, GetProp.c
 * Protect against both integer overflow and just plain oversized
 * memory allocation - no server should ever return this many props.
 *
 * RETURN: true on valid size.
 * RETURN: false on invalid size.
 */
bool 
__XValidSize(
        uint32_t value_len
        );

/*
 * RETURN: true if reply is valid.
 * RETURN: false if reply is not valid.
 */
bool
__XValidReply(
        xcb_get_property_reply_t  *reply
        );
bool
__XIsEmptyReply(
        xcb_get_property_reply_t  *reply
	);

void *
__XValidateReply(
        xcb_connection_t *display,
        xcb_get_property_reply_t *reply,
        xcb_generic_error_t *error
        );

void *
__XCheckReply(
        xcb_connection_t *display,
        xcb_get_property_reply_t *reply,
        xcb_generic_error_t *error
        );

/*
 * Manually throw a XCBError not recommended to use, even for implementors.
 */
void
__XCBThrowError(
        xcb_connection_t *display,
        xcb_void_cookie_t cookie, 
        uint8_t error, 
        uint8_t major_code, 
        uint16_t minor_code
        );

void
__XCBSetErrorHandler(
        void (*error_handler)(
            XCBDisplay *, 
            XCBGenericError *
            )
        );

void 
XCBBreakPoint(
        void
        );

void 
XCBDebugPushID(
    const char *const function_name, 
    uint32_t sequence
    );





#ifdef __cplusplus
}
#endif




#endif
