#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define NUM 9

bool chk[NUM];
vector<int> node_Tree[NUM];

void dfs(int start)
{
    stack<int> s; // 탐색 순서를 담을 스택.
    s.push(start);  // 시작 인덱스 값 push
    chk[start] = true;  // 시작 인덱스는 확인 됬으므로 true

    while(!s.empty())
    {
        int cur_Node = s.top();
        s.pop();

        for(int i=0; i < node_Tree[cur_Node].size(); i++)
        {
            int get_Node = node_Tree[cur_Node][i];  // 찾은 노드값 가져오기

            if(!chk[get_Node]) //찾은 노드값이 처음 보는 값이라면..
            {
                chk[get_Node] = true;
                dfs(get_Node); // 재귀 반복.
            }
        }
    }
}

int main(void)
{
    node_Tree[1].push_back(2);
    node_Tree[1].push_back(3);

    node_Tree[2].push_back(4);

    node_Tree[3].push_back(5);
    node_Tree[3].push_back(6);

    node_Tree[4].push_back(7);
    node_Tree[4].push_back(8);

    dfs(1);

}