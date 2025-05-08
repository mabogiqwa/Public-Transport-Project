#include <iostream>
#include "stack.h"
#include "passenger.h"

int main()
{
    NodePtr currentPtr = initialize_list(Passenger(1,2,'S'));
    NodePtr head = currentPtr;

    add_node(currentPtr, Passenger(2,3,'C'));
    add_node(currentPtr, Passenger(3,1,'C'));

    print(head);

    return 0;
}
