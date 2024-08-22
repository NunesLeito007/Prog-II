#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

class Aluno {
private:
    std::string rga;
    std::string nome;
    std::vector<std::string> disciplinas;

public:
    // Construtor padrão
    Aluno() = default;

    // Construtor com parâmetros
    Aluno(const std::string& rga, const std::string& nome);

    // Getters
    std::string getRGA() const;
    std::string getNome() const;
    const std::vector<std::string>& getDisciplinas() const;
    void adicionarDisciplina(const std::string& codigoDisciplina);



    // Setters
    void setRGA(const std::string& rga);
    void setNome(const std::string& nome);

    // Operadores de comparação para uso em std::map
    bool operator<(const Aluno& other) const;
};

#endif // ALUNO_H
