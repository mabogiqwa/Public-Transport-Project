#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>

struct Passenger
{
    int timeInstance;
    int boardingTime;
    char routeSymbol;
};

struct Node
{
    Passenger p;
    Node *link;
};
typedef Node* NodePtr;

std::vector<Passenger> store_data();

int main()
{
    std::vector<Passenger> data = store_data();

    data.pop_back(); //removes the extra entry at the back

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i].timeInstance << " " << data[i].routeSymbol << " " << data[i].boardingTime << std::endl;
    }
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
                somePassenger.timeInstance = std::stoi(doubleDigit);
            } else {
                somePassenger.timeInstance = std::stoi(std::string(1, next));
            }
        }
        if (isalpha(next)) //Checks if character is a char
        {
            if (next == 'C') { somePassenger.routeSymbol = next; }
            if (next == 'L') { somePassenger.routeSymbol = next; }
            if (next == 'S') { somePassenger.routeSymbol = next; }
        }
        if (isdigit(next)) //Stores the boarding time
        {
            somePassenger.boardingTime = std::stoi(std::string(1, next));
        }
        index++;
    }
    ins.close();

    return passengerData;
}
