#include "Aluno.h"

// Construtor com parâmetros
Aluno::Aluno(const std::string& rga, const std::string& nome) : rga(rga), nome(nome) {}

// Getters
std::string Aluno::getRGA() const {
    return rga;
}

std::string Aluno::getNome() const {
    return nome;
}

// Setters
void Aluno::setRGA(const std::string& rga) {
    this->rga = rga;
}

void Aluno::setNome(const std::string& nome) {
    this->nome = nome;
}

// Operadores de comparação
bool Aluno::operator<(const Aluno& other) const {
    return rga < other.rga;
}

const std::vector<std::string>& Aluno::getDisciplinas() const {
    return disciplinas;
}

void Aluno::adicionarDisciplina(const std::string& codigoDisciplina) {
    disciplinas.push_back(codigoDisciplina);
}
