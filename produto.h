//
#ifndef PRODUTO_H
#define PRODUTO_H

// Estrutura que representa um produto no estoque
typedef struct {
    int id;             // ID unico do produto
    char nome[50];      // Nome do produto
    float preco;        // Preco do produto
    int quantidade;     // Quantidade em estoque
} Produto;

#endif // PRODUTO_H
