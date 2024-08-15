#include <iostream>

using namespace std;
int main(){
    
    string senha;  
    int cont = 0;    
    bool letra_maiuscula = false, letra_minuscula = false, caracter_especial = false;   
    bool validacao = false;
    

    while(!validacao){
        
        cout << "insira uma senha valida que contenha as seguintes especificações\n\n• Pelo menos dois numeros\n• Pelo menos um caractere especial, como @, #, %, &, $\n• Pelo menos uma letra maiuscula\n• Pelo menos uma letra minuscula\n\nSenha: ";
        cin >> senha;
        for(auto c : senha){
            
            if (isdigit(c)){
                cont++;
            }
            
            if (islower(c)){
                letra_minuscula = true;
            }
            
            if (isupper(c)){
                letra_maiuscula = true;
            }
            
            if (ispunct(c)){
                caracter_especial = true;
            }
        }
        
        if ((cont >= 2) && letra_maiuscula && letra_minuscula && caracter_especial){
            cout << "!!Senha Valida!! =)\n";
            validacao = true;
        }
        
        else{
            cout << "!!Senha Invalida!! =,(\nTente Novamente\n\n";
            
            if (cont < 2)
                cout << "Quantidade de numeros faltando é: " << 2 - cont << "\n";
            
            if (!letra_minuscula)
                cout << "Falta algumas letras minusculas\n";
            
            if (!letra_maiuscula)
                cout << "Falta também letras maiusculas\n";
            
            if (!caracter_especial)
                cout << "Cade o caracter especial?\n\n";
        }
    }
}