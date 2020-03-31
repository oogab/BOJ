#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
bool check[1001];
vector<int> edges[1001];

void dfs(int x) {
    check[x] = true;
    cout << x << " ";
    for(int i=0; i<edges[x].size(); i++) {
        int next = edges[x][i];
        if(check[next]) continue;
        dfs(next);
    }
    return;
}

void bfs(int x) {
    queue<int> q;
    memset(check, false, sizeof(check));
    check[x] = true;
    q.push(x);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i=0; i<edges[node].size(); i++) {
            int next = edges[node][i];
            if(check[next]) continue;
            check[next] = true;
            q.push(next);
        }

    }
    
}

int main(void) {
    cin >> n >> m >> v;
    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        sort(edges[i].begin(), edges[i].end()); 
    }
    dfs(v);
    puts("");
    bfs(v);
    puts("");
    return 0;
}