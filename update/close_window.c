/*
** EPITECH PROJECT, 2023
** close_window
** File description:
** close_window
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

void close_window(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}
