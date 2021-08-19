#ifndef FILE_HPP
#define FILE_HPP
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "Node.hpp"
#include "DoubleLinkedList.hpp"
#include "Compare.hpp"
using namespace std;

class File{
private:
    string firstNumberArray,secondNumberArray;
    long long int arraySize;	
public:
    File();
    void addToList(DoubleLinkedList *&,string);
    void addToListDouble(DoubleLinkedList*&,DoubleLinkedList*&);
    void calculateArraySize();
    void readFile(DoubleLinkedList*&,DoubleLinkedList*&);
};
#endif 