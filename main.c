#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

//__Cristovão e Jorge

FILE *ficheiro;

void mostrar_data ()
{
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);
	int ano=tm.tm_year+1900;
	printf(" %02d/%02d/%04d  %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon+1 ,ano, tm.tm_hour,tm.tm_min);

}
typedef struct conta
{
	int numero_conta,codigo_cliente;
	char *estado;
	float saldo;


}conta;


typedef struct pessoa
{
	int codigo_cliente,telefone,idade,tipo_cliente;
	char nome[100],morada[100],bi[22],nif[25];

}pessoa;
void continuar (){
	char d;
	printf("\t\n Digite qualquer tecla para continuar: ");
	scanf("%s",&d);
}
void cabecalho (){
	printf("\t\n-----------------------------------------------------------");
	printf("\t\t\n SISTEMA DE GESTÃO BANCO BAI \n\tBAI CONFIANÇA NO FUTURO ");
	 mostrar_data();
	printf("\t\n-------------------------------------------------------\t\n");
}
void menu (){

	printf(" \t\n (1)-cadastrar clientes \t\n (2)-Listar Clientes clientes \t\n (3)-Abertura de Conta  \t\n (4)-Depositar Dinheiro \t\n (5)-Levantar Dinheiro\t\n (6)-Consultar Saldo\t\n (7)-Transfeir Dinheiro \t\n (8)-Atualizar Dados \t\n (9)-Terminar Sessão \t\n Escolha uma opcao:");

}

conta contas[1000];
pessoa clientes[1000];
FILE *backup;
int Total_Cli=0, totalContas=0;

bool CadastrarClientes (pessoa p) {
	conta c;
	clientes[Total_Cli] = p;
	contas[Total_Cli].codigo_cliente=p.codigo_cliente;
	contas[Total_Cli].numero_conta = 0;
	contas[Total_Cli].estado= "Inactiva";
	Total_Cli = Total_Cli + 1;
	return true;
}
void Listar_Clientes (){
	for (int i=0; i<=Total_Cli-1; i++){
		if (contas[i].numero_conta==0){

			if (clientes[i].tipo_cliente==0){
				printf("\t\nCodigo:%d ",clientes[i].codigo_cliente);
				printf("\nNome:%s ",clientes[i].nome);
				printf("\nNº DE Identificacao (B.I):%s",clientes[i].bi);
				printf("\nTelefone: %d",clientes[i].telefone);
				printf("\nIdade:%d ", clientes[i].idade);
				printf("\nMorada:%s ",clientes[i].morada);

			}
			else {
				printf("\t\nCodigo:%d ",clientes[i].codigo_cliente);
				printf("\nNome Empresa:%s ",clientes[i].nome);
				printf("\nIdentificacao NIF:%s ",clientes[i].nif);
				printf("\nTelefone: %d",clientes[i].telefone);
				printf("\nLocalizacao:%s ",clientes[i].morada);
			}


		}
		else {
			if (clientes[i].tipo_cliente==0){

				printf("\t\nCodigo:%d ",clientes[i].codigo_cliente);
				printf("\nNome:%s ",clientes[i].nome);
				printf("\nIdentificacao:%s ",clientes[i].bi);
				printf("\nTelefone: %d",clientes[i].telefone);
				printf("\nIdade:%d ", clientes[i].idade);
				printf("\nMorada:%s ",clientes[i].morada);
				printf("\nNumero de conta: %d ",contas[i].numero_conta);
				printf("\nSaldo:%.2f ", contas[i].saldo);
				printf("\nEstado da Conta: %s ",contas[i].estado);
			}
			else{

				printf("\t\nCodigo:%d ",clientes[i].codigo_cliente);
				printf("\nNome Empresa:%s",clientes[i].nome);
				printf("\nIdentificacao NIF:%s ",clientes[i].nif);
				printf("\nTelefone: %d",clientes[i].telefone);
				printf("\nLocalizacao:%s ",clientes[i].morada);
			}

	 	}

		}
	printf("\n=========================================================\n");
	}

