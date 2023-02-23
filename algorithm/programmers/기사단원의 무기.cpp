#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 약수 구하는 함수
int factor(int a) {
    if (a <= 0) {     // a가 0이거나 음수면 그냥 return   
		return 0;
	}
    int count = 0;

	for (int i = 1; i * i <= a; i++) {

		if (i * i == a) {
            count++;
		}else if (a % i == 0) {
            count+= 2;
		}
	}
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> divisor_count;
    
    for(int i = 1 ; i <= number ; i++){
        if(i == 1){
            answer++;
            continue;
        }
        
        if(factor(i) > limit){
            answer += power;
        }else{
            answer += factor(i);
        }
    }
    
    return answer;
}