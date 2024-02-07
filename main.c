/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/
#include "structs.h"
#include "my_radar.h"
#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static sfSprite *set_bg(void)
{
    sfIntRect area = {0, 0, 1920, 1080};
    sfTexture *bg_text = sfTexture_createFromFile("images/map.png", &area);
    sfSprite *bg = sfSprite_create();

    sfSprite_setTexture(bg, bg_text, 1);
    return bg;
}

static void del_arrived(lst_planes **begin)
{
    lst_planes *tmp = *begin;

    while (tmp->next != NULL) {
        if (tmp->next->plane->arrived == 1) {
            tmp->next = tmp->next->next;
        } else {
            tmp = tmp->next;
        }
    }
    tmp = *begin;
    while (tmp != NULL) {
        if (tmp->plane->arrived == 1) {
            *begin = tmp->next;
        }
        tmp = tmp->next;
    }
}

static int check_end(corner *corners)
{
    for (int i = 0; i < 32; i++) {
        if (corners[i].nb_planes != 0)
            return 0;
    }
    return 1;
}

int game(lst_planes *l_planes, lst_towers *l_towers)
{
    window_t *window = initialise_w(1920, 1080);
    corner *corners = initialise_corners();
    sfSprite *bg = set_bg();

    if (corners == NULL || window == NULL) {
        return 84;
    }
    while (sfRenderWindow_isOpen(window->sfwindow) && l_planes != NULL) {
        if (check_end(corners) == 1) {
            sfRenderWindow_close(window->sfwindow);
        }
        update(window, corners, l_planes, l_towers);
        del_arrived(&l_planes);
        draw(window, bg, l_planes, l_towers);
    }
    destroy_all(window, l_planes, l_towers);
    return 0;
}

static int max_entities(char *path)
{
    int nb = 0;
    int file = open(path, O_RDONLY);
    int value_read = 0;
    char c = 0;

    value_read = read(file, &c, 1);
    while (value_read > 0) {
        if (c == '\n')
            nb++;
        value_read = read(file, &c, 1);
    }
    if (nb > 70000)
        return -1;
    return 0;
}

static int check_file(char *path)
{
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;
    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);

    if (file == -1) {
        mini_printf("error openning file\n");
        return 84;
    }
    if (max_entities(path) == -1) {
        mini_printf("too many entities\n");
        return 84;
    }
    l_planes = set_planes(&file, path, &l_towers, texture);
    if (l_planes == NULL) {
        mini_printf("file not conform\n");
        return 84;
    }
    return game(l_planes, l_towers);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0) {
            print_help();
        } else {
            return check_file(argv[1]);
        }
    } else {
        mini_printf("bad number of arguments: %d but 1 expected\n", argc - 1);
        mini_printf("retry with -h\n");
        return 84;
    }
}
