#ifndef TYPES_H_
#define TYPES_H_

#include <cstdint>
#include <linux/fb.h>

/**
 * wrapper to common types
 */

typedef uint8_t byte;
typedef uint32_t Pixel;

typedef struct fb_fix_screeninfo ScreenInfoFix;
typedef struct fb_var_screeninfo ScreenInfoVar;

#endif
