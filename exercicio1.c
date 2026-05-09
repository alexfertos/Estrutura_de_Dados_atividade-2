#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    char cpf[20];
    char nascimento[20];
    char motivo[20];
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

int estaCheia(Fila *f) {
    return f->fim == MAX - 1;
}

void enqueue(Fila *f, Pessoa p) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }

    if (estaVazia(f))
        f->inicio = 0;

    f->fim++;
    f->dados[f->fim] = p;
}

Pessoa dequeue(Fila *f) {
    Pessoa vazio = {"", "", "", ""};

    if (estaVazia(f)) {
        return vazio;
    }

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
    Fila fila;
    iniciarFila(&fila);

    Pessoa p1 = {"Adao", "111", "01/01/1990", "Reclamar"};
    Pessoa p2 = {"Eva", "222", "02/02/1992", "Elogiar"};
    Pessoa p3 = {"Ana", "333", "03/03/1995", "Reclamar"};
    Pessoa p4 = {"David", "444", "04/04/1991", "Elogiar"};
    Pessoa p5 = {"Julia", "555", "05/05/1998", "Reclamar"};

    enqueue(&fila, p1);
    enqueue(&fila, p2);
    enqueue(&fila, p3);
    enqueue(&fila, p4);
    enqueue(&fila, p5);

    int reclamar = 0;
    int elogiar = 0;

    while (!estaVazia(&fila)) {
        Pessoa p = dequeue(&fila);

        if (strcmp(p.motivo, "Reclamar") == 0)
            reclamar++;
        else
            elogiar++;
    }

    if (elogiar < reclamar)
        printf("Na fila de hoje tivemos %d pessoas que vieram elogiar e %d para reclamar.\n", elogiar, reclamar);
    else
        printf("Na fila de hoje tivemos %d pessoas que vieram reclamar e %d para elogiar.\n", reclamar, elogiar);

    return 0;
}
