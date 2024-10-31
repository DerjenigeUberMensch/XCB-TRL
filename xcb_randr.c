#include "xcb_randr.h"

XCBCookie
XCBRRSetScreenConfig(
    XCBDisplay *display,
    XCBWindow window,
    XCBTimestamp timestamp,
    XCBTimestamp config_timestamp,
    uint16_t sizeID,
    uint16_t rotation,
    uint16_t rate
    )
{
}

XCBCookie
XCBRRDeleteOutputPropertyCookie(
    XCBDisplay *display,
    XCBRROutput output,
    XCBAtom property
    )
{
}

XCBCookie
XCBRRGetOutputPropertyCookie(
    XCBDisplay *display,
    XCBRROutput output, 
    XCBAtom property,
    XCBAtom type,
    uint32_t long_offset,
    uint32_t long_length,
    uint8_t _delete,
    uint8_t pending
    )
{
}

XCBCookie
XCBRRCreateMode(
    XCBDisplay *display,
    XCBWindow win,
    XCBRRModeInfo mode_info,
    uint32_t name_len,
    char *name
    )
{
}

XCBCookie
XCBRRDestroyMode(
    XCBDisplay *display,
    XCBRRMode mode
    )
{
}

XCBCookie
XCBRRAddOutputMode(
    XCBDisplay *display,
    XCBRROutput output,
    XCBRRMode mode
    )
{
}

XCBCookie
XCBRRDeleteOutputMode(
    XCBDisplay *display,
    XCBRROutput output,
    XCBRRmode mode
    )
{
}

XCBCookie
XCBRRGetCrtcInfo(
    XCBDisplay *display,
    XCBRRCrtc crtc, 
    XCBTimestamp config_timestamp
    )
{
}

XCBCookie
XCBRRSetCrtcConfig(
    XCBDisplay *display,
    XCBRRCrtc crtc,
    XCBTimestamp timestamp,
    XCBTimestamp config_timestamp,
    int32_t x,
    int32_t y,
    XCBRRMode mode,
    uint16_t rotation,
    uint32_t outputs_len,
    XCBRROutput *outputs
    )
{
}

XCBCookie
XCBRRGetCrtcGamma(
    XCBDisplay *display,
    XCBRRCrtc crtc
    )
{
}

XCBCookie
XCBRRSetCrtcGamma(
    XCBDisplay *display,
    XCBRRCrtc crtc,
    uint16_t size,
    const uint16_t *red,
    const uint16_t *green,
    const uint16_t *blue
    )
{
}

XCBCookie
XCBRRGetScreenResourcesCurrent(
    XCBDisplay *display,
    XCBWindow window
    )
{
}

XCBCookie
XCBRRSetCrtcTransform(
    XCBDisplay *display,
    XCBRRCrtc crtc,
    XCBRenderTransform transform,
    uint16_t filter_len,
    const char *filter_name,
    uint32_t filter_params_len,
    const XCBRenderFixed *file_params
    )
{
}

XCBCookie
XCBRRGetCrtcTransform(
    XCBDisplay *display,
    XCBRRCrtc crtc
    )
{
}

XCBCookie
XCBRRGetPanning(
    XCBDisplay *display,
    XCBRRCrtc crtc
    )
{
}

XCBCookie
XCBRRSetPanning(
    XCBDisplay *display,
    XCBRRCrtc crtc,
    XCBTimestamp timestamp,
    uint32_t left,
    uint32_t top,
    uint32_t width,
    uint32_t height,
    uint32_t track_left,
    uint32_t track_top,
    uint32_t track_width,
    uint32_t track_height,
    int32_t border_width,
    int32_t border_top,
    int32_t border_right,
    int32_t border_bottom
    )
{
}

XCBCookie
XCBRRSetOutputPrimary(
    XCBDisplay *display,
    XCBWindow window,
    XCBRROutput output
    )
{
}

XCBCookie
XCBRRGetOutputPrimary(
    XCBDisplay *display,
    XCBWindow win
    )
{
}

XCBCookie
XCBRRGetProviders(
    XCBDisplay *display,
    XCBWindow win
    )
{
}

XCBCookie
XCBRRGetProvidersInfo(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBTimestamp config_timestamp
    )
{
}

