#include<iostream>
#include "Guesser.hpp"
#include <vector>

using namespace std;

namespace bullpgia{
  class SmartGuesser: public bullpgia::Guesser{

    private :
    string myGuess;
    // to learn the solutions
    uint bull=0;
    uint pgia=0;
    uint length=0;
    int turns=0;
    bool founddigit=false;
    bool once=true;
    string solution="";
    int guesserhelper=0;
    public :
    SmartGuesser(){
    }
    SmartGuesser(const string& temp){
      myGuess = temp;
      bull = 0;
      pgia = 0;
      length=0;
    }
    ~SmartGuesser(){}
    void learn(string solutions) override;
    string guess() override;
    void startNewGame(uint length) override;
  };
};
