CXXFLAGS=	-I "./include"

basla: program1
	./bin/program1.exe
program1: Node.o DoubleLinkedList.o Compare.o File.o Program.o main.o
	g++ ./lib/Node.o ./lib/DoubleLinkedList.o ./lib/Compare.o ./lib/File.o ./lib/Program.o ./lib/main.o -o ./bin/program1
	
Node.o:
	g++ $(CXXFLAGS) -c ./src/Node.cpp -o ./lib/Node.o 
DoubleLinkedList.o:
	g++ $(CXXFLAGS) -c ./src/DoubleLinkedList.cpp -o ./lib/DoubleLinkedList.o 
Compare.o:
	g++ $(CXXFLAGS) -c ./src/Compare.cpp -o ./lib/Compare.o 
File.o:
	g++ $(CXXFLAGS) -c ./src/File.cpp -o ./lib/File.o 
Program.o:
	g++ $(CXXFLAGS) -c ./src/Program.cpp -o ./lib/Program.o 
main.o:
	g++ $(CXXFLAGS) -c ./src/main.cpp -o ./lib/main.o 





