#include "scene/_scene.hpp"
#include "misc/_misc.hpp"
#include <ncurses.h>
#include <iostream>
#include <stdlib.h>

//         DEFINIÇÃO DE CENAS         //
// (A arte deve ser no máximo 103x25) //

SCENE test = new_scene(
        "test",
        file_content("ASCII/welcome.txt"),
        "answer? [Yes/No]"
    );

SCENE test_caseYes = new_scene(
        "yes",
        "it worked",
        "cool"
    );

SCENE test_caseNo = new_scene(
        "no",
        "nononononononono",
        "NOOOOOOOOOOOO"
    );

SCENE scenes[MAX_SCENES] = {
    test,
    test_caseYes,
    test_caseNo,
};

//     DEFINIÇÃO DE ANIMAÇÕES      //
// (A arte deve ser no máximo _x_) //

ANIM test_anim = new_anim(
        "ONE",
        "TWO",
        "THREE"
);

ANIM animations[MAX_SCENES] = {
    test_anim
};

//         DEFINIÇÃO DE ROTINAS        //
// (Definir da última para a primeira) //

void yes_rou() {
    show(test_caseYes);
    getch();
}

void no_rou() {
    show(test_caseNo);
    getch();
}

void anim_rou() {
    showAnim(test_anim, 0.3, 5);
}

void start_rou() {
    const char *answers[] = {"YES", "NO", "ANIM"};
    functionPtr funcs[] = {yes_rou, no_rou, anim_rou};
    handle_choice(&test, answers, funcs, 3);
}