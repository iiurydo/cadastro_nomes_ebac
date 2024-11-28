#include <stdio.h>//Trasmitir o c�digo para o usu�rio.
#include <stdlib.h>//Para alocar memoria no computador.
#include <locale.h>//Biblioteca de texto, para localiza��o de regional de palavras por idioma.
#include <string.h>//Gerenciador e manipulador de Strings.
//Bibliotecas

int consulta()//Fun��o para consulta de usu�rios.
{
	//Vari�veis	
	char cpf[40];
	char conteudo[300];
	//Vari�veis
	printf("+-+-+ Consultar NOMES +-+-+\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//C�digo reponsavel por armazenar dados escritos pelo usu�rio.
	
	setlocale(LC_ALL, "Portuguese");
	
	FILE *file;//C�digo instrutivo ao programa para abrir a fun��o de arquivos.
	file=fopen(cpf, "r");//"r" para ler o arquivo selecionado.
	
	
	if (file == NULL)//C�digo respons�vel a indicar caso o dado inserido pelo usu�rio esteja incorreto.
	{
	
		printf("CPF n�o encontrado, tente novamente.\n");
	}
	while(fgets(conteudo, 300, file)!= NULL)//C�digo de repeti��o, enquanto o "arquivo" tiver uma vari�vel dentro dela, ela ser� armazenada em outra vari�vel.
	{
		printf("Resultado de sua pesquisa: ");
		printf("%s", conteudo);
		printf("\n");		
	}
	fclose(file);//Respons�vel por fechar o arquivo aberto anteriormente.
	system("pause");
}


int registrar()//Fun��o de registro de usu�rio.
{
	//vari�veis
	char sexo [40];
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char cargo[40];
	//vari�veis
	printf("+-+-+ Cadastramento de ALUNOS +-+-+\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //fun��o para copiar as vari�veis de uma a outra.
	
	FILE *file; //criar um arquivo.
	
	
	file = fopen(arquivo, "w"); //w � uma instru��o para reescrever o nome do arquivo.
	fprintf(file, cpf); //codigo para escrever dentro do arquivo...
	fclose(file); // fecha arquivo.
	
	file = fopen(arquivo, "a");//abre o arquivo, a fun��o "a" � para atualizar os dados escritos dentro do arquivo.
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

int deletar()//Fun��o respons�vel por deletar os arquivos.
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
		printf("CPF n�o encontrado no sistema...\n");
	}
	system("pause");//Congelar a interface para o usu�rio.
	
}

int main()//Fun��o matriz do programa.
{
	int rep=1;
	int opcao=1;
	
	for(rep=1;rep=1;)
	{
	
	
		setlocale(LC_ALL, "Portuguese");
		system("cls");
		
		printf("--- Biblioteca de nomes EBAC ---\n\n");
		//MENU
		printf("Qual fun��o desejada:\n\n");
		printf("\t1 - Cadastrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do programa\n\n");
		
		printf("Op��o: ");
		scanf("%d", &opcao);//Repons�vel por armazenar os dados inseridos.
		
		system("cls");//Limpador de interface.
		
		switch(opcao)//Fun��o de chaves para selecionar uma fun��o instruida anteriormente no MENU.
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
			printf("Op��o invalida, tente novamente.\n");
			system("pause");
			break;	
		}
	}
	
}
	
	

