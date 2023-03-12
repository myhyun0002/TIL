#include <iostream>
#include <queue>
using namespace std;

int main(){
  cin.tie(NULL);

  int n,k;
  cin >> n >> k;

  int max_result = 0;
  int sum = 0;

  queue<int> q;

  int input;

  for(int i = 0 ; i < n ; i++){
    cin >> input;
    q.push(input);

    if(i > k-1){
      sum += input;
      int q_front = q.front();
      q.pop();

      sum -= q_front;
      if(max_result < sum){
        max_result = sum;
      }
    }else if(i == k-1){
      sum += input;
      max_result = sum;
    }else{
      sum += input;
    }
  }

  cout << max_result ;

  return 0;
}