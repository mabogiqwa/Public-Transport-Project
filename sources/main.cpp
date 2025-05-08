#include <iostream>
#include <vector>
#include <fstream>
#include "stack.h"
#include "passenger.h"

std::vector<Passenger> store_data();

int main()
{
    std::vector<Passenger> data;
    NodePtr currentPtr = initialize_list(Passenger(1,2,'S'));
    NodePtr head = currentPtr;

    add_node(currentPtr, Passenger(2,3,'C'));
    add_node(currentPtr, Passenger(3,1,'C'));

    pop_front(head);

    data = store_data();

    return 0;
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
        std::cout << "The file failed to open!" << std::endl;
        exit(1);
    }

    index = 1;
    Passenger somePassenger;
    while (ins.get(next))
    {
        if (next == '\n') { //Check if we have reached the end of line
            //std::cout << somePassenger.timeInstance << " " << somePassenger.routeSymbol << " " << somePassenger.boardingTime << std::endl;
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
        if (isdigit(next)) { somePassenger.setBoardingTime(std::stoi(std::string(1, next))); }

        index++;
    }
    ins.close();

    passengerData.pop_back();

    return passengerData;
}
