# algorithm 라이브러리 sort
```c++
#include <algorithm>
```
추가하면 sort 함수를 사용할 수 있다.    
기본적인 형태는   
```c++
sort(v.begin(),v.end(),조건절);
```
- v : vector
- 조건절
  - 안써주면 default는 오름차순이다.
  - 해당 조건절 자리에는 세가지 정도가 올 수 있다.
    - less<>() : 오름차순
    - greater<>() : 내림차순
    - 사용자 지정 조건절
___
<br/>
<br/>

## 사용자 지정 조건절
___
```c++
#include <algorithm>
#include <vector>

bool compare(pair<int,int>a,pair<int,int> b){
    // printf("현재 비교하고 있는 쌍은 (%d,%d), (%d,%d) 입니다\n",a.first,a.second,b.first,b.second);
    if(a.second == b.second){
        return a.first > b.first;       // 
    }else{
        return a.second > b.second;
    }
}

vector<pair<int,int>> v;

sort(v.begin(),v.end(),compare)
```
위와 같이 사용자가 지정한 compare라는 조건으로 sort 가능하다.   
해석하자면      
vector에 있는 pair들이 차례대로 sort가 될텐데   
<br/> 

두 pair가 들어왔을 때 만약 두 pair의 두번째 값을 서로 비교해서 같다면 앞쪽에 오는 pair는 first 같이 더 큰 애라는 뜻이다.
```cpp
bool compare(pair<int,int>a,pair<int,int> b){
    if(a.second == b.second){
        return a.first > b.first;      
    }
```
<br/>

그 외에는 전부 두번째 값이 더 큰 애를 앞쪽에 두겠다는 뜻이다.
```cpp
      else{
              return a.second > b.second;
      }
```