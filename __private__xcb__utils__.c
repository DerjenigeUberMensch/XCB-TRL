#include "__private__xcb__utils__.h"

#include <xcb/xcb.h>

#include "xcb_trl.h"

/*
 * DONOT CHANGE.
 * Due to implementation details this function should NEVER be changed. 
 *
 */
void *
__xcb__private__handle__err(
        xcb_connection_t *display, 
        xcb_generic_error_t *err,
        void *reply
        )
{
    if(reply)
    {   return reply;
    }

    /* on some rare ocassions err can be NULL */
    if(err)
    {   XCBSendErrorP(display, err);
    }

    return NULL;
}
