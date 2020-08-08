#include <iostream>

#include <queue>
#include <vector>

using namespace std;

#define NUM 9

int number = NUM;
bool chk[NUM];

vector<int> node_Tree[NUM];

void bfs(int start) // 시작 인덱스값을 할당.
{
    queue<int> q; // 탐색 순서를 담을 큐
    q.push(start); // 시작 인덱스 값 push
    chk[start] = true;  // start 먼저 체크 하였으니 true

    while(!q.empty())   // q 가 비여질 때까지 돌린다.
    {
        int cur_Node = q.front();   // 맨 처음 노드값 가져오기
        q.pop();
        
        for(int i = 0; i < node_Tree[cur_Node].size(); i++) // 현제 노드 값에 연결 되어 있는 노드를 찾는다.
        {
            int get_Node = node_Tree[cur_Node][i];  // 찾은 노드값 가져오기

            if(!chk[get_Node])  // 처음 보드 노드 값이라면..
            {
                q.push(get_Node);
                chk[get_Node] = true;
                // 다음 찾을 값으로 큐에 배정 하고 체크 true 해준다.
            }
        }
    }

}