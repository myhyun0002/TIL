#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
  reverse 활용
*/

int main(){
  string str;
  cin >> str;

  string temp = str;

  reverse(temp.begin(), temp.end());

  if(str == temp){
    cout << "1";  
  }else{
    cout << "0";
  }
  return 0;
}