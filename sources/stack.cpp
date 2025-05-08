#include "stack.h"
#include <iostream>

Node* initialize_list(Passenger p)
{
    NodePtr tempPtr = new Node;
    tempPtr->passenger.setTimeInstance(p.getTimeInstance());
    tempPtr->passenger.setBoardingTime(p.getBoardingTime());
    tempPtr->passenger.setRouteSymbol(p.getRouteSymbol());
    tempPtr->link = nullptr;

    return tempPtr;
}

void add_node(NodePtr &head, Passenger p)
{
    NodePtr tempPtr = new Node;
    tempPtr->passenger.setTimeInstance(p.getTimeInstance());
    tempPtr->passenger.setBoardingTime(p.getBoardingTime());
    tempPtr->passenger.setRouteSymbol(p.getRouteSymbol());
    head->link = tempPtr;
    head = tempPtr;
    tempPtr->link = nullptr;
}

void print(NodePtr &head)
{
    NodePtr tempPtr = new Node;
    for (tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        std::cout << tempPtr->passenger << std::endl << std::endl;
    }

}

void pop_front(NodePtr &actualHead)
{
    NodePtr tempPtr = new Node;

    tempPtr = actualHead;
    NodePtr newHead = actualHead->link;
    actualHead = newHead;
    tempPtr->link = nullptr;

    delete tempPtr;
}

void deallocate_list(NodePtr &head)
{
    NodePtr tempPtr = head;
    NodePtr currentNode;
    while (tempPtr != nullptr)
    {
        currentNode = tempPtr;
        tempPtr = tempPtr->link;
        delete currentNode;
    }
    head = nullptr;
}
