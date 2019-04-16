// Full realization ---- Part2 

#include <iostream>
#include "PhysicalNumber.h"
#include<exception>
#include <math.h> 
using namespace std;
using namespace ariel;



      // copy constructor

    PhysicalNumber::PhysicalNumber(const double num,const Unit x)
    {
	 this->number=num;
         this->_x=x;
    }


    PhysicalNumber::PhysicalNumber(const PhysicalNumber& p1)
    {
        this->number=p1.number;
        this->_x=p1._x;
    }
    

        // onry operator + && onry operator -

     PhysicalNumber PhysicalNumber::operator+()const
     {
        if(this->number < 0)
	{
            return PhysicalNumber(number*(-1),_x);
        }
        else
        return *this;
     }
     
     PhysicalNumber PhysicalNumber::operator-()const
     {

         return PhysicalNumber(number*(-1),_x); 
     } 



         // operator (+, +=) && operator (-, _=) && operator (==)

     PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& a)const
     {
        PhysicalNumber thispn = PhysicalNumber(this->number,this->_x);
        if(thispn.unit2(a)==false)
	{
		throw runtime_error("Can not convert");
	}
        PhysicalNumber tx =PhysicalNumber(a.number,a._x);
        double temp= thispn.number + conversion(thispn,tx);
        return PhysicalNumber(temp,_x);
     }
    

    PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& a)const
    {
        PhysicalNumber thispn = PhysicalNumber(this->number,this->_x);
        if(thispn.unit2(a)==false)
	{
		throw runtime_error("Can not convert");
	}
        PhysicalNumber tx = PhysicalNumber(a.number,a._x);
        double temp = this->number-1*(conversion(thispn,tx));
        return PhysicalNumber(temp,_x);       
    }


 
    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber &a)
    {
      PhysicalNumber tx = (*this+a);
      this->number =tx.number;
      return *this;
    }
    


    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber &a)
    {
        PhysicalNumber tx = (*this-a);
        this->number = tx.number;
        return *this;	
    }


    PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& a)
    {
        this->number = a.number;
        this->_x =a._x;
        return *this;
    }


    
           // check equal by boolean operator


   bool PhysicalNumber::operator==(const PhysicalNumber& a)
    {
        if(this->unit2(a)==false)
	{
		throw runtime_error("Can not convert");
	}
        PhysicalNumber b = PhysicalNumber(this->number,this->_x);
        PhysicalNumber c = PhysicalNumber(a.number,a._x);
        if(b>c || b<c)
	{
            return false;
        }
        else
            return true;
   }


   bool PhysicalNumber::operator!=(const PhysicalNumber& a)
   {
       if(*this==a) return false;
       return true;
    }


    bool PhysicalNumber::operator>(const PhysicalNumber &a)
    {
        if(this->unit2(a)==false)
	{
		throw runtime_error("Can not convert"); 
	}
        PhysicalNumber b = PhysicalNumber(this->number,this->_x);
        PhysicalNumber c = PhysicalNumber(a.number,a._x);
        double our = conversion(b,c);
        return (this->number>our);         
    }


    bool PhysicalNumber::operator<(const PhysicalNumber& a)
    {
        if(this->unit2(a)==false)
	{
		throw runtime_error("Can not convert");
	}
        PhysicalNumber b = PhysicalNumber(this->number,this->_x);
	PhysicalNumber c = PhysicalNumber(a.number,a._x);
        double our = conversion(b,c);
        return (this->number<our);
    }


    bool PhysicalNumber::operator>=(const PhysicalNumber& a)
    {
        if(this->unit2(a)==false)
	{
		throw runtime_error("Can not convert");
	}
        PhysicalNumber b = PhysicalNumber(this->number,this->_x);
        PhysicalNumber c = PhysicalNumber(a.number,a._x);
        if(b>c || b==c)
	{
            return true;
        }
        else
            return false;
    }



    bool PhysicalNumber::operator<=(const PhysicalNumber& a)
    {
        if(this->unit2(a)==false)
	{
		throw runtime_error("Can not convert");
	}
        PhysicalNumber b = PhysicalNumber(this->number,this->_x);
        PhysicalNumber c = PhysicalNumber(a.number,a._x);
        if(b==c || b<c)
	{
            return true;
        }
        else
            return false;
    }


 

  // promotion and subtraction operator


 PhysicalNumber PhysicalNumber::operator++(int)
 {
        PhysicalNumber p1(*this);
        number++;
        return p1;
 }

PhysicalNumber PhysicalNumber::operator++()
{
	number++;
	return *this;
}

PhysicalNumber PhysicalNumber::operator--(int)
{
        PhysicalNumber p1(*this);
        number--;
        return p1;
}   
   
PhysicalNumber PhysicalNumber::operator--()
{
        number--;
        return *this;
}




        // input && output

   ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c){//output
    PhysicalNumber pn (c.num,c.u);
    string str;
    switch (pn.u) {
        case Unit::KM :
            str = "km";
            break;
        case Unit::M :
            str = "m";
            break;
        case Unit::CM :
            str = "cm";
            break;
        case Unit::HOUR :
            str = "hour";
            break;
        case Unit::MIN :
            str = "min";
            break;
        case Unit::SEC :
            str = "sec";
            break;
        case Unit::TON :
            str = "ton";
            break;
        case Unit::KG :
            str = "kg";
            break;
        case Unit::G :
            str = "g";
            break;
    }
    return os << pn.num << "[" << str << "]";
    }


