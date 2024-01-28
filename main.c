#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>



typedef struct contas{
    char numero_de_conta[200];
    float saldo;
    int estadoDaConta;

}contas;

typedef struct pessoa{
    char nome[200];
    char nif[17];
    int telefone;
    int codigo;
    contas conta;
}pessoa;
    FILE *backup;
    pessoa p;
    int id = 0;
    pessoa cliente[1000];
    //char numConta[200];
    char numConta[24] = "20232024000";
    char novo [200];

void restaurar_Ficheiro();

bool Authentication(char login, char senha){
    bool guardado = false;

        if(strcmp(login, "Admin") == 0 && strcmp(senha, "123456") == 0){
            return true;
        }
        else{
          return false;
        }
}
void Menu(){
    system ("color 1f");
    printf("-------------------------------------------------------------\n");
	printf("Seja Bem-vindo ao Sistema Integrado de Gestão XPTO do BAI \n            BAI Confiança no Futuro           \n");
	printf ("------------------------------------------------------------\n");
	printf ("                        MENU DE OPÇÕES                      \n");
	printf( "------------------------------------------------------------\n");
	printf( "(1)- Cadastrar Clientes \n");
	printf( "(2)- Listar Clientes    \n");
	printf( "(3)- Abertura de Conta  \n");
	printf( "(4)- Levantar Dinheiro  \n");
 	printf( "(5)- Transferir Dinheiro\n");
	printf( "(6)- Depositar Dinheiro \n");
	printf( "(7)- Consultar Saldo    \n");
	printf( "(8)- Actualizar Dados   \n");
	printf( "(00)- ** Sair do sistema   \n");
	printf( "Escolha Uma Opção \n Opção: ");


}
bool cadastrar_cliente(pessoa p){
    p.conta.estadoDaConta = 0;
    cliente[id-1].codigo = id;
    strcpy(cliente[id-1].nome, p.nome); //O comando strcpy serve para atribuir conteúdo de uma string para outra
    strcpy(cliente[id-1].conta.numero_de_conta, "Não tem Conta");
    printf ("Codigo: %d\nNome: %s\nNº de conta: %s\n", cliente[id-1].codigo, cliente[id-1].nome, cliente[id-1].conta.numero_de_conta);
    system ("pause");

    return true;
}
int AberturaDeConta(pessoa p, int cod){
       cliente[cod-1].conta.estadoDaConta = 1;
       cliente[cod-1].conta.saldo = 20000.00;
       char cof[13];
       cliente[cod-1].codigo= cod;
       snprintf(novo, 24, "%s%d", numConta, cod);
       strcpy (cliente[cod-1].conta.numero_de_conta, novo);
       printf("Codigo:%d \n",cliente[cod-1].codigo );
       printf("Nome:%s \n",cliente[cod-1].nome );
       printf("Numero de Conta:%s \n",cliente[cod-1].conta.numero_de_conta );
}

int listar_clientes(pessoa w){
   cliente[id] = w;
   printf("===========   Lista de clientes  ============ \n\n");
   if (id == 0){
       cliente[id].codigo = 0;
       cliente[id].conta.saldo = 0;
       strcpy (cliente[id].nome, "0" );
       printf ("Codigo do cliente: %d\n",cliente[id].codigo );
       printf ("Nome: %s\n", cliente[id].nome);
       printf ("Nº de conta: %s\n\n", cliente[id].conta.numero_de_conta);
       printf ("Saldo: %2f\n", cliente[id].conta.saldo);
   }
   else {
     for (int t = 0; t  <= id-1; t++){
       cliente[t].codigo = t + 1;
       printf ("Codigo do cliente: %d\n",cliente[t].codigo);
       printf ("Nome: %s\n", cliente[t].nome);
       printf ("Nº de conta: %s\n\n", cliente[t].conta.numero_de_conta);
       printf ("Saldo da conta: %2f\n", cliente[t].conta.saldo);
       cliente[t].codigo++;
   }
   }
return id;
}
int comparation(pessoa k){
    for (int n=0; n <= id -1; n++){
    if(strcmp(k.conta.numero_de_conta, cliente[n].conta.numero_de_conta)== 0){
        return n;
    }

}



}
void Depositar(char n, float quantia, int cod){
for (int i=0; i < cod; n++){
       if(cliente[i].codigo == cod){

            if(cliente[i].conta.saldo  > quantia){
            cliente[i].conta.saldo -= quantia;
            printf("Levantamento feito com sucesso \nSaldo actual: %2.2f", cliente[i].conta.saldo);
            system ("pause");
            return true;
            }
       }
    }
}

