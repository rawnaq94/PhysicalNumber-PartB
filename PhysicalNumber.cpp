// Partial realization --- Part 1

#include <iostream>
#include "PhysicalNumber.h"
#include<exception>
#include <math.h> 
using namespace std;

using namespace ariel;


          // copy constructor

    PhysicalNumber::PhysicalNumber(double number,Unit _x)
    {
         this->number=number;
         this->_x=_x;
     }

    PhysicalNumber::PhysicalNumber(const PhysicalNumber& temp)
    {
        this->number=temp.number;
        this->_x=temp._x;
    }

          // onry operator

     PhysicalNumber PhysicalNumber::operator+(){ return *this; } 
     PhysicalNumber PhysicalNumber::operator-(){ return *this; } 


          // operator (+) && operator (-)

    const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& a)
    {
         double num=number;
         return PhysicalNumber(num,_x);
    }
    
    const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& a)
    {
	 double num=number;
         return PhysicalNumber(num,_x);
     }

    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& a){ return *this; }
    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& a){ return *this; }
   

          // check equal by boolean operator 

    bool PhysicalNumber::operator== (const PhysicalNumber& n){ return false; }
    bool PhysicalNumber::operator!= (const PhysicalNumber& n){ return false; }
    bool PhysicalNumber::operator> (const PhysicalNumber& n){ return false; }
    bool PhysicalNumber::operator< (const PhysicalNumber& n){ return false; }
    bool PhysicalNumber::operator>= (const PhysicalNumber& n){ return false; }
    bool PhysicalNumber::operator<= (const PhysicalNumber& n){ return false; }
    

          // promotion and subtraction operator
    
    PhysicalNumber PhysicalNumber::operator++(){ return *this; }
    PhysicalNumber PhysicalNumber::operator--(){ return *this; }
    PhysicalNumber PhysicalNumber::operator--(int){ return *this; }
    PhysicalNumber PhysicalNumber::operator++(int)
    {
        PhysicalNumber temp(*this);
    	 return *this;
    }
    

    ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){ return os; }
    istream &ariel::operator>> (istream& is, PhysicalNumber& c){ return is; }

