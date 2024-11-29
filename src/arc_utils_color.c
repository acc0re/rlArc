#include "utils/arc_utils_color.h"
#include <stdio.h>
#include <stdlib.h>

Color arc_utils_color_from_hex(const char* hex)
{
    char r_str[3] = {hex[0], hex[1], '\0'};
    char g_str[3] = {hex[2], hex[3], '\0'};
    char b_str[3] = {hex[4], hex[5], '\0'};

    unsigned long r = strtoul(r_str, NULL, 16);
    unsigned long g = strtoul(g_str, NULL, 16);
    unsigned long b = strtoul(b_str, NULL, 16);

    return (Color){(unsigned char)r, (unsigned char)g, (unsigned char)b, 255};
}