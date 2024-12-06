#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de memoria
#include <locale.h> //biblioteca de alocação de texto por regiao
#include <string.h> //biblioteca responsavel por strings

void registro(){				//aba de registro de usuario

	setlocale(LC_ALL, "Portuguese"); //Definição de linguagem

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
	printf("Sucesso ao criar usuário!\n");	
	system("pause");
}

void consulta(){		//Aba de consulta
	
	setlocale(LC_ALL, "Portuguese");	 //Definição de linguagem

	char cpf[40], conteudo[200]; 	//Definicao de variaveis
	
	printf("Digite o CPF a ser consultado:");	//Coleta de dados para consulta
	scanf("%s",cpf);
	
	FILE *file;  //Funcao arquivo
	file = fopen(cpf, "r");  //Definicao abrir arquivo "cpf" funcao "read"
	 if (file == NULL) {	//Retorno se CPF for inexistente
        printf("Não foi possível encontrar o CPF digitado\n");
        system("pause");
     }
     
    while(fgets(conteudo, 200, file) != NULL){		//Coleta de dados do arquivo
    	printf("\nEssas são as informações do usuário: ");
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
    		printf("Não foi possível encontrar o CPF digitado\n");
        	system("pause");
     }
    fclose(file);
		
	if (remove(cpf) == 0) { 		//Verificacao se o arquivo foi removido
        printf("Usuário deletado com sucesso\n");
    } else {
        printf("Erro ao deletar o usuário\n");
    }
	system("pause");		
}

int main()
{
	int opcao=0; //Definição de variaveis
	char comp=-1, senha[]="a";
	setlocale(LC_ALL, "Portuguese"); //Definição de linguagem
	
	while (comp != 0) { 		//Looping para repetir a senha sem fechar o programa
        system("cls");
        printf("Digite a senha de acesso: ");
        scanf("%s", senha);     //Salva a senha digitada

        comp = strcmp(senha, "admin");   //Compara a senha digitada com a senha correta

        if (comp != 0) {   //Se a senha estiver incorreta
            printf("Senha incorreta! Tente novamente.\n");
            system("pause"); 
        }
    }
  		while (1) {
    	   	system("cls");
    	    printf("\t=========== Cartorio EBAC ===========\n\n"); // MENU INICIAL
    	    printf("\t1 - Registrar nomes\n");
    	    printf("\t2 - Consultar nomes\n");
    	    printf("\t3 - Deletar nomes\n");
    	    printf("\t4 - Sair do programa\n\n");
    	    printf("Opção: ");

	        scanf("%d", &opcao); // Leitura da variável para ser usada no switch

	        system("cls"); // Limpeza da tela

	        // INÍCIO DA SELEÇÃO:
	        switch (opcao) {
	            case 1: // Condição de registro de nomes
	                registro(); // Chama a função
   	             break;

	            case 2: // Condição de consulta de nomes
	                consulta(); // Chama a função
   		            break;

    	        case 3: // Condição de exclusão de nomes
        	        exclusao(); // Chama a função
        	        break;

    	        case 4: // Opção para sair
    	            printf("Fechando aplicação\n");
    	            return 0;

   	        	default: // Condição além do esperado
                	system("cls");
            	    printf("Esta opção não está disponível\n");
            	    system("pause");
            	    break;
        	}
    	}
	}
