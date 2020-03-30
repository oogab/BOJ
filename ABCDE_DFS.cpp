#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int cnt = 1;
int ans = 0;
bool check[2000];
vector<int> edges[2000];

void dfs(int x) {
    check[x] = true;
    if(cnt==5) {
        ans = 1;
        return;
    }
    for(int i=0; i<edges[x].size(); i++) {
        int next = edges[x][i];
        if(check[next]) continue;
        cnt += 1;
        dfs(next);
        cnt -= 1;
    }
    //check[x] = false;
    return;
}

int main(void) {
    int n, m, a, b;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    memset(check, false, sizeof(check));

    for(int i=0; i<=n; i++) {
        dfs(i);
        if(ans==1) break;
    }

    cout << ans << '\n';
    return 0;
}