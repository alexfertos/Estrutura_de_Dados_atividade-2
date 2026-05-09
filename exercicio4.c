#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

typedef struct {
    Pessoa dados[MAX];
    int inicio;
    int fim;
} Fila;

void iniciarFila(Fila *f) {
    f->inicio = -1;
    f->fim = -1;
}

int estaVazia(Fila *f) {
    return f->inicio == -1;
}

void enqueue(Fila *f, Pessoa p) {
    if (f->fim == MAX - 1) {
        printf("Fila cheia!\n");
        return;
    }

    if (estaVazia(f))
        f->inicio = 0;

    f->fim++;
    f->dados[f->fim] = p;
}

Pessoa dequeue(Fila *f) {
    Pessoa vazio = {"", 0};

    if (estaVazia(f))
        return vazio;

    Pessoa removido = f->dados[f->inicio];

    if (f->inicio == f->fim) {
        f->inicio = -1;
        f->fim = -1;
    } else {
        f->inicio++;
    }

    return removido;
}

int main() {
    Fila prioridade;
    Fila normal;

    iniciarFila(&prioridade);
    iniciarFila(&normal);

    Pessoa pessoas[5] = {
        {"Eva", 30},
        {"Adao", 70},
        {"Ana", 25},
        {"Carlos", 80},
        {"Julia", 40}
    };

    for (int i = 0; i < 5; i++) {
        if (pessoas[i].idade > 65)
            enqueue(&prioridade, pessoas[i]);
        else
            enqueue(&normal, pessoas[i]);
    }

    printf("Ordem de atendimento:\n\n");

    while (!estaVazia(&prioridade)) {
        Pessoa p = dequeue(&prioridade);
        printf("%s - %d anos (PRIORITARIO)\n", p.nome, p.idade);
    }

    while (!estaVazia(&normal)) {
        Pessoa p = dequeue(&normal);
        printf("%s - %d anos\n", p.nome, p.idade);
    }

    return 0;
}
