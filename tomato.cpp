#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int field[1000][1000];
int dist[1000][1000];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void) {
    int n, m;
    queue<pair<int, int> > q;
    memset(dist, 0, sizeof(dist));
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &field[i][j]);
            if(field[i][j]==1) {
                q.push(make_pair(i, j));
            }
        }
    }

    bool zero_check = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(field[i][j]==0) {
                zero_check = false;
            }
        }
    }
    if(zero_check) {
        printf("%d\n", 0);
        return 0;
    }
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if(0 <= a && a < n && 0 <= b && b < m) {
                if(field[a][b] == 0) {
                    q.push(make_pair(a, b));
                    field[a][b] = 1;
                    dist[a][b] = dist[x][y]+1;
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(field[i][j]==0) {
                printf("%d\n", -1);
                return 0;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(ans < dist[i][j]) {
                ans = dist[i][j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}