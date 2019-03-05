#include<iostream>
#include<stdlib.h>

int power(int x,int n){
  int result = 1;
  while(n != 0){
    if(n % 2 == 1)
    result *= x;
    x *= x;
    n /= 2;
  }
  return result;
}

int main(){
// int* ptr;
// ptr =(int*)malloc(sizeof(int) * 10);
int ans = power(2,3);
std::cout<<ans<<std::endl;
return 0;
}
