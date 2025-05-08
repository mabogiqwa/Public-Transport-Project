#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

class Passenger
{
public:
    Passenger() : timeInstance(0), boardingTime(0), routeSymbol(' ') {}
    Passenger& operator=(const Passenger& p);
    void setTimeInstance(int tI);
    void setBoardingTime(int bT);
    void setRouteSymbol(char rS);
    int getTimeInstance();
    int getBoardingTime();
    char getRouteSymbol();
private:
    int timeInstance;
    int boardingTime;
    char routeSymbol;
};

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

int Passenger::getBoardingTime() { return boardingTime; }

int Passenger::getTimeInstance() { return timeInstance; }

char Passenger::getRouteSymbol() { return routeSymbol; }

struct Node
{
    Passenger p;
    Node *link;
};
typedef Node* NodePtr;

std::vector<Passenger> store_data();

void print_table();

int main()
{
    std::vector<Passenger> data = store_data();

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i].getTimeInstance() << " " << data[i].getRouteSymbol() << " " << data[i].getBoardingTime() << std::endl;
    }
}

void print_table()
{
    //std::cout << "T\tnext\t\tS\tL\tC\tWQS\tWQL\t\WQC\tCS\tCL\tCC" << std::endl;
}

std::vector<Passenger> store_data()
{
    std::ifstream ins; //Declare instream object
    std::vector<Passenger> passengerData;
    char next;
    int index;

    ins.open("taxiData.txt");
    if (ins.fail())
    {
        std::cerr << "The file failed to open!";
        exit(1);
    }

    index = 1;
    Passenger somePassenger;
    while (ins.get(next))
    {
        if (next == '\n') { //Check if we have reached the end of line
            passengerData.push_back(somePassenger);
            index = 0;
        }
        if ((index == 1) && isdigit(next)) //Store the timeInstance
        {
            if (isdigit(ins.peek())) //Checks if next character is a digit
            {
                std::string doubleDigit = "";

                doubleDigit += next;
                doubleDigit += ins.peek();
                somePassenger.setTimeInstance(std::stoi(doubleDigit));
            } else {
                somePassenger.setTimeInstance(std::stoi(std::string(1, next)));
            }
        }
        if (isalpha(next)) //Checks if character is a char
        {
            if (next == 'C') { somePassenger.setRouteSymbol(next); }
            if (next == 'L') { somePassenger.setRouteSymbol(next); }
            if (next == 'S') { somePassenger.setRouteSymbol(next); }
        }
        if (isdigit(next)) //Stores the boarding time
        {
            somePassenger.setBoardingTime(std::stoi(std::string(1, next)));
        }
        index++;
    }
    ins.close();

    passengerData.pop_back(); //removes the extra entry at the back

    return passengerData;
}
