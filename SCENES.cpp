#include "scene/_scene.hpp"
#include "misc/_misc.hpp"
#include <ncurses.h>
#include <iostream>
#include <stdlib.h>
#include <SFML/Audio.hpp>

sf::Music music;

#pragma region CENAS
//         DEFINIÇÃO DE CENAS         //
// (A arte deve ser no máximo 103x25) //

SCENE test = new_scene(
        "Test",
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
#pragma endregion

#pragma region ANIMACOES
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

#pragma endregion

#pragma region ROTINAS

//         DEFINIÇÃO DE ROTINAS        //
// (Definir da última para a primeira) //

void yes_rou() {
    music.openFromFile("audio/comet.wav");
    music.play();

    show(test_caseYes, 1);
    getch();

    music.stop();
}

void no_rou() {
    show(test_caseNo, 2);
    getch();
}

void anim_rou() {
    showAnim(test_anim, 0.3, 5);
}

void start_rou() {
    const char *answers[] = {"YES", "NO", "ANIM"};
    functionPtr funcs[] = {yes_rou, no_rou, anim_rou};
    handle_choice(&test, 1, answers, funcs, 3);
}

#pragma endregion