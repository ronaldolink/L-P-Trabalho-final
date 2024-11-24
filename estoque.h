#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "produto.h"

// Função para adicionar um produto ao estoque
void adicionarProduto(Produto *estoque, int *tamanho);

// Função para atualizar um produto no estoque
void atualizarProduto(Produto *estoque, int tamanho);

// Função para listar todos os produtos no estoque
void listarProdutos(const Produto *estoque, int tamanho);

// Função para salvar o estoque em um arquivo
void salvarEstoque(const Produto *estoque, int tamanho, const char *nomeArquivo);

// Função para carregar o estoque de um arquivo
int carregarEstoque(Produto *estoque, int tamanhoMax, const char *nomeArquivo);

#endif // ESTOQUE_H
