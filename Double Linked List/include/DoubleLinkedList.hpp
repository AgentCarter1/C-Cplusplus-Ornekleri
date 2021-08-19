#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include<iostream>
#include "Node.hpp"
using namespace std;
class DoubleLinkedList{
	private:
		Node *head;
		int size;		
		Node* FindPreviousNode(int);
        void insert(int,const int&);
	public:
		DoubleLinkedList();
		void add(const int&);					
		friend ostream& operator<<(ostream&,DoubleLinkedList&);
        Node*& returnHeadAdress();
        void updateHeadAdress(Node*&);
        void reverseList();
		bool isEmpty()const;
		int returnSize();
		void removeAt(int);
		void clear();
		~DoubleLinkedList();
}; 
#endif

