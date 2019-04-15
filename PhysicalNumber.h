#include <iostream>
#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"

using namespace std;

namespace ariel 
{

    class PhysicalNumber
    {
    
       public:
       PhysicalNumber(double number,Unit _x);
       PhysicalNumber(const PhysicalNumber& temp);
	    
	    // onry operator
            
        PhysicalNumber operator+();
        PhysicalNumber operator-();
	    
           // operator (+) && operator (-)

        const PhysicalNumber operator+(const PhysicalNumber&); 
	const PhysicalNumber operator-(const PhysicalNumber&);
	PhysicalNumber& operator+=(const PhysicalNumber&);
	PhysicalNumber& operator-=(const PhysicalNumber&);
	

	   // check equal by boolean operator
	    
        bool operator== (const PhysicalNumber&);
        bool operator!= (const PhysicalNumber&);
	bool operator> (const PhysicalNumber&);
        bool operator< (const PhysicalNumber&);
        bool operator>= (const PhysicalNumber&);
        bool operator<= (const PhysicalNumber&);
        
      
	   // promotion and subtraction operator
	    
        PhysicalNumber operator++(int);
        PhysicalNumber operator++();
        PhysicalNumber operator--(int);
        PhysicalNumber operator--();
    
           // input && output
	
	friend istream& operator>> (istream& is, PhysicalNumber& c);    
        friend ostream& operator<< (ostream& os, const PhysicalNumber& c);
        
      
	private:
                double number;
	        Unit _x;
    };
}
#endif
