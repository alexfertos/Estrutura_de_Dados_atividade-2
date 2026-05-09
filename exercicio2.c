#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    int tempo;
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
    Fila fila;
    iniciarFila(&fila);

    enqueue(&fila, (Pessoa){"Eva", 10});
    enqueue(&fila, (Pessoa){"Adao", 7});
    enqueue(&fila, (Pessoa){"Ana", 12});
    enqueue(&fila, (Pessoa){"Carlos", 5});
    enqueue(&fila, (Pessoa){"Julia", 9});

    int soma = 0;
    int quantidade = 0;

    while (!estaVazia(&fila)) {
        Pessoa p = dequeue(&fila);

        printf("%s foi atendido em %d minutos\n", p.nome, p.tempo);

        soma += p.tempo;
        quantidade++;
    }

    float media = (float)soma / quantidade;

    printf("\nMedia de atendimento: %.2f minutos\n", media);

    if (media > 8)
        printf("Recomenda-se abrir um novo caixa.\n");
    else
        printf("Nao e necessario abrir um novo caixa.\n");

    return 0;
}
