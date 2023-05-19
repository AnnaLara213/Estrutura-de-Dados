#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char marca[100];
    char site[100];
    char telefone[15];
    char UF[3];
} Fabricante;

typedef struct {
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    Fabricante fabricante;
} Produto;

void listarMarcas(Fabricante* fabricantes, int numFabricantes) {
    printf("Lista de marcas:\n");
    for (int i = 0; i < numFabricantes; i++) {
        printf("%d. %s\n", i + 1, fabricantes[i].marca);
    }
    printf("\n");
}

void listarProdutos(Produto* produtos, int numProdutos) {
    printf("Lista de produtos:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("\n");
    }
}

void listarProdutosPorEstado(Produto* produtos, int numProdutos, char estado[]) {
    printf("Lista de produtos do estado %s:\n", estado);
    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.UF, estado) == 0) {
            printf("Produto %d:\n", i + 1);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
            printf("Valor de venda: R$ %.2f\n", produtos[i].valorVenda);
            printf("Valor do lucro: R$ %.2f\n", produtos[i].valorLucro);
            printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("\n");
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto encontrado no estado %s.\n\n", estado);
    }
}

void listarProdutosPorMarca(Produto* produtos, int numProdutos, char marca[]) {
    printf("Lista de produtos da marca %s:\n", marca);
    int encontrou = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.marca, marca) == 0) {
            printf("Produto %d:\n", i + 1);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
            printf("Valor de venda: R$ %.2f\n", produtos[i].valorVenda);
            printf("Valor do lucro: R$ %.2f\n", produtos[i].valorLucro);
            printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("\n");
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum produto encontrado da marca %s.\n\n", marca);
    }
}

void encontrarProdutoMaisCaro(Produto* produtos, int numProdutos) {
    float maiorValor = 0;
    char estadosMaisCaros[50][3];
    int numEstadosMaisCaros = 0;

    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda > maiorValor) {
            maiorValor = produtos[i].valorVenda;
            numEstadosMaisCaros = 0;
            strcpy(estadosMaisCaros[numEstadosMaisCaros], produtos[i].fabricante.UF);
            numEstadosMaisCaros++;
        } else if (produtos[i].valorVenda == maiorValor) {
            strcpy(estadosMaisCaros[numEstadosMaisCaros], produtos[i].fabricante.UF);
            numEstadosMaisCaros++;
        }
    }

    printf("Estado(s) onde está registrado o produto mais caro (valor de venda: R$ %.2f):\n", maiorValor);
    for (int i = 0; i < numEstadosMaisCaros; i++) {
        printf("%d. %s\n", i + 1, estadosMaisCaros[i]);
    }
    printf("\n");
}

void encontrarFabricanteMaisBarato(Produto* produtos, int numProdutos) {
    float menorValor = produtos[0].valorVenda;
    char fabricantesMaisBaratos[50][100];
    int numFabricantesMaisBaratos = 0;

    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].valorVenda < menorValor) {
            menorValor = produtos[i].valorVenda;
            numFabricantesMaisBaratos = 0;
            strcpy(fabricantesMaisBaratos[numFabricantesMaisBaratos], produtos[i].fabricante.marca);
            numFabricantesMaisBaratos++;
        } else if (produtos[i].valorVenda == menorValor) {
            strcpy(fabricantesMaisBaratos[numFabricantesMaisBaratos], produtos[i].fabricante.marca);
            numFabricantesMaisBaratos++;
        }
    }

    printf("Fabricante(s) onde está registrado o produto mais barato (valor de venda: R$ %.2f):\n", menorValor);
    for (int i = 0; i < numFabricantesMaisBaratos; i++) {
        printf("%d. %s\n", i + 1, fabricantesMaisBaratos[i]);
    }
    printf("\n");
}

void ordenarProdutosPorValor(Produto* produtos, int numProdutos) {
    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("Lista de produtos em ordem crescente de valor:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("\n");
    }
}

