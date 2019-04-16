#ifndef PHYSICALNUMBER_H
#define PHYSICALNUMBER_H
#include <iostream>
#include "Unit.h"
using namespace std;


namespace ariel
{
	
    static string const arr[] = {"km", "cm", "m", "kg", "g", "ton", "hour", "min", "sec"};
	
    class PhysicalNumber
    {

        public:
	    
	    //consts && setres
	    
        PhysicalNumber(const double num,const Unit x);
        PhysicalNumber(const PhysicalNumber& p1);
        void setNumber(double n);
        void setUnit(Unit _x);
	    
	    
	    // onry operator
            
        PhysicalNumber operator+()const;
        PhysicalNumber operator-()const;
	    
	    // operator (+) && operator (-)

        PhysicalNumber operator+(const PhysicalNumber& a)const; 
	PhysicalNumber operator-(const PhysicalNumber& a)const;
	PhysicalNumber& operator+=(const PhysicalNumber& a);
	PhysicalNumber& operator-=(const PhysicalNumber& a);
	PhysicalNumber& operator=(const PhysicalNumber& a);

      
	    // check equal by boolean operator

        bool operator== (const PhysicalNumber& a) ;
        bool operator!= (const PhysicalNumber& a) ;    
        bool operator> (const PhysicalNumber& a) ;
        bool operator< (const PhysicalNumber& a) ;
        bool operator>= (const PhysicalNumber& a) ;
        bool operator<= (const PhysicalNumber& a) ;
       
	    
	    
	     // promotion and subtraction operator
       
	PhysicalNumber operator++(int i);
        PhysicalNumber operator++();
        PhysicalNumber operator--(int i);
        PhysicalNumber operator--();
	    

	    // input && output
    
        friend istream& operator>> (istream& is, PhysicalNumber& c);    
        friend ostream& operator<< (ostream& os, const PhysicalNumber& c);
   
	    // private paramtres
	    
	private:
        double number;
	Unit _x;
        
           // private func
  
        double conversion(PhysicalNumber& a ,PhysicalNumber& b)const; // Option to convert
        friend istream& unitInput(istream& is, PhysicalNumber& n);
        bool unit2(const PhysicalNumber& a);

    };
	
       istream& operator>> (istream& is, PhysicalNumber& c);    
       ostream& operator<< (ostream& os, const PhysicalNumber& c);
}
#endif
