/*
** EPITECH PROJECT, 2023
** test generate value
** File description:
** test_generate value
*/
#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_radar.h"
#include "structs.h"
#include "my_radar.h"
#include "my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/CircleShape.h>
#include <stdlib.h>

Test(my_radar, check_valid_in_1)
{
    char path[] = "tests/scripts/invalids/in_1";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_2)
{
    char path[] = "tests/scripts/invalids/in_2";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_3)
{
    char path[] = "tests/scripts/invalids/in_3";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_4)
{
    char path[] = "tests/scripts/invalids/in_4";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_5)
{
    char path[] = "tests/scripts/invalids/in_5";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_6)
{
    char path[] = "tests/scripts/invalids/in_6";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_7)
{
    char path[] = "tests/scripts/invalids/in_7";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_8)
{
    char path[] = "tests/scripts/invalids/in_8";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_9)
{
    char path[] = "tests/scripts/invalids/in_9";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_10)
{
    char path[] = "tests/scripts/invalids/in_10";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_in_11)
{
    char path[] = "tests/scripts/invalids/in_11";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_void)
{
    char path[] = "tests/scripts/invalids/void";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}

Test(my_radar, check_valid_sc_1)
{
    char path[] = "tests/scripts/sc_1";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert(l_planes != NULL);
}

Test(my_radar, check_valid_wrong_file)
{
    char path[] = "tests/scripts/v";
    int file = open(path, O_RDONLY);
    lst_planes *l_planes = NULL;
    lst_towers *l_towers = NULL;

    sfTexture *texture = sfTexture_createFromFile("images/plane.png", NULL);
    l_planes = set_planes(&file, path, &l_towers, texture);
    cr_assert_eq(l_planes, NULL);
}
