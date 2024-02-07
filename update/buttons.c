/*
** EPITECH PROJECT, 2023
** buttons
** File description:
** buttons
*/
#include "structs.h"
#include "my_radar.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void buttons(sfKeyEvent *event, window_t *window)
{
    if (event->code == sfKeyS) {
        window->sprite *= -1;
    }
    if (event->code == sfKeyL) {
        window->hitbox *= -1;
    }
}
