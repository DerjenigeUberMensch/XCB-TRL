#ifndef __XCB__RANDR__H__
#define __XCB__RANDR__H__

#include "xcb_trl.h"

#include <xcb/randr.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef xcb_randr_query_version_reply_t XCBRRQueryVersion;
typedef xcb_randr_get_screen_info_reply_t XCBRRGetScreenInfo;
typedef xcb_randr_get_screen_size_range_reply_t XCBRRGetScreenSize;
typedef xcb_randr_get_screen_resources_reply_t XCBRRGetScreenResources;
typedef xcb_randr_get_output_info_reply_t XCBRRGetOutputInfo;
typedef xcb_randr_output_t XCBRROutput;
typedef xcb_randr_mode_info_t XCBRRModeInfo;
typedef xcb_randr_mode_t XCBRRMode;
typedef xcb_randr_crtc_t XCBRRCrtc;
typedef xcb_randr_provider_t XCBRRProvider;
typedef xcb_randr_transform_t XCBRRTransform;
typedef xcb_randr_query_output_property_reply_t XCBRRQueryOutputProperty;
typedef xcb_randr_monitor_info_t XCBRRMonitorInfo;
typedef xcb_randr_set_screen_config_reply_t XCBRRSetScreenConfig;
typedef xcb_randr_get_output_property_reply_t XCBRRGetOutputProperty;
typedef xcb_randr_create_mode_reply_t XCBRRCreateMode;
typedef xcb_randr_get_crtc_info_reply_t XCBRRGetCrtcInfo;
typedef xcb_randr_set_crtc_config_reply_t XCBRRSetCrtcConfig;

typedef xcb_render_transform_t XCBRenderTransform;
typedef xcb_render_fixed_t XCBRenderFixed;

XCBCookie
XCBRRQueryVersionCookie(
    XCBDisplay *display,
    uint32_t major_version,
    uint32_t minor_version
    );

/*
 * RETURN: XCBRRQueryVersion * on Success.
 * RETURN: NULL on Failure.
 */
XCBRRQueryVersion *
XCBRRQueryVersionReply(
    XCBDisplay *display,
    XCBCookie cookie
    );

/* TODO: XRRSet
 */



XCBCookie
XCBRRSelectInput(
    XCBDisplay *display,
    XCBWindow win,
    uint16_t enable
    );

XCBCookie
XCBRRSetScreenSize(
    XCBDisplay *display,
    XCBWindow win,
    uint32_t width,
    uint32_t height,
    uint32_t milimeter_width,
    uint32_t milimeter_height
    );


XCBCookie
XCBRRConfigureOutputProperty(
    XCBDisplay *display,
    XCBRROutput output,
    XCBAtom property,
    uint8_t pending,
    uint8_t range,
    uint32_t values_len,
    const int32_t *values
    );

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
    );

XCBCookie
XCBRRGetScreenInfoCookie(
    XCBDisplay *display,
    XCBWindow win
    );

XCBRRGetScreenInfo *
XCBRRGetScreenInfoReply(
    XCBDisplay *display,
    XCBCookie cookie 
    );


XCBCookie
XCBRRGetScreenSizeRangeCookie(
    XCBDisplay *display,
    XCBWindow win
    );

XCBRRGetScreenSize *
XCBRRGetScreenISizeRangeReply(
    XCBDisplay *display,
    XCBCookie cookie 
    );

XCBCookie
XCBRRGetScreenResourcesCookie(
    XCBDisplay *display,
    XCBWindow win
    );

XCBRRGetScreenResources *
XCBRRGetScreenResourcesReply(
    XCBDisplay *display,
    XCBCookie cookie
    );


XCBCookie
XCBRRGetOutputInfoCookie(
    XCBDisplay *display,
    XCBRROutput output,
    XCBTimestamp config_timestamp
    );

XCBRRGetOutputInfo *
XCBRRGetOutputInfoReply(
    XCBDisplay *display,
    XCBCookie cookie
    );

XCBCookie
XCBRRQueryOutputPropertyCookie(
    XCBDisplay *display,
    XCBRROutput output,
    XCBAtom property
    );

XCBRRQueryOutputProperty *
XCBRRQueryOutputPropertyReply(
    XCBDisplay *display,
    XCBCookie cookie
    );


XCBCookie
XCBRRSetScreenConfigCookie(
    XCBDisplay *display,
    XCBWindow window,
    XCBTimestamp timestamp,
    XCBTimestamp config_timestamp,
    uint16_t sizeID,
    uint16_t rotation,
    uint16_t rate
    );

