// image_to_jpeg.h - lightweight JPEG conversion interface
#pragma once

#include "sdkconfig.h"

#ifndef CONFIG_IDF_TARGET_ESP32

#include <stddef.h>
#include <stdint.h>

// Keep this header self-contained. image_to_jpeg only needs pixel-format
// integer values, and including linux/videodev2.h here leaks ioctl macros
// that conflict with lwIP socket headers in unrelated translation units.
#ifndef XIAOZHI_V4L2_PIX_FMT_T_DEFINED
#define XIAOZHI_V4L2_PIX_FMT_T_DEFINED
typedef uint32_t v4l2_pix_fmt_t;
#endif

#ifndef V4L2_PIX_FMT_RGB565
#define V4L2_PIX_FMT_RGB565 0x50424752  // 'RGBP'
#endif
#ifndef V4L2_PIX_FMT_RGB565X
#define V4L2_PIX_FMT_RGB565X 0x52474250 // 'PRGB'
#endif
#ifndef V4L2_PIX_FMT_RGB24
#define V4L2_PIX_FMT_RGB24 0x33424752   // 'RGB3'
#endif
#ifndef V4L2_PIX_FMT_YUYV
#define V4L2_PIX_FMT_YUYV 0x56595559    // 'YUYV'
#endif
#ifndef V4L2_PIX_FMT_YUV422P
#define V4L2_PIX_FMT_YUV422P 0x36315559 // 'YU16'
#endif
#ifndef V4L2_PIX_FMT_YUV420
#define V4L2_PIX_FMT_YUV420 0x32315559  // 'YU12'
#endif
#ifndef V4L2_PIX_FMT_GREY
#define V4L2_PIX_FMT_GREY 0x59455247    // 'GREY'
#endif
#ifndef V4L2_PIX_FMT_UYVY
#define V4L2_PIX_FMT_UYVY 0x59565955    // 'UYVY'
#endif
#ifndef V4L2_PIX_FMT_JPEG
#define V4L2_PIX_FMT_JPEG 0x4745504A    // 'JPEG'
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef size_t (*jpg_out_cb)(void* arg, size_t index, const void* data, size_t len);

bool image_to_jpeg(uint8_t* src, size_t src_len, uint16_t width, uint16_t height,
                   v4l2_pix_fmt_t format, uint8_t quality, uint8_t** out, size_t* out_len);

bool image_to_jpeg_cb(uint8_t* src, size_t src_len, uint16_t width, uint16_t height,
                      v4l2_pix_fmt_t format, uint8_t quality, jpg_out_cb cb, void* arg);

#ifdef __cplusplus
}
#endif

#endif  // CONFIG_IDF_TARGET_ESP32
