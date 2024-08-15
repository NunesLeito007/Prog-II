#include <iostream>
#include <string>

using namespace std;

class Carro{
private:
    string modelo;
    string marca;
    int ano;
    float quilometragem;
public:
    Carro (string mod, string mrc, int an, float km) : modelo(mod), marca(mrc), ano(an), quilometragem(km){};

    void dirigir(float valor){
        quilometragem = quilometragem + valor;
    }
    
    void mostrarDados(){
        cout << "Marca: " << marca << ", Modelo: " << modelo << ", Ano: "<< ano << ", Quilometragem "<< quilometragem << endl;
    }

};


int main(){
    Carro car1("Toyota","Corolla",2020,15000) ;
    car1.mostrarDados();
    car1.dirigir(500);
    car1.mostrarDados();
    return 0;
}