// C++ program to distinct permutations of the string
// credit to : https://www.geeksforgeeks.org/distinct-permutations-string-set-2/
#include <bits/stdc++.h> 
#include <string>
#include <vector>
using namespace std; 

vector<string> vec;  
// Returns true if str[curr] does not matches with any of the 
// characters after str[start] 
bool shouldSwap(string str, int start, int curr) 
{ 
    for (int i = start; i < curr; i++)  
        if (str[i] == str[curr]) 
            return 0; 
    return 1; 
} 
  
// Prints all distinct permutations in str[0..n-1] 
void findPermutations(string str, int index, int n) 
{ 
    if (index >= n) { 
        vec.push_back(str); 
        return; 
    } 
  
    for (int i = index; i < n; i++) { 
  
        // Proceed further for str[i] only if it  
        // doesn't match with any of the characters 
        // after str[index] 
        bool check = shouldSwap(str, index, i); 
        if (check) { 
            swap(str[index], str[i]); 
            findPermutations(str, index + 1, n); 
            swap(str[index], str[i]); 
        } 
    } 
} 
vector<string> getcombi(string s){
    int count =0;
    string str=s;
    int n=str.length();
    findPermutations(str, 0, n);	 
    return vec; 
}  
 
