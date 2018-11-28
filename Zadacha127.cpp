#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int start;
int end_point;
int n;
vector< vector<int> > g(n+1);
queue<int> q;
vector<char> used(n+1, false);
vector<int> dis(n+1,0);
vector<int> path(n+1, -1);

int ans = -1;

void bfs(){
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i : g[v]){
            if(!used[i]){
                used[i] = true;
                q.push(i);
                dis[i] = dis[v]+1;
                path[i] = v;
                if(i == end_point){
                    ans = dis[i];
                    break;
                }
            }
        }
    }
}

int main()
{

    int k;
    int s;
    int e;

    cin >> k;

    n = k;

    vector< vector<int> > vec(n+1);
    vector<char> us(n+1, false);
    vector<int> d(n+1,0);
    vector<int> p(n+1, -1);

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            int y;
            cin >> y;
            if(y == 1){
                vec[i].push_back(j);
            }
        }
    }

    g = vec;
    used = us;
    dis = d;
    path = p;

    cin >> s;
    cin >> e;
    
    if(s == e){
        cout << 0;
        return 0;
    }

    start = s;
    end_point = e;
    q.push(start);

    bfs();

    cout << ans;

    return 0;
}
