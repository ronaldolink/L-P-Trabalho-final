#include <stdio.h>
#include <string.h>
#include "estoque.h"

void adicionarProduto(Produto *estoque, int *tamanho) {
    printf("Adicionando um novo produto...\n");
    printf("ID: ");
    scanf("%d", &estoque[*tamanho].id);
    printf("Nome: ");
    scanf(" %[^\n]", &estoque[*tamanho].nome);
    printf("Preco: ");
    scanf("%f", &estoque[*tamanho].preco);
    printf("Quantidade: ");
    scanf("%d", &estoque[*tamanho].quantidade);
    (*tamanho)++;
}

void atualizarProduto(Produto *estoque, int tamanho) {
    int id, encontrado = 0;
    printf("Informe o ID do produto a ser atualizado: ");
    scanf("%d", &id);
    for (int i = 0; i < tamanho; i++) {
        if (estoque[i].id == id) {
            printf("Produto encontrado. Atualizando informacoes...\n");
            printf("Novo nome: ");
            scanf(" %[^\n]", &estoque[i].nome);
            printf("Novo preco: ");
            scanf("%f", &estoque[i].preco);
            printf("Nova quantidade: ");
            scanf("%d", &estoque[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

void listarProdutos(const Produto *estoque, int tamanho) {
    printf("Listando produtos...\n");
    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d | Nome: %s | Preço: %.2f | Quantidade: %d\n",
               estoque[i].id, estoque[i].nome, estoque[i].preco, estoque[i].quantidade);
    }
}

void salvarEstoque(const Produto *estoque, int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    fwrite(estoque, sizeof(Produto), tamanho, arquivo);
    fclose(arquivo);
    printf("Estoque salvo com sucesso!\n");
}

int carregarEstoque(Produto *estoque, int tamanhoMax, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0;
    }
    int tamanho = fread(estoque, sizeof(Produto), tamanhoMax, arquivo);
    fclose(arquivo);
    printf("Estoque carregado com sucesso!\n");
    return tamanho;
}
