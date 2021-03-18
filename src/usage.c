/*
** EPITECH PROJECT, 2020
** usage
** File description:
** display the usage
*/

#include "../include/tetris.h"

void usage(char *str)
{
    my_printf("Usage: %s [options]\n", str);
    my_printf("Options:\n");
    my_printf(" --help\t\t\tDisplay this help\n");
    my_printf(" -L --level={num}\tStart Tetris at level num (def: 1)\n");
    my_printf(" -l --key-left={K}\tMove the tetrimino LEFT using the K key ");
    my_printf("(def: left arrow)\n");
    my_printf(" -r --key-right={K}\tMove the tetrimino RIGHT using the K ");
    my_printf("key (def: right arrow)\n");
    my_printf(" -t --key-turn={K}\tTURN the tetrimino clockwise 90d using ");
    my_printf("the K key (def: top arrow)\n");
    my_printf(" -d --key-drop={K}\tDROP the tetrimino using the K key ");
    my_printf("(def: down arrow)\n");
    my_printf(" -q --key-quit={K}\tQUIT the game using the K key ");
    my_printf("(def: 'q' key)\n");
    my_printf(" -p --key-pause={K}\tPAUSE/RESTART the game using the K key ");
    my_printf("(def: space bar)\n");
    my_printf(" --map-size={row,col}\tSet the numbers of rows and columns of ");
    my_printf("the map (def: 20,10)\n");
    my_printf(" -w --without-next\tHide next tetrimino (def: false)\n");
    my_printf(" -D --debug\t\tDebug mode (def: false)\n");
}
