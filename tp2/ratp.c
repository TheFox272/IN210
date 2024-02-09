#include "age.h"
static const float Price = 1.2;

float computePrice(int age, int tourist)
{
    int limitAge;
    recupAge(&limitAge);
    if (age>limitAge)
    {
        if (tourist)
            return Price*2;
        return Price;
    }
    else 
    {
        if (tourist)
            return Price;
        return Price/2;
    }
}
