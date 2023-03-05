/*
  combination(조합) + 재귀 공부

  1 2 3 4 중 순서 생각 안하고 3개 뽑는 경우

  1 2 3
  1 2 4
  1 3 4
  2 3 4

  (4 * 3 * 2) / (3*2*1) = 4
*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> const  &b){
  for(int i =0 ; i < b.size() ; i++){
    cout << b[i] << " ";
  }
  cout << endl;
}

// 재귀로 짠 combination
void combination(int start, vector<int> b, int n, int k){
  if(b.size() == k){
    //print(b);
    printf("이제 return한다.\n");
    return;
  }

  for(int i = start + 1 ; i <= n ; i++){
    b.push_back(i);
    print(b);
    combination(i,b,n,k);
    printf("combination 끝\n");
    b.pop_back();
  }
  return;
}

// 중첩 for문으로 짠 combination
// 1부터 n까지 
// n개중 3개를 뽑는 경우
void combination_for(int n){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < i ;  j++){
      for(int k = 0 ; k < j ; k++){
        cout << i << " " << j << " " << k << "\n";      
      }
    }
  }
}

int main(){

  vector<int> b;

  combination(0,b,4,3);
  return 0;
}