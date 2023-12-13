#include <stdio.h>
#include <stdlib.h>

struct Cliente {
int numeroConta;
char nome[50];
float saldo;
};
void cadastrarCliente(struct Cliente *clientes) {
printf("Digite o nome do cliente: ");
scanf("%s", clientes->nome);
printf("Digite o numero da conta: ");
scanf("%d", &clientes->numeroConta);   
  clientes->saldo = 0.0;

printf("Cliente cadastrado com sucesso!\n");
}


void consultarSaldo(struct Cliente *clientes) {
int numeroConta;

printf("Digite o numero da conta para consultar o saldo: ");
scanf("%d", &numeroConta);

if (clientes->numeroConta == numeroConta) {
printf("Saldo de %s: %.2f\n", clientes->nome, clientes->saldo);
} else {
printf("Conta nao encontrada.\n");
}
}

void realizarDeposito(struct Cliente *clientes) {
float valor;

printf("Digite o valor do deposito: ");
scanf("%f", &valor);
   clientes->saldo += valor;
printf("Deposito realizado com sucesso! ", clientes->nome, clientes->saldo);
}

void realizarSaque(struct Cliente *clientes) {
float valor;

printf("Digite o valor do saque: ");
 scanf("%f", &valor);
if (valor > clientes->saldo) {
printf("Saldo insuficiente.\n");

 } else {
    clientes->saldo -= valor;
printf("Saque realizado com sucesso!", clientes->nome, clientes->saldo);
}
}

int main() {
struct Cliente cliente;
int opcao;

do {
printf("\n==========================\n");
printf("\n  BANCO CENTRAL SENAI\n");
printf("\n==========================\n");
printf("\n--- Menu ---\n");
printf("1. Cadastrar Cliente\n");
printf("2. Consultar Saldo\n");
printf("3. Realizar Deposito\n");
printf("4. Realizar Saque\n");
printf("0. Sair\n");
printf("Escolha uma opcao: ");
scanf("%d", &opcao);

    switch (opcao) {
        case 1:
        cadastrarCliente(&cliente);
            break;
        case 2:
        consultarSaldo(&cliente);
            break;
        case 3:
        realizarDeposito(&cliente);
            break;
        case 4:
        realizarSaque(&cliente);
            break;
        case 0:
        printf("Saindo do programa!\n");
            break;
                default:
        printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

   
    
    return 0;
}