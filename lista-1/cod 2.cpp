#include <iostream>
#include <string>

using std::string;
using namespace std;

void reset(int *ip){
    *ip = 1;
  
};

void incrementa(int *ip){
    (*ip)++;
};

void dobra(int *ip){
    *ip = (*ip)*2;
};

int main(){
    int perd1, perd2, perd3, Cwing = 1;
    cout << "Entrada:\n";
    cout << "Informe os instantes em tempo onde ocorrerão as perdas: \n";
    cin >> perd1 >> perd2 >> perd3;
    cout << "Saída:\n";
    cout<<"Seg";
    cout<<"|";
    cout<<"Cwin\n";
    for(int i = 0; i < 100; ++i){
        cout<<i;
        cout<<"|";
        if(i == perd1 || i == perd2 || i == perd3){
            reset(&Cwing);
            cout<<"perda\n";
        }else{
            cout<<Cwing<<endl;
        }
        if(Cwing < 6){
            incrementa(&Cwing);
        } else if (Cwing < 50){
            dobra(&Cwing);
        } 
       
    }
}