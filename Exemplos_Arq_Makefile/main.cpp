#include <iostream>
#include <map>
#include <vector>
#include "Aluno.h"
#include "Disciplina.h"
#include "Funcoes.h"



int main() {
    std::map<std::string, Aluno> alunos;
    std::map<std::string, Disciplina> disciplinas;

    // Carregar alunos e disciplinas dos arquivos
    carregarDisciplinas("data/disciplinas.txt", disciplinas);
    carregarAlunos("data/alunos.txt", alunos, disciplinas);


    // Exemplo de como adicionar um novo aluno
    Aluno novoAluno("20239999", "Novo Aluno");
    alunos[novoAluno.getRGA()] = novoAluno;

    // Exemplo de como adicionar uma nova disciplina
    Disciplina novaDisciplina("CSCI999", 60);
    disciplinas[novaDisciplina.getCodigo()] = novaDisciplina;

    // Matricular o novo aluno em uma das disciplinas
    if (disciplinas.find("CSCI999") != disciplinas.end()) {
        disciplinas["CSCI999"].matricularAluno(novoAluno);
        alunos[novoAluno.getRGA()].adicionarDisciplina("CSCI999");
    }

    listarDisciplinas(disciplinas);


    // Gravar os dados de volta nos arquivos
    gravarAlunos("data/alunos.txt", alunos);
    gravarDisciplinas("data/disciplinas.txt", disciplinas);

    return 0;
}
