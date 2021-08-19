#include "File.hpp"
    File :: File(){
        arraySize=0;
    }
    void File :: addToList(DoubleLinkedList *& list,string data){
    string tripleNumber="";
    tripleNumber += data[0];
    for (int i = 1; i < arraySize+1; i++) {       
            if (i % 3 == 0) {
                int willAddNumber = stoi(tripleNumber);
                if (willAddNumber < 100)
                    willAddNumber += 100;
                list->add(willAddNumber);
                tripleNumber = "";
            }
            tripleNumber += data[i];
        }
    }
    void File :: addToListDouble(DoubleLinkedList*&list1,DoubleLinkedList*&list2){
        addToList(list1,firstNumberArray);
        addToList(list2,secondNumberArray);
    }
    void File :: calculateArraySize(){
        while(firstNumberArray[arraySize]!='\0'){
            arraySize++;
        }
    }
    void File :: readFile(DoubleLinkedList*&list1,DoubleLinkedList*&list2){
        ifstream readFile("Deneme.txt");
        string line;
        while (getline(readFile, line)) {
		    stringstream ss(line);
		    getline(ss, firstNumberArray, '#');
		    getline(ss, secondNumberArray, '#');
	    }
        readFile.close();    
        calculateArraySize();
        addToListDouble(list1,list2);
    }