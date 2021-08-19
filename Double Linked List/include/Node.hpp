#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;	
	Node(const int,Node *,Node*);
    ~Node();
};
#endif  