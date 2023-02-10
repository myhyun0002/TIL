#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100000
int arr[MAX_N];
unordered_map<int,int> freq;

bool compare(pair<int,int>a,pair<int,int> b){
    // printf("현재 비교하고 있는 쌍은 (%d,%d), (%d,%d) 입니다\n",a.first,a.second,b.first,b.second);
    if(a.second == b.second){
        return a.first > b.first;       // 
    }else{
        return a.second > b.second;
    }
}

int main() {
    int n,k;
    cin >> n >> k;

    for(int i = 0 ; i < n ;i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<pair<int,int>> freq_vector(freq.begin(),freq.end());
    sort(freq_vector.begin(),freq_vector.end(),compare);
    int count = 0;

    for(auto pair :freq_vector){
        if(count == k){
            break;
        }
        cout << pair.first << " ";
        count++;
    }
    
    

    return 0;
}

// algorithm 라이브러리에 sort 함수 설명
// 기본적으로 sort(v.begin,v.end)

/*
algorithm 라이브러리에 sort 함수 설명
기본적인 형태는 sort(v.begin(),v.end(),sort 조건)
v : vector이다.
sort 조건 : default는 오름차순이고 사용자 지정 sort함수도 가능하다.


bool compare(pair<int,int>a,pair<int,int> b){
    // printf("현재 비교하고 있는 쌍은 (%d,%d), (%d,%d) 입니다\n",a.first,a.second,b.first,b.second);
    if(a.second == b.second){
        return a.first > b.first;       // 
    }else{
        return a.second > b.second;
    }
}

위와 같이 지정했을 시 의미를 해석해보자.
if(a.second == b.second) : vector에 있는 값이 차례대로 들어오는데 해당 두개 중에서 두번째 value가 같다면 첫번째 key가 큰 애를
앞으로 보내겠다는 듯
그 외에 것들은 value들을 비교해서 value가 큰 애를 앞으로 보내겠다는 뜻
*/