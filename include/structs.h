/*
** EPITECH PROJECT, 2023
** structs
** File description:
** structs
*/

#ifndef STRUCTS_
    #define STRUCTS_
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/CircleShape.h>
    #include <SFML/Graphics/RenderTexture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Graphics/Text.h>
    #include <math.h>

typedef struct {
    sfRenderWindow *sfwindow;
    sfClock *clock;
    sfClock *clock_delay;
    sfEvent event;
    sfText *timer;
    int hitbox;
    int sprite;
} window_t;

typedef struct plane_t {
    float x;
    float y;
    int x_final;
    int y_final;
    int speed;
    int delay;
    int before;
    int arrived;
    int under_tower;
    sfRectangleShape *rectangle;
    sfVector2f vec_speed;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect area;
} plane_t;


typedef struct lst_plane {
    plane_t *plane;
    struct lst_plane *next;
} lst_planes;

typedef struct lst_tower {
    int x;
    int y;
    int radius;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect area;
    sfCircleShape* circle;
    struct lst_tower *next;
} lst_towers;

typedef struct {
    sfIntRect area;
    int nb_planes;
    lst_planes *planes;
}corner;

#endif /* !STRUCTS_ */
