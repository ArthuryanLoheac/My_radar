/*
** EPITECH PROJECT, 2023
** initialise_corners
** File description:
** initialise_corners
*/
#include "structs.h"
#include "my_radar.h"
#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>


corner *initialise_corners(void)
{
    corner *corners;
    int k = 0;

    corners = malloc(sizeof(corner) * 32);
    if (corners == NULL) {
        return NULL;
    }
    for (int i = 0; i < 32; i++) {
        corners[i].area.width = 280;
        corners[i].area.height = 310;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            corners[k].area.left = i * (1920 / 8) - 20;
            corners[k].area.top = j * (1080 / 4) - 20;
            k++;
        }
    }
    return corners;
}
