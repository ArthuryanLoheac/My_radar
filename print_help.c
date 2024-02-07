/*
** EPITECH PROJECT, 2023
** print_help
** File description:
** print_help
*/
#include "my.h"

void print_help(void)
{
    mini_printf("Air traffic simulation panel\n\n");
    mini_printf("USAGE\n    ./my_radar [OPTIONS] path_to_script\n");
    mini_printf("        path_to_script    The path to the script file.\n\n");
    mini_printf("OPTIONS\n    -h  print the usage and quit.\n");
    mini_printf("\nUSER INTERACTIONS");
    mini_printf("\n    'L' key enable/disable hitboxes and areas.\n");
    mini_printf("    'S' key enable/disable sprites.\n");
}
