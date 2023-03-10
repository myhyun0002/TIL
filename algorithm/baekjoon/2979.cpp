#include <iostream>
using namespace std;

int main(){
  int arr[100] = {0,};
  int money[4] = {0,};

  int a1,a2,a3;
  cin >> money[1] >> money[2] >> money[3];


  for(int i = 0 ; i < 3 ; i++){
    int start = 0;
    int end = 0;

    cin >> start >> end;

    for(int j = start ; j < end ; j++){
      arr[j]++;
    }
  }

  int sum = 0;

  for(int a : arr){
    sum += a * money[a];
  }
  cout << sum << endl;

  return 0;
}