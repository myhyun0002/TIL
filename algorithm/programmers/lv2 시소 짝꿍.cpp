#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

/*

4 3 2 || 2 3 4

시소 짝꿍 : 두명이 양쪽에 앉았을 때 평행이 되는 관계

사람 무게 * (중간에서 좌석간의 거리) 가 같아야 한다.

*/
long long gcd (int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

bool lcm_evaluate(int a,int b){
    long long lcm_a = lcm(a,b)/b;
    long long lcm_b = lcm(a,b)/a;
    
    if(lcm_a == 1 || lcm_b == 1){
        lcm_a *= 2;
        lcm_b *= 2;
    }
    
    // 2,3 3,4 2,4 인 경우에는 true
    if(lcm_a < 5 && lcm_a >= 2 && lcm_b >= 2 && lcm_b < 5){
        return true;
    }else{
        return false;
    }
    
}

long long solution(vector<int> weights) {
    long long answer = 0;
    
    /*
    map에서 long 부분은 해당 수가 몇 번 나오는지 count 해주는 수다.
    이걸 int로 하니까 죽어도 안 풀렸는데 long으로 바꾸니까 풀렸다.
    왤까?
    
    
    */
    
    map<int,long> weight_map;
    
    for(int i = 0 ; i < weights.size() ; i++){
        weight_map[weights[i]]++;
    }
    
    for(auto m1 : weight_map){
        if(m1.second >= 2){
            answer += (m1.second)*(m1.second - 1) / 2;
        }
        
        for(auto m2 : weight_map){
            if(m2.first == m1.first){
                continue;
            }
            
            if(lcm_evaluate(m1.first,m2.first)){
                answer += m1.second * m2.second;
            }
        }
        
        weight_map.erase(m1.first);
    }
        
    
    return answer;
}