#include <iostream>
using namespace std;

void ROT13(char c){
  if('a' <= c && c <= 'z'){
    cout << (char)((c-'a' + 13)%26 + 'a');
  }else if('A' <= c && c <= 'Z'){
    cout << (char)((c-'A' + 13)%26 + 'A');
  }else{
    cout << c;
  }

}

int main(){
  cin.tie(NULL);

  string str;
  getline(cin,str);

  for(char c : str){
    ROT13(c);
  }
  
  return 0;
}