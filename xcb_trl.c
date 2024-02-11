

#include "xcb_trl.h"
#include <xcb/xcb.h>


inline XCBConnection *
XCBOpenDisplay(const char *displayName, int *screenNumber)
{
    XCBConnection *display = xcb_connect(displayName, screenNumber);
    /* We need to check return type cause xcb_connect never returns NULL (for some reason).
     * So we just check error, which requires display.
     */
    if(xcb_connection_has_error(display))
    {   
        /* This frees the connection data that was allocated. */
        xcb_disconnect(display);
        return NULL;
    }
    return display;
}

inline void 
XCBCloseDisplay(XCBConnection *display)
{
    /* Closes connection and frees resulting data. */
    xcb_disconnect(display);
}

inline int 
XCBFlush(XCBConnection *display)
{
    /* This locks the XServer thread (pthread mutix lock).
     * and writes the buffer to the server.
     * RETURN 0 on Success.
     * RETURN 1 on Failure.
     */
    return xcb_flush(display);
}

inline unsigned long
XCBGetMaximumRequestLength(XCBConnection *display)
{
    /* <Straight from the documentation.>
     *
     * In the absence of the BIG-REQUESTS extension, returns the
     * maximum request length field from the connection setup data, which
     * may be as much as 65535. If the server supports BIG-REQUESTS, then
     * the maximum request length field from the reply to the
     * BigRequestsEnable request will be returned instead.
     *
     * Note that this length is measured in four-byte units, making the
     * theoretical maximum lengths roughly 256kB without BIG-REQUESTS and
     * 16GB with.
     */
    return xcb_get_maximum_request_length(display);
}


inline XCBGenericEvent *
XCBPollForEvent(XCBConnection *display)
{
    /* TODO */
    /* If I/O error do something */
    xcb_poll_for_event(display);
}


inline XCBGenericEvent *
XCBPollForQueuedEvent(XCBConnection *display)
{
    return xcb_poll_for_queued_event(display);
}


inline int
XCBCheckDisplayError(XCBConnection *display)
{
    /* Error values:
     * XCB_CONN_ERROR, because of socket errors, pipe errors or other stream errors.
     * XCB_CONN_CLOSED_EXT_NOTSUPPORTED, when extension not supported.
     * XCB_CONN_CLOSED_MEM_INSUFFICIENT, when memory not available.
     * XCB_CONN_CLOSED_REQ_LEN_EXCEED, exceeding request length that server accepts.
     * XCB_CONN_CLOSED_PARSE_ERR, error during parsing display string.
     * XCB_CONN_CLOSED_INVALID_SCREEN, because the server does not have a screen matching the display.
     */
    return xcb_connection_has_error(display);
}

inline char *
XCBGetErrorText(XCBConnection *display)
{
    /* TODO */
    return "";
}






/* events */





XCBGenericEvent *
XCBNextEvent(XCBConnection *display)
{
    /* waits till next event happens before returning */
    return xcb_wait_for_event(display);
}

XCBGenericEvent *
XCBWaitForEvent(XCBConnection *display)
{
    /* waits till next event happens before returning */
    return xcb_wait_for_event(display);
}











inline XCBCookie 
XCBMapWindow(XCBConnection display, XCBWindow window)
{
    return xcb_map_window(display, window)
}

inline XCBWindow 
XCBCreateWindow(XCBConnection *display, XCBWindow parent, 
int x, int y, unsigned int width, unsigned int height, int border_width, 
int depth, unsigned int class, unsigned long valuemask)
{
    const XCBWindow id = xcb_generate_id(display);
    const void *used = NULL;
    xcb_create_window(display, depth, id, parent, x, y, width, height, border_width, 
    class, visual, valuemask, used)
    return 
}

inline XCBGC 
XCBCreateGC(XCBConnection *display, XCBDrawable drawable, 
unsigned long valuemask, unsigned long *valuelist)
{
    const XCBGC id = xcb_generate_id(display);
    xcb_create_gc(display, id, drawable, valuemask, valuelist);
    return id;
}

inline XCBCookie 
XCBChangeGC(XCBConnection *display, XCBGC gc, unsigned long valuemask, unsigned long *valuelist))
{
    return xcb_change_gc(display, gc, valuemask, valuelist);
}

inline XCBCookie 
XCBDrawPoint(XCBConnection *display, int coordinatemode, XCBDrawable drawable, XCBGC gc, unsigned long points_len, XCBPoint *points)
{
    return xcb_poly_point(display, coordinatemode, drawable, gc, points_len, points);
}






/* dumb stuff */

void 
XCBPrefetchMaximumRequestLength(XCBConnection *display)
{
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
    xcb_prefetch_maximum_request_length(display);
}

xcb_generic_event_t *xcb_poll_for_queued_event(xcb_connection_t *c);

