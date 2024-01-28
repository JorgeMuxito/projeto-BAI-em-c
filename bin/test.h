#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <ctype.h>
#include <time.h>



typedef struct contas{
    int numero_de_conta;
    float saldo;
    char estadoDaConta[100];
    char tipo_de_conta[12];
    int codigo;
}contas;

typedef struct pessoa{
    char nome[200];
    char nif[17];
    char telefone[10];
    int codigo;
    char data[100];
}pessoa;

typedef struct clientes {
pessoa pessoa;
contas contas;



} clientes;



    int CliCadastrados = 0;
    clientes cliente[1000];
    int numConta = 202320240;
    contas conta[1000];
    contas c;
    int cod, te, cod1, receber_id;
    int ver;
    int tipo_de_conta = 2;

int menu(){
    system ("color f1");
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



bool cadastrar_clientes(pessoa p){
    cliente[CliCadastrados-1].pessoa.codigo = CliCadastrados;
    strcpy(cliente[CliCadastrados-1].pessoa.nif, p.nif);
    strcpy(cliente[CliCadastrados-1].pessoa.telefone, p.telefone);
    strcpy(cliente[CliCadastrados-1].pessoa.nome, p.nome); //O comando strcpy serve para atribuir conteúdo de uma string para outra

    return true;
}

int AberturaDeConta(pessoa p, int tipo_de_conta, int cod){
       int h = 1;
       if (cliente[cod-1].pessoa.codigo == cod){

       strcpy(cliente[cod-1].contas.estadoDaConta, "Inactivo");
       conta[cod-1].saldo = 0;
       cliente[cod-1].contas.saldo = conta[cod-1].saldo;
       cliente[cod-1].contas.codigo= cod;
       conta[cod-1].numero_de_conta = 202320240 + cod;
       cliente[cod-1].contas.numero_de_conta = conta[cod-1].numero_de_conta;

       printf("\n=========== Dados pessoais ============\n");
       printf("Codigo:%d \n",conta[cod-1].codigo );
       printf("Nome:%s \n",cliente[cod-1].pessoa.nome );
       printf("\n=========== Dados da conta  ============\n");
       printf("Número de Conta:%d \n",cliente[cod-1].contas.numero_de_conta );
       printf("Saldo:%2.2f \n",cliente[cod-1].contas.saldo );
       system("pause");
       system("cls");
       h++;
       return tipo_de_conta;

       }
       else{
        printf(" O Id inserido já está associada a uma Conta ! \n");
       return 0;
       }

}

int listar_clientes(pessoa w){
   printf("===========   Lista de clientes  ============ \n\n");
   if (CliCadastrados == 0){
       cliente[CliCadastrados].pessoa.codigo = 0;
       cliente[CliCadastrados].contas.saldo = 0;
       cliente[CliCadastrados].contas.numero_de_conta = 0;
       strcpy (cliente[CliCadastrados].pessoa.nome, "Não tem nome" );
       printf ("Codigo do cliente: %d\n",cliente[CliCadastrados].pessoa.codigo );
       printf ("Nome: %s\n", cliente[CliCadastrados].pessoa.nome);
       printf ("Nº de conta: %d\n\n", cliente[CliCadastrados].contas.numero_de_conta);
       printf ("Saldo: %2.2f\n", cliente[CliCadastrados].contas.saldo);
   }
   else {
     for (int t = 0; t  <= CliCadastrados-1; t++){
       cliente[t].pessoa.codigo = t + 1;
       printf ("Codigo do cliente: %d\n",cliente[t].pessoa.codigo);
       printf ("Nome: %s\n", cliente[t].pessoa.nome);
       printf ("Nº de conta: %s\n\n", cliente[t].contas.numero_de_conta);
       printf ("Saldo da conta: %2f\n", cliente[t].contas.saldo);
       cliente[t].pessoa.codigo++;
   }
   }
return CliCadastrados;
}

bool Verification(int cod){

        for (int t= 0; t < CliCadastrados; t++){
            if (cod == cliente[t].pessoa.codigo){
                return true;
            }
        }
}



bool Verification2(int numero_de_conta){

        for (int t= 0; t < CliCadastrados; t++){
            if (numero_de_conta == cliente[t].contas.numero_de_conta){
                    cod=cliente[t].pessoa.codigo;

                        return true;


            }
        }
}


bool Verification3(int numero_de_conta){

        for (int t= 0; t < CliCadastrados; t++){
            if (numero_de_conta == cliente[t].contas.numero_de_conta){
                    cod1=cliente[t].pessoa.codigo;

                        return true;


            }
        }
}

bool consultar_saldo(int numero_de_conta){

        for (int t= 0; t < CliCadastrados; t++){
            if (numero_de_conta == cliente[t].contas.numero_de_conta){
                  printf("O saldo da Conta: %.2f", cliente[t].contas.saldo);


                        return true;


            }
        }
}

bool levantar_dinheiro(int numero_de_conta, float quantia){

    if (cliente[cod-1].contas.saldo >= quantia)
    {
        cliente[cod-1].contas.saldo = cliente[cod-1].contas.saldo - quantia;
        printf("O saldo da conta: %.2f \n", cliente[cod-1].contas.saldo);
        printf ( "\t\t\n\n            LEVANTAMENTO COM SUCESSO|O|   \n" );
    }
    else
    {
        printf (" O saldo não é suficiente para realizar esta operação! \n");
    }


                return true;


}

bool depositar_dinheiro(int numero_de_conta, float quantia){

        cliente[cod-1].contas.saldo += quantia;
        printf("O saldo da conta: %.2f \n", cliente[cod-1].contas.saldo);

        printf ( "\t\t\n\n            DEPÓSITO COM SUCESSO|O|   \n" );
        return true;
}

bool transferir_dinheiro (int conta_enviar, int conta_receber, float quantia) {

    if ( Verification2(conta_enviar) == true)
    {
        if ( Verification3(conta_receber) == true)
        {
            if (cliente [cod-1].contas.saldo >= quantia)
            {
                cliente [cod-1].contas.saldo = cliente [cod-1].contas.saldo - quantia;
                cliente [cod1-1].contas.saldo = cliente [cod1-1].contas.saldo + quantia;
                printf ( "\t\t\n\n            TRANSFERÊNCIA COM SUCESSO|O|   \n" );
                return true;

            }
            else
            {
                printf(" O saldo não suficiente para realizar esta operação!");
            }


        }
        else
        {
             printf("A conta a receber não existe!\n");
        }
    }


            else {
                        printf("A conta a enviar não existe!\n");


                    }

}

 bool actualizar_dados( int receber_id, int opcao4){

       if ( opcao4 == 1)
       {
             printf("Nome: \n");

            scanf("%s", cliente[receber_id -1].pessoa.nome);
       }

       if (opcao4 == 2)
       {
            printf("\nTelefone: %d\n");
            scanf("%d", cliente[receber_id -1].pessoa.telefone);
       }
      if (opcao4 == 3)
      {
          printf("\nNIF: ");
        scanf("%s",cliente[receber_id -1].pessoa.nif);
      }



         printf ( "\t\t\n\n            ACTUALIZADO COM SUCESSO|O|   \n" );


return true;


 }

bool cliente_ja_tem_conta(int cod){
    if (conta[cod-1].estadoDaConta == "Inactivo"){
        return true;
    }
    else{
        return false;
    }

}


void backup_dados(){
    FILE *backup = fopen("arquivoBackup.isaf", "w+");
    if (backup == NULL){
        fprintf (stderr, "Impossivel abrir ficheiro \n");
        return;
    }
    for (int i = 0; i < CliCadastrados; i++){
        fprintf (backup, "%d,%s,%s,%d \n", cliente[i].pessoa.codigo, cliente[i].pessoa.nome, cliente[i].pessoa.nif, cliente[i].pessoa.telefone);
    }
    fclose(backup);
    printf("backup realizado com sucesso!!");
    }

    char opcao;
    int opcao1, opcao2, opcao3, operacao4, op1;
    int tipo_de_conta, numero_de_conta1, numero_de_conta2;
    float quantia;
    float valor;
    pessoa p;
    int resp;
    char login[100];
    char senha[100];
    bool escrito = false;
    setlocale(LC_ALL, "");
    system("color 1f");
    printf("---------------------------------------------------\n");
    printf("                  BAI, confiança no futuro         \n");
    printf("---------------------------------------------------\n\n");
    printf("login ou cadastro \n\n");

    printf("Digite o seu login: ");
    scanf("%s", login);
    printf("\nDigite o sua senha: ");
    scanf("%s%*c", senha);

    if (!escrito){/*
        escrever_login_senha(login, senha);
        printf("Seja-bem vindo ao sistema X do BAI\n\n");
        system ("pause");
        escrito = true;
    }
    do {
        if (strlen(login) < 5 || strlen(login) > 20){
            printf ("login deve ter entre 5 e 20 caractere");
            continue;
        }
        if (strlen(senha) < 8 || strlen(senha) > 30){
            printf ("login deve ter entre 8 e 30 caractere");
            continue;
        }
        break;

    }while(1);*/
    //int autenticado = Autenticar(login, senha);

 //   if (/*autenticado*/){
    do{

        menu();
        scanf("%c%*c", &opcao);
        system ("cls");
        switch(opcao){
            case '1':
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
                            CliCadastrados++;
                            do{
                                printf( "\n\t         Ficha de Cadastro do Cliente          \n");
                                printf( "\nCliente nº: %d", CliCadastrados, "\n");
                                p.codigo = CliCadastrados;
                                printf( "\nNome: ");
                                scanf("%[^\n]%*c",p.nome);/*a expressão %*c serve para limpar o buffer*/
                                fflush (stdin);
                                printf("\nNIF ou BI: ");
                                scanf("%[^\n]%*c",p.nif);/*a expressão %*c serve para limpar o buffer*/
                                printf("\nTelefone: ");
                                scanf("%[^\n]%*c",&p.telefone);
                                system ("cls");
                                do{
                                    printf( "\nCódigo do cliente: %d", p.codigo, "\n");
                                    printf("\nNome: %s \n",p.nome);
                                    printf ("\nTelefone: %d", p.telefone);
                                    printf ("\nNIF ou BI: %s", p.nif);

                                    printf("\n1-salvar dados digitados \n2-Editar dados\nR:");
                                    scanf("%d%*c", &opcao2);
                                    system("cls");
                                }while(opcao2 != 1 && opcao2 != 2);
                            }while (opcao2 != 1);
                            cadastrar_clientes(p);
                            system ("cls");

                            printf ( "\t\t\n\n     CADASTRADO COM SUCESSO|O|   \n" );
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
            case '2':
                listar_clientes(p);
                system ("pause");
                system ("cls");
            break;

            case '3':


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
                                cliente_ja_tem_conta;
                                if (cliente_ja_tem_conta(cod) == false){
                                    AberturaDeConta(p, tipo_de_conta, cod);
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
              case '4':

                  do{
                    printf ("\t\t================ Levantamento =================\n\n");
                    printf("1-Levantar dinheiro \n2-voltar ao Menu");
                    scanf("%i%*c", &opcao1);
                    system ("cls");
                }while (opcao1 != 1 && opcao1 != 2);
                switch (opcao1){
                   case 1:
                          printf("Digite Numero de Conta: ");
                          scanf("%d", &numero_de_conta1);
                          printf("Digite a Quantia: ");
                          scanf("%f", &quantia);
                          if ( Verification2(numero_de_conta1) == true)

                          {
                                levantar_dinheiro(numero_de_conta1, quantia);
                          }
                          else {
                            printf("Não existe\n");
                          }

                    break;
                }


            break;

            case '5':
                     do{


                        printf ("\t\t================ Tranferir =================\n\n");
                        printf("1-Transferir dinheiro \n2-voltar ao Menu");
                        scanf("%i%*c", &opcao1);
                        system ("cls");
                        }while (opcao1 != 1 && opcao1 != 2);
                        switch (opcao1){
                        case 1:

                          printf("Digite o número de conta a enviar: ");
                          scanf("%d", &numero_de_conta1);
                           printf("Digite o número de conta a receber : ");
                          scanf("%d", &numero_de_conta2);
                           printf("Digite a quantia: ");
                          scanf("%f", &quantia);

                              transferir_dinheiro(numero_de_conta1, numero_de_conta2, quantia);





                        break;
                        }



            break;
            case '6':

                     do{


                        printf ("\t\t================ Depósito =================\n\n");
                        printf("1-Depositar Dinheiro \n2-voltar ao Menu");
                        scanf("%i%*c", &opcao1);
                        system ("cls");
                    }while (opcao1 != 1 && opcao1 != 2);
                    switch (opcao1){
                        case 1:

                          printf("Digite Numero de Conta: ");
                          scanf("%d", &numero_de_conta1);
                          printf("Digite a Quantia :");
                          scanf("%f", &quantia);
                          if ( Verification2(numero_de_conta1) == true)
                          {
                                depositar_dinheiro(numero_de_conta1, quantia);
                          }
                          else {
                            printf("Não existe uma conta associada a este número\n");
                          }

                        break;
                    }



            break;
            case '7':


                     do{

                            printf ("\t\t================ Consultar =================\n\n");
                            printf("1-Consultar dinheiro \n2-voltar ao Menu");
                            scanf("%i%*c", &opcao1);
                            system ("cls");
                        }while (opcao1 != 1 && opcao1 != 2);
                        switch (opcao1){
                        case 1:

                          printf("Digite Numero de Conta: ");
                          scanf("%d", &numero_de_conta1);

                          if ( consultar_saldo(numero_de_conta1) == true)
                          {

                             consultar_saldo(numero_de_conta1);

                          }
                          else {
                            printf("Não existe\n");
                          }

                        break;
                        }




            break;
            case '8':

                    do{


                        printf ("\t\t================ Actualizar Dados =================\n\n");
                        printf("1-Actualizar Dados \n2-voltar ao Menu");
                        scanf("%i%*c", &opcao1);
                        system ("cls");
                    }while (opcao1 != 1 && opcao1 != 2);
                    switch (opcao1){
                        case 1:

                          printf("Digite o Id do Cliente: ");
                          scanf("%d", &receber_id);



                          if ( Verification(receber_id) == true)
                            {
                                        printf ("Dados Actuais: %s\n");
                                        printf ("Nome: %s\n", cliente[receber_id -1].pessoa.nome);
                                        printf ("Telefone: %s\n", cliente[receber_id -1].pessoa.telefone);
                                        printf ("Nif: %s\n", cliente[receber_id -1].pessoa.nif);
                                        printf("Digite a opcão que pretendes alterar: ");



                                        do {

                                                printf("\n 1-NOME");
                                                printf("\n 2-TELEFONE");
                                                printf("\n 3-NIF ");
                                                scanf("%d", &operacao4);
                                        } while (operacao4 !=1 || operacao4 !=2 || operacao4 !=3);

                                        actualizar_dados(receber_id, operacao4);
                          }
                          else {
                            printf("Não existe uma conta associada a este número\n");
                          }

                        break;
                    }



            break;



        }
    }while (opcao != '0');
    backup_dados();
     }
}

#endif // TEST_H_INCLUDED