XCBRRSetScreenConfig *
XCBRRSetScreenConfigReply(
    XCBDisplay *display,
    XCBCookie cookie
    );



XCBCookie
XCBRRDeleteOutputProperty(
    XCBDisplay *display,
    XCBRROutput output,
    XCBAtom property
    );

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
    );

XCBRRGetOutputProperty *
XCBRRGetOutputPropertyReply(
        XCBDisplay *display,
        XCBCookie cookie
        );

XCBCookie
XCBRRCreateModeCookie(
    XCBDisplay *display,
    XCBWindow win,
    XCBRRModeInfo mode_info,
    uint32_t name_len,
    char *name
    );

XCBRRCreateMode *
XCBRRCreateModeReply(
    XCBDisplay *display,
    XCBCookie cookie
    );

XCBCookie
XCBRRDestroyMode(
    XCBDisplay *display,
    XCBRRMode mode
    );

XCBCookie
XCBRRAddOutputMode(
    XCBDisplay *display,
    XCBRROutput output,
    XCBRRMode mode
    );

XCBCookie
XCBRRDeleteOutputMode(
    XCBDisplay *display,
    XCBRROutput output,
    XCBRRMode mode
    );

XCBCookie
XCBRRGetCrtcInfoCookie(
    XCBDisplay *display,
    XCBRRCrtc crtc, 
    XCBTimestamp config_timestamp
    );

XCBRRGetCrtcInfo *
XCBRRGetCrtcInfoReply(
    XCBDisplay *display,
    XCBCookie cookie
    );

XCBCookie
XCBRRSetCrtcConfigCookie(
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
    );

XCBRRSetCrtcConfig *
XCBRRSetCrtcConfigReply(
    XCBDisplay *display,
    XCBCookie cookie
    );

XCBCookie
XCBRRGetCrtcGamma(
    XCBDisplay *display,
    XCBRRCrtc crtc
    );

XCBCookie
XCBRRSetCrtcGamma(
    XCBDisplay *display,
    XCBRRCrtc crtc,
    uint16_t size,
    const uint16_t *red,
    const uint16_t *green,
    const uint16_t *blue
    );

XCBCookie
XCBRRGetScreenResourcesCurrent(
    XCBDisplay *display,
    XCBWindow window
    );

XCBCookie
XCBRRSetCrtcTransform(
    XCBDisplay *display,
    XCBRRCrtc crtc,
    XCBRenderTransform transform,
    uint16_t filter_len,
    const char *filter_name,
    uint32_t filter_params_len,
    const XCBRenderFixed *file_params
    );

XCBCookie
XCBRRGetCrtcTransform(
    XCBDisplay *display,
    XCBRRCrtc crtc
    );

XCBCookie
XCBRRGetPanning(
    XCBDisplay *display,
    XCBRRCrtc crtc
    );

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
    );

XCBCookie
XCBRRSetOutputPrimary(
    XCBDisplay *display,
    XCBWindow window,
    XCBRROutput output
    );

XCBCookie
XCBRRGetOutputPrimary(
    XCBDisplay *display,
    XCBWindow win
    );

XCBCookie
XCBRRGetProviders(
    XCBDisplay *display,
    XCBWindow win
    );

XCBCookie
XCBRRGetProvidersInfo(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBTimestamp config_timestamp
    );

XCBCookie
XCBRRSetProviderOffloadSink(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBRRProvider sink_provider,
    XCBTimestamp config_timestamp
    );

XCBCookie
XCBSetProviderOutputSource(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBRRProvider sink_provider,
    XCBTimestamp config_timestamp
    );

XCBCookie
XCBRRListProviderProperties(
    XCBDisplay *display,
    XCBRRProvider provider
    );

XCBCookie
XCBRRQueryProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property
    );

XCBCookie
XCBRRConfigureProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property,
    uint8_t pending,
    uint8_t range,
    uint32_t values_len,
    const int32_t *values
    );  

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
    );

XCBCookie
XCBRRDeleteProviderProperty(
    XCBDisplay *display,
    XCBRRProvider provider,
    XCBAtom property
    );

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
    );

XCBCookie
XCBRRGetMonitors(
    XCBDisplay *display,
    XCBWindow window,
    uint8_t get_active
    );

XCBCookie
XCBRRSetMonitor(
    XCBDisplay *display,
    XCBWindow window,
    XCBRRMonitorInfo *monitor_info
    );

XCBCookie
XCBRRDeleteMonitor(
    XCBDisplay *display,
    XCBWindow window,
    XCBAtom atom
    );

















 	
#ifdef __cplusplus
}
#endif


#endif
