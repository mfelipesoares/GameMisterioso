#ifndef _SCENE

#define _SCENE
#define MAX_SCENES 50

// armazena os componentes de uma cena do jogo
typedef struct scene {
    const char* title;
    const char* art;
    const char* text;
} * SCENE;

// cria uma animação ASCII de 3 frames
typedef struct anim {
    const char* frame1;
    const char* frame2;
    const char* frame3;
} * ANIM;

// cria uma cena nova
SCENE new_scene(const char* title, const char* art, const char* text);

// cia uma animação nova
ANIM new_anim(const char* frame1, const char* frame2, const char* frame3);

// mostra a cena s na tela
void show(SCENE s);

// mostra a animação a na tela
void showAnim(ANIM a, double sleep_time, int times);

// libera o espaço alocado pelas estruturas cena
void free_scenes(SCENE scenes[MAX_SCENES]);

// libera o espaço alocado pelas estruturas animação
void free_anim(ANIM animations[MAX_SCENES]);

// faz a tela piscar com uma certa cena
void blink(SCENE sc, double seconds, int times);

#endif