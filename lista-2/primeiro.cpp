/*
UFMT - ProgII
Aluno: Gabriel Nunes
*/


#include <iostream>

using namespace std;

struct Servidor {
  string nome;
  int peso;
  int numSolicitacoes = 0;
};

void printStatus(int numeroServidores, Servidor servidores[]) {
  for (int i = 0; i < numeroServidores; i++) {
    cout << "numSolicitacoes: " << endl;
    cout << servidores[i].numSolicitacoes << endl;
  }
}

void roundRobin(int requisicoes, int numeroServidores, Servidor servidores[]) {
  for (int i = 0; i < requisicoes; i++) {
    servidores[i % numeroServidores].numSolicitacoes += 1;
  }
}

void weightedRoundRobin(int requisicoes, int numeroServidores,
                        Servidor servidores[]) {
  for (int i = 0;; i++) {
    int acc = 0;
    for (int j = 0;; j++) {
      acc += 1;
      servidores[i % numeroServidores].numSolicitacoes += 1;
      requisicoes--;
      if (requisicoes == 0) {
        break;
      }
      if (servidores[i % numeroServidores].peso == acc) {
        break;
      }
    }
    if (requisicoes == 0) {
      break;
    }
  }
}

void randomRobin(int requisicoes, int numeroServidores, Servidor servidores[]) {
  for (int i = 0; i < requisicoes; i++) {
    int randomNum = rand() % (numeroServidores + 1);
    servidores[randomNum].numSolicitacoes += 1;
  }
}

void zerarServidores(int numeroServidores, Servidor servidores[]) {
  for (int i = 0; i < numeroServidores; i++) {
    servidores[i].numSolicitacoes = 0;
  }
}

int main() {
  int numeroServidores, peso, requisicoes;

  cout << "Numero de servidores: " << endl;
  cin >> numeroServidores;

  Servidor servidores[numeroServidores];

  for (int i = 0; i < numeroServidores; i++) {
    cout << "Peso do servidor: " << endl;
    cin >> peso;
    servidores[i].peso = peso;
  }

  cout << "Numero de requisicoes: " << endl;
  cin >> requisicoes;

  roundRobin(requisicoes, numeroServidores, servidores);
  printStatus(numeroServidores, servidores);
  zerarServidores(numeroServidores, servidores);

  weightedRoundRobin(requisicoes, numeroServidores, servidores);
  printStatus(numeroServidores, servidores);
  zerarServidores(numeroServidores, servidores);

  randomRobin(requisicoes, numeroServidores, servidores);
  printStatus(numeroServidores, servidores);
  zerarServidores(numeroServidores, servidores);
}
