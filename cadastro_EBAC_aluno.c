#include <stdio.h>//Trasmitir o código para o usuário.
#include <stdlib.h>//Para alocar memoria no computador.
#include <locale.h>//Biblioteca de texto, para localização de regional de palavras por idioma.
#include <string.h>//Gerenciador e manipulador de Strings.
//Bibliotecas

int consulta()//Função para consulta de usuários.
{
	//Variáveis	
	char cpf[40];
	char conteudo[300];
	//Variáveis
	printf("+-+-+ Consultar NOMES +-+-+\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//Código reponsavel por armazenar dados escritos pelo usuário.
	
	setlocale(LC_ALL, "Portuguese");
	
	FILE *file;//Código instrutivo ao programa para abrir a função de arquivos.
	file=fopen(cpf, "r");//"r" para ler o arquivo selecionado.
	
	
	if (file == NULL)//Código responsável a indicar caso o dado inserido pelo usuário esteja incorreto.
	{
	
		printf("CPF não encontrado, tente novamente.\n");
	}
	while(fgets(conteudo, 300, file)!= NULL)//Código de repetição, enquanto o "arquivo" tiver uma variável dentro dela, ela será armazenada em outra variável.
	{
		printf("Resultado de sua pesquisa: ");
		printf("%s", conteudo);
		printf("\n");		
	}
	fclose(file);//Responsável por fechar o arquivo aberto anteriormente.
	system("pause");
}


int registrar()//Função de registro de usuário.
{
	//variáveis
	char sexo [40];
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char cargo[40];
	//variáveis
	printf("+-+-+ Cadastramento de ALUNOS +-+-+\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //função para copiar as variáveis de uma a outra.
	
	FILE *file; //criar um arquivo.
	
	
	file = fopen(arquivo, "w"); //w é uma instrução para reescrever o nome do arquivo.
	fprintf(file, cpf); //codigo para escrever dentro do arquivo...
	fclose(file); // fecha arquivo.
	
	file = fopen(arquivo, "a");//abre o arquivo, a função "a" é para atualizar os dados escritos dentro do arquivo.
	fprintf(file, " =/= CPF\n");
	fclose(file);
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " =/= NOME\n");
	fclose(file);
	
	printf("Diga o SOBRENOME a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file =fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, " =/= SOBRENOME\n");
	fclose(file);
	
	printf("Qual o Sexo do Aluno: ");
	scanf("%s", sexo);
	
	file=fopen(arquivo, "a");
	fprintf(file, sexo);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, " =/= SEXO\n");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s", cargo);
		
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file, " =/= CARGO");
	fclose(file);
	
}

int deletar()//Função responsável por deletar os arquivos.
{
	char cpf[40];
	
	FILE *file;
	file = fopen(cpf, "r");
	
	printf("+-+-+ Apagar Arquivos +-+-+\n\n");
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	if(remove(cpf)==0)
	{
		printf("Arquivo deletado com sucesso...\n");
	}
	
	else
	{
		printf("CPF não encontrado no sistema...\n");
	}
	system("pause");//Congelar a interface para o usuário.
	
}

int main()//Função matriz do programa.
{
	int rep=1;
	int opcao=1;
	
	for(rep=1;rep=1;)
	{
	
	
		setlocale(LC_ALL, "Portuguese");
		system("cls");
		
		printf("--- Biblioteca de nomes EBAC ---\n\n");
		//MENU
		printf("Qual função desejada:\n\n");
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do programa\n\n");
		
		printf("Opção: ");
		scanf("%d", &opcao);//Reponsável por armazenar os dados inseridos.
		
		system("cls");//Limpador de interface.
		
		switch(opcao)//Função de chaves para selecionar uma função instruida anteriormente no MENU.
		{
		
		case 1:
			registrar();
			break;
		case 2:
			consulta();
			break;
			
		case 3:
			deletar();
			break;
		case 4:
			printf("Fim do programa...\n");
			return 0;
			break;
	
		default:
			printf("Opção invalida, tente novamente.\n");
			system("pause");
			break;	
		}
	}
	
}
	
	

