#include <iostream>
#include <string>

using namespace std;

class ContaBancaria{
private:
    string conta;
    double saldo;
    string nome;

public:
    
    ContaBancaria(string cnt, double prc, string nm) : conta(cnt), saldo(prc), nome(nm) {};

    void setNome(string nm) {
        nome = nm;
    }

    string getNome() const {
        return nome;
    }

    void setSaldo(double prc) {
        saldo = prc;
    }

    double getSaldo() const {
        return saldo;
    }

    void setnome(string nm) {
        nome = nm;
    }

    void depositar(int valor) {
        saldo = saldo + valor;
    }

    void sacar(int quantidade) {
        if (saldo < quantidade) {
            cout << "Erro: Quantidade a ser sacada maior que a quantidade em caixa." << endl;
        } else {
            saldo = saldo - quantidade;
        }
    }

    void mostrarDados() const {
        cout << "Conta: " << conta << endl;
        cout << "Titular: " << nome << endl;
        cout << "Saldo: R$:" << saldo << endl;
    }
};


int main(){
    ContaBancaria c1 ("12345-6", 1000.0, "Joao Silva");
    c1.mostrarDados();
    c1.depositar(500.0);
    c1.sacar(300.0);
    c1.mostrarDados();
    return 0;   
}