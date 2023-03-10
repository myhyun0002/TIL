#include <iostream>
#include <stack>
using namespace std;

/*
  stack
  
  삽입 : stack.push()
  맨 위 값 반환 : stack.top()
  삭제 : stack.pop()

*/

int main(){
  string str;
  cin >> str;

  stack<char> s;

  int str_half_size = str.size() / 2;

  for(int i = 0; i < str_half_size; i++){
    s.push(str[i]);
  }

  int result = 1;

  int search_start_index;

  if(str.size() % 2 == 0){
    search_start_index = str_half_size;
  }else{
    search_start_index = str_half_size + 1;
  }

  for(int i = search_start_index ; i < str.size() ; i++){
    char current_str = s.top();
    s.pop();
    if(current_str != str[i]){
      result = 0;
      break;
    }
  }

  cout << result << endl;
  return 0;
}