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
        set_nome(n);
        set_idade(i);
    }

    void set_nome(char* n) {
        nome = (char*) malloc(sizeof(char)*strlen(n));
        strcpy(nome, n);
    }

    void set_idade(unsigned short i) {idade = i;}

    char* get_nome() {return nome;}
    unsigned short get_idade() {return idade;}
};

class aluno: public pessoa { 
    unsigned short matricula;
    float cra;

    public:
    aluno(char* n, unsigned short i,
    unsigned short mat, float _cra
    ) : pessoa(n, i) {
        set_matricula(mat);
        set_cra(_cra);
    }

    void set_matricula(unsigned short mat) {matricula = mat;}
    void set_cra(float _cra) {cra = _cra;}

    void mostrar_infos() {
        cout << "Nome: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Matricula: " << get_matricula() << endl;
        cout << "CRA: " << get_cra() << endl;
    }

    unsigned short get_matricula() {return matricula;}
    float get_cra() {return cra;}
};

class professor: public pessoa {
    unsigned short cod_departemento;
    unsigned short ano_contratacao;

    public:
    professor(char* n, unsigned short i,
    unsigned short cod, unsigned short ano
    ) : pessoa(n, i) {
        set_cod_departamento(cod);
        set_ano_contratacao(ano);
    }

    void set_cod_departamento(unsigned short cod) {cod_departemento = cod;}
    void set_ano_contratacao(unsigned short ano){ano_contratacao = ano;}

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

    void mostrar_infos() {
            cout << "Sala: " << sala << endl;
            cout << "Qtd. de alunos: " << tam_turma << endl;
            cout << "Infos. dos alunos: " << endl;
            for (int i = 0; i < tam_turma; i++) {
                alunos[i].mostrar_infos();
            }
        }
};


int main(void) {
    turma t1(3, 102);
    t1.mostrar_infos();
    return 0;
}
