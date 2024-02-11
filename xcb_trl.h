#ifndef XCB_PTL_TYPEDEF_H_
#define XCB_PTL_TYPEDEF_H_

#include <xcb/xcb.h>
#include <xcb/xcb_aux.h>
#include <xcb/xcb_event.h>
#include <xcb/xcbext.h>
#include <xcb/xcb_ewmh.h>
#include <xcb/xcb_keysyms.h>
#include <xcb/xcb_cursor.h>

typedef xcb_connection_t XCBConnection;
typedef xcb_screen_t XCBScreen;
typedef xcb_window_t XCBWindow;
typedef xcb_void_cookie_t XCBCookie;
typedef xcb_gcontext_t XCBGC;
typedef xcb_drawable_t XCBDrawable;
typedef xcb_point_t XCBPoint;
typedef xcb_generic_event_t XCBGenericEvent;


/* 
 * Opens the display and returns a XCBConnection* on Success.
 *
 * RETURN: NULL on Failure.
 * To check error use XCBGetErrorText() or see XCBCheckDisplayError() to get error number.
 */
extern XCBConnection *XCBOpenDisplay(const char *displayName, int *screenNumber);
/* 
 * Closes the connection Specified and Frees the data associated with connection.
 * No side effects if display is NULL.
 */
extern void XCBCloseDisplay(XCBConnection *display);
/* 
 * Flushes buffered output to XServer.
 * Blocks Until buffer is fully flushed.
 *
 * RETURN: 0 on Success.
 * RETURN: 1 on Failure.
 */ 
extern int XCBFlush(XCBConnection *display);

/*
 * Gets the maximum data that a XCBConnection* can hold in bytes / 4.
 * Ex: 4 bytes size would return 1
 * 
 * RANGE:
 *                    (256kiB)
 * NO_EXTENSION -> (0, 65535)
 * 
 * //COMMENT, Im not sure on this one docu is vague 
 *                    (16GB)
 * BIG_REQUESTS -> (0, 2097152)
 * 
 * RETURN: Max Request length in (bytes / 4)
 */
extern unsigned long XCBGetMaximumRequestLength(XCBConnection *display);







/* 
 * RETURN: XCB_CONN_ERROR, because of socket errors, pipe errors or other stream errors.
 * RETURN: XCB_CONN_CLOSED_EXT_NOTSUPPORTED, when extension not supported.
 * RETURN: XCB_CONN_CLOSED_MEM_INSUFFICIENT, when memory not available.
 * RETURN: XCB_CONN_CLOSED_REQ_LEN_EXCEED, exceeding request length that server accepts.
 * RETURN: XCB_CONN_CLOSED_PARSE_ERR, error during parsing display string.
 * RETURN: XCB_CONN_CLOSED_INVALID_SCREEN, because the server does not have a screen matching the display.
 */
extern int XCBCheckDisplayError(XCBConnection *display);


/* TODO */
extern char *XCBGetErrorText(XCBConnection *display);



/* events */


/* 
 * Gets and returns the next Event from the XServer
 * This Function Blocks until a request is received
 *
 * RETURN: XCBGenericEvent * on Success
 * RETURN: XCBGenericError * on Error
 * RETURN: NULL on I/O Error
 */
XCBGenericEvent *XCBNextEvent(XCBConnection *display);
/* 
 * Gets and returns the next Event from the XServer
 * This Function Blocks until a request is received
 *
 * RETURN: XCBGenericEvent * on Success
 * RETURN: XCBGenericError * on Error
 * RETURN: NULL on I/O Error
 */
XCBGenericEvent *XCBWaitForEvent(XCBConnection *display);

/**
 * @brief Returns the next event or error from the server.
 * @param c The connection to the X server.
 * @return The next event from the server.
 *
 * Returns the next event or error from the server, if one is
 * available, or returns @c NULL otherwise. If no event is available, that
 * might be because an I/O error like connection close occurred while
 * attempting to read the next event, in which case the connection is
 * shut down when this function returns.
 */
XCBGenericEvent *XCBPollForEvent(xcb_connection_t *c);
/** <Straight from the documentation.>
 * @brief Returns the next event without reading from the connection.
 * @param c The connection to the X server.
 * @return The next already queued event from the server.
 *
 * This is a version of xcb_poll_for_event that only examines the
 * event queue for new events. The function doesn't try to read new
 * events from the connection if no queued events are found.
 *
 * This function is useful for callers that know in advance that all
 * interesting events have already been read from the connection. For
 * example, callers might use xcb_wait_for_reply and be interested
 * only of events that preceded a specific reply.
 */
XCBGenericEvent *XCBPollForQueuedEvent(xcb_connection_t *c);






/* mapping */
extern XCBCookie XCBMapWindow(XCBConnection *display, XCBWindow window);

/* windows*/
extern XCBWindow XCBCreateWindow(XCBConnection *display);

/* GC */
extern XCBGC XCBCreateGC();
/* Valuemasks
XCB_GC_FUNCTION
XCB_GC_PLANE_MASK
XCB_GC_FOREGROUND
XCB_GC_BACKGROUND
XCB_GC_LINE_WIDTH
XCB_GC_LINE_STYLE
XCB_GC_CAP_STYLE
XCB_GC_JOIN_STYLE
XCB_GC_FILL_STYLE
XCB_GC_FILL_RULE
XCB_GC_TILE
XCB_GC_STIPPLE
XCB_GC_TILE_STIPPLE_ORIGIN_X
XCB_GC_TILE_STIPPLE_ORIGIN_Y
XCB_GC_FONT
XCB_GC_SUBWINDOW_MODE
XCB_GC_GRAPHICS_EXPOSURES
XCB_GC_CLIP_ORIGIN_X
XCB_GC_CLIP_ORIGIN_Y
XCB_GC_CLIP_MASK
XCB_GC_DASH_OFFSET
XCB_GC_DASH_LIST
XCB_GC_ARC_MODE
*/
extern XCBCookie XCBChangeGC(XCBConnection *display, XCBGC gc, unsigned long valuemask, unsigned long valuelist);





/* dumb stuff */


/**
 * @brief Prefetch the maximum request length without blocking.
 * @param c The connection to the X server.
 *
 * Without blocking, does as much work as possible toward computing
 * the maximum request length accepted by the X server.
 *
 * Invoking this function may cause a call to xcb_big_requests_enable,
 * but will not block waiting for the reply.
 * xcb_get_maximum_request_length will return the prefetched data
 * after possibly blocking while the reply is retrieved.
 *
 * Note that in order for this function to be fully non-blocking, the
 * application must previously have called
 * xcb_prefetch_extension_data(c, &xcb_big_requests_id) and the reply
 * must have already arrived.
 */
extern void XCBPrefetchMaximumRequestLength(XCBConnection *display);

#endif
