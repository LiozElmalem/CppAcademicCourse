#include <string>
#include <algorithm>
#include "SmartGuesser.hpp"
#include "get combinations.cpp"
using namespace std;

void bullpgia::SmartGuesser:: learn(string solutions) {
  size_t i = solutions.find(',');
  int x = stoi(solutions.substr(0,i));
  int y = stoi(solutions.substr(i+1,solutions.length()));
  if(!founddigit){
    try
    {
      if(x>0){
        for(int i=0;i<x;i++){
          solution+=to_string(guesserhelper);
          }
    }
    }catch(const std::exception& e){
      std::cerr << e.what() << '\n';
    }
    bull = x;
    pgia += x;
    if(pgia==length&&once){
      founddigit=true;
      bull=0,pgia=0,guesserhelper=-1;
    }
    guesserhelper++;
  }
}
string bullpgia::SmartGuesser:: guess(){
  myGuess="";
    if(!founddigit&&pgia<length){
      for(int i=0;i<length;i++){
        myGuess+=to_string(guesserhelper);
      }
    }
    else{
      if(once){
        vec=getcombi(solution);
        once=false;
      }
      myGuess=vec[guesserhelper];
      guesserhelper=(guesserhelper+1);
      }
    turns++;
    return myGuess;
}
void bullpgia::SmartGuesser:: startNewGame(uint len) {
  bull=0;
  pgia=0;
  turns=0;
  founddigit=false;
  once=true;
  solution="";
  vec.clear();
  guesserhelper=0;
  length=len;
}