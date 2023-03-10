#include <iostream>
using namespace std;

int main(){
  int arr[26] = {0,};
  string vocabulary;
  cin >> vocabulary;

  for(char alpha : vocabulary){
    int index = alpha - 'a';
    arr[index] += 1;
  }

  for(int a : arr){
    cout << a << " ";
  }
  return 0;
}