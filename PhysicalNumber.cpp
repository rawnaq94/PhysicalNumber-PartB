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

   ostream &ariel::operator<< (ostream& os, const PhysicalNumber& c)
   {
      PhysicalNumber p1 (c.number,c._x);
      string cd;
      switch (p1._x) {
        case Unit::KM :
            cd="km";
            break;
	
        case Unit::CM :
            cd="cm";
            break;	      
		      
        case Unit::M :
            cd="m";
            break;
		    
	case Unit::KG :
            cd="kg";
            break;
		    
        case Unit::G :
            cd="g";
            break;	      

       case Unit::TON :
            cd="ton";
            break;
	    	      
        case Unit::HOUR :
            cd="hour";
            break;
		    
        case Unit::MIN :
            cd="min";
            break;
		    
        case Unit::SEC :
            cd="sec";
            break;	
    }
    return os << p1.number << "[" << cd << "]";
    }




istream& ariel::operator>>(istream& is, PhysicalNumber& c) {
    string input;
std::ios::pos_type startPosition = is.tellg();
is >> input;
Unit type; 
double Value; 
int first=input.find('[');
int last=input.find(']');
if(first==-1 || last==-1 || first>=last) 
{
    auto errorState=is.rdstate();
    is.clear();
    is.seekg(startPosition);
    is.clear(errorState);
    return is;
}
std::string _values=input.substr(0,first);
std::string _type=input.substr(first+1,last-first-1);
try
{
   Value=stod(_values);   
}
catch(std::exception& pn)
{
    auto errorState = is.rdstate(); 
    is.clear();
    is.seekg(startPosition); 
    is.clear(errorState);
    return is;
}
if(_type.compare("km")==0) type=Unit::KM; 
else if(type.compare("m")==0) type=Unit::M; 
else if(type.compare("cm")==0) type=Unit::CM; 
else if(type.compare("ton")==0) type=Unit::TON; 
else if(type.compare("kg")==0) type=Unit::KG; 
else if(type.compare("g")==0) type=Unit::G; 
else if(type.compare("hour")==0) type=Unit::HOUR; 
else if(type.compare("min")==0) type=Unit::MIN; 
else if(type.compare("sec")==0) type=Unit::SEC;
else 
{
    auto errorState=is.rdstate(); 
    is.clear(); 
    is.seekg(startPosition);
    is.clear(errorState);
    return is;
}
p1._x=type;
p1.number=Value;
return is;
}




     // private func
  
 bool PhysicalNumber::unit2(const PhysicalNumber& a)
 { 
     if((a._x>=0 && a._x<=2) && (this->_x>=0 && this->_x<=2)) //First
     {  
         return true;
     }
  
     else if((a._x>=3 && a._x<=5) && (this->_x>=3 && this->_x<=5)) //Second
     {
          return true;
     }
   
     else if((a._x>=6 && a._x<=8) && (this->_x>=6 && this->_x<=8)) //Third
     {
         return true;
     }
     else return false;
}



double PhysicalNumber::unit_Converter(PhysicalNumber& left,PhysicalNumber& right)const //Option to convert
{
      if(left.unit2(right)==false)
      {
          throw runtime_error("Can not convert");
      }
      else
      {
           switch (left._x)
	   {
            case KM:
			   
           switch(right._x)
	   { 
                case KM:
                return right.number;
                break;               
               
                case M:
                return right.number/1000;
                break;
                
                case CM:
                return right.number/100000;
                break;
               
                default:
                throw runtime_error("Can not convert");
            }
                break;
                case M:
            switch(right._x)
	    {    
                case M:
                return right.number;
                break;  

                case KM:
                return right.number*1000;
                break;
                
                case CM:
                return right.number/100;
                break;
              
                default:
               throw runtime_error("Can not convert");
            }
               break;            
               case CM:
            switch(right._x)
	    {    
                case CM:
                return right.number;
                break;  

                case KM:
                return right.number*100000;
                break;
                
                case M:
                return right.number*100;
                break;

                default:
                throw runtime_error("Can not convert");
            }
                break;
                case HOUR:
            switch(right._x)
	    { 
                case HOUR:
                return right.number;
                break;  
               
                case MIN:
                return right.number/60;
                break;
                
                case SEC:
                return right.number/3600;
                break;
               
                default:
                throw runtime_error("Can not convert");
            }
                break;
                case MIN:
            switch(right._x)
	    {    
                case MIN:
                return right.number;
                break;  
               
                case HOUR:
                return right.number*60;
                break;
                
                case SEC:
                return right.number/60;
                break;
               
                default:
                throw runtime_error("Can not convert");
            }
                break;
                case SEC:
            switch(right._x)
	    {    
                case SEC:
                return right.number;
                break;  
                
                case HOUR:
                return right.number*3600;
                break;
                
                case MIN:
                return right.number*60;
                break;
                
                default:
               throw runtime_error("Can not convert");
            }
               break;
               case TON:
            switch(right._x)
	    {
                case TON:
                return right.number;
                break;  
               
                case KG:
                return right.number/1000;
                break;
                
                case G:
                return right.number/1000000;
                break;

                default:
                throw runtime_error("Can not convert");
            }
                break;
                case KG:
            switch(right._x)
	    {  
                case KG:
                return right.number;
                break;  
                
                case TON:
                return right.number*1000;
                break;
                
                case G:
                return right.number/1000;
                break;
                
                default:
                throw runtime_error("Can not convert");
            }
                break; 
                case G:
            switch(right._x)
	    {
                case G:
                return right.number;
                break;  
                
                case KG:
                return right.number*1000;
                break;
                
                case TON:
                return right.number*1000000;
                break;
               
                default:
                throw runtime_error("Can not convert");
            }
            break;
        }   
        }
}
     
