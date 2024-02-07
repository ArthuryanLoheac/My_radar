/*
** EPITECH PROJECT, 2023
** draw
** File description:
** draw
*/
#include "structs.h"
#include "my_radar.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <stdio.h>
#include "my.h"

static void draw_planes(window_t *window, lst_planes *l_planes)
{
    sfTime time_game;
    float time_plane;

    while (l_planes != NULL) {
        time_game = sfClock_getElapsedTime(window->clock_delay);
        time_plane = time_game.microseconds / 1000000.0;
        if (window->sprite == 1 &&
            time_plane >= l_planes->plane->delay) {
            sfRenderWindow_drawSprite(window->sfwindow,
                l_planes->plane->sprite, NULL);
        }
        if (window->hitbox == 1 &&
            time_plane >= l_planes->plane->delay) {
            sfRenderWindow_drawRectangleShape(window->sfwindow,
                l_planes->plane->rectangle, NULL);
        }
        l_planes = l_planes->next;
    }
}

static void draw_towers(window_t *window, lst_towers *l_towers)
{
    while (l_towers != NULL) {
        if (window->sprite == 1) {
            sfRenderWindow_drawSprite(window->sfwindow,
                l_towers->sprite, NULL);
        }
        if (window->hitbox == 1) {
            sfRenderWindow_drawCircleShape(window->sfwindow,
                l_towers->circle, NULL);
        }
        l_towers = l_towers->next;
    }
}

void draw(window_t *window, sfSprite *bg,
    lst_planes *l_planes, lst_towers *l_towers)
{
    sfRenderWindow_clear(window->sfwindow, sfColor_fromRGBA(0, 0, 0, 255));
    sfRenderWindow_drawSprite(window->sfwindow, bg, NULL);
    draw_towers(window, l_towers);
    draw_planes(window, l_planes);
    sfRenderWindow_drawText(window->sfwindow, window->timer, NULL);
    sfRenderWindow_display(window->sfwindow);
}
