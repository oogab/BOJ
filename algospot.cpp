#include <iostream>
#include <cstring>
#include <utility>
#include <deque>

using namespace std;

int map[101][101];
int d[101][101];
bool c[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
    int n, m;
    scanf("%d %d", &m, &n);

    memset(d, 0, sizeof(d));
    memset(c, false, sizeof(c));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    deque<pair<int, int> > q;
    q.push_back(make_pair(1, 1));
    c[1][1] = true;
    d[1][1] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for(int i=0; i<4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if(0 < a && a <= n && 0 < b && b <= m ) {
                if(c[a][b]==false && map[a][b]==0) {
                    q.push_front(make_pair(a, b));
                    d[a][b] = d[x][y];
                    c[a][b] = true;
                }
                if(c[a][b]==false && map[a][b]==1) {
                    q.push_back(make_pair(a, b));
                    d[a][b] = d[x][y] + 1;
                    c[a][b] = true;
                }
            }
        }
    }

    printf("%d\n", d[n][m]);
    return 0;
}