VPATH	=	./src
CXXFLAGS=	-I "./include"

basla: program1 calistir

program1: cJSON.o  main.o
	gcc   ./lib/cJSON.o ./lib/main.o -o  ./bin/program1
	
cJSON.o:cJSON.c
	gcc -o ./lib/cJSON.o -c $(CXXFLAGS) $<

main.o:main.c
	gcc -o ./lib/main.o -c $(CXXFLAGS) $<
		
calistir:
	./bin/program1