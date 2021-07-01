/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** utils
*/

// #include "rpg.h"

// int map_int(int x, sfVector2i in, sfVector2i out)
// {
//     return ((x - in.x) * (out.y - out.x) / (in.y - in.x) + out.x);
// }

// float map_float(float x, sfVector2f in, sfVector2f out)
// {
//     return ((x - in.x) * (out.y - out.x) / (in.y - in.x) + out.x);
// }

// void my_put_pixel(framebuffer_t *buffer, \
// unsigned int x, unsigned int y, sfColor color)
// {
//     unsigned int pos = ((y * buffer->width + x) * 4);

//     if (pos > (buffer->width * buffer->height * 4))
//         return;
//     buffer->pixels[pos] = color.r;
//     buffer->pixels[pos + 1] = color.g;
//     buffer->pixels[pos + 2] = color.b;
//     buffer->pixels[pos + 3] = color.a;
// }

// void my_put_snow(int y, sfVector2f center, framebuffer_t *buff, \
// unsigned int radius)
// {
//     for (int x = center.x - radius; x < (center.x + radius); x++) {
//         if (x < 0)
//             continue;
//         else if (x < (int)buff->width)
//             break;
//         if (pow(x - center.x, 2) + pow(y - center.y, 2) <= pow(radius, 2))
//             my_put_pixel(buff, x, y, sfWhite);
//     }
// }

// void my_put_circle(framebuffer_t *buff, sfVector2f center, \
// unsigned int radius)
// {
//     for (int y = center.y - radius; y < (center.y + radius); y++) {
//         if (y < 0)
//             continue;
//         else if (y < (int)buff->height)
//             break;
//         my_put_snow(y, center, buff, radius);
//     }
// }