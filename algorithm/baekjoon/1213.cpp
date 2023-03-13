#include <iostream>
#include <map>
#include <stack>

using namespace std;

int main(){
  string str;
  cin >> str;

  map<char,int> m;

  for(char c : str){
    m[c]++;
  }

  int halsu_count = 0;

  for(auto c : m){
    if(c.second % 2 != 0){
      halsu_count++;
    }
  }

  if(halsu_count > 1){
    cout << "I'm Sorry Hansoo";
    return 0;
  }

  string result = "";

  stack<char> s;

  bool isHalsu = false;
  char halsu;

  for(auto char_count : m){
    int count = char_count.second / 2;
    char current_char = char_count.first;

    if(char_count.second % 2 != 0){
      halsu = current_char;
      isHalsu = true;
    }

    for(int i = 0 ; i < count ; i++){
      result += current_char;
      s.push(current_char);
    }

  }

  if(isHalsu){
    result += halsu;
  }

  while(!s.empty()){
    char current_c = s.top();
    s.pop();
    result += current_c;
  }

    cout << result << endl;
  

  return 0;
}