int Verification_ID_Cliente (int id){
	for (int i=0; i<=Total_Cli-1; i++){
		if (id==clientes[i].codigo_cliente)
		return i;

	}
	return -1;
}
bool abertura_de_conta (pessoa p, int tipo_conta) {



	conta c;


	c.numero_conta = 20232024 + p.codigo_cliente;
	c.saldo = 0.0;
	c.estado="Nao activo";
	contas[totalContas] = c;

	totalContas++;

	return true;

}
int Verification_conta (int c){
	for (int i=0; i<=totalContas-1; i++){
		if (c==contas[i].numero_conta){
			return i;
		}

	}
	return -1;
}
bool depositar (int num_conta,float montante){
	int	i=Verification_conta(num_conta);

				if (i==-1){
					printf("Conta invalida");
					return false;
				}


				contas[i].saldo=contas[i].saldo+montante;
				contas[i].estado="Activo";


}
bool Levantar (int num_conta,float montante){
	int	i=Verification_conta(num_conta);

				if (i==-1){
					printf("Conta invalida");
					return false;
				}
				else{
					if (montante>contas[i].saldo){
		            printf("Montante indisponivel de ser sacado.");
		            return false;
			     	}
				}


				contas[i].saldo=contas[i].saldo-montante;



}

float consultar (int num_conta){
	 	int	i=Verification_conta(num_conta);

				if (i==-1){
					printf("Conta invalida");
					return false;
				}
		return contas[i].saldo;

  }

bool	transferir_dinheiro (int num_conta1,int num_conta2,float montante) {
   		int	i=Verification_conta(num_conta1);
   		int j=Verification_conta(num_conta2);

				if ((i==-1)||(j==-1)){
					printf("Conta invalida");
					return false;
				}
				if (contas[i].saldo<contas[j].saldo){
					printf("Porfavor, consulte o seu saldo");
				}
				else {
					contas[i].saldo=contas[i].saldo-montante;
					contas[j].saldo=contas[j].saldo+montante;

				}


				contas[i].saldo=contas[i].saldo+montante;

 }
bool Authentication(char login[10], char senha[10]){

    if (strcmp(login, "Lukau")== 0 && strcmp(senha, "111610")== 0 ){
        return true;
    }
    else{
        return false;
    }
 }


