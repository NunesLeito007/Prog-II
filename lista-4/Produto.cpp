#include <iostream>
#include <string>

using namespace std;

class Produto {
private:
    string nome;
    double preco;
    int quantidade;

public:
    
    Produto(string nm, double prc, int quant) : nome(nm), preco(prc), quantidade(quant) {}

    void setNome(string nm) {
        nome = nm;
    }

    string getNome() const {
        return nome;
    }

    void setPreco(double prc) {
        preco = prc;
    }

    double getPreco() const {
        return preco;
    }

    void setQuantidade(int quant) {
        quantidade = quant;
    }

    int getQuantidade() const {
        return quantidade;
    }

   
    void adicionarEstoque(int quantidade) {
        this->quantidade += quantidade;
    }

    void removerEstoque(int quantidade) {
        if (quantidade > this->quantidade) {
            cout << "Erro: Quantidade a ser removida maior que a quantidade em estoque." << endl;
        } else {
            this->quantidade -= quantidade;
        }
    }


    void mostrarDados() const {
        cout << "Nome: " << nome << endl;
        cout << "Preço: R$ " << preco << endl;
        cout << "Quantidade em estoque: " << quantidade << endl;
    }
};

int main() {
    
    Produto p1("Notebook", 2500.0, 10);

    p1.mostrarDados();
    p1.adicionarEstoque(5);
    p1.removerEstoque(3);
    p1.mostrarDados();

    return 0;
}
