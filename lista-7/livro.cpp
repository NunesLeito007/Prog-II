#include "Livro.h"
#include <iostream>

using namespace std;

// Métodos da classe Livro

string Livro::getISBN() const {
    return ISBN;
}

string Livro::getTitulo() const {
    return titulo;
}

bool Livro::isDisponivel() const {
    return disponivel;
}

void Livro::emprestar() {
    if (disponivel) {
        disponivel = false;
    } else {
        cerr << "O livro já está emprestado." << endl;
    }
}

void Livro::devolver() {
    if (!disponivel) {
        disponivel = true;
    } else {
        cerr << "O livro já está disponível." << endl;
    }
}

void Livro::exibirDados() const {
    cout << "\nISBN: " << ISBN << "\nTítulo: " << titulo << "\nDisponível: "
              << (disponivel ? "Sim" : "Não") << endl;
}


