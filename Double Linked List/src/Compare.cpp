#include "Compare.hpp"

void Compare ::updateAdress(Node *&list1Temp, Node *&list2Temp, int repeat)
{
    for (int i = 0; i < repeat; i++)
    {
        list1Temp = list1Temp->next;
        list2Temp = list2Temp->next;
    }
}
void Compare ::changeFirstNode(Node *&list1Temp, Node *&list2Temp)
{
    Node *list1TempNext = list1Temp->next;
    list2Temp->next->prev = list1Temp;
    list1Temp->next->prev = list2Temp;
    list1Temp->next = list2Temp->next;
    list1Temp->prev = NULL;
    list2Temp->next = list1TempNext;
    list2Temp->prev = NULL;
}
void Compare ::changeMiddleNode(Node *&list1Temp, Node *&list2Temp)
{
    Node *list1TempNext = list1Temp->next;
    Node *list1TempPrev = list1Temp->prev;
    list2Temp->next->prev = list1Temp;
    list2Temp->prev->next = list1Temp;
    list1Temp->prev->next = list2Temp;
    list1Temp->next->prev = list2Temp;
    list1Temp->next = list2Temp->next;
    list1Temp->prev = list2Temp->prev;
    list2Temp->next = list1TempNext;
    list2Temp->prev = list1TempPrev;
}
void Compare ::changeLastNode(Node *&list1Temp, Node *&list2Temp)
{
    Node *list1TempPrev = list1Temp->prev;
    list2Temp->prev->next = list1Temp;
    list1Temp->prev->next = list2Temp;
    list1Temp->next = NULL;
    list1Temp->prev = list2Temp->prev;
    list2Temp->next = NULL;
    list2Temp->prev = list1TempPrev;
}
void Compare ::updateHeadAdress(Node *&list1Temp, Node *&list2Temp, DoubleLinkedList *&list1, DoubleLinkedList *&list2, int repeat)
{
    list1Temp = list1->returnHeadAdress();
    list2Temp = list2->returnHeadAdress();
    updateAdress(list1Temp, list2Temp, repeat);
}
void Compare ::printLastSituation(DoubleLinkedList *&list1, DoubleLinkedList *&list2)
{
    cout << "Sayi 1: " << *list1;
    cout << "Sayi 2: " << *list2;
}
void Compare ::changeAdress(DoubleLinkedList *&list1, DoubleLinkedList *&list2, Node *&list1Temp, Node *&list2Temp, int repeat)
{
    if (list1Temp->prev == NULL)
    {
        changeFirstNode(list1Temp, list2Temp);
        updateHeadAdress(list1Temp, list2Temp, list1, list2, repeat);
    }
    else if (list1Temp->next == NULL)
    {
        changeLastNode(list1Temp, list2Temp);
        updateHeadAdress(list1Temp, list2Temp, list1, list2, repeat);
    }
    else
    {
        changeMiddleNode(list1Temp, list2Temp);
        updateHeadAdress(list1Temp, list2Temp, list1, list2, repeat);
    }
}
void Compare ::compareNodes(DoubleLinkedList *&list1, DoubleLinkedList *&list2)
{
    Node *list1Temp = list1->returnHeadAdress();
    Node *list2Temp = list2->returnHeadAdress();
    for (int repeat = 1; repeat < list1->returnSize() + 1; repeat++)
    {
        if (list1Temp->data < list2Temp->data)
        {
            changeAdress(list1, list2, list1Temp, list2Temp, repeat);
        }
        else if (list1Temp->data > list2Temp->data)
        {
            list1->reverseList();
            updateHeadAdress(list1Temp, list2Temp, list1, list2, repeat);
        }
        else
        {
            list2->reverseList();
            updateHeadAdress(list1Temp, list2Temp, list1, list2, repeat);
        }
    }
    printLastSituation(list1, list2);
    delete list2Temp, list1Temp;
}
Compare ::~Compare() {}