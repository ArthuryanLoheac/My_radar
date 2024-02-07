/*
** EPITECH PROJECT, 2023
** set_planes
** File description:
** set_planes
*/
#include "structs.h"
#include "my_radar.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int is_void(int *file, char *path)
{
    char c = 0;

    if (read(*file, &c, 1) <= 0) {
        return 1;
    }
    close(*file);
    *file = open(path, O_RDONLY);
    return 0;
}

static int line_to_str(int file, lst_planes **l_planes, lst_towers **l_towers,
    sfTexture* texture)
{
    char c = 0;
    char str[50];
    int value_read = 0;
    int i = 0;

    for (int k = i; k < 50; k++)
        str[k] = '\0';
    value_read = read(file, &c, 1);
    while (value_read > 0 && c != '\n') {
        str[i] = c;
        i++;
        value_read = read(file, &c, 1);
    }
    if (add_lst(l_planes, str, l_towers, texture) == -1)
        return -1;
    if (value_read > 0)
        return (line_to_str(file, l_planes, l_towers, texture));
    return 0;
}

static int check_plane(lst_planes* planes)
{
    if (planes->plane->speed == 0) {
        return -1;
    }
    if (planes->plane->x > 1920 || planes->plane->y > 1080 ||
        planes->plane->x_final > 1920
        || planes->plane->y_final > 1080) {
        return -1;
    }
    return 0;
}

static int check_tower(lst_towers* towers)
{
    if (towers->radius == 0) {
        return -1;
    }
    if (towers->x > 1920 || towers->y > 1080) {
        return -1;
    }
    return 0;
}

static int check_values(lst_planes* l_planes, lst_towers* l_towers)
{
    lst_planes* planes = l_planes;
    lst_towers* towers = l_towers;

    while (planes != NULL) {
        if (check_plane(planes) == -1) {
            return -1;
        }
        planes = planes->next;
    }
    while (towers != NULL) {
        if (check_tower(towers) == -1) {
            return -1;
        }
        towers = towers->next;
    }
    return 0;
}

lst_planes* set_planes(int *file, char *path, lst_towers **towers,
    sfTexture* texture)
{
    lst_planes* l_planes = NULL;
    lst_towers* l_towers = NULL;

    if (is_void(file, path) == 1)
        return NULL;
    if (line_to_str(*file, &l_planes, &l_towers, texture) == -1) {
        return NULL;
    }
    if (check_values(l_planes, l_towers) == -1) {
        return NULL;
    }
    *towers = l_towers;
    return l_planes;
}
