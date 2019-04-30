#include <string>
#include"calculate.hpp"
using namespace bullpgia;

string bullpgia::calculateBullAndPgia(const string choice,const string guess){
  int bull = 0,pgia=0,i;
  int arrchoice[10],arrguess[10];
  for (i=0;i<10;i++){
    arrchoice[i]=0,arrguess[i]=0;
  }
  for(i=0;i<choice.length();i++){
    if(choice[i]==guess[i])
      bull++;
  }
  for(i=0;i<choice.length();i++){
    int temp=(choice[i])-'0';
    arrchoice[temp]++;
  }
  for (i=0;i<guess.length();i++){
    int temp=(guess[i])-'0';
    arrguess[temp]++;
  }
  for (i=0;i<10;i++){
    pgia+=min(arrchoice[i],arrguess[i]);
  }
  pgia-=bull;
  return to_string(bull) + "," + to_string(pgia);
}
