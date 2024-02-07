/*
** EPITECH PROJECT, 2023
** update
** File description:
** update
*/
#include "structs.h"
#include "my_radar.h"
#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void is_arrived(lst_planes *l_planes, float delta_time)
{
    if (l_planes->plane->x == l_planes->plane->x_final &&
        l_planes->plane->y == l_planes->plane->y_final) {
        l_planes->plane->arrived = 1;
    }
    if ((l_planes->plane->x > l_planes->plane->x_final &&
        l_planes->plane->before == 1) ||
        (l_planes->plane->x < l_planes->plane->x_final &&
        l_planes->plane->before == 0)) {
        l_planes->plane->arrived = 1;
    }
    l_planes->plane->x += (l_planes->plane->vec_speed.x * delta_time);
    l_planes->plane->y += (l_planes->plane->vec_speed.y * delta_time);
}

static void move_is_arrived(lst_planes *l_planes,
    float delta_time, window_t *window)
{
    sfVector2f position;
    sfTime time_game;
    float time_plane;

    while (l_planes != NULL) {
        time_game = sfClock_getElapsedTime(window->clock_delay);
        time_plane = time_game.microseconds / 1000000.0;
        if (time_plane >= l_planes->plane->delay) {
            is_arrived(l_planes, delta_time);
            position.x = l_planes->plane->x;
            position.y = l_planes->plane->y;
            sfSprite_setPosition(l_planes->plane->sprite, position);
            sfRectangleShape_setPosition(l_planes->plane->rectangle, position);
        }
        l_planes = l_planes->next;
    }
}

static void check_collide(lst_planes *l_planes, lst_planes *plane)
{
    while (plane != NULL) {
        if (plane != l_planes && l_planes->plane->x < plane->plane->x + 20 &&
            l_planes->plane->x + 20 > plane->plane->x &&
            l_planes->plane->y < plane->plane->y + 20 &&
            l_planes->plane->y + 20 > plane->plane->y &&
            (l_planes->plane->under_tower == 0 ||
            plane->plane->under_tower == 0)) {
            l_planes->plane->arrived = 1;
            plane->plane->arrived = 1;
        }
        plane = plane->next;
    }
}

static void check_list_collisions(lst_planes *l_planes)
{
    lst_planes *plane = l_planes;
    lst_planes *save = l_planes;

    while (l_planes != NULL) {
        plane = save;
        if (l_planes->plane->under_tower == 0) {
            check_collide(l_planes, plane);
        }
        l_planes = l_planes->next;
    }
}

static void check_collisions(corner *corners)
{
    for (int i = 0; i < 32; i++) {
        check_list_collisions(corners[i].planes);
    }
}

static void is_in_distance(lst_planes *l_planes, lst_towers *l_towers)
{
    int distance = sqrt(pow((l_planes->plane->x + 10 - l_towers->x), 2) +
        pow((l_planes->plane->y + 10 - l_towers->y), 2));

    if (distance <= l_towers->radius) {
        l_planes->plane->under_tower += 1;
    }
}

static void check_under_tower(lst_planes *l_planes, lst_towers *l_towers)
{
    lst_towers *save = l_towers;

    while (l_planes != NULL) {
        l_planes->plane->under_tower = 0;
        l_towers = save;
        while (l_towers != NULL) {
            is_in_distance(l_planes, l_towers);
            l_towers = l_towers->next;
        }
        l_planes = l_planes->next;
    }
}

static void add_to_lst(corner *corners, lst_planes *l_planes, int i)
{
    lst_planes *plane_add;

    if (sfIntRect_contains(&corners[i].area, l_planes->plane->x,
    l_planes->plane->y) == sfTrue) {
        plane_add = malloc(sizeof(lst_planes));
        plane_add->plane = l_planes->plane;
        plane_add->next = corners[i].planes;
        corners[i].planes = plane_add;
        corners[i].nb_planes += 1;
    }
}

static void put_in_corners(corner *corners, lst_planes *l_planes)
{
    for (int i = 0; i < 32; i++) {
        corners[i].nb_planes = 0;
        corners[i].planes = NULL;
    }
    while (l_planes != NULL) {
        for (int i = 0; i < 32; i++) {
            add_to_lst(corners, l_planes, i);
        }
        l_planes = l_planes->next;
    }
}

void update(window_t *window, corner *corners,
    lst_planes *l_planes, lst_towers *l_towers)
{
    sfTime time_game = sfClock_getElapsedTime(window->clock);
    float delta_time = time_game.microseconds / 100000.0;

    sfClock_restart(window->clock);
    while (sfRenderWindow_pollEvent(window->sfwindow,
        &window->event)) {
        close_window(&window->event, window->sfwindow);
        if (window->event.type == sfEvtKeyPressed) {
            buttons(&window->event.key, window);
        }
    }
    update_timer(window);
    move_is_arrived(l_planes, delta_time, window);
    check_under_tower(l_planes, l_towers);
    put_in_corners(corners, l_planes);
    check_collisions(corners);
}
