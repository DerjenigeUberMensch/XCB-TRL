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
typedef xcb_connection_t XCBDisplay;
typedef xcb_setup_t XCBSetup;
typedef xcb_screen_iterator_t XCBScreenIterator;
typedef xcb_screen_t XCBScreen;
typedef xcb_window_t XCBWindow;
typedef xcb_cursor_t XCBCursor;
typedef xcb_void_cookie_t XCBCookie;
typedef xcb_intern_atom_cookie_t XCBAtomCookie;
typedef xcb_atom_t XCBAtom;

typedef xcb_visualid_t XCBVisualId;

typedef xcb_get_window_attributes_cookie_t XCBWindowAttributesCookie;
typedef xcb_get_window_attributes_cookie_t XCBAttributesCookie;
typedef xcb_get_window_attributes_cookie_t XCBGetAttributesCookie;
typedef xcb_get_geometry_cookie_t XCBGetGeometryCookie;
typedef xcb_get_geometry_cookie_t XCBGeometryCookie;
typedef xcb_get_geometry_cookie_t XCBWindowGeometryCookie;
typedef xcb_query_extension_cookie_t XCBExtensionCookie;
typedef xcb_query_extension_reply_t XCBExtensionReply;
typedef xcb_get_window_attributes_reply_t XCBWindowAttributes;
typedef xcb_get_window_attributes_reply_t XCBAttributes;
typedef xcb_get_geometry_reply_t XCBGeometry;
typedef xcb_get_geometry_reply_t XCBWindowGeometry;
typedef xcb_pixmap_t XCBPixmap;
typedef xcb_gcontext_t XCBGC;
typedef xcb_drawable_t XCBDrawable;
typedef xcb_point_t XCBPoint;
typedef xcb_font_t XCBFont;
typedef xcb_generic_event_t XCBGenericEvent;
typedef xcb_generic_error_t XCBGenericError;





/* 
 * Opens the display and returns a XCBDisplay* on Success.
 *
 * RETURN: NULL on Failure.
 * To check error use XCBGetErrorText() or see XCBCheckDisplayError() to get error number.
 */
extern XCBDisplay *XCBOpenDisplay(const char *displayName, int *screenNumber);
/* 
 * Closes the connection Specified and Frees the data associated with connection.
 * No side effects if display is NULL.
 */
extern void XCBCloseDisplay(XCBDisplay *display);
/* 
 * display: Specifies the connection to the X server.
 * return a connection number for the specified display. On a POSIX-conformant system, this is the file descriptor of the connection.
 */
extern int XCBDisplayNumber(XCBDisplay *display);
/* 
 * display: Specifies the connection to the X server.
 * return a connection number for the specified display. On a POSIX-conformant system, this is the file descriptor of the connection.
 */
extern int XCBDisplayNumber(XCBDisplay *display);
/*
 */
extern XCBScreen *XCBScreenOfDisplay(XCBDisplay *display, int scren);
/*
 */
extern XCBScreen *XCBDefaultScreenOfDisplay(XCBDisplay *display, int scren);
/*
 * display: Specifies the connection to the X server.
 * return the number of available screens.
 */
extern int XCBScreenCount(XCBDisplay *display);
/*
 * return a pointer to a string that provides some identification of the owner of the X server implementation. If the data returned by the server is in the Latin Portable Character Encoding, then the string is in the Host Portable Character Encoding. Otherwise, the contents of the string are implementation dependent.
 * MUST BE FREED BY CALLING free()
 */
extern char *XCBServerVendor(XCBDisplay *display);
/*  display Specifies the connection to the X server.
 *  return the major version number (11) of the X protocol associated with the connected display. 
 */
extern int XCBProtocolVersion(XCBDisplay *display);
/* display 	Specifies the connection to the X server.
 * return the minor protocol revision number of the X server.
 */
extern int XCBProtocolRevision(XCBDisplay *display);
/*
 * display 	Specifies the connection to the X server.
 * return a number related to a vendor's release of the X server.
 */
extern int XCBVendorRelease(XCBDisplay *display);
extern int XCBBitmapUnit(XCBDisplay *display);
extern int XCBBitmapBitOrder(XCBDisplay *display);
extern int XCBBitmapPad(XCBDisplay *display);
extern int XCBImageByteOrder(XCBDisplay *display);


extern int XCBRootOfScreen(XCBDisplay *display);
/* Gets the screen setup struct AKA screen stuff */
extern const XCBSetup *XCBGetSetup(XCBDisplay *display);

extern XCBScreen *XCBGetScreen(XCBDisplay *display);
/*
 * These are useful with functions that need a drawable of a particular screen and for creating top-level windows.
 * return the root window. 
 */
extern XCBWindow XCBRootWindow(XCBDisplay *display, int screen);
/*
 */
extern XCBWindow XCBDefaultRootWindow(XCBDisplay *display, int screen);
/*  return the width of the screen in pixels
 */
extern uint16_t XCBDisplayWidth(XCBDisplay *display, int screen);
/* return an integer that describes the height of the screen in pixels. 
 */
extern uint16_t XCBDisplayHeight(XCBDisplay *display, int screen);
extern uint8_t XCBDisplayDepth(XCBDisplay *display, int screen);
extern XCBCookie XCBSelectInput(XCBDisplay *display, XCBWindow window, uint32_t mask);
/*
 */
