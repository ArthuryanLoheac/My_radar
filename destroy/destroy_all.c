/*
** EPITECH PROJECT, 2023
** destroy_all
** File description:
** destroy_all
*/
#include "structs.h"
#include "my_radar.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/CircleShape.h>
#include <stdlib.h>

void destroy_all(window_t *window, lst_planes *l_planes,
    lst_towers *l_towers)
{
    lst_towers *pervious = l_towers;

    sfRenderWindow_destroy(window->sfwindow);
    while (l_planes != NULL) {
        free(l_planes->plane);
        l_planes = l_planes->next;
    }
    while (l_towers != NULL) {
        pervious = l_towers;
        l_towers = l_towers->next;
        free(pervious);
    }
}
