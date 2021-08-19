#include "Program.hpp"
Program :: Program(){}
void Program :: Run(){
    DoubleLinkedList* firstLinkedList = new DoubleLinkedList();
    DoubleLinkedList* secondLinkedList = new DoubleLinkedList();
    Compare* compare = new Compare();
    File * file = new File();     
    file->readFile(firstLinkedList,secondLinkedList);    
    compare->compareNodes(firstLinkedList, secondLinkedList);    
    delete compare, firstLinkedList, secondLinkedList,file;
}
Program :: ~Program(){} 