void ordenarProdutosPorLucro(Produto* produtos, int numProdutos) {
    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (produtos[j].valorLucro > produtos[j + 1].valorLucro) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }

    printf("Lista de produtos em ordem crescente de maior valor do lucro:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: R$ %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: R$ %.2f\n", produtos[i].valorVenda);
        printf("Valor do lucro: R$ %.2f\n", produtos[i].valorLucro);
        printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("\n");
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Fabricante fabricantes[5];
    Produto produtos[50];
    int numFabricantes = 0;
    int numProdutos = 0;

    
    printf("=== Cadastro de fabricantes ===\n");
    while (numFabricantes < 2 || numFabricantes > 5) {
        printf("Digite o número de fabricantes (entre 2 e 5): ");
        scanf("%d", &numFabricantes);
    }

    for (int i = 0; i < numFabricantes; i++) {
        printf("Fabricante %d:\n", i + 1);
        printf("Digite a marca: ");
        scanf(" %[^\n]s", fabricantes[i].marca);
        printf("Digite o site: ");
        scanf(" %[^\n]s", fabricantes[i].site);
        printf("Digite o telefone: ");
        scanf(" %[^\n]s", fabricantes[i].telefone);
        printf("Digite a UF: ");
        scanf(" %[^\n]s", fabricantes[i].UF);
        printf("\n");
    }

   
    printf("=== Cadastro de produtos ===\n");
    while (numProdutos < 5 || numProdutos > 50) {
        printf("Digite o número de produtos (entre 5 e 50): ");
        scanf("%d", &numProdutos);
    }

    for (int i = 0; i < numProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Digite a descrição: ");
        scanf(" %[^\n]s", produtos[i].descricao);
        printf("Digite o peso: ");
        scanf("%f", &produtos[i].peso);
        printf("Digite o valor de compra: ");
        scanf("%f", &produtos[i].valorCompra);
        printf("Digite o valor de venda: ");
        scanf("%f", &produtos[i].valorVenda);
        produtos[i].valorLucro = produtos[i].valorVenda - produtos[i].valorCompra;
        produtos[i].percentualLucro = (produtos[i].valorLucro / produtos[i].valorCompra) * 100;

        printf("Digite o fabricante (número de 1 a %d): ", numFabricantes);
        int fabricanteNumero;
        scanf("%d", &fabricanteNumero);
        produtos[i].fabricante = fabricantes[fabricanteNumero - 1];
        printf("\n");
    }

    int opcao;
    do {
        printf("=== Menu ===\n");
        printf("1. Listar todas as marcas\n");
        printf("2. Listar todos os produtos\n");
        printf("3. Listar os produtos de um determinado estado\n");
        printf("4. Listar os produtos de uma determinada marca\n");
        printf("5. Apresentar o(s) estado(s) onde está registrado o produto mais caro\n");
        printf("6. Apresentar o(s) fabricante(s) onde está registrado o produto mais barato\n");
        printf("7. Listar todos os produtos em ordem crescente de valor\n");
        printf("8. Listar todos os produtos em ordem crescente de maior valor do lucro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarMarcas(fabricantes, numFabricantes);
                break;
            case 2:
                listarProdutos(produtos, numProdutos);
                break;
            case 3:
                printf("Digite o estado: ");
                char estado[3];
                scanf(" %[^\n]s", estado);
                listarProdutosPorEstado(produtos, numProdutos, estado);
                break;
            case 4:
                printf("Digite a marca: ");
                char marca[100];
                scanf(" %[^\n]s", marca);
                listarProdutosPorMarca(produtos, numProdutos, marca);
                break;
            case 5:
                encontrarProdutoMaisCaro(produtos, numProdutos);
                break;
            case 6:
                encontrarFabricanteMaisBarato(produtos, numProdutos);
                break;
            case 7:
                ordenarProdutosPorValor(produtos, numProdutos);
                break;
            case 8:
                ordenarProdutosPorLucro(produtos, numProdutos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