XCBCookie
XCBRRSetProviderOffloadSink(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBRRProvider sink_provider,
    XCBTimestamp config_timestamp
    )
{
}

XCBCookie
XCBSetProviderOutputSource(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBRRProvider sink_provider,
    XCBTimestamp config_timestamp
    )
{
}

XCBCookie
XCBRRListProviderProperties(
    XCBDisplay *display,
    XCBRRProvider provider
    )
{
}

XCBCookie
XCBRRQueryProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property
    )
{
}

XCBCookie
XCBRRConfigureProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property,
    uint8_t pending,
    uint8_t range,
    uint32_t values_len,
    const int32_t *values
    )
{
}  

XCBCookie
XCBRRChangeProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property,
    XCBAtom type,
    uint8_t format,
    uint8_t mode,
    uint32_t num_items,
    const void *data
    )
{
}

XCBCookie
XCBRRDeleteProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property
    )
{
}

XCBCookie
XCBRRGetProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property,
    XCBAtom type,
    uint32_t long_offset,
    uint32_t long_length,
    uint8_t _delete,
    uint8_t pending
    )
{
}

XCBCookie
XCBRRGetMonitors(
    XCBDisplay *display,
    XCBWindow window,
    uint8_t get_active
    )
{
}

XCBCookie
XCBRRSetMonitor(
    XCBDisplay *display,
    XCBWindow window,
    XCBMonitorInfo *monitor_info
    )
{
}

XCBCookie
XCBRRDeleteMonitor(
    XCBDisplay *display,
    XCBWindow window,
    XCBAtom atom
    )
{
}






























































XCBCookie
XCBRRQueryVersionCookie(
    XCBDisplay *display,
    uint32_t major_version,
    uint32_t minor_version
    )
{
    xcb_randr_query_version_cookie_t cookie = xcb_randr_query_version(display, major_version, minor_version);
    XCBCookie ret = { .sequence = cookie.sequence };

    return ret;
}

XCBRRQueryVersion *
XCBRRQueryVersionReply(
    XCBDisplay *display,
    XCBCookie cookie
    )
{
    xcb_randr_query_version_cookie_t cookie1 = { .sequence = cookie.sequence };
    XCBGenericError *err = NULL;
    XCBRRQueryVersion *ret;

    ret = xcb_randr_query_version_reply(display, cookie1, &err);

    if(err)
    {
        XCBSendErrorP(display, err);
        if(ret)
        {   free(ret);
        }
        ret = NULL;
    }
    return ret;
}


XCBCookie
XCBRRSelectInput(
    XCBDisplay *display,
    XCBWindow win,
    uint16_t enable
    )
{
    XCBCookie ret = xcb_randr_select_input(display, win, enable);

    return ret;
}

XCBCookie
XCBRRSetScreenSize(
    XCBDisplay *display,
    XCBWindow win,
    uint32_t width,
    uint32_t height,
    uint32_t milimeter_width,
    uint32_t milimeter_height
    )
{
    XCBCookie ret = xcb_randr_set_screen_size(display, win, width, height, milimeter_width, milimeter_height);

    return ret;
}

XCBCookie
XCBRRConfigureOutputProperty(
    XCBDisplay *display,
    XCBRROutput output,
    XCBAtom property,
    uint8_t pending,
    uint8_t range,
    uint32_t values_len,
    const int32_t *values
    )
{
    XCBCookie ret = xcb_randr_configure_output_property(display, output, property, pending, range, values_len, values);

    return ret;
}

XCBCookie
XCBRRChangeOutputProperty(
    XCBDisplay *display,
    XCBRROutput output,
    XCBAtom property,
    XCBAtom type,
    uint8_t format,
    uint8_t mode,
    uint32_t num_units,
    const void *data
    )
{
    XCBCookie ret = xcb_randr_change_output_property(display, output, property, type, format, mode, num_units, data);

    return ret;
}

XCBCookie
XCBRRGetScreenInfoCookie(
    XCBDisplay *display,
    XCBWindow win
    )
{
    xcb_randr_get_screen_info_cookie_t cookie = xcb_randr_get_screen_info(display, win);
    XCBCookie ret = { .sequence = cookie.sequence };

    return ret;
}