extern XCBCookie XCBChangeWindowAttributes(XCBDisplay *display, XCBWindow window, uint32_t mask, XCBWindowAttributes *window_attributes);
extern uint32_t XCBBlackPixel(XCBDisplay *display, int screen);
extern uint32_t XCBWhitePixel(XCBDisplay *display, int screen);
/* syncs the display */
extern void XCBSync(XCBDisplay *display);
extern XCBCookie XCBMoveWindow(XCBDisplay *display, XCBWindow window, int32_t x, int32_t y);
extern XCBCookie XCBMoveResizeWindow(XCBDisplay *display, XCBWindow window, int32_t x, int32_t y, uint32_t width, uint32_t height);
extern XCBCookie XCBRaiseWindow(XCBDisplay *display, XCBWindow window);
extern XCBCookie XCBLowerWindow(XCBDisplay *display, XCBWindow window);
extern XCBCookie XCBRaiseWindowIf(XCBDisplay *display, XCBWindow window);
extern XCBCookie XCBLowerWindowIf(XCBDisplay *display, XCBWindow window);
extern XCBCookie XCBSetWindowBorderWidth(XCBDisplay *display, XCBWindow window, uint32_t border_width);
extern XCBCookie XCBSetSibling(XCBDisplay *display, XCBWindow window, XCBWindow sibling);

extern XCBWindowAttributesCookie XGetWindowAttributesCookie(XCBDisplay *display, XCBWindow window);
extern XCBWindowAttributes *XCBGetWindowAttributesReply(XCBDisplay *display, XCBWindowAttributesCookie cookie);
extern XCBGeometryCookie XCBGetWindowGeometryCookie(XCBDisplay *display, XCBWindow window);
extern XCBGeometry *XCBGetWindowGeometryReply(XCBDisplay *display, XCBGeometryCookie cookie);
extern XCBPixmap XCBCreatePixmap(XCBDisplay *display, XCBWindow root, unsigned int width, unsigned int height, unsigned short depth);

extern XCBCursor XCBCreateFontCursor(XCBDisplay *display, int shape);
extern XCBCookie XCBFreeCursor(XCBDisplay *display, XCBCursor cursor);



/* fonts */
/**/
extern XCBCookie XCBOpenFont(XCBDisplay *display, XCBFont id, const char *name);




/* 
 * Flushes buffered output to XServer.
 * Blocks Until buffer is fully flushed.
 *
 * RETURN: 0 on Success.
 * RETURN: 1 on Failure.
 */ 
extern int XCBFlush(XCBDisplay *display);

/*
 * Gets the maximum data that a XCBDisplay* can hold in bytes / 4.
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
extern unsigned long XCBGetMaximumRequestLength(XCBDisplay *display);







/* 
 * RETURN: XCB_CONN_ERROR, because of socket errors, pipe errors or other stream errors.
 * RETURN: XCB_CONN_CLOSED_EXT_NOTSUPPORTED, when extension not supported.
 * RETURN: XCB_CONN_CLOSED_MEM_INSUFFICIENT, when memory not available.
 * RETURN: XCB_CONN_CLOSED_REQ_LEN_EXCEED, exceeding request length that server accepts.
 * RETURN: XCB_CONN_CLOSED_PARSE_ERR, error during parsing display string.
 * RETURN: XCB_CONN_CLOSED_INVALID_SCREEN, because the server does not have a screen matching the display.
 */
extern int XCBCheckDisplayError(XCBDisplay *display);


/* TODO */
extern char *XCBGetErrorText(XCBDisplay *display);



/* events */


/* 
 * Gets and returns the next Event from the XServer
 * This returns a structure called xcb_generic_event_t
 * This Function Blocks until a request is received
 *
 * RETURN: XCBGenericEvent * on Success
 * RETURN: XCBGenericError * on Error
 * RETURN: NULL on I/O Error
 */
XCBGenericEvent *XCBNextEvent(XCBDisplay *display);
/* 
 * Gets and returns the next Event from the XServer
 * This returns a structure called xcb_generic_event_t
 * This Function Blocks until a request is received
 *
 * RETURN: XCBGenericEvent * on Success
 * RETURN: XCBGenericError * on Error
 * RETURN: NULL on I/O Error
 */
XCBGenericEvent *XCBWaitForEvent(XCBDisplay *display);

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






/* This function sends a event to the XServer to map the window specified
 * This request isnt received immediatly;
 * For an immediate request to the XServer xcb_flush() must be called; 
 * USE xcb_flush with caution
 *
 * RETURN: Cookie to request
 */
extern XCBCookie XCBMapWindow(XCBDisplay *display, XCBWindow window);

/* windows*/
extern XCBWindow XCBCreateWindow(XCBDisplay *display, XCBWindow parent, int x, int y, unsigned int width, unsigned int height, int border_width, uint8_t depth, unsigned int _class, XCBVisualId visual, uint32_t valuemask, const uint32_t *value_list);
/* GC */
extern XCBGC XCBCreateGC(XCBDisplay *display, XCBDrawable drawable, 
uint32_t valuemask, const void *valuelist);

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
extern XCBCookie XCBChangeGC(XCBDisplay *display, XCBGC gc, uint32_t valuemask, const void *valuelist);





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
extern void XCBPrefetchMaximumRequestLength(XCBDisplay *display);

#endif
