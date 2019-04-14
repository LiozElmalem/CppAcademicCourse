#include<iostream>
#include <string>
#include "PhysicalNumber.h"
#include <iomanip>

using namespace std;
using ariel::PhysicalNumber;


PhysicalNumber::PhysicalNumber(double num,Unit un):n(num),unit(un){}

string get_string_unit(PhysicalNumber l){ // return the type name
int x = l.get_unit();
switch (x) {
  case 0:return "M";
  case 1:return "CM";
  case 2:return "KM";
  case 3:return "SEC";
  case 4:return "MIN";
  case 5:return "HOUR";
  case 6:return "G";
  case 7:return "KG";
  case 8:return "TON";
}
return "";
}
string get_type(const PhysicalNumber& l){ // return the class of the type
  std::string s=get_string_unit(l);
  if(s.compare("M")==0||s.compare("CM")==0||s.compare("KM")==0)return "LENGTH";
  if(s.compare("G")==0||s.compare("KG")==0||s.compare("TON")==0)return "SIZE";
  if(s.compare("SEC")==0||s.compare("MIN")==0||s.compare("HOUR")==0)return "TIME";
  return "";
}

bool isSameType(ariel::Unit u1 , ariel::Unit u2){
  bool ans = false;
  if((u1 == 0 && u2 == 0 )|| (u1 == 0 && u2 == 1 )||( u1 == 0 && u2 == 2)){ans = true;}
  else if((u1 == 1 && u2 == 0) ||( u1 == 1 && u2 == 1 )||(u1 == 1 && u2 == 2)){ans = true;}
  else if((u1 == 2 && u2 == 0) || (u1 == 2 && u2 == 1 )||(u1 == 2 && u2 == 2)){ans = true;}
  else if((u1 == 3 && u2 == 3 )|| (u1 == 3 && u2 == 4) || (u1 == 3 && u2 == 5)){ans = true;}
  else if((u1 == 4 && u2 == 3 )|| (u1 == 4 && u2 == 4) || (u1 == 4 && u2 == 5)){ans = true;}
  else if((u1 == 5 && u2 == 3) || (u1 == 5 && u2 == 4)|| (u1 == 5 && u2 == 5)){ans = true;}
  else if((u1 == 6 && u2 == 6) || (u1 == 6 && u2 == 7) || (u1 == 6 && u2 == 8)){ans = true;}
  else if((u1 == 7 && u2 == 6) || (u1 == 7 && u2 == 7) || (u1 == 7 && u2 == 8)){ans = true;}
  else if((u1 == 8 && u2 == 6) || (u1 == 8 && u2 == 7) || (u1 == 8 && u2 == 8)){ans = true;}
  return ans;
}

double ariel::PhysicalNumber::cast_it_to(ariel::Unit to_type) const{
  if(!isSameType(unit,to_type))  throw std::invalid_argument("Exception,they must be from the same type");
  double ans = 0;
  double x = n;
  switch (unit) {
    case CM:
    {
    switch(to_type){
      case M: { ans = x / 100;
        break;
      }
      case CM:{ ans = x;
        break;
      }
      case KM: {
        ans = x / 100000;
        break;
    }
  }
    break;
  }
    case M:
    {
    switch(to_type){
      case M : {ans = x;
        break;
      }
      case CM: { ans = x * 100;
        break;
      }
      case KM: {ans = x / 1000;
        break;
      }
    }
    break;
  }
    case KM:
    {
    switch(to_type){
      case KM :
       {
        ans = x;
        break;
      }
      case M: {
        ans = x * 1000;
        break;
      }
      case CM: {
        ans = x * 100000;
        break;
      }
    }
    break;
   }
    //
    case SEC:
    {
    switch(to_type){
      case SEC :{ ans = x;
        break;}
      case MIN: {ans = x / 60;
        break;}
      case HOUR:{ ans = x / 3600;
        break;}
    }
    break;
  }
    case MIN:
    {
    switch(to_type){
      case MIN :{ ans = x;
        break;}
      case SEC:{ ans = x * 60;
        break;}
      case HOUR:{ ans = x / 60;
        break;}
    }
    break;
  }
    case HOUR:
    {
    switch(to_type){
      case HOUR : {ans  = x;
        break;}
      case SEC: {ans = x * 3600;
        break;}
      case MIN:{ ans = x * 60;
        break;}
    }
    break;
  }
    //
    case G:
    {
    switch (to_type) {
      case G : {ans = x;
        break;}
      case KG: {ans = x / 1000;
        break;}
      case TON: {ans = x / 1000000;
        break;}
    }
    break;
  }
    case KG:
    {
    switch (to_type) {
      case KG :{ ans = x;
        break;}
      case G: {ans = x * 1000;
        break;}
      case TON: { ans = x / 1000;
        break; }
    }
    break;
  }
    case TON:
    {
    switch (to_type) {
      case TON : {ans = x;
        break;}
      case G: {ans = x * 1000000;
        break;}
      case KG:{ ans = x * 1000;
        break;}
    }
    break;
  }
  }
  return ans;
}
// the operators

