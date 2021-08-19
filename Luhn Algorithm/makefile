VPATH	=	./src
CXXFLAGS=	-I "./include"

basla: program1 calistir

program1: Calculator.o Dosya.o Calistir.o main.o
	gcc  ./lib/Calculator.o ./lib/Dosya.o ./lib/Calistir.o ./lib/main.o -o  ./bin/program1

Calculator.o:Calculator.c
	gcc -o ./lib/Calculator.o -c $(CXXFLAGS) $<

Dosya.o:Dosya.c
	gcc -o ./lib/Dosya.o -c $(CXXFLAGS) $<

Calistir.o:Calistir.c
	gcc -o ./lib/Calistir.o -c $(CXXFLAGS) $<

main.o:main.c
	gcc -o ./lib/main.o -c $(CXXFLAGS) $<
	
	
calistir:
	./bin/program1