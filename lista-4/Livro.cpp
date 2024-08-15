#include <iostream>

using namespace std;

class Livro{
    private:
        string titulo;
        string autor;
        int anoPublicacao;
        int numPaginas;

    public:
        string getTitulo()
        {
            return titulo;
        }

    
        void setTitulo(string titulo)
        {
            titulo = titulo;
        }

    
        string getAutor()
        {
            return autor;
        }

    
        void setAutor(string autor)
        {
         autor = autor;
        }

    
        int getAnoPublicacao()
        {
            return anoPublicacao;
        }

    
        void setAnoPublicacao(int anoPublicacao)
        {
         anoPublicacao = anoPublicacao;
        }

    
        int getNumPaginas()
        {
            return numPaginas;
        }

    
        void setNumPaginas(int numPaginas)
        {
         numPaginas = numPaginas;
        }

     

    // constructor
    Livro(string title, string author, int publiYear, int pag){
        titulo = title;
        autor = author;
        anoPublicacao = publiYear;
        numPaginas = pag;
    }

    void mostrarDados(){
        cout << "o livro " << titulo << " foi escrito por "
         << autor << "  e publicado em " << anoPublicacao
          << " e possui" << numPaginas << " paginas " << endl;    }


};
int main(){ 
    Livro l1("o pequeno principe","fulano", 1990, 100);
    l1.mostrarDados();
}
