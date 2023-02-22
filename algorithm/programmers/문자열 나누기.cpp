#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<char,int> x_freq;
    
    for(int i = 0 ; i < s.length() ; i++){
        char current_char = s[i];
        
        x_freq[current_char] = 1;
        int not_x_freq = 0;
        
        while(true){
            if(x_freq[current_char] == not_x_freq){
                answer++;
                break;
            }
            i++;
            char current_x_next_char = s[i];
            if(current_char != current_x_next_char){
                not_x_freq++;
            }else{
                x_freq[current_char]++;
            }
        }
        
    }
    return answer;
}