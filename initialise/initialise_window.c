/*
** EPITECH PROJECT, 2023
** initialise_w
** File description:
** initialise_w
*/
#include "structs.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Font.h>
#include <stdlib.h>

static void set_timer(window_t *window)
{
    sfVector2f pos = {1800, 10};

    window->timer = sfText_create();
    sfText_setFont(window->timer, sfFont_createFromFile("font/dogica.otf"));
    sfText_setString(window->timer, "0");
    sfText_setPosition(window->timer, pos);
    sfText_setColor(window->timer, sfWhite);
}

window_t *initialise_w(int width, int height)
{
    window_t *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = malloc(sizeof(window_t));
    if (window == NULL) {
        return NULL;
    }
    window->sfwindow = sfRenderWindow_create(video_mode,
        "my_radar", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->sfwindow, 120);
    window->clock = sfClock_create();
    window->clock_delay = sfClock_create();
    set_timer(window);
    window->sprite = 1;
    window->hitbox = 1;
    return window;
}
