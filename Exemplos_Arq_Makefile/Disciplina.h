#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <map>
#include <string>
#include "Aluno.h"

class Disciplina {
public:
    Disciplina() = default;
    Disciplina(const std::string& codigo, int cargaHoraria)
        : codigo(codigo), cargaHoraria(cargaHoraria) {}

    std::string getCodigo() const { return codigo; }
    int getCargaHoraria() const { return cargaHoraria; }

    void matricularAluno(Aluno& aluno);
    void listarAlunos() const;
    void adicionarDisciplina(const std::string& codigo, int cargaHoraria);

private:
    std::string codigo;
    int cargaHoraria;
    std::map<std::string, Aluno> alunos; // Mapeia RGA para Aluno
};

#endif // DISCIPLINA_H
