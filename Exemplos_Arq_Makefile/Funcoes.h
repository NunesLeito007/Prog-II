#ifndef FUNCOES_H
#define FUNCOES_H

#include <map>
#include "Aluno.h"
#include "Disciplina.h"

void carregarAlunos(const std::string& nomeArquivo, std::map<std::string, Aluno>& alunos, std::map<std::string, Disciplina>& disciplinas);
void carregarDisciplinas(const std::string& nomeArquivo, std::map<std::string, Disciplina>& disciplinas);
void gravarAlunos(const std::string& nomeArquivo, const std::map<std::string, Aluno>& alunos);
void gravarDisciplinas(const std::string& nomeArquivo, const std::map<std::string, Disciplina>& disciplinas);
//void associarAlunosDisciplinas(std::map<std::string, Aluno>& alunos, std::map<std::string, Disciplina>& disciplinas);
void listarDisciplinas(const std::map<std::string, Disciplina>& disciplinas);

#endif // FUNCOES_H
