#include "Disciplina.h"
#include <iostream>

void Disciplina::matricularAluno(Aluno& aluno) {
    alunos[aluno.getRGA()] = aluno;
}

void Disciplina::listarAlunos() const {
    if (alunos.empty()) {
        std::cout << "Nenhum aluno matriculado.\n";
        return;
    }

    for (const auto& [rga, aluno] : alunos) {
        std::cout << "RGA: " << aluno.getRGA() << "\n";
        std::cout << "Nome: " << aluno.getNome() << "\n";
        std::cout << "--------------------\n";
    }
}

void Disciplina::adicionarDisciplina(const std::string& codigo, int cargaHoraria) {
    this->codigo = codigo;
    this->cargaHoraria = cargaHoraria;
}
