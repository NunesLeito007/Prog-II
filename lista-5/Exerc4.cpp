#include <iostream>
#include <vector>
#include <string>

using namespace std;

// classe base midia
class Midia {
public:
    
    Midia(const string& titulo) : titulo(titulo) {}

    // metodos virtuais
    virtual void exibirInfo() const = 0;
    virtual void reproduzir() const = 0;

    virtual ~Midia() = default; // Destruidor virtual para garantir a correta destruição de objetos derivados

protected:
    string titulo;
};

// derivada Livro
class Livro : public Midia {
public:
    Livro(const string& titulo, const string& autor) : Midia(titulo), autor(autor) {}

    void exibirInfo() const override {
        cout << "Livro: " << titulo << endl;
        cout << "Autor: " << autor << endl;
    }

    void reproduzir() const override {
        cout << "Não é possível reproduzir um livro." << endl;
    }

private:
    string autor;
};

// derivada CD
class CD : public Midia {
public:
    CD(const string& titulo, const string& artista) : Midia(titulo), artista(artista) {}

    void exibirInfo() const override {
        cout << "CD: " << titulo << endl;
        cout << "Artista: " << artista << endl;
    }

    void reproduzir() const override {
        cout << "Reproduzindo CD: " << titulo << " por " << artista << endl;
    }

private:
    string artista;
};

// derivada DVD
class DVD : public Midia {
public:
    DVD(const string& titulo, const string& diretor) : Midia(titulo), diretor(diretor) {}

    void exibirInfo() const override {
        cout << "DVD: " << titulo << endl;
        cout << "Diretor: " << diretor << endl;
    }

    void reproduzir() const override {
        cout << "Reproduzindo DVD: " << titulo << " dirigido por " << diretor << endl;
    }

private:
    string diretor;
};

int main() {
    // criando um vetor de ponteiros Midia
    vector<Midia*> midias;

    // adicionando classes derivadas ao vetor
    midias.push_back(new Livro("Harry Potter", "Joanne Jo Rowling"));
    midias.push_back(new CD("Boate Azul", "Leonardo"));
    midias.push_back(new DVD("Shrek", "Dream Works"));

    // percorrendo o vetor e chamando os métodos
    for (const auto& midia : midias) {
        midia->exibirInfo();
        midia->reproduzir();
        cout << endl;
    }

    // liberando a memória
    for (auto& midia : midias) {
        delete midia;
    }

    return 0;
}
