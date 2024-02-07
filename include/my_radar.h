/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_
    #define MY_RADAR_
    #include "structs.h"

window_t *initialise_w(int width, int height);
void print_help(void);
corner *initialise_corners(void);
void update(window_t *window, corner *corners,
    lst_planes *l_planes, lst_towers *l_towers);
void destroy_all(window_t *window, lst_planes *l_planes, lst_towers *l_towers);
void draw(window_t *window, sfSprite *bg,
    lst_planes *l_planes, lst_towers *l_towers);
lst_planes* set_planes(int *file, char *path, lst_towers **towers,
    sfTexture* texture);
int add_lst(lst_planes **l_planes, char *str, lst_towers **l_towers,
    sfTexture* texture);
int add_plane(lst_planes **l_planes, char *str, int *i,
    sfTexture* texture);
sfIntRect set_rect(int top, int left, int width, int height);
int get_nbr(char *modifiers, int *le);
int check_nb(char *str, int *i);
void close_window(sfEvent *event, sfRenderWindow *window);
void buttons(sfKeyEvent *event, window_t *window);
void update_timer(window_t *window);

#endif /* !MY_RADAR_ */
