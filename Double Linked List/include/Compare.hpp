#ifndef COMPARE_HPP
#define COMPARE_HPP
#include<iostream>
#include "Node.hpp"
#include "DoubleLinkedList.hpp"
using namespace std;

class Compare {
public:       
    void updateAdress(Node*&, Node*&, int);
    void changeFirstNode(Node*&, Node*&);
    void changeMiddleNode(Node*&, Node*&);
    void changeLastNode(Node*&, Node*&);
    void updateHeadAdress(Node*&, Node*&, DoubleLinkedList*&,DoubleLinkedList*&,int);
    void printLastSituation(DoubleLinkedList*&, DoubleLinkedList*&);
    void compareNodes(DoubleLinkedList*&, DoubleLinkedList*&);
    void changeAdress(DoubleLinkedList*&, DoubleLinkedList*&,Node*&,Node*&,int);
	~Compare();
};


#endif