istream& ariel::operator>>(istream& is, PhysicalNumber& pn) {
    string input;

// remember place for rewinding
std::ios::pos_type startPosition = is.tellg();

is >> input;

Unit new_type; // Answers
double new_Value; // Ansers

int f_index = input.find('[');
int l_index = input.find(']');

if(f_index == -1 || l_index == -1 || f_index >= l_index) 
{
    auto errorState = is.rdstate(); // remember error state
    is.clear(); // clear error so seekg will work
    is.seekg(startPosition); // rewind
    is.clear(errorState); // set back the error flag
    return is;
}

std::string numbers = input.substr(0,f_index);
std::string s_type = input.substr(f_index+1,l_index - f_index - 1 );

try
{
    new_Value = stod(numbers);   
}
catch(std::exception& e)
{
    auto errorState = is.rdstate(); // remember error state
    is.clear(); // clear error so seekg will work
    is.seekg(startPosition); // rewind
    is.clear(errorState); // set back the error flag
    return is;
}

if( s_type.compare("km") == 0 ) new_type = Unit::KM; 
else if( s_type.compare("m") == 0 ) new_type = Unit::M; 
else if( s_type.compare("cm") == 0 ) new_type = Unit::CM; 

else if( s_type.compare("ton") == 0 ) new_type = Unit::TON; 
else if( s_type.compare("kg") == 0 ) new_type = Unit::KG; 
else if( s_type.compare("g") == 0 ) new_type = Unit::G; 

else if( s_type.compare("hour") == 0 ) new_type = Unit::HOUR; 
else if( s_type.compare("min") == 0 ) new_type = Unit::MIN; 
else if( s_type.compare("sec") == 0 ) new_type = Unit::SEC;
else {
    auto errorState = is.rdstate(); // remember error state
    is.clear(); // clear error so seekg will work
    is.seekg(startPosition); // rewind
    is.clear(errorState); // set back the error flag
    return is;
}

pn.u = new_type;
pn.num = new_Value;
return is;

}

//private functions:

//checking if the given units are from the same "family" [mass,time,lenght]
 bool PhysicalNumber::sameUnit(const PhysicalNumber& other){ 
     //first family unit
     if((other.u >=0 && other.u<=2) && (this->u >=0 && this->u<=2)){
       
         return true;
     }
     //second family unit
        else if((other.u >=3 && other.u<=5) && (this->u >=3 && this->u<=5)){
        
                return true;
     }
     //third family unit
                else if((other.u >=6 && other.u<=8) && (this->u >=6 && this->u<=8)){
        
                         return true;
     }
     else return false;
}

//checking if the given Physical Numbers can be convert
double PhysicalNumber::unit_Converter(PhysicalNumber& left,PhysicalNumber& right)const{
      if(left.sameUnit(right)==false) {
          throw runtime_error("not the same family unit can not convert1");
      }
      else{
           switch (left.u){
            case KM:
            switch(right.u){ 
                case KM:
                return right.num;
                break;               
               
                case M:
                return right.num/1000;
                break;
                
                case CM:
                return right.num/100000;
                break;
               
                default:
                throw runtime_error("not the same family unit can not convert2");
            }
            break;
            case M:
            switch(right.u){
                
                case M:
                return right.num;
                break;  

                case KM:
                return right.num*1000;
                break;
                
                case CM:
                return right.num/100;
                break;
              
                default:
               throw runtime_error("not the same family unit can not convert3");
                
            }
            break;            
            case CM:
            switch(right.u){
                
                case CM:
                return right.num;
                break;  

                case KM:
                return right.num*100000;
                break;
                
                case M:
                return right.num*100;
                break;

                default:
                throw runtime_error("not the same family unit can not convert4");
            }
            break;

            case HOUR:
            switch(right.u){
                
                case HOUR:
                return right.num;
                break;  
               
                case MIN:
                return right.num/60;
                break;
                
                case SEC:
                return right.num/3600;
                break;
               
                default:
                throw runtime_error("not the same family unit can not convert5");
            }
            break;
            case MIN:
            switch(right.u){
                
                case MIN:
                return right.num;
                break;  
               
                case HOUR:
                return right.num*60;
                break;
                
                case SEC:
                return right.num/60;
                break;
               
                default:
                throw runtime_error("not the same family unit can not convert6");
            }
            break;
            case SEC:
            switch(right.u){
                
                case SEC:
                return right.num;
                break;  
                
                case HOUR:
                return right.num*3600;
                break;
                
                case MIN:
                return right.num*60;
                break;
                
                default:
               throw runtime_error("not the same family unit can not convert7");
            }
            break;
            case TON:
            switch(right.u){
               
                case TON:
                return right.num;
                break;  
               
                case KG:
                return right.num/1000;
                break;
                
                case G:
                return right.num/1000000;
                break;

                default:
                throw runtime_error("not the same family unit can not convert8");
            }
            break;
            case KG:
            switch(right.u){
                
                case KG:
                return right.num;
                break;  
                
                case TON:
                return right.num*1000;
                break;
                
                case G:
                return right.num/1000;
                break;
                
                default:
                throw runtime_error("not the same family unit can not convert9");
            }
            break; 
            case G:
            switch(right.u){
                
                case G:
                return right.num;
                break;  
                
                case KG:
                return right.num*1000;
                break;
                
                case TON:
                return right.num*1000000;
                break;
               
                default:
                throw runtime_error("not the same family unit can not convert10");
            }
            break;
        }   
    }
}
     
