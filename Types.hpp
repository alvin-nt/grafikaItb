#ifndef TYPES_H_
#define TYPES_H_

#include <cstdint>
#include <cstddef>
#include <linux/fb.h>
#include <linux/input.h>

/**
 * wrapper to common types
 */

#define null NULL

typedef uint8_t byte;
typedef uint32_t Pixel;

typedef struct fb_fix_screeninfo ScreenInfoFix;
typedef struct fb_var_screeninfo ScreenInfoVar;

typedef struct input_event KeyboardEvent[64];

#endif
