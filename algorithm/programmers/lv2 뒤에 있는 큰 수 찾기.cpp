#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i = 0 ; i < numbers.size() ; i++){
        answer.push_back(-1);
    }
    
    stack<pair<int,int>> st;
    for(int i = 0 ; i < numbers.size() ; i++){
        
        while(!st.empty()){
            pair<int,int> top = st.top();
            
            if(top.first >= numbers[i]){
                break;
            }
            
            // 만약 top이 현재 값보다 작다면
            // top 기준으로 top보다 크고 가장 가까운 값이 현재값이 되는 것이다.
            answer[top.second] = numbers[i];
            st.pop();
        }
        
        st.push({numbers[i],i});
    }
   
    
    return answer;
}