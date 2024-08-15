/*
UFMT - ProgII
Aluno: Gabriel Nunes
*/


#include <iostream>
using namespace std;

int main() {
  string palavra, aux = "";
  cin >> palavra;

  for (int i = 0; i < palavra.length(); i++) {
    aux = palavra[i] + aux;
  }

  if (palavra == aux) {
    cout << "eh palindromo" << endl;
  } else {
    cout << "nao eh palindromo" << endl;
  }
}
