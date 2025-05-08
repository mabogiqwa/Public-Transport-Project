#ifndef PASSENGER_H
#define PASSENGER_H

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

#endif // PASSENGER_H
