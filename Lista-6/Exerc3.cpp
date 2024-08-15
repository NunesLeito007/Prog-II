#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


class Forma{
    private:
        double a;
    public:

        double getArea(){return a;}
        virtual double area() = 0;
};

class Triangulo : public Forma{
    private:
        int base, altura;
    public:
        Triangulo(double b, double a){
            base = b;
            altura = a;
        }
        int getBase(){return base;}
        void setBase(int b){base = b;}
        int getAltura(){return altura;}
        int setAltura(int alt){altura = alt;}

        double area(){
            return (base * altura) / 2.0;
        }

};
class Retangulo : public Forma{
    private:
        double base, altura;
    public:
        Retangulo(double b, double a){
            base = b;
            altura = a;
        }
        double getBase(){return base;}
        void setBase(double b){base = b;}
        double getAltura(){return altura;}
        void setAltura(double alt){altura = alt;}

        double area(){
            return base * altura;
        }

};
class Circulo : public Forma{
    private:
        double Raio;
    public:
        Circulo(int r){
            Raio = r;
        }
        double getRaio(){return Raio;}
        void setRaio(double r){Raio = r;}

        double area(){
            return (M_PI * Raio * Raio);
;
        }

};


int main () {
    vector<Forma*>formas;
    formas.push_back(new Circulo(5.0));
    formas.push_back(new Retangulo(4.0 , 6.0));
    formas.push_back(new Triangulo(4.0, 5.0));
    for ( Forma * forma : formas ) {
        cout << " Area : " << forma->area () << endl ;
    }
    for ( Forma * forma : formas ) {
        delete forma;
    }
return 0;
}