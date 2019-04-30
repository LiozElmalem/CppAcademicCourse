#pragma once
#include <string>
#include "calculate.hpp"

using namespace std;

namespace bullpgia{
  class Guesser{
  private:
     // variabales
    string myGuess;
    
  public:
    Guesser(){
      myGuess = "";
    }
    Guesser(const string& temp){
      myGuess = temp;
    }
    uint length;
    virtual ~Guesser(){}
    // functions
    virtual void startNewGame(uint length){}
    virtual string guess() = 0;
    virtual void learn(string solutions){}

  };
};
