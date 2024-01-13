#include <ncurses.h>
#include <iostream>
#include <cstring>
#include <unistd.h>

#include "scene/_scene.hpp"
#include "misc/_misc.hpp"
#include "SCENES.cpp"

using namespace std;

int main(int argc, char **argv) {

    char input[50];

    // inicia a tela do ncurses
    initscr();

    int height, width;
    getmaxyx(stdscr, height, width);

    // tela de config
    while(1) {
        WINDOW *mwin = newwin(height, width, 0, 0);
        refresh();
        box(mwin, 0, 0);
        mvprintw(height/2-1, width/2 - 45, "Ajuste o tamanho do terminal para que as quatro bordas da janela do jogo sejam visíveis");
        mvprintw(height/2, width/2 - 25, "Digite \"quit\" em qualquer prompt para sair do jogo");
        mvprintw(height/2+1, width/2 - 24, "(após as mudanças, digite \"start\" para começar)");
        wrefresh(mwin);
        move(32,2);
        getstr(input);
        upper(input);
        refresh();
        if (answer(input,"START")) {clear(); start_rou(); break;}
        else if (answer(input,"QUIT")) {clear(); break;}
        clear();
    }
    refresh();

    endwin();
    free_scenes(scenes);
    free_anim(animations);
    return 0;
}   
