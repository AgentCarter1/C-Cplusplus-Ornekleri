#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "guncelPortfoy.h"

struct node *head = NULL;
struct node *current = NULL;

void printList()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("Hisse: %s\nMaliyet: %g\nAdet: %d\n\n", ptr->sembol, ptr->maliyet, ptr->adet);
        ptr = ptr->next;
    }
}
void insertFirst(char *sembol, double maliyet, int adet)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->sembol = sembol;
    link->maliyet = maliyet;
    link->adet = adet;
    link->next = head;
    head = link;
}

struct node *find(char *sembol)
{
    struct node *current = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (strcmp(current->sembol, sembol) != 0)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            current = current->next;
        }
    }
    return current;
}

struct node *delete (char *sembol)
{

    struct node *current = head;
    struct node *previous = NULL;
    if (head == NULL)
    {
        return NULL;
    }

    while (strcmp(current->sembol, sembol) != 0)
    {

        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (current == head)
    {
        head = head->next;
    }
    else
    {

        previous->next = current->next;
    }

    return current;
}