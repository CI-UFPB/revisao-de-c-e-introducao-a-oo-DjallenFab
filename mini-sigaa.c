#include <stdio.h>   // Biblioteca padrão para funções de entrada e saída
#include <stdlib.h>  // Biblioteca padrão para funções de alocação de memória, conversão de tipos, etc.
#include <string.h>

#define TAM_NOME 40  // Define o tamanho máximo do nome do aluno
#define ARG_COUNT 2  // Define o número esperado de argumentos na linha de comando

/*
 * MINI SIGAA
 * Este código é um exemplo de como implementar estruturas e funções em C 
 * para representar e manipular alunos e turmas (como um mini SIGAA).
 */

// Estrutura para representar um aluno
typedef struct {
	char nome[TAM_NOME];  // Nome do aluno
	int matricula;        // Número de matrícula do aluno
  float cra;            // Coeficiente de Rendimento Acadêmico (CRA) do aluno
} t_aluno;

// Estrutura para representar o professor
// " t_professor para representar um professor e ela deve conter informações como nome, código do
// departamento e ano de contratação"
typedef struct {
	char nome[TAM_NOME]; // Nome do professor
	int cod_departamento; // Código do departamento
	short ano_contratacao; // Ano da contratação 
} t_professor;

// Estrutura para representar uma turma
typedef struct {
	t_professor* professor; // Ponteiro para uma estrutura t_professor, representando o professor associado a turma
	t_aluno* alunos;  // Ponteiro para um array de alunos
	int tam_turma;    // Tamanho da turma (número de alunos)
	int sala;         // Número da sala de aula
} t_turma;

// Funções para t_professor
void cadastra_professor(t_professor *p) {
	printf("Digite o nome do professor >> ");
	scanf("%s", p->nome);
	printf("Digite o codigo do departamento do professor >> ");
	scanf("%d", &p->cod_departamento);
	printf("Digite o ano de contratacao do professor >> ");
	scanf("%hd%*c", &p->ano_contratacao);
}

void exibe_professor(t_professor *p) {
	printf("Nome do professor: %s\n", p->nome);
	printf("Codigo do departamento do professor: %d\n", p->cod_departamento);
	printf("Ano de contratacao do professor: %hd\n", p->ano_contratacao);
}
/*====================================================*/

// Funções para t_alunos
// Função para cadastrar um aluno
void cadastra_aluno(t_aluno *a) {
	char c;
	printf("Digite o nome do aluno: ");
	scanf("%[^\n]", a->nome);  // Lê o nome do aluno
	printf("Digite a matricula do aluno: ");
	scanf("%d", &a->matricula);  // Lê a matrícula do aluno
	printf("Digite o CRA do aluno: ");
	scanf("%f", &a->cra);  // Lê o CRA do aluno
	scanf("%c", &c); // ATS: consome o caractere '\n' remanescente
}

// Função para exibir informações de um aluno
void exibe_aluno(t_aluno *a) {
	printf("Nome: %s\n", a->nome);  // Exibe o nome do aluno
	printf("Matricula: %d\n", a->matricula);  // Exibe a matrícula do aluno
	printf("CRA: %f\n", a->cra);  // Exibe o CRA do aluno
}
/*====================================================*/

// Funções para t_turma
// Função para cadastrar uma turma
void associa_professor_turma(t_turma*, t_professor*);
float calcula_media_cra_turma(t_turma*);
void cadastra_turma(t_turma* t, int tam) {
	printf("Cadastrando turma com %d alunos...\n", tam);
	t->alunos = (t_aluno*) malloc(sizeof(t_aluno) * tam);  // Aloca memória para os alunos
	t->tam_turma = tam;  // Define o tamanho da turma
	t_professor *professor;
	associa_professor_turma(t, professor);
	cadastra_professor(&t->professor);
	for (int i = 0; i < tam; i++) {
		cadastra_aluno(&t->alunos[i]);  // Cadastra cada aluno na turma
	}
	
	printf("Digite o numero da sala: ");
	scanf("%d", &t->sala);  // Lê o número da sala de aula
}

