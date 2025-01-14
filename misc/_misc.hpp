#ifndef _MISC

#define _MISC

// ponteiro para função
typedef void (*functionPtr)();

// torna string maiúscula
void upper(char* input);

// faz pergunta para o usuário
void ask(char* input);

// compara as strings input e answer, retorna true se forem iguais
bool answer(char* input, const char* answer);

// redireciona o usuário para uma cena nova dependendo da resposta dada
void handle_choice(SCENE* prompt, int colorIndex, const char* answers[], functionPtr funcs[], int num_options);

// abre um arquivo .txt e retorna seu conteúdo para uma variável char[]
char* file_content(const char* path);

#endif