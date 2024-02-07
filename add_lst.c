/*
** EPITECH PROJECT, 2023
** add_lst
** File description:
** add_lst
*/
#include "structs.h"
#include "my_radar.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void set_circle(lst_towers *tower)
{
    sfVector2f position;
    sfVector2f origin = {tower->radius, tower->radius};

    position.x = tower->x;
    position.y = tower->y;
    sfCircleShape_setOutlineColor(tower->circle,
        sfColor_fromRGBA(0, 100, 255, 100));
    sfCircleShape_setFillColor(tower->circle, sfColor_fromRGBA(0, 0, 0, 0));
    sfCircleShape_setOutlineThickness(tower->circle, 2);
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setOrigin(tower->circle, origin);
    sfCircleShape_setPosition(tower->circle, position);
}

static int add_tower(lst_towers **l_towers, char *str, int *i)
{
    lst_towers *tower = NULL;
    sfVector2f position;

    tower = malloc(sizeof(lst_towers));
    tower->x = get_nbr(str + *i, i);
    tower->y = get_nbr(str + *i, i);
    tower->radius = get_nbr(str + *i, i);
    tower->next = *l_towers;
    tower->area = set_rect(0, 0, 26, 26);
    tower->texture = sfTexture_createFromFile("images/tower.png", NULL);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, tower->texture, 0);
    position.x = tower->x - 13;
    position.y = tower->y - 13;
    tower->circle = sfCircleShape_create();
    set_circle(tower);
    sfSprite_setPosition(tower->sprite, position);
    *l_towers = tower;
    return 0;
}

static int check_every_nb(char *str, int *i)
{
    for (int j = 0; j < 6; j++) {
        if (check_nb(str, i) == -1)
            return -1;
    }
    return 0;
}

static int check_every_nb_tower(char *str, int *i)
{
    for (int j = 0; j < 3; j++) {
        if (check_nb(str, i) == -1)
            return -1;
    }
    return 0;
}

static int is_line_good(char *str)
{
    int i = 1;

    if (str[0] == 'A') {
        if (check_every_nb(str, &i) == -1)
            return -1;
    }
    if (str[0] == 'T') {
        if (check_every_nb_tower(str, &i) == -1)
            return -1;
    }
    for (int j = i; j < 50; j++) {
        if (str[j] != 0) {
            mini_printf("too much charcters\n");
            return -1;
        }
    }
    return 0;
}

int add_lst(lst_planes **l_planes, char *str, lst_towers **l_towers,
    sfTexture* texture)
{
    int i = 2;

    if (str[0] == 'A') {
        if (is_line_good(str) == -1) {
            return -1;
        }
        return add_plane(l_planes, str, &i, texture);
    }
    if (str[0] == 'T') {
        if (is_line_good(str) == -1) {
            return -1;
        }
        return add_tower(l_towers, str, &i);
    }
    return -1;
}
