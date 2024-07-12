#include <iostream>
#include <strings.h>
using namespace std;

// classe que representa uma pessoa, foi feita para reuso de codigo
// ja que a funcao construtora é minimamente 'complexa'
class pessoa {
    char *nome; // ponteiro para poder guardar o nome dinamicamente
    unsigned short idade; // usando variaveis short ja que ninguem vai ter uma idade exorbitante e unsigned pois nao existe idade negativa
    
    public:
    pessoa (char* n, unsigned short i) {
        nome = (char*) malloc(sizeof(char)*strlen(n));
        strcpy(nome, n);
        idade = i;
    }

    char* get_nome() {return nome;}
    unsigned short get_idade() {return idade;}
};

class aluno: public pessoa { 
    unsigned short matricula;
    float cra;

    public:
    aluno(char* n, unsigned short i, unsigned short mat, float _cra) : pessoa(n, i) {
        matricula = mat;
        cra = _cra;
    }

    unsigned short get_matricula() {return matricula;}
    float get_cra() {return cra;}
};

class professor: public pessoa {
    unsigned short cod_departemento;
    unsigned short ano_contratacao;

    public:
    professor(char* n, unsigned short i, unsigned short cod, unsigned short ano) : pessoa(n, i) {
        cod_departemento = cod;
        ano_contratacao = ano;
    }

    unsigned short get_cod_departamento() {return cod_departemento;}
    unsigned short get_ano_contratacao() {return ano_contratacao;}
};

class turma {
    // ainda nao sei como representar a classe turma
    // mas, levando em consideracao o codigo em C, alunos é um ponteiro para alocacao dinamica
    // mas professor, se nao for ponteiro, pede as informacoes para a funcao construtora, irei manter como ponteiro por enquanto
    aluno *alunos;
    professor *prof;
    unsigned short tam_turma;
    unsigned short sala;

    public:
    turma(unsigned short tam, unsigned short s) {
        tam_turma = tam;
        sala = s;

    }
    unsigned short get_sala() {return sala;}
};


int main(void) {
    aluno a1("Djallen", 18, 1212, 8);

    cout << a1.get_matricula() << endl;
    return 0;
}
