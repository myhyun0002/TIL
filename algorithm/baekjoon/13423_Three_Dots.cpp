#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

/*
  이진 탐색 문제
  
  왼쪽 오른쪽을 사용하여 문제 풀이 (두개의 점을 사용)

*/
int main(){

  cin.tie(NULL);
  int n;
  cin >> n;

  int dot_num;

  for(int i = 0 ; i < n ; i++){
    cin >> dot_num;

    vector<int> dots;
    set<int> dots_set;
    int dot;

    for(int j = 0 ; j < dot_num; j++){
      cin >> dot;
      dots.push_back(dot);
      dots_set.insert(dot);
    }

    sort(dots.begin(),dots.end());

    int answer = 0;
    cout << "\n";
    for(int k = 0 ; k < dot_num ; k++){
      for(int l = k+1 ; l < dot_num ; l++){
        int left = k;
        int right = l;

        double val = (dots[left]+dots[right])/2;
        printf("%d와 %d 사이에 진짜 찾을려는 값은 %.2lf입니다.\n",left,right,val);

        while(left < right){
          int mid = (left+right)/2;

          if((double)dots[mid] == val){
            printf("\n%d,%d,%d",dots[left],dots[mid],dots[right]);
            break;
          }else if((double)dots[mid] < val){
            left = mid + 1;
          }else{
            right = mid - 1;
          }
        }

      }
    }

    cout << "\n\n";
  }
  return 0;
}