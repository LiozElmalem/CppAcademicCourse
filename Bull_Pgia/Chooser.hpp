
#pragma once
#include <string>

using namespace std;

namespace bullpgia{

  class Chooser{
  private:
    // variabales
    string myChoose;
  public:
    Chooser(){
      myChoose = "";
    }
    Chooser(const string& temp){
      myChoose = temp;
    }
    // functions
    virtual ~Chooser(){}
    virtual string choose(uint length) = 0;
    uint length();
  };
};
