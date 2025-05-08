#include <iostream>

class Passenger
{
public:
    Passenger() : timeInstance(0), boardingTime(0), routeSymbol(' ') {}
    Passenger(int tI, int bT, char rS);
    Passenger& operator=(const Passenger& p);
    friend std::ostream& operator<<(std::ostream& out, const Passenger& p);
    void setTimeInstance(int tI);
    void setBoardingTime(int bT);
    void setRouteSymbol(char rS);
    int getTimeInstance() const;
    int getBoardingTime() const;
    char getRouteSymbol() const;
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

std::ostream& operator<<(std::ostream& out, const Passenger& p)
{
    out << "Time instance: " << p.getTimeInstance() << "\nBoarding Time: " << p.getBoardingTime() << "\nRoute symbol: " << p.getRouteSymbol();

    return out;
}

void Passenger::setBoardingTime(int bT) { boardingTime = bT; }

void Passenger::setTimeInstance(int tI) { timeInstance = tI; }

void Passenger::setRouteSymbol(char rS) { routeSymbol = rS; }

int Passenger::getBoardingTime() const { return boardingTime; }

int Passenger::getTimeInstance() const { return timeInstance; }

char Passenger::getRouteSymbol() const { return routeSymbol; }

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

int main()
{
    Passenger p1(1,2,'S');
    NodePtr currentPtr = new Node;
    NodePtr head;

    currentPtr = initialize_list(p1);
    head = currentPtr;

    add_node(currentPtr, Passenger(2,3,'C'));
    add_node(currentPtr, Passenger(3,1,'C'));

    pop_front(head);

    //std::cout << head->passenger;

    print(head);

    return 0;
}

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
