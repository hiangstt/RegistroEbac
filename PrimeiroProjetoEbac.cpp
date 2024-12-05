#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regiao
#include <string.h> //biblioteca responsavel por strings

void registro(){				//aba de registro de usuario

	setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem

	char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];		//variaveis

	printf("CPF a ser cadastrado: ");
	scanf("%s", cpf);		//Coleta de dados a ser cadastrado
	
	strcpy(arquivo, cpf);		//copiar o valor da string
	
	FILE *file;				//cria o arquivo banco de dados
	file = fopen(arquivo, "w");		//funcao "WRITE" para criar o arquivo
		fprintf(file,cpf);			//escreve o que estiver na variavel dentro do arquivo
		fprintf(file, "|");
	fclose(file);			//fecha o arquivo salvo
	
	printf("Digite o NOME a ser cadastrado: "); 		//COLETA DE DADOS
	 scanf("%s", nome);	
	 file = fopen(arquivo, "a");
		fprintf(file,nome);
		fprintf(file, "|");
	 fclose(file);
	 	
	printf("Digite o SOBRENOME a ser cadastrado: ");		//COLETA DE DADOS
	 scanf("%s", sobrenome);	
	 file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fprintf(file, "|");
	fclose(file);
		
	printf("Digite o CARGO a ser cadastrado: ");		//COLETA DE DADOS
	 scanf(" %[^\n]", cargo);	
	 file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fprintf(file, "|");
	fclose(file);
	printf("Sucesso ao criar usuario!\n");	
	system("pause");
}

void consulta(){		//Aba de consulta
	
	setlocale(LC_ALL, "Portuguese");	 //Defini��o de linguagem

	char cpf[40], conteudo[200]; 	//Definicao de variaveis
	
	printf("Digite o CPF a ser consultado:");	//Coleta de dados para consulta
	scanf("%s",cpf);
	
	FILE *file;  //Funcao arquivo
	file = fopen(cpf, "r");  //Definicao abrir arquivo "cpf" funcao "read"
	 if (file == NULL) {	//Retorno se CPF for inexistente
        printf("N�o foi poss�vel encontrar o CPF digitado\n");
        system("pause");
     }
     
    while(fgets(conteudo, 200, file) != NULL){		//Coleta de dados do arquivo
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);		//Exibicao do conteudo na tela //%s string
    	printf("\n\n");
    	system("pause");
	}
	fclose(file);	
}

void exclusao(){		//Aba 
	
	char cpf[40]; //Declaracao de variaveis
	
	printf("Digite o CPF a ser deletado: "); //Coleta de dados
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
		if (file == NULL) {
    		printf("N�o foi poss�vel encontrar o CPF digitado\n");
        	system("pause");
     }
    fclose(file);
		
	if (remove(cpf) == 0) { 		//Verificacao se o arquivo foi removido
        printf("Usu�rio deletado com sucesso\n");
    } else {
        printf("Erro ao deletar o usu�rio\n");
    }
	system("pause");		
}

int main()
{
	int opcao=0; //Defini��o de variaveis
	int repeticao=1;
	
	setlocale(LC_ALL, "Portuguese"); //Defini��o de linguagem
		
	for(repeticao=1;repeticao=1;)
	{
	    system("cls");
   	    printf("\t=========== Cartorio EBAC ===========\n\n");//MENU INICIAL
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do programa\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); //Leitura da variavel para ser usada no if
	
    	system("cls"); // limpeza da tela
    
    	//INICIO DA SELE��O:
    	switch(opcao){
    		
    		case 1:    //condi��o de registro de nomes
    		    registro();		//Chama a funcao
    		break;
					
			case 2:	//condicao de consulta de nomes
			    consulta();		//Chama a funcao
			break;
			  	
			case 3:	//condicao de exclusao de nomes
			    exclusao();		//Chama a funcao
	   		break;

			case 4:	//condicao de exclusao de nomes
			    printf("Fechando aplica��o");
			    return 0;
	   		break;

			default:	//condicao alem do esperado
			    system("cls");
				printf("Esta op��o n�o esta dispon�vel\n");
				system("pause");
			break;
		}
 	}
}
