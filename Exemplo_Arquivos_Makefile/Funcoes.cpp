#include "Funcoes.h"
#include <fstream>
#include <sstream>
#include <iostream>

void carregarAlunos(const std::string& nomeArquivo, std::map<std::string, Aluno>& alunos, std::map<std::string, Disciplina>& disciplinas) {
    std::ifstream file(nomeArquivo);
    std::string rga, nome, linha;

    if (!file) {
        std::cerr << "Não foi possível abrir o arquivo de alunos.\n";
        return;
    }

    while (std::getline(file, rga)) {
        std::getline(file, nome);
        Aluno aluno(rga, nome);

        // Ler códigos das disciplinas
        std::getline(file, linha);
        std::istringstream iss(linha);
        std::string codigoDisciplina;

        while (iss >> codigoDisciplina) {
            aluno.adicionarDisciplina(codigoDisciplina);
            if (disciplinas.find(codigoDisciplina) != disciplinas.end()) {
                disciplinas[codigoDisciplina].matricularAluno(aluno);
            }
        }

        alunos[rga] = aluno;
    }
}

void carregarDisciplinas(const std::string& nomeArquivo, std::map<std::string, Disciplina>& disciplinas) {
    std::ifstream file(nomeArquivo);
    std::string codigo;
    int cargaHoraria;

    if (!file) {
        std::cerr << "Não foi possível abrir o arquivo de disciplinas.\n";
        return;
    }

    while (std::getline(file, codigo)) {
        file >> cargaHoraria;
        file.ignore(); // Ignora o caractere de nova linha
        Disciplina disciplina(codigo, cargaHoraria);
        disciplinas[codigo] = disciplina;
    }
}

void gravarAlunos(const std::string& nomeArquivo, const std::map<std::string, Aluno>& alunos) {
    std::ofstream file(nomeArquivo);

    if (!file) {
        std::cerr << "Não foi possível abrir o arquivo de alunos para gravação.\n";
        return;
    }

    for (const auto& [rga, aluno] : alunos) {
        file << aluno.getRGA() << "\n";
        file << aluno.getNome() << "\n";
        
        // Recuperar os códigos das disciplinas associadas ao aluno
        std::string disciplinasAlunos;
        const auto& disciplinas = aluno.getDisciplinas();
        for (const auto& codigoDisciplina : disciplinas) {
            disciplinasAlunos += codigoDisciplina + " ";
        }

        // Escrever os códigos das disciplinas no arquivo
        if (!disciplinasAlunos.empty()) {
            file << disciplinasAlunos.substr(0, disciplinasAlunos.length() - 1) << "\n"; // Remove o último espaço
        } else {
            file << "\n"; // Linha em branco se não houver disciplinas
        }
    }
}

void gravarDisciplinas(const std::string& nomeArquivo, const std::map<std::string, Disciplina>& disciplinas) {
    std::ofstream file(nomeArquivo);

    if (!file) {
        std::cerr << "Não foi possível abrir o arquivo de disciplinas para gravação.\n";
        return;
    }

    for (const auto& [codigo, disciplina] : disciplinas) {
        file << disciplina.getCodigo() << "\n";
        file << disciplina.getCargaHoraria() << "\n";
    }
}


// void associarAlunosDisciplinas(std::map<std::string, Aluno>& alunos, std::map<std::string, Disciplina>& disciplinas) {
//     for (auto& [codigo, disciplina] : disciplinas) {
//         for (const auto& [rga, aluno] : alunos) {
//             disciplina.matricularAluno(aluno);
//         }
//     }
// }

void listarDisciplinas(const std::map<std::string, Disciplina>& disciplinas) {
    for (const auto& pair : disciplinas) {
        std::cout << "Código da disciplina: " << pair.second.getCodigo() << std::endl;
        pair.second.listarAlunos();
        std::cout << "-----------------------------------\n";
    }
}


