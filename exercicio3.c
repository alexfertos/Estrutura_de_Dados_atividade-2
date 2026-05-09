#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int codigo;
    char arquivo[50];
    int bytes;
} Documento;

typedef struct {
    Documento dados[MAX];
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

void enqueue(Fila *f, Documento d) {
    if (f->fim == MAX - 1) {
        printf("Fila cheia!\n");
        return;
    }

    if (estaVazia(f))
        f->inicio = 0;

    f->fim++;
    f->dados[f->fim] = d;
}

Documento dequeue(Fila *f) {
    Documento vazio = {0, "", 0};

    if (estaVazia(f))
        return vazio;

    Documento removido = f->dados[f->inicio];

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

    enqueue(&fila, (Documento){1, "arquivo1.pdf", 500});
    enqueue(&fila, (Documento){2, "foto.png", 1200});
    enqueue(&fila, (Documento){3, "texto.docx", 800});
    enqueue(&fila, (Documento){4, "planilha.xlsx", 1500});
    enqueue(&fila, (Documento){5, "slide.pptx", 2000});

    while (!estaVazia(&fila)) {
        Documento d = dequeue(&fila);

        printf("Imprimindo documento...\n");
        printf("Codigo: %d\n", d.codigo);
        printf("Arquivo: %s\n", d.arquivo);
        printf("Tamanho: %d bytes\n\n", d.bytes);
    }

    return 0;
}
