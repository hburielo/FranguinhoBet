#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Usuario{
    char nomeu[255];
    char cpfu [11];
    char senhau [6];
}Usuario;

void clearbuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int cadastro(){
    Usuario usuarios[10];
    bool autenticado = false;
    char nome [255];
    char cpf [11];
    char senha [6];
    int op;
    printf("Bem-vindo(a) a Frango.bet\n");
    printf("Gostaria de realizar login ou cadastro?\n");
    puts("1 - Login\n");
    puts("2 - Cadastro\n");
    
    scanf("%d",&op);
    clearbuffer();

    if(op == 2){
        printf("Digite o seu nome: ");
        fgets(nome,255,stdin);
        printf("Digite o seu CPF para cadastro: ");
        fgets(cpf, 11, stdin);
        printf("Digite a sua senha desejada: ");
        fgets(senha,6,stdin);

        Usuario *usuario = malloc(sizeof(Usuario));

        strcpy(usuario->nomeu, nome);
        strcpy(usuario->cpfu,cpf);
        strcpy(usuario->senhau, senha);

        printf("NOME: %s\n", nome);
        printf("cpf: %s\n", cpf);
        printf("senha: %s\n", senha);

        printf("Nome: %s\n", usuario->nomeu);
        printf("cpf: %s\n", usuario->cpfu);
        printf("senha: %s\n", usuario->senhau);
    } 
    else if (op == 1){
        printf("Digite seu cpf: ");
        fgets(cpf,11,stdin);
        printf("Digite sua senha: ");
        fgets(senha,6,stdin);

        for(int i = 0; i<sizeof(usuarios);i++){
            if(strcmp(usuarios[i].cpfu,cpf)==0 && strcmp(usuarios[i].senhau,senha)==0){
                printf("Bem vindo");
                autenticado = true;
                break;
            }
        }
        if(!autenticado){
            printf("Erro");
        }
                    
    }
    return 0;
}



int main(void){
   
    cadastro();
    return 0;
}