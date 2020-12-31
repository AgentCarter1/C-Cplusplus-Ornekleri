CXXFLAGS=	-I "./include"

basla: program1
	./bin/program1.exe
program1: calisanlarDugum.o calisanlar.o AgacDugum.o AvlAgaci.o main.o
	g++ ./lib/calisanlarDugum.o ./lib/calisanlar.o ./lib/AgacDugum.o ./lib/AvlAgaci.o ./lib/main.o -o ./bin/program1
	
calisanlarDugum.o:
	g++ $(CXXFLAGS) -c ./src/calisanlarDugum.cpp -o ./lib/calisanlarDugum.o 
calisanlar.o:
	g++ $(CXXFLAGS) -c ./src/calisanlar.cpp -o ./lib/calisanlar.o 
AgacDugum.o:
	g++ $(CXXFLAGS) -c ./src/AgacDugum.cpp -o ./lib/AgacDugum.o 
AvlAgaci.o:
	g++ $(CXXFLAGS) -c ./src/AvlAgaci.cpp -o ./lib/AvlAgaci.o 
main.o:
	g++ $(CXXFLAGS) -c ./src/main.cpp -o ./lib/main.o 





