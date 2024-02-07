/*
** EPITECH PROJECT, 2023
** add_plane.c
** File description:
** add_plane.c
*/
#include "structs.h"
#include "my_radar.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/RectangleShape.h>

int check_nb(char *str, int *i)
{
    int len = 0;

    if (str[*i] != ' ') {
        return -1;
    }
    *i += 1;
    while (str[*i] != ' ' && str[*i] != '\0') {
        if (str[*i] >= '0' && str[*i] <= '9') {
            (*i)++;
            len++;
        } else {
            return -1;
        }
    }
    if (len == 0 || len > 4) {
        return -1;
    }
    return 0;
}

int get_nbr(char *modifiers, int *le)
{
    int number = 0;
    int len = 0;

    while (modifiers[len] != ' ' && modifiers[len] != '\0') {
        len++;
    }
    for (int i = (len - 1); i >= 0; i--) {
        number += (modifiers[len - i - 1] - '0') * my_compute_power_rec(10, i);
        *le += 1;
    }
    *le += 1;
    return number;
}

sfIntRect set_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}

static int dist(int xa, int ya, int xb, int yb)
{
    return sqrt(pow((xa - xb), 2) + pow((ya - yb), 2));
}

static void set_speed(lst_planes *plane)
{
    plane->plane->vec_speed.x = ((plane->plane->x_final - plane->plane->x) /
        dist(plane->plane->x, plane->plane->y, plane->plane->x_final,
        plane->plane->y_final)) *
        plane->plane->speed;
    plane->plane->vec_speed.y = ((plane->plane->y_final - plane->plane->y) /
        dist(plane->plane->x, plane->plane->y, plane->plane->x_final,
        plane->plane->y_final)) *
        plane->plane->speed;
}

static void set_direction(lst_planes *plane)
{
    if (plane->plane->x <= plane->plane->x_final) {
        plane->plane->before = 1;
    }
    if (plane->plane->x > plane->plane->x_final) {
        plane->plane->before = 0;
    }
}

static void set_pos(lst_planes *plane, char *str, int *i)
{
    plane->plane->x = get_nbr(str + *i, i);
    plane->plane->y = get_nbr(str + *i, i);
    plane->plane->x_final = get_nbr(str + *i, i);
    plane->plane->y_final = get_nbr(str + *i, i);
}

static void set_rectangle(lst_planes *plane)
{
    sfVector2f pos = {plane->plane->x, plane->plane->y};
    sfVector2f size = {20, 20};

    plane->plane->rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(plane->plane->rectangle, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->plane->rectangle,
        sfColor_fromRGBA(255, 100, 0, 100));
    sfRectangleShape_setOutlineThickness(plane->plane->rectangle, 1);
    sfRectangleShape_setPosition(plane->plane->rectangle, pos);
    sfRectangleShape_setSize(plane->plane->rectangle, size);
}

static void set_values(lst_planes *ls_plane, char *str, int *i)
{
    ls_plane->plane->speed = get_nbr(str + *i, i);
    ls_plane->plane->delay = get_nbr(str + *i, i);
    ls_plane->plane->arrived = 0;
    ls_plane->plane->under_tower = 0;
}

int add_plane(lst_planes **l_planes, char *str, int *i, sfTexture* texture)
{
    lst_planes *ls_plane = malloc(sizeof(lst_planes));
    sfVector2f position;

    ls_plane->plane = malloc(sizeof(plane_t));
    set_pos(ls_plane, str, i);
    set_values(ls_plane, str, i);
    ls_plane->plane->area = set_rect(0, 0, 20, 20);
    ls_plane->plane->texture = texture;
    ls_plane->plane->sprite = sfSprite_create();
    sfSprite_setTexture(ls_plane->plane->sprite, ls_plane->plane->texture, 0);
    position.x = ls_plane->plane->x;
    position.y = ls_plane->plane->y;
    set_rectangle(ls_plane);
    sfSprite_setPosition(ls_plane->plane->sprite, position);
    set_speed(ls_plane);
    set_direction(ls_plane);
    ls_plane->next = *l_planes;
    *l_planes = ls_plane;
    return 0;
}
