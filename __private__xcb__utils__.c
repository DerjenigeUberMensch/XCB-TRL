#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <xcb/xcb.h>

#include <X11/Xproto.h>

#include "xcb_trl.h"
#include "__private__xcb__utils__.h"



/* HELPER FUNCTION */
xcb_screen_t *
screen_of_display(
        xcb_connection_t *display, 
        int screen
        )
{
    xcb_screen_iterator_t iter;

    iter = xcb_setup_roots_iterator(xcb_get_setup(display));
    for(; iter.rem; --screen, xcb_screen_next(&iter))
    {
        if(screen == 0)
        {   return iter.data;
        }
    }
    return NULL;
}

char *
XCBDebugGetCallStack(void)
{
    char *stack = NULL;
#ifdef XCB_TRL_ENABLE_DEBUG
#endif
    return stack;
}

char *
XCBDebugGetLastCall(void)
{
    const char *lastcall = NULL;
#ifdef XCB_TRL_ENABLE_DEBUG
#endif
    return (char *)lastcall;
}

char *
XCBDebugGetFirstCall(void)
{
    char *firstcall = NULL;
#if XCB_TRL_ENABLE_DEBUG
#endif
    return firstcall;
}

/* TODO */
char *
XCBDebugGetAdjacentCallers(
        XCBCookie cookie
        )
{
    /* prob could use a hashmap or something */
#ifdef XCB_TRL_ENABLE_DEBUG
#endif
    return NULL;
}

char *
XCBDebugGetNameFromId(
        XCBCookie id
        )
{
#ifdef XCB_TRL_ENABLE_DEBUG
#endif
    return NULL;
}