XCBRRGetScreenInfo *
XCBRRGetScreenInfoReply(
    XCBDisplay *display,
    XCBCookie cookie 
    )
{
    XCBGenericError *err = NULL;
    xcb_randr_get_screen_info_cookie_t cookie1 = { .sequence = cookie.sequence };

    XCBRRGetScreenInfo *ret = xcb_randr_get_screen_info_reply(display, cookie1, &err);

    if(err)
    {
        XCBSendErrorP(display, err);
        if(ret)
        {   free(ret);
        }
        ret = NULL;
    }

    return ret;
}


XCBCookie
XCBRRGetScreenSizeRangeCookie(
    XCBDisplay *display,
    XCBWindow win
    )
{
    xcb_randr_get_screen_size_range_cookie_t cookie = xcb_randr_get_screen_size_range(display, win);

    XCBCookie ret = { .sequence = cookie.sequence };

    return ret;
}

XCBRRGetScreenSize *
XCBRRGetScreenISizeRangeReply(
    XCBDisplay *display,
    XCBCookie cookie 
    )
{
    XCBGenericError *err = NULL;
    xcb_randr_get_screen_size_range_cookie_t cookie1 = { .sequence = cookie.sequence };

    XCBRRGetScreenSize *ret = xcb_randr_get_screen_size_range_reply(display, cookie1, &err);

    if(err)
    {
        XCBSendErrorP(display, err);
        if(ret)
        {   free(ret);
        }
        ret = NULL;
    }

    return ret;
}



XCBCookie
XCBRRGetScreenResourcesCookie(
    XCBDisplay *display,
    XCBWindow win
    )
{
    xcb_randr_get_screen_resources_cookie_t cookie = xcb_randr_get_screen_resources(display, win);

    XCBCookie ret = { .sequence = cookie.sequence };

    return ret;
}

XCBRRGetScreenResources *
XCBRRGetScreenResourcesReply(
    XCBDisplay *display,
    XCBCookie cookie
    )
{
    XCBGenericError *err = NULL;
    xcb_randr_get_screen_resources_cookie_t cookie1 = { .sequence = cookie.sequence };

    XCBRRGetScreenResources *ret = xcb_randr_get_screen_resources_reply(display, cookie1, &err);

    if(err)
    {
        XCBSendErrorP(display, err);
        if(ret)
        {   free(ret);
        }
        ret = NULL;
    }

    return ret;
}

XCBCookie
XCBRRGetOutputInfoCookie(
    XCBDisplay *display,
    XCBRROutput output,
    XCBTimestamp config_timestamp
    )
{
    xcb_randr_get_output_info_cookie_t cookie = xcb_randr_get_output_info(display, output, config_timestamp);
    XCBCookie ret = { .sequence = cookie.sequence }; 

    return ret;
}

XCBRRGetOutputInfo *
XCBRRGetOutputInfoReply(
    XCBDisplay *display,
    XCBCookie cookie
    )
{
    XCBGenericError *err = NULL;
    xcb_randr_get_output_info_cookie_t cookie1 = { .sequence = cookie.sequence };

    XCBRRGetOutputInfo *ret = xcb_randr_get_output_info_reply(display, cookie1, &err);

    if(err)
    {
        XCBSendErrorP(display, err);
        if(ret)
        {   free(ret);
        }
        ret = NULL;
    }
    return ret;
}

XCBCookie
XCBRRQueryOutputPropertyCookie(
    XCBDisplay *display,
    XCBRROutput output,
    XCBAtom property
    )
{
    xcb_randr_query_output_property_cookie_t cookie = xcb_randr_query_output_property(display, output, property);
    XCBCookie ret = { .sequence = cookie.sequence };

    return ret;
}

XCBRRQueryOutputProperty *
XCBRRQueryOutputPropertyReply(
    XCBDisplay *display,
    XCBCookie cookie
    )
{
    XCBGenericError *err = NULL;
    xcb_randr_query_output_property_cookie_t cookie1 = { .sequence = cookie.sequence };

    XCBRRQueryOutputProperty *ret = xcb_randr_query_output_property_reply(display, cookie1, &err);

    if(err)
    {
        XCBSendErrorP(display, err);
        if(ret)
        {   free(ret);
        }
        ret = NULL;
    }
    return ret;
}
