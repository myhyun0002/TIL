#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;

  int result = a;

  for(int i = 0 ; i < b ; i++){
    result = result * a;
    printf("%d를 %d번 곱하면 %d이고 %d로 나눈 나머지는 %d이다.\n",a,i+1,result,c,result % c);
  }

  return 0;
}