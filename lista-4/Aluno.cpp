#include <iostream>

using namespace std;

class Aluno{
    string nome;
    int matricula;
    string curso;
    float nota;
    
    public:

    // constructor

        Aluno(string name, int mat, string cur,float n){
            nome = name;
            matricula = mat;
            curso = cur;
            nota = n;
        }

        string getNome(){
            return nome;
        }

        int getMatricula(){
            return matricula;
        }
        string getCurso(){
            return curso;
        }
        float getNota(){
            return nota;
        }

        void setNome(string name){
            nome = name;
        }

        void setMatricula(int mat){
            matricula = mat;
        }

        void setCurso(string cur){
            curso = cur;
        }
        void setNota(float n){
            nota = 
            n;
        }


        bool verificaAprovacao(){
            if (nota >= 6.0)
                return true;
            else
                return false;
        }




    
};

int main(){
    Aluno al1("jao", 1234, "ciencia da computacao", 7.6);
    if (al1.verificaAprovacao())
        cout << "aprovado";
    
    else
        cout << "reprovado";
}