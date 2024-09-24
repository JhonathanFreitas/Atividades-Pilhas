#include <iostream>
#include <cstdio>
#include "Pilha.h"

using namespace std;

// Função para validar se a expressão possui os parênteses e colchetes fechados corretamente
bool validaExpressao(const string& expressao) {
    Pilha_Construtor();  // Inicializa a pilha
    int topo;

    for (int i = 0; i < expressao.length(); i++) {
        char atual = expressao[i];

        // Empilha o valor ASCII dos parênteses ou colchetes de abertura
        if (atual == '(' || atual == '[') {
            Pilha_Empilhar(static_cast<int>(atual));
        }

        // Verifica os fechamentos
        else if (atual == ')' || atual == ']') {
            if (Pilha_Vazia()) {
                Pilha_Destrutor();  // Libera memória
                return false;  // Erro, pois há um fechamento sem abertura correspondente
            }

            Pilha_Topo(topo);

            // Verifica correspondência de parênteses usando os valores ASCII
            if ((atual == ')' && topo == '(') || (atual == ']' && topo == '[')) {
                Pilha_Desempilhar(topo);
            } else {
                Pilha_Destrutor();  // Libera memória
                return false;  // Erro, fechou com o símbolo errado
            }
        }
    }

    // Verifica se a pilha está vazia após o loop
    bool resultado = Pilha_Vazia();
    Pilha_Destrutor();  // Libera memória
    return resultado;
}

// Função principal para demonstrar o uso da Pilha
int main()
{
    string expressao;  // Variável para a expressão matemática
    char continuar;    // Variável utilizada para continuar a inserção de expressões

    do {
        printf("Digite a expressao matematica para validar: ");
        cin >> expressao;

        if (validaExpressao(expressao)) {
            printf("OK\n");
        } else {
            printf("Errado\n");
        }

        printf("Deseja validar outra expressao? (S/N): ");
        setbuf(stdin, nullptr);
        scanf(" %c", &continuar);  // Espaço adicionado antes de %c

    } while(toupper(continuar) != 'N');

    return 0;
}
