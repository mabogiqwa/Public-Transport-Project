#include <iostream>

class Passenger
{
public:
    Passenger() : timeInstance(0), boardingTime(0), routeSymbol(' ') {}
    Passenger(int tI, int bT, char rS);
    Passenger& operator=(const Passenger& p);
    void setTimeInstance(int tI);
    void setBoardingTime(int bT);
    void setRouteSymbol(char rS);
private:
    int timeInstance;
    int boardingTime;
    char routeSymbol;
};

Passenger::Passenger(int tI, int bT, char rS)
{
    timeInstance = tI;
    boardingTime = bT;
    routeSymbol = rS;
}

//Overloading = operator to avoid sharing of memory
Passenger& Passenger::operator=(const Passenger& p)
{
    Passenger altP;

    altP.boardingTime = p.boardingTime;
    altP.timeInstance = p.timeInstance;
    altP.routeSymbol = p.routeSymbol;

    return *this;
}

void Passenger::setBoardingTime(int bT) { boardingTime = bT; }

void Passenger::setTimeInstance(int tI) { timeInstance = tI; }

void Passenger::setRouteSymbol(char rS) { routeSymbol = rS; }

struct Node
{
    Passenger passenger;
    Node *link;
};
typedef Node* NodePtr;

Node* initialize_list(Passenger p);

void add_node(NodePtr &head, Passenger p);

void pop_node(NodePtr &head);

void deallocate_list(NodePtr &head);

int main()
{
    Passenger p1(1,2,'S');
    NodePtr currentPtr, head;

    currentPtr = initialize_list(p1);
    head = currentPtr;

    add_node(currentPtr, Passenger(1,2,'C'));
    add_node(currentPtr, Passenger(2,3,'L'));
    add_node(currentPtr, Passenger(2,2,'C'));

    return 0;
}

Node* initialize_list(Passenger p)
{
    NodePtr tempPtr = new Node;
    tempPtr->passenger = p;
    tempPtr->link = nullptr;

    return tempPtr;
}

void add_node(NodePtr &head, Passenger p)
{
    NodePtr tempPtr = new Node;
    tempPtr->passenger = p;
    head->link = tempPtr;
    head = tempPtr;
    tempPtr->link = nullptr;
}

void pop_node(NodePtr &head)
{
    NodePtr tempPtr;
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
