//Feito por Jadson Dias e Sidney Willian//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Produto
{
    char nome[50];
    float preco;
    int quantidade;
};
void cadastrarProduto(struct Produto *estoque, int *quantidadeProdutos)
{
    printf("Digite o nome do produto: ");
    scanf("%s", estoque[*quantidadeProdutos].nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &estoque[*quantidadeProdutos].preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &estoque[*quantidadeProdutos].quantidade);

    (*quantidadeProdutos)++;
    printf("Produto cadastrado com sucesso!\n");
}

void realizarVenda(struct Produto *estoque, int *quantidadeProdutos)
{
    char nomeProduto[50];
    int a, quantidadeVendida;

    printf("Digite o nome do produto a ser vendido: ");
    scanf("%s", nomeProduto);

    for (a = 0; a < *quantidadeProdutos; a++)
    {
        if (strcmp(estoque[a].nome, nomeProduto) == 0)
        {
            printf("Digite a quantidade a ser vendida: ");
            scanf("%d", &quantidadeVendida);

            if (quantidadeVendida <= estoque[a].quantidade)
            {
                estoque[a].quantidade -= quantidadeVendida;
                printf("Venda realizada com sucesso!\n");
            }
            else
            {
                printf("Quantidade em estoque insuficiente!\n");
            }

            return;
        }
    }

    printf("Produto nao encontrado!\n");
}

void exibirRelatorio(struct Produto *estoque, int quantidadeProdutos)
{
    int a;
    printf("\tRelatorio de Vendas\n");
    for (a = 0; a < quantidadeProdutos; a++)
    {
        printf("Produto: %s | Preco: %.2f | Quantidade em Estoque: %d\n",
               estoque[a].nome, estoque[a].preco, estoque[a].quantidade);
    }

}

void pesquisarProduto(struct Produto *estoque, int quantidadeProdutos)
{
    char nomeProduto[50];
    int a;

    printf("Digite o nome do produto a ser pesquisado: ");
    scanf("%s", nomeProduto);

    for (a = 0; a < quantidadeProdutos; a++)
    {
        if (strcmp(estoque[a].nome, nomeProduto) == 0)
        {
            printf("Produto encontrado!\n");
            printf("Nome: %s | Preco: %.2f | Quantidade em Estoque: %d\n",
                   estoque[a].nome, estoque[a].preco, estoque[a].quantidade);
            return;
        }
    }

    printf("Produto nao encontrado!\n");
}

void main()
{
    struct Produto estoque[100];
    int quantidadeProdutos = 0;
    int opcao;

    do
    {
        printf("\tVENDAS\n");
        printf("| 1 | Cadastrar Produto         |\n");
        printf("| 2 |Realizar Venda             |\n");
        printf("| 3 |Exibir Relatorio de Vendas |\n");
        printf("| 4 |Pesquisar Produto          |\n");
        printf("| 5 |Sair                       |\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarProduto(estoque, &quantidadeProdutos);
            break;
        case 2:
            realizarVenda(estoque, &quantidadeProdutos);
            break;
        case 3:
            exibirRelatorio(estoque, quantidadeProdutos);
            break;
        case 4:
            pesquisarProduto(estoque, quantidadeProdutos);
            break;
        case 5:
            printf("Saindo do sistema. Obrigado!\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);
}