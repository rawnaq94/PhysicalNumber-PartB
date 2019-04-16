#include <iostream>
#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include "Unit.h"
using namespace std;


namespace ariel 
{
    static string const arr[]={"km", "cm", "m", "kg", "g", "ton", "hour", "min", "sec"};
    class PhysicalNumber
    {
    
       public:
       PhysicalNumber(double number,Unit _x);
       PhysicalNumber(const PhysicalNumber& temp);
	    
	    // onry operator
            
        PhysicalNumber operator+()const;
        PhysicalNumber operator-()const;
	    
	    // consts && setres
	    
	PhysicalNumber(const double num, const Unit x);
	PhysicalNumber(cost PhysicalNumber& p1);
	void setNumber(double n);
	void setUnit(Unit _x);
	    
           // operator (+) && operator (-)

        PhysicalNumber operator+(const PhysicalNumber& a)const; 
	PhysicalNumber operator-(const PhysicalNumber& a)const;
	PhysicalNumber& operator+=(const PhysicalNumber& a);
	PhysicalNumber& operator-=(const PhysicalNumber& a);
	PhysicalNumber& operator=(const PhysicalNumber& a);
	

	   // check equal by boolean operator
	    
	friend bool unit2(const PhysicalNumber& a, const PhysicalNumber& b);    
        friend bool operator== (const PhysicalNumber& a, const PhysicalNumber& b);
        bool operator!= (const PhysicalNumber& a);
	bool operator> (const PhysicalNumber& a);
        bool operator< (const PhysicalNumber& a);
        bool operator>= (const PhysicalNumber& a);
        bool operator<= (const PhysicalNumber& a);
        
      
	   // promotion and subtraction operator
	    
        PhysicalNumber operator++(int i); 
        PhysicalNumber operator++();
        PhysicalNumber operator--(int i);
        PhysicalNumber operator--();
    
           // input && output
	
	friend istream& operator>> (istream& is, PhysicalNumber& c);    
        friend ostream& operator<< (ostream& os, const PhysicalNumber& c);
        
      
	private:
                double number;
	        Unit _x;
	    
	 
	double conversion(PhysicalNumber& a, PhysicalNumber& b)const;
        friend istream& unit_Input(istream& is, PhysicalNumber& n);   
    };
	
	
	istream& operator>> (istream& is, PhysicalNumber& c);
	ostream& operator<< (ostream& os, const PhysicalNumber& c);
	bool operator== (const PhysicalNumber& a, const PhysicalNumber& b);
        bool unit2(const PhysicalNumber& a, const PhysicalNumber& b); 
	
	
}
#endif
