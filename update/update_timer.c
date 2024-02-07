/*
** EPITECH PROJECT, 2023
** update_timer
** File description:
** update_timer
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


static int len_num(int nb)
{
    int len = 0;

    if (nb < 0) {
        nb = -nb;
        len ++;
    }
    for (int j = 1; nb / j > 0; j *= 10) {
        len ++;
    }
    return len;
}

static void special_case(int *points, char *str, int *len_nb, int *i)
{
    if (*points < 0) {
        (*i)++;
        str[0] = '-';
        *points = -(*points);
        (*len_nb)--;
    }
    if (*points == 0) {
        str[0] = '0';
        str[1] = '\0';
    }
}

static char *pts_to_str(int points)
{
    char *str;
    int len_nb = len_num(points);
    int i = 0;

    str = malloc(len_nb + 2);
    for (int a = 0; a < len_nb + 2; a++)
        str[a] = '\0';
    special_case(&points, str, &len_nb, &i);
    for (int j = my_compute_power_rec(10, len_nb - 1); j > 0; j /= 10) {
        if (i == len_nb - 1) {
            str[i] = '.';
            i++;
        }
        str[i] = (points / j) + '0';
        i++;
        points -= (points / j) * j;
    }
    str[i] = '\0';
    return str;
}

void update_timer(window_t *window)
{
    sfTime time_game = sfClock_getElapsedTime(window->clock_delay);
    int time = (int)(time_game.microseconds / 100000.0);

    sfText_setString(window->timer, pts_to_str(time));
}