bool ariel::operator > (const PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else {
      double r_n = r.cast_it_to(l.unit);
      double l_n = l.n;
      return l_n>r_n;
    }
  }

bool ariel::operator < (const PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n = r.cast_it_to(l.unit);
      double l_n = l.n;
      return l_n<r_n;
    }
  }

bool ariel::operator >= (const PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n =r.cast_it_to(l.unit);
      double l_n = l.n;
      return l_n>=r_n;
    }
  }

bool ariel::operator <= (const PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n =r.cast_it_to(l.unit);
      double l_n = l.n;
      return l_n<=r_n;
    }
  }

bool ariel::operator == (const PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n =r.cast_it_to(l.unit);
      double l_n = l.n;
      return l_n==r_n;
    }
  }

bool ariel::operator != (const PhysicalNumber& l,const PhysicalNumber& r){
  return !(l==r);
}

PhysicalNumber& ariel::PhysicalNumber::operator ++(){
  ++n;
  return *this;
}

PhysicalNumber ariel::PhysicalNumber::operator ++(int){
  double n_ = n;
  n++;
  return PhysicalNumber(n_,unit);
}

PhysicalNumber ariel::PhysicalNumber::operator --(int){
  double n_ = n;
  n--;
  return PhysicalNumber(n_,unit);
}

PhysicalNumber& ariel::PhysicalNumber::operator --(){
  --n;
  return *this;
}

PhysicalNumber ariel::operator + (const PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n = r.cast_it_to(l.unit);
      double l_n = l.n;
  PhysicalNumber temp(r_n+l_n,l.unit);
  return temp;
}
}

PhysicalNumber ariel::operator += (PhysicalNumber& l,const PhysicalNumber& r){
   if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n = r.cast_it_to(l.unit);
      double l_n = l.n;
      l.set_number(l_n+r_n);
   return l;
 }
}

PhysicalNumber ariel::operator - (const PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n = r.cast_it_to(l.unit);
      double l_n = l.n;
      PhysicalNumber temp(l_n-r_n,l.unit);
      return temp;}
}

PhysicalNumber ariel::operator - (const PhysicalNumber& l){
  PhysicalNumber temp(-l.n,l.unit);
  return temp;
}

PhysicalNumber ariel::operator + (const PhysicalNumber& l){return l;}

PhysicalNumber ariel::operator -= (PhysicalNumber& l,const PhysicalNumber& r){
  if(get_type(l).compare(get_type(r))!=0){
    throw std::invalid_argument("Exception,they must be from the same type");}
    else{
      double r_n = r.cast_it_to(l.unit);
      double l_n = l.n;
      l.set_number(l_n-r_n);
    }
   return l;
 }

istream& ariel::operator >> (istream & is,PhysicalNumber& f){
  string s;
  is >> s;
  Unit un_;
  double n_;
  int p1 = s.find('[');
  int p2 = s.find(']');
  if(p1 == -1 || p2 == -1 || p1 > p2){
    cout <<"illegal input";
    return is;
  } 
  string num = s.substr(0,p1); // from the start to [
  string unit = s.substr(p1+1 ,p2 - p1 - 1); // from [ to ]
  try{
  n_ = stod(num);
  }
  catch(exception& e){
    cout << e.what() << endl;
  }
  if(num.compare("")==0){
    cout <<"illegal input";
    return is;
  }
  // LENGTH
  if( unit.compare("km") == 0 ) un_ = Unit::KM;
  else if( unit.compare("m") == 0 ) un_ = Unit::M;
  else if( unit.compare("cm") == 0 ) un_ = Unit::CM;
  //TIME
  else if( unit.compare("hour") == 0 ) un_ = Unit::HOUR;
  else if( unit.compare("min") == 0 ) un_ = Unit::MIN;
  else if( unit.compare("sec") == 0 ) un_ = Unit::SEC;
  //WEIGHT
  else if( unit.compare("ton") == 0 ) un_ = Unit::TON;
  else if( unit.compare("kg") == 0 ) un_ = Unit::KG;
  else if( unit.compare("g") == 0 ) un_ = Unit::G;
  else {
    cout <<"illegal input";
    return is;
  }
  f.unit = un_;
  f.n = n_;
  return is;
}
// for the output
string un(PhysicalNumber l){
int x = l.get_unit();
switch (x) {
  case 0:return "m";
  case 1:return "cm";
  case 2:return "km";
  case 3:return "sec";
  case 4:return "min";
  case 5:return "hour";
  case 6:return "g";
  case 7:return "kg";
  case 8:return "ton";
}
return "";
}
//
ostream& ariel::operator <<(ostream & os,const PhysicalNumber& f){
  os << f.n << "[" << un(f) << "]";
  return os;
}
