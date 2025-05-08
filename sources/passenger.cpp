#include "passenger.h"
#include <iostream>

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
