#include <iostream>
#include <stack>
using namespace std;

int main(){
  cin.tie(NULL);

  int n;
  cin >> n;

  string input;
  int result = 0;

  for(int i = 0 ; i < n ; i++){
    stack <char> s;

    cin >> input;

    for(char c : input){
      if(s.empty()){
        s.push(c);
      }else{
        if(s.top() == c){
          s.pop();
        }else{
          s.push(c);
        }
      }

    }
    if(s.empty()){
      result++;
    }
  }

  cout << result ;

  return 0;
}