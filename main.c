#include <stdio.h>
#include "estoque.h"

#define TAMANHO_MAX_ESTOQUE 100
#define ARQUIVO_ESTOQUE "estoque.bin"

int main() {
    Produto estoque[TAMANHO_MAX_ESTOQUE];
    int tamanho = 0;
    int opcao;

    // Carrega o estoque do arquivo
    tamanho = carregarEstoque(estoque, TAMANHO_MAX_ESTOQUE, ARQUIVO_ESTOQUE);

    // Menu
    do {
        printf("\n |||Sistema de Gerenciamento de Estoque||| \n");
        printf("1. Adicionar Produto: \n");
        printf("2. Atualizar Produto: \n");
        printf("3. Listar Produtos: \n");
        printf("4. Salvar Estoque: \n");
        printf("5. Sair. \n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Escolher uma opção
        switch (opcao) {
            case 1:
                adicionarProduto(estoque, &tamanho);
            break;
            case 2:
                atualizarProduto(estoque, tamanho);
            break;
            case 3:
                listarProdutos(estoque, tamanho);
            break;
            case 4:
                salvarEstoque(estoque, tamanho, ARQUIVO_ESTOQUE);
            break;
            case 5:
                printf("Encerrando o sistema...\n");
            break;
            default:
                printf("Opçao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