// Função para exibir informações de uma turma
void exibe_turma(t_turma* t) {
	printf("Sala: %d\n", t->sala);  // Exibe o número da sala de aula
	exibe_professor(t->professor); // Exibe as informacoes do professor
	for (int i = 0; i < t->tam_turma; i++) {
		exibe_aluno(&t->alunos[i]);  // Exibe as informações de cada aluno na turma
	}
	float media_cra_turma = calcula_media_cra_turma(t);
	printf("CRA da turma: %f\n", media_cra_turma);

}

void associa_professor_turma(t_turma *t, t_professor *p) {
	t->professor = p;
}

float calcula_media_cra_turma(t_turma *t) {
	float total=0;
	for (int i=0; i < t->tam_turma; i++) {
		total += t->alunos[i].cra;
	}
	return total/t->tam_turma;
}
/*====================================================*/

int main(void) {
	t_turma turma1, turma2;
	t_professor rodolfo, adolfo;
	t_aluno alunos_t1[3], alunos_t2[3];

	turma1.sala = 201;
	turma1.tam_turma = 3;
	strcpy(&rodolfo.nome, "Rodolfo");
	rodolfo.ano_contratacao = 2005;
	rodolfo.cod_departamento = 3001;
	turma1.professor = &rodolfo;
	strcpy(alunos_t1[0].nome,"Pedro");
	alunos_t1[0].matricula = 1111;
	alunos_t1[0].cra = 7.8;
	strcpy(alunos_t1[1].nome,"Joao");
	alunos_t1[1].matricula = 1112;
	alunos_t1[1].cra = 8.3;
	strcpy(alunos_t1[2].nome,"Adilson");
	alunos_t1[2].matricula = 1113;
	alunos_t1[2].cra = 6.7;
	turma1.alunos = alunos_t1;
	exibe_turma(&turma1);

	puts("");

	turma2.sala = 404;
	turma2.tam_turma = 3;
	strcpy(adolfo.nome, "Adolfo");
	adolfo.ano_contratacao = 1997;
	adolfo.cod_departamento = 2074;
	turma2.professor = &adolfo;
	strcpy(alunos_t2[0].nome,"Diogenes");
	alunos_t2[0].matricula = 1122;
	alunos_t2[0].cra = 9.6;
	strcpy(alunos_t2[1].nome,"Demostenes");
	alunos_t2[1].matricula = 1124;
	alunos_t2[1].cra = 7.4;
	strcpy(alunos_t2[2].nome,"Demetrius");
	alunos_t2[2].matricula = 1130;
	alunos_t2[2].cra = 5.7;
	turma2.alunos = alunos_t2;
	exibe_turma(&turma2);
	return 0;
}

// Função principal
// Recebe o número de alunos da turma como argumento na linha de comando
// Cadastra a turma e exibe as informações dos alunos
/*
int main(int argc, char** argv) {
	t_turma turma;
	int tam_turma = 0;
	
	// Verifica se o número de argumentos passados na linha de comando é o esperado
	if (argc != ARG_COUNT) {
		printf("Use: %s <NUMERO_DE_ALUNOS>\n", argv[0]);  // Informa o uso correto do programa
		exit(0);  // Termina o programa se o número de argumentos estiver incorreto
	} else {
		tam_turma = atoi(argv[1]);  // Converte o argumento da linha de comando para inteiro
		cadastra_turma(&turma, tam_turma);  // Cadastra a turma
		exibe_turma(&turma);  // Exibe as informações da turma
	}
	printf("Media turma %.2f", calcula_media_cra_turma(&turma));
	// Libera a memória alocada para os alunos da turma
	for (int i = 0; i < tam_turma; i++) {
		free(&turma.alunos[i]);  // Libera a memória alocada para cada aluno
	}

	return 0;
}
*/