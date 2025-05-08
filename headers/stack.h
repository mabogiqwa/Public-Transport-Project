#ifndef STACK_H
#define STACK_H

#include "passenger.h"

struct Node
{
    Passenger passenger;
    Node *link;
};
typedef Node* NodePtr;

Node* initialize_list(Passenger p);

void add_node(NodePtr &head, Passenger p);

void pop_node(NodePtr &head);

void pop_front(NodePtr &actualHead);

void deallocate_list(NodePtr &head);

void print(NodePtr &head);

#endif