bool levantar_dinheiro(char k, float quantia,int cod){
printf ("Numero de conta: %s", cod);
system ("pause");
for (int n=0; n <= id -1; n++){
       if(strcmp(cliente[n].conta.numero_de_conta, k)==0){

            if(cliente[n].conta.saldo  > quantia){
            cliente[n].conta.saldo -= quantia;
            printf("Levantamento feito com sucesso \nSaldo actual: %2.2f", cliente[n].conta.saldo);
            system ("pause");
            return true;
            }
            else {
            printf ("/!\\ O saldo não é suficiente para realizar essa operação");
            system ("pause");
            return false;
            }


       }
       else {
        printf("Erro");
        return false;
       }

return false;

}
}

int Transferencia(char num, float vlor, int clicod){
for ()
return 0;
}
int actualizacao_de_dados(pessoa p, int id){

return 0;
}

int consulta_de_saldo(){

}
bool Verification(int cod){

        for (int t= 0; t <= id; t++){
            if (cod == cliente[t].codigo){
                return true;
            }
        }
}
bool vclient_ja_conta(int cod){
    if (cliente[cod-1].conta.estadoDaConta == 1){
        return true;
    }
    else{
        return false;
    }

}
void backup_dos_dados();

int cod;

int main ()
{
    int opcao, opcao1, opcao2, opcao3, op1;
    id = 0;
    int    tentativas = 3;
    float quantia;
    char login[10], senha[10];
    int resp;
    setlocale(LC_ALL, "portuguese");
    do{
        printf ("Digite o seu login: \n");
        scanf("%s[^\n]", login);
        printf ("Digite a sua senha: \n");
        scanf("%s", senha);
        bool A = Authentication(login, senha);
       if(A == true){
    do{

        Menu();
        scanf("%d%*c", &opcao);
        system ("cls");

        switch(opcao){
            case 1:
                do{
                printf( "(1)Cadastrar novo cliente \n");
                printf( "(2) Voltar para menu principal\n");
                scanf("%d%*c", &opcao1);
                }while (opcao1 != 1 && opcao1 != 2);
                system ("cls");
                switch(opcao1)
                {
                    case 1:
                        do{
                            id++;
                            do{
                                printf( "\n\t         Ficha de Cadastro do Cliente          \n");
                                printf( "\nCódigo do cliente: AO000 %d", id, "\n");
                                printf( "\nNome: ");
                                scanf("%[^\n]%*c",p.nome);/*a expressão %*c serve para limpar o buffer*/
                                system ("cls");
                                do{
                                    printf( "\nCódigo do cliente: AO000 %d", id, "\n");
                                    printf("\nNome: %s \n",p.nome);
                                    printf("\n1-salvar dados digitados \n2-Editar dados\nR:");
                                    scanf("%d%*c", &opcao2);
                                    system("cls");
                                }while(opcao2 != 1 && opcao2 != 2);
                            }while (opcao2 != 1);
                            cadastrar_cliente(p);
                            system ("cls");

                            printf ( "\t\t\n\n            CADASTRADO COM SUCESSO|O|   \n" );
                            system("pause");
                            system ("cls");
                            do{
                                printf("\n1-cadastrar um novo cliente \n2-Voltar ao Menu\n");
                                scanf("%d%*c", &opcao3);
                                system ("cls");

                              }while (opcao3!= 1 && opcao3 != 2);

                        }while (opcao3 == 1);

                      }

            break;
            case 2:
                do{
                printf(" ");
                listar_clientes(p);
                system ("pause");
                system ("cls");

                }while(1);
            break;

            case 3:

                    do{
                        printf ("\t\t================ Abertura de Conta =================\n\n");
                        printf("1-Abrir conta \n2-voltar ao Menu");
                        scanf("%i%*c", &opcao1);
                        system ("cls");
                    }while (opcao1 != 1 && opcao1 != 2);
                     switch (opcao1){
                   case 1:
                       do{
                           printf ("Pretente efetuar a abertura de uma: \n0-Conta Empresarial \n1-Conta particular \n");
                           scanf ("%i%*c", &op1);
                           system ("cls");
                        }while(op1 != 0 && op1 != 1);
                                   int cod;
                        printf ("\nDigite o código do cliente que pretende efetuar a abertura:  \n");
                        scanf("%d", &cod);
                            Verification(cod);
                            if (Verification(cod)== true){
                                vclient_ja_conta(cod);
                                if (vclient_ja_conta(cod) == false){
                                    AberturaDeConta(p, cod);
                                }
                                else{
                                    system ("cls");
                                    printf("O codigo digitado ja tem uma conta associda \n");
                                }

                            }
                            else
                            {


                                    do{
                                    printf ("/!\\Não foi encontrado nenhum cliente com esse codigo \n");
                                    printf ("1-Voltar para cadastrar o clinte \n2-Digitar novamente o codigo \nR:");
                                    scanf ("%i%*c", resp);
                                    system ("cls");
                                    }while (resp != 1 && resp != 2);
                            }


                    break ;

                     }


            break;
            case 4:

                printf("\n========== Depositar ==============\n");
                printf("\nDigite o codigo do cliente: ");
                scanf("%d", &cod);
                printf("\nDigite o numero de conta do cliente: ");
                scanf("%s%*c", &numConta);
                printf("\nDigite o montante cliente: ");
                scanf("%2.f", &quantia);



                Depositar(numConta, quantia, cod);

            break;

            case 5:

                printf ("\n\t============== Levantar Dinheiro  =============\n");
                printf ("Digite o numero de conta: \n");
                scanf("%s%*c", numConta);
                printf ("Digite a quantia que pretende levantar: ");
                scanf("%2f%*c", quantia);
                printf("\nDigite o codigo do cliente: ");
                scanf("%d", &cod);

                levantar_dinheiro(numConta, quantia, cod);
            break;
            case 6:
                printf ("\n\t============== Transferência  =============\n");
                printf ("Digite o numero de conta: \n");
                scanf("%s%*c", numConta);
                printf ("Digite a quantia que pretende levantar: ");
                scanf("%2f%*c", &quantia);
                printf("\nDigite o codigo do cliente: ");
                scanf("%d", &cod);
                Transferencia(numConta, quantia, cod);
                break;
            case 7:
                printf ("\n\t============== Actualizacão dos dados  =============\n");
                printf ("Digite o numero de conta: \n");
                scanf("%s%*c", numConta);
                printf("\nDigite o codigo do cliente: ");
                scanf("%d", &cod);
                bool V = Verification(cod);
                if (V == true){
                actualizacao_de_dados(p, cod);
                break;
                }
                else{
                  printf ("Não Existe cliente com este codigo");
                  exit(1);
                  break;
                }
                break;
            case 8:
                printf ("\n\t============= Restaurar Ficheiro  =============\n");
                restaurar_Ficheiro();
            break;
            case 9:
                printf ("\n\t============== Backup do sistema  =============\n");
                backup_dos_dados();
            break;
            default:
            exit(2);
            break;
        }



    }while (opcao != 0);
}
    else {
       tentativas--;
       if(tentativas == 0){
        exit(1);
        }
    }
    }while(tentativas == 0);
}

void restaurar_Ficheiro(){

    backup = fopen("backupIsaf.txt", "r");
     fscanf(backup, "%s", p.nome);

    fclose (backup);

}

void backup_dos_dados(){
    backup = fopen("backupIsaf.txt", "w");

    fprintf(backup, "%s", p.nome);

    fclose (backup);

}