int main (){
	setlocale(LC_ALL,"portuguese");
	int opcao;
	pessoa p;
	int tentativas = 3;
	char login[10], senha[10];
    bool A;
	do{
        printf("\t\n        BAI CONFIANÇA NO FUTURO              ");
        printf("\n\tLogin:    ");
        fflush(stdin);
        scanf("%s", login);
        printf("\n\tSenha:    ");
        scanf("%s", senha);
        tentativas--;
        system ("cls");
	bool A = Authentication(login, senha);
	if (A == true){
	do {
	   system("color f9");
		cabecalho();
     	menu ();
		scanf("%d",&opcao);
		system ("cls");

		switch (opcao){

			case 1:

				p.codigo_cliente = Total_Cli + 1;
			    system ("cls");
			  	cabecalho();
				printf("\t\n==================Cadstrar cliente===============\t\n");
				printf(" Marque:   \n0-Cliente particular  \n1-Cliente Empresarial: ");
				scanf("%d",&p.tipo_cliente);
				if (p.tipo_cliente==0){

						printf("\t\ncodigo: %d\n",p.codigo_cliente);
						printf(" Nome: ");
					    fflush(stdin);
						scanf("%[^\n]",p.nome);
						printf(" Nº Identificacao do BI: ");
						fflush(stdin);
						scanf("%[^\n]",p.bi);
						printf(" Telefone: ");
						scanf("%d",&p.telefone);
						printf(" Idade: ");
						scanf("%d",&p.idade);
						printf(" Morada: ");
						 fflush(stdin);
						scanf("%[^\n]",p.morada);
				}
				else {

						printf("\t\ncodigo: %d\n",p.codigo_cliente);
						printf(" Nome Empresa: ");
					    fflush(stdin);
						scanf("%[^\n]",p.nome);
						printf(" Identificacao NIF: ");
						fflush(stdin);
						scanf("%[^\n]",p.bi);
						printf("Tel: ");
						scanf("%d",&p.telefone);
						printf(" Localizacao: ");
						 fflush(stdin);
						scanf("%[^\n]",p.morada);

				}


			    CadastrarClientes(p);
			    printf("\n\t  Cadastrado com sucesso \n");
			    system("pause");
			    system("cls");
                break;

			case 2:
				    system ("cls");
				    printf("\t\n==================Listar_Clientes cliente===========\t\n");
				    Listar_Clientes();
				    system("pause");
				    system ("cls");

					break;
			case 3:

			   system ("cls");
			   int codigo;

			   printf( "Digite o seu codigo pessoal: ");
			   scanf("%d",&codigo);



			   	int i =Verification_ID_Cliente(codigo);
			   	if (i==-1){

			   	printf( "O seu codigo pessoal esta incorreto ");

				   }

			   else {
						int tconta;
						printf( "Insira o tipo de conta 0 para particular ou 1 para empresarial: ");
						scanf("%d",&tconta);
							if (clientes[i].tipo_cliente!=tconta){
		                         printf("Tipo de conta incompativel para este cliente");
	                        }

						   else {
						        abertura_de_conta(clientes[i], tconta);
						        system("cls");
						        cabecalho();
							    printf("Conta aberta com sucesso \n");
							    printf(" Faca  seu primeiro depoito para activar a sua conta ");
							    Sleep(1);
							    Listar_Clientes ();
							    system ("pause");
							}

				  }

					break;
			case 4:
                printf("========= Depositar Dinheiro =========\n");
				float montante;
				int c;
				printf(" Digite o numero de conta:");
				scanf("%d",&c);
			    printf("Digite o montante: ");
				scanf("%f",&montante);
				depositar(c,montante);
			    printf("\t\nOperacao realizada com sucesso\n");
				break;


			case 5:
				printf("=========Levantar Dinheiro=========\n");
				float v;
				int n_conta;

				printf(" Digite o numero de conta:");
				scanf("%d",&n_conta);
			    printf("Digite o montante a levantar: ");
				scanf("%f",&v);
				Levantar(n_conta,v);
			    printf("\t\nOperacao realizada com sucesso\n");
				break;

			case 6:
				printf("=========Consultar Saldo da Conta=========\n");
				int cc;
				printf(" Digite o numero de conta:");
				scanf("%d",&cc);
			    printf("Saldo Actual: %.3f",consultar(cc));
				break;

			case 7:
				printf("=========Transferencia dinheiro =========\n");

				float saldo;
				int c1,c2;

				printf(" Digite o seu numero de conta:");
				scanf("%d",&c1);
				printf(" Digite o numero de conta do Destinatário:");
				scanf("%d",&c2);
			    printf("Digite o montante: ");
				scanf("%f",&saldo);
				transferir_dinheiro (c1,c2,saldo);
			    printf("\t\nOperacao realizada com sucesso\n");
				break;

			case 8:

				printf("=========Atualizar dados do cliente =========\n");

				int option;

				do {

	                 int codigo;
				     printf( "Digite o seu codigo pessoal: ");
				     scanf("%d",&codigo);
				   	 int i =Verification_ID_Cliente(codigo);
				   	 if (i==-1){

                        printf( "O seu codigo pessoal esta incorreto ");
                        break;
				    }

				    else{

						if (clientes[i].tipo_cliente==0){

							printf("\t\nCodigo:%d ",clientes[i].codigo_cliente);
							printf("Nome:%s ",clientes[i].nome);
							printf("Identificacao BI:%s",clientes[i].bi);
							printf("Telefone: %d",clientes[i].telefone);
							printf("Idade:%d ", clientes[i].idade);
							printf("Morada:%s ",clientes[i].morada);

						}
						else {

							printf("Codigo:%d ",clientes[i].codigo_cliente);
							printf("Nome Empresa:%s ",clientes[i].nome);
							printf("Identificacao NIF:%s ",clientes[i].nif);
							printf("Telefone: %d",clientes[i].telefone);
							printf("Localizacao:%s ",clientes[i].morada);
						}
							}

					 printf("\tEscolha o campo que deseja editar:\n\n\t1-Nome/Designacao\n\t2-NIF/BI\n\t3-Contacto Telefonico\n\t4-Localizacao\n\t5-Voltar ao menu \n");
					 int repete;
					 scanf("%d",&option);
					 switch (option){
					  	    case 1:

					  	    	printf("novo nome: ");
					  	    	 fflush(stdin);
					  	    	scanf("%[^\n]",clientes[i].nome);
					  	    	printf( "\tOBS: Informação Editada com sucesso com Sucesso, deseja editar mais alguma coisa? (1/0)\n");
						        scanf("%d",&repete);
					        	  switch (repete){
					        	  	case 1:
								     	option=5;
									break;
							           case 2:
							       	break;

								default:

								printf("\tDigite uma opção Valida");

								  }

					  	    		break;
					  	    case 2:
					  	    	printf(" Novo BI/NIF: ");
					  	    	fflush(stdin);
					  	    	scanf("%[^\n]",clientes[i].bi);
					  	    	printf( "\tOBS: Informação Editada com sucesso com Sucesso, deseja editar mais alguma coisa? (1/0)\n");
						        scanf("%d",&repete);
					        	  switch (repete){
					        	  	case 1:
								     	option=5;
									break;
							           case 2:
							       	break;

								default:

								printf("\tDigite uma opção Valida");

								  }
					  	      	break;

					  	    case 3:
					  	    	printf("Novo contacto: ");
					  	    	scanf("%d",&clientes[i].telefone);
					  	    		printf( "\tOBS: Informação Editada com sucesso com Sucesso, deseja editar mais alguma coisa? (1/0)\n");
						        scanf("%d",&repete);
					        	  switch (repete){
					        	  	case 1:
								     	option=5;
									break;
							           case 2:
							       	break;

								default:

								printf("\tDigite uma opção Valida");

								  }
					  	    	break;
					  	   	case 4:
					  	   		printf("Nova Localizao: ");
					  	   		scanf("%[^\n]",clientes[i].morada);
					  	   			printf( "\tOBS: Informação Editada com sucesso com Sucesso, deseja editar mais alguma coisa? (1/0)\n");
						        scanf("%d",&repete);
					        	  switch (repete){
					        	  	case 1:
								     	option=5;
									break;
							           case 2:
							       	break;

								default:

								printf("\tDigite uma opção Valida");

								  }

					  	   	case 5:

					  	   		break;
					  	   	default:
					  	   		break;

					  	   		printf("opcao invalida\n");

				         }




				}while (option!=5);


		default:

			 	break;

              }

	   } while (opcao!=9);
	   }
	   else {
          printf ("\n  Senha ou Login errado      ");
          system ("pause");
          system ("cls");
	   }
	}while (tentativas != 0 || A == false );
    printf("Programa Bloqueado !!! \nForam feitas tentativas demais\n");
	system ("pause");
	return 0;
}


void restaurar_Ficheiro(){

    backup = fopen("backupIsaf.txt", "r");
     fscanf(backup, " ");

    fclose (backup);

}

void backup_dos_dados(){
    backup = fopen("backupIsaf.txt", "w");

    fprintf(backup, " ");

    fclose (backup);

}
