#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int max_x;
int max_y;

struct Pos{
    int x;
    int y;
    int level;
};

bool maps_in_range(int x, int y){
    return (0 <= x && x < max_x) && (0 <= y && y < max_y);
};

int bfs(vector<string> maps,Pos startPos,Pos endPos){
    int dx[4] = {0,1,0,-1};   // 위, 오른쪽, 아래, 왼쪽
    int dy[4] = {1,0,-1,0};   // 위, 오른쪽, 아래, 왼쪽
    
    int visited[100][100] = {0,};
    queue<Pos> q;
    q.push(startPos);
    visited[startPos.x][startPos.y] = 1;
    
    while(!q.empty()){
        // 현재 탐색할 노드
        Pos current_node = q.front();
        q.pop();
        
        int x = current_node.x;
        int y = current_node.y;
        int level = current_node.level;
        
        // printf("현재 지점은 %d,%d이고 count는 %d입니다.\n",x,y,level);
        
        // endpoint에 도달하면 나온다.
        if(x == endPos.x && y == endPos.y){
           return level;
        }
        
        // 동,서,남,북으로 탐색
        for(int i = 0 ; i < 4 ; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            int next_level = level + 1;
            
            // maps 범위에 벗어나지 않으면서 'X'가 아니고 방문한 적 없다면 queue에 추가.
            if(maps_in_range(next_x,next_y) && maps[next_x][next_y] != 'X' && visited[next_x][next_y] != 1){
                      
                q.push({next_x,next_y,next_level});
                visited[next_x][next_y] = 1;
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;

    max_x = maps.size();
    max_y = maps[0].size();
    
    Pos startPos;
    Pos endPos;
    Pos leverPos;
    
    bool startFind = false;
    bool leverFind = false;
    bool endFind = false;
    
    for(int x = 0 ; x < max_x ; x++){
        for(int y = 0 ; y < max_y ; y++){
            
            // 시작 지점
            if(maps[x][y] == 'S'){
                startPos = {x,y,0};
                startFind = true;
            }
            
            // 레버 지점
            if(maps[x][y] == 'L'){
                leverPos = {x,y,0};
                leverFind = true;
            }
            
            // exit 지점 
            if(maps[x][y] == 'E'){
                endPos = {x,y,0};
                endFind = true;
            }
        
        }
        
        // 시작,레버,exit 지점 다 찾았으면 for문 나온다.
        if(startFind && endFind && leverFind){
            break;
        }
    }
    
    // 시작 지점부터 레버 지점까지 최단 거리
    answer = bfs(maps,startPos,leverPos);
    
    
    if(answer != -1){
        
        // 레버 지점부터 끝 지점까지 최단거리
        int temp = bfs(maps,leverPos,endPos);
        
        if(temp == -1){
            answer = -1;
        }else{
            answer += temp;
        }
    }

    return answer;
}