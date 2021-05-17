VPATH	=	./src
CXXFLAGS=	-I "./include"

basla: program1 calistir

program1: cJSON.o dosyaoku.o bankaalis.o bankasatis.o emirler.o hisseler.o portfoy.o guncelPortfoy.o main.o
	gcc   ./lib/cJSON.o ./lib/dosyaoku.o ./lib/bankaalis.o ./lib/bankasatis.o ./lib/emirler.o ./lib/hisseler.o ./lib/portfoy.o ./lib/guncelPortfoy.o ./lib/main.o -o  ./bin/program1
	
	
cJSON.o:cJSON.c
	gcc -o ./lib/cJSON.o -c $(CXXFLAGS) $<

dosyaoku.o:dosyaoku.c
	gcc -o ./lib/dosyaoku.o -c $(CXXFLAGS) $<

bankaalis.o:bankaalis.c
	gcc -o ./lib/bankaalis.o -c $(CXXFLAGS) $<

bankasatis.o:bankasatis.c
	gcc -o ./lib/bankasatis.o -c $(CXXFLAGS) $<

emirler.o:emirler.c
	gcc -o ./lib/emirler.o -c $(CXXFLAGS) $<

hisseler.o:hisseler.c
	gcc -o ./lib/hisseler.o -c $(CXXFLAGS) $<

portfoy.o:portfoy.c
	gcc -o ./lib/portfoy.o -c $(CXXFLAGS) $<  

guncelPortfoy.o:guncelPortfoy.c
	gcc -o ./lib/guncelPortfoy.o -c $(CXXFLAGS) $<

main.o:main.c
	gcc -o ./lib/main.o -c $(CXXFLAGS) $<
		
calistir:
	./bin/program1