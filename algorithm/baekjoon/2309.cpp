#include <iostream>
#include <set>
using namespace std;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  set<int> s;

  int height;
  int sum = 0;

  for(int i = 0 ; i < 9 ; i++){
    cin >> height;
    s.insert(height);
    sum += height;
  }

  int result_sum = sum - 100;

  for(int s_height : s){
    int find_height = result_sum - s_height;
    if(s.find(find_height) != s.end()){
      s.erase(find_height);
      s.erase(s_height);
      break;
    }
  }

  for(int s_height : s){
    cout << s_height << endl;
  }

  return 0;
}