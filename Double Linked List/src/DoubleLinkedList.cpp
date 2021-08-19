#include "DoubleLinkedList.hpp"

DoubleLinkedList ::DoubleLinkedList()
{
	head = NULL;
	size = 0;
}
void DoubleLinkedList ::add(const int &item)
{
	insert(size, item);
}
void DoubleLinkedList ::insert(int index, const int &item)
{
	if (index == 0)
	{
		head = new Node(item, NULL, NULL);
	}
	else
	{
		Node *prv = FindPreviousNode(index);
		prv->next = new Node(item, NULL, prv);
	}
	size++;
}
Node *DoubleLinkedList ::FindPreviousNode(int index)
{
	Node *prev = head;
	int i = 1;
	for (Node *itr = head; i != index; itr = itr->next, i++)
	{
		prev = prev->next;
	}
	return prev;
}
ostream &operator<<(ostream &screen, DoubleLinkedList &right)
{
	int index = 0;
	for (Node *itr = right.head; index < right.size; itr = itr->next, index++)
	{
		screen << itr->data;
	}
	screen << endl;
	return screen;
}

Node *&DoubleLinkedList ::returnHeadAdress()
{
	return head;
}
void DoubleLinkedList ::updateHeadAdress(Node *&adres)
{
	head = adres;
}
void DoubleLinkedList ::reverseList()
{
	Node *current = head;
	Node *prev = NULL;
	while (current != NULL)
	{
		current->prev = current->next;
		current->next = prev;
		prev = current;
		current = current->prev;
	}
	head = prev;
	head->prev = NULL;
}
bool DoubleLinkedList ::isEmpty() const
{
	return size == 0;
}
void DoubleLinkedList ::clear()
{
	while (!isEmpty())
	{
		removeAt(0);
	}
}
int DoubleLinkedList ::returnSize()
{
	return size;
}
void DoubleLinkedList ::removeAt(int index)
{
	Node *del;
	if (index == 0)
	{
		del = head;
		if (size == 1)
		{
			head = head->next = head->prev = NULL;
		}
		else
		{
			head = head->next;
			head->prev = del->prev;
			del->prev->next = head;
		}
	}
	else
	{
		Node *prv = FindPreviousNode(index);
		del = prv->next;
		prv->next = del->next;
		del->next->prev = prv;
	}
	size--;
	delete del;
}

DoubleLinkedList ::~DoubleLinkedList()
{
	clear();
}



