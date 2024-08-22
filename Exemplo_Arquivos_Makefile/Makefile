# Variáveis de compilador e flags
CXX = g++
CXXFLAGS = #-std=c++11 -Wall

# Diretivas de arquivos
TARGET = main
OBJECTS = main.o Aluno.o Disciplina.o Funcoes.o
HEADERS = Aluno.h Disciplina.h Funcoes.h

# Regra padrão
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regras para gerar arquivos .o a partir dos .cpp
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

Aluno.o: Aluno.cpp Aluno.h
	$(CXX) $(CXXFLAGS) -c Aluno.cpp

Disciplina.o: Disciplina.cpp Disciplina.h
	$(CXX) $(CXXFLAGS) -c Disciplina.cpp

Funcoes.o: Funcoes.cpp Funcoes.h
	$(CXX) $(CXXFLAGS) -c Funcoes.cpp

# Limpeza dos arquivos temporários
clean:
	rm -f $(TARGET) $(OBJECTS)

# Limpeza total, incluindo os arquivos de backup
cleanall: clean
	rm -f *~
