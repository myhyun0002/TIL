#include <iostream>
#include <set>

using namespace std;

int main(){
  int n,m;
  cin >> n >>m;

  set<int> s;
  int result = 0;

  int input;
  for(int i = 0 ; i < n ; i++){
    cin >> input;
    if(input > m){
      continue;
    }else{
      if(s.find(input) != s.end()){
        result++;
        s.erase(input);
      }else{
        s.insert(m-input);
      }
    }
  }

  cout << result << endl;
  return 0;
}