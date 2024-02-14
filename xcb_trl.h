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
extern void XCBSetIOErrorHandler(XCBDisplay *display, void *IOHandler);

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











/* 1356 xproto.h */
/* MASKS */
/*
 * modifier 
 * -----------------
 * XCB_MOD_MASK_SHIFT = 1,
 * XCB_MOD_MASK_LOCK = 2,
 * XCB_MOD_MASK_CONTROL = 4,
 * XCB_MOD_MASK_1 = 8,
 * XCB_MOD_MASK_2 = 16,
 * XCB_MOD_MASK_3 = 32,
 * XCB_MOD_MASK_4 = 64,
 * XCB_MOD_MASK_5 = 128,
 * XCB_MOD_MASK_ANY = 32768
 *
 * Key
 * ---------------------
 * XCB_KEY_BUT_MASK_SHIFT = 1,
 * XCB_KEY_BUT_MASK_LOCK = 2,
 * XCB_KEY_BUT_MASK_CONTROL = 4,
 * XCB_KEY_BUT_MASK_MOD_1 = 8,
 * XCB_KEY_BUT_MASK_MOD_2 = 16,
 * XCB_KEY_BUT_MASK_MOD_3 = 32,
 * XCB_KEY_BUT_MASK_MOD_4 = 64,
 * XCB_KEY_BUT_MASK_MOD_5 = 128,
 * XCB_KEY_BUT_MASK_BUTTON_1 = 256,
 * XCB_KEY_BUT_MASK_BUTTON_2 = 512,
 * XCB_KEY_BUT_MASK_BUTTON_3 = 1024,
 * XCB_KEY_BUT_MASK_BUTTON_4 = 2048,
 * XCB_KEY_BUT_MASK_BUTTON_5 = 4096
 *
 * Button
 * ----------------------
 *
 * XCB_BUTTON_MASK_1 = 256,
 * XCB_BUTTON_MASK_2 = 512,
 * XCB_BUTTON_MASK_3 = 1024,
 * XCB_BUTTON_MASK_4 = 2048,
 * XCB_BUTTON_MASK_5 = 4096,
 * XCB_BUTTON_MASK_ANY = 32768
 *
 * Visual Class 
 * ---------------------
 * XCB_VISUAL_CLASS_STATIC_GRAY = 0,
 * XCB_VISUAL_CLASS_GRAY_SCALE = 1,
 * XCB_VISUAL_CLASS_STATIC_COLOR = 2,
 * XCB_VISUAL_CLASS_PSEUDO_COLOR = 3,
 * XCB_VISUAL_CLASS_TRUE_COLOR = 4,
 * XCB_VISUAL_CLASS_DIRECT_COLOR = 5
 *
 * Event
 * --------------------
 * XCB_EVENT_MASK_NO_EVENT = 0,
 * XCB_EVENT_MASK_KEY_PRESS = 1,
 * XCB_EVENT_MASK_KEY_RELEASE = 2,
 * XCB_EVENT_MASK_BUTTON_PRESS = 4,
 * XCB_EVENT_MASK_BUTTON_RELEASE = 8,
 * XCB_EVENT_MASK_ENTER_WINDOW = 16,
 * XCB_EVENT_MASK_LEAVE_WINDOW = 32,
 * XCB_EVENT_MASK_POINTER_MOTION = 64,
 * XCB_EVENT_MASK_POINTER_MOTION_HINT = 128,
 * XCB_EVENT_MASK_BUTTON_1_MOTION = 256,
 * XCB_EVENT_MASK_BUTTON_2_MOTION = 512,
 * XCB_EVENT_MASK_BUTTON_3_MOTION = 1024,
 * XCB_EVENT_MASK_BUTTON_4_MOTION = 2048,
 * XCB_EVENT_MASK_BUTTON_5_MOTION = 4096,
 * XCB_EVENT_MASK_BUTTON_MOTION = 8192,
 * XCB_EVENT_MASK_KEYMAP_STATE = 16384,
 * XCB_EVENT_MASK_EXPOSURE = 32768,
 * XCB_EVENT_MASK_VISIBILITY_CHANGE = 65536,
 * XCB_EVENT_MASK_STRUCTURE_NOTIFY = 131072,
 * XCB_EVENT_MASK_RESIZE_REDIRECT = 262144,
 * XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY = 524288,
 * XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT = 1048576,
 * XCB_EVENT_MASK_FOCUS_CHANGE = 2097152,
 * XCB_EVENT_MASK_PROPERTY_CHANGE = 4194304,
 * XCB_EVENT_MASK_COLOR_MAP_CHANGE = 8388608,
 * XCB_EVENT_MASK_OWNER_GRAB_BUTTON = 16777216
 *
 * Motion
 * -------------------------------
 * XCB_MOTION_NORMAL = 0,
 * XCB_MOTION_HINT = 1
 *
 * Notify Detail
 * ------------------------------
 * XCB_NOTIFY_DETAIL_ANCESTOR = 0,
 * XCB_NOTIFY_DETAIL_VIRTUAL = 1,
 * XCB_NOTIFY_DETAIL_INFERIOR = 2,
 * XCB_NOTIFY_DETAIL_NONLINEAR = 3,
 * XCB_NOTIFY_DETAIL_NONLINEAR_VIRTUAL = 4,
 * XCB_NOTIFY_DETAIL_POINTER = 5,
 * XCB_NOTIFY_DETAIL_POINTER_ROOT = 6,
 * XCB_NOTIFY_DETAIL_NONE = 7
 *
 * Notify Mode
 * -----------------------------
 * XCB_NOTIFY_MODE_NORMAL = 0,
 * XCB_NOTIFY_MODE_GRAB = 1,
 * XCB_NOTIFY_MODE_UNGRAB = 2,
 * XCB_NOTIFY_MODE_WHILE_GRABBED = 3
 *
 * Visiblity 
 * ----------------------------
 * XCB_VISIBILITY_UNOBSCURED = 0,
 * XCB_VISIBILITY_PARTIALLY_OBSCURED = 1,
 * XCB_VISIBILITY_FULLY_OBSCURED = 2
 *
 * Place
 * ----------------------------
 * XCB_PLACE_ON_TOP = 0,
 * XCB_PLACE_ON_BOTTOM = 1
 *
 * Property
 * ----------------------------
 * XCB_PROPERTY_NEW_VALUE = 0,
 * XCB_PROPERTY_DELETE = 1
 *
 * Time
 * ----------------------------
 * XCB_TIME_CURRENT_TIME = 0
 *
 * Atom
 * ----------------------------
 * XCB_ATOM_NONE = 0,
 * XCB_ATOM_ANY = 0,
 * XCB_ATOM_PRIMARY = 1,
 * XCB_ATOM_SECONDARY = 2,
 * XCB_ATOM_ARC = 3,
 * XCB_ATOM_ATOM = 4,
 * XCB_ATOM_BITMAP = 5,
 * XCB_ATOM_CARDINAL = 6,
 * XCB_ATOM_COLORMAP = 7,
 * XCB_ATOM_CURSOR = 8,
 * XCB_ATOM_CUT_BUFFER0 = 9,
 * XCB_ATOM_CUT_BUFFER1 = 10,
 * XCB_ATOM_CUT_BUFFER2 = 11,
 * XCB_ATOM_CUT_BUFFER3 = 12,
 * XCB_ATOM_CUT_BUFFER4 = 13,
 * XCB_ATOM_CUT_BUFFER5 = 14,
 * XCB_ATOM_CUT_BUFFER6 = 15,
 * XCB_ATOM_CUT_BUFFER7 = 16,
 * XCB_ATOM_DRAWABLE = 17,
 * XCB_ATOM_FONT = 18,
 * XCB_ATOM_INTEGER = 19,
 * XCB_ATOM_PIXMAP = 20,
 * XCB_ATOM_POINT = 21,
 * XCB_ATOM_RECTANGLE = 22,
 * XCB_ATOM_RESOURCE_MANAGER = 23,
 * XCB_ATOM_RGB_COLOR_MAP = 24,
 * XCB_ATOM_RGB_BEST_MAP = 25,
 * XCB_ATOM_RGB_BLUE_MAP = 26,
 * XCB_ATOM_RGB_DEFAULT_MAP = 27,
 * XCB_ATOM_RGB_GRAY_MAP = 28,
 * XCB_ATOM_RGB_GREEN_MAP = 29,
 * XCB_ATOM_RGB_RED_MAP = 30,
 * XCB_ATOM_STRING = 31,
 * XCB_ATOM_VISUALID = 32,
 * XCB_ATOM_WINDOW = 33,
 * XCB_ATOM_WM_COMMAND = 34,
 * XCB_ATOM_WM_HINTS = 35,
 * XCB_ATOM_WM_CLIENT_MACHINE = 36,
 * XCB_ATOM_WM_ICON_NAME = 37,
 * XCB_ATOM_WM_ICON_SIZE = 38,
 * XCB_ATOM_WM_NAME = 39,
 * XCB_ATOM_WM_NORMAL_HINTS = 40,
 * XCB_ATOM_WM_SIZE_HINTS = 41,
 * XCB_ATOM_WM_ZOOM_HINTS = 42,
 * XCB_ATOM_MIN_SPACE = 43,
 * XCB_ATOM_NORM_SPACE = 44,
 * XCB_ATOM_MAX_SPACE = 45,
 * XCB_ATOM_END_SPACE = 46,
 * XCB_ATOM_SUPERSCRIPT_X = 47,
 * XCB_ATOM_SUPERSCRIPT_Y = 48,
 * XCB_ATOM_SUBSCRIPT_X = 49,
 * XCB_ATOM_SUBSCRIPT_Y = 50,
 * XCB_ATOM_UNDERLINE_POSITION = 51,
 * XCB_ATOM_UNDERLINE_THICKNESS = 52,
 * XCB_ATOM_STRIKEOUT_ASCENT = 53,
 * XCB_ATOM_STRIKEOUT_DESCENT = 54,
 * XCB_ATOM_ITALIC_ANGLE = 55,
 * XCB_ATOM_X_HEIGHT = 56,
 * XCB_ATOM_QUAD_WIDTH = 57,
 * XCB_ATOM_WEIGHT = 58,
 * XCB_ATOM_POINT_SIZE = 59,
 * XCB_ATOM_RESOLUTION = 60,
 * XCB_ATOM_COPYRIGHT = 61,
 * XCB_ATOM_NOTICE = 62,
 * XCB_ATOM_FONT_NAME = 63,
 * XCB_ATOM_FAMILY_NAME = 64,
 * XCB_ATOM_FULL_NAME = 65,
 * XCB_ATOM_CAP_HEIGHT = 66,
 *
 *
 *
 * Colormap State
 * ------------------------------
 * XCB_COLORMAP_STATE_UNINSTALLED = 0,
 * XCB_COLORMAP_STATE_INSTALLED = 1
 * 
 * Colormap
 * ------------------------------
 * XCB_COLORMAP_NONE = 0
 *
 * Mapping
 * ------------------------------
 * XCB_MAPPING_MODIFIER = 0,
 * XCB_MAPPING_KEYBOARD = 1,
 * XCB_MAPPING_POINTER = 2
 *
 * Window Class
 * ------------------------------
 * XCB_WINDOW_CLASS_COPY_FROM_PARENT = 0,
 * XCB_WINDOW_CLASS_INPUT_OUTPUT = 1,
 * XCB_WINDOW_CLASS_INPUT_ONLY = 2
 *
 *
 *
 * Backing store
 * ------------------------------
 * XCB_BACKING_STORE_NOT_USEFUL = 0,
 * XCB_BACKING_STORE_WHEN_MAPPED = 1,
 * XCB_BACKING_STORE_ALWAYS = 2
 *
 * Image order
 * --------------------------
 * XCB_IMAGE_ORDER_LSB_FIRST = 0,
 * XCB_IMAGE_ORDER_MSB_FIRST = 1
 *
 * Window
 * -----------------------
 * XCB_WINDOW_NONE = 0,
 *
*/

#endif
