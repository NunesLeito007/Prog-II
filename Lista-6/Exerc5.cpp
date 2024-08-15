#include <iostream>
#include <vector>


class Transporte {
public:
    virtual void iniciar(){};  
    virtual void parar(){};    
};

class Carro : public Transporte {
public:
    void iniciar() override {std::cout << "Carro iniciando" << std::endl;}
    void parar() override {std::cout << "Carro parando" << std::endl;}
};

class Bicicleta : public Transporte {
public:
    void iniciar() override {std::cout << "Bicicleta iniciando" << std::endl;}
    void parar() override {std::cout << "Bicicleta parando" << std::endl;}
};

class Aviao : public Transporte {
public:
    void iniciar() override {std::cout << "Avião decolando" << std::endl;}
    void parar() override {std::cout << "Avião pousando" << std::endl;}
};

int main() {
    
    std::vector<Transporte*> transportes;
    
    transportes.push_back(new Carro());
    transportes.push_back(new Bicicleta());
    transportes.push_back(new Aviao());
    
    for (Transporte* transporte : transportes) {
        transporte->iniciar();
        transporte->parar();
    }
    return 0;
}