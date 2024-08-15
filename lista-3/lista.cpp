/*
UFMT - ProgII
Aluno: Gabriel Nunes
*/


#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

struct Usuario {
  string nome;
  unique_ptr<int> recurso;
  vector<weak_ptr<Usuario> > dependencias;
};

vector<shared_ptr<Usuario> > usuarios;

void adicionarUsuario (const string& nome) {
  shared_ptr<Usuario> ptr = make_shared<Usuario>();
  ptr->nome = nome;
  usuarios.push_back(ptr);
  cout << "Usuario '" <<  nome <<  "' adicionado" << endl;
}

void adicionarDependencia(const string& nomeUsuario, const string& nomeDependencia) {
  int i;
  for (i = 0; i < usuarios.size(); i++){
    if(usuarios[i]->nome == nomeDependencia){
      break;
    }
  }
  weak_ptr<Usuario> ptr(usuarios[i]);
  for (i = 0; i < usuarios.size(); i++){
    if(usuarios[i]->nome == nomeUsuario){
      break;
    }
  }
  usuarios[i]->dependencias.push_back(ptr);
  cout << "Usuario '" << nomeDependencia << "' adicionado como dependencia de '" << nomeUsuario << "'" << endl;
}

void listarDependencias(const string& nomeUsuario) {
  int i;
  for (i = 0; i < usuarios.size(); i++){
    if(usuarios[i]->nome == nomeUsuario){
      break;
    }
  }

  cout << "Dependencias de '" <<  nomeUsuario <<  "':" << endl;
  for (int j = 0; j < usuarios[i]->dependencias.size(); j++){
    if(shared_ptr<Usuario> ptr = usuarios[i]->dependencias[j].lock()){
      cout << "- " << ptr->nome << endl; 
    }
  }
}

void atribuirRecursoExclusivo(const string& nomeUsuario , int valor){
  int i;
  for (i = 0; i < usuarios.size(); i++){
    if(usuarios[i]->nome == nomeUsuario){
      break;
    }
  }
  usuarios[i]->recurso = make_unique<int>(valor);
  cout << "Recurso exclusivo de '" << nomeUsuario << "' atribuido com valor: " << valor << "." << endl;
}

int main() {
  adicionarUsuario("Alice"); 
  adicionarUsuario("Bob");
  adicionarUsuario("Carol");

  adicionarDependencia("Alice", "Bob");
  adicionarDependencia("Alice", "Carol");

  atribuirRecursoExclusivo("Alice", 42);

  listarDependencias("Alice");
  listarDependencias("Bob");
  
  return 0;
}
