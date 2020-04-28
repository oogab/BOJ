#include <iostream>
#include <utility>
#include <cstring>
#include <queue>

using namespace std;

char map[51][51];
int water[51][51];
int hog[51][51];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void) {
    int n, m;
    int d_n, d_m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> map[i][j];
        }
    }

    queue<pair<int, int> > w_q;
    queue<pair<int, int> > h_q;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(map[i][j]=='*') {
                w_q.push(make_pair(i, j));
                continue;
            }
            if(map[i][j]=='S') {
                h_q.push(make_pair(i, j));
                continue;
            }
            if(map[i][j]=='D') {
                d_n = i;
                d_m = j;
                continue;
            }
        }
    }

    memset(water, -1, sizeof(water));
    int w_x = w_q.front().first;
    int w_y = w_q.front().second;
    water[w_x][w_y] = 0;
    while(!w_q.empty()) {
        int x = w_q.front().first;
        int y = w_q.front().second;
        w_q.pop();
        for(int i=0; i<4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if(0 < a && a <=n && 0 < b && b <= m) {
                if(map[a][b]=='D') continue;
                if(map[a][b]=='X') continue;
                if(water[a][b]==-1) {
                    w_q.push(make_pair(a, b));
                    water[a][b] = water[x][y] + 1;
                }
            }
        }
    }

    memset(hog, -1, sizeof(hog));
    int h_x = h_q.front().first;
    int h_y = h_q.front().second;
    hog[h_x][h_y] = 0;
    while(!h_q.empty()) {
        int x = h_q.front().first;
        int y = h_q.front().second;
        h_q.pop();
        for(int i=0; i<4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            if(0 < a && a <= n && 0 < b && b <= m) {
                if(hog[a][b]!=-1) continue;
                if(map[a][b]=='X') continue;
                if(map[a][b]=='*') continue;
                if(water[a][b]!=-1 && hog[x][y]+1 >= water[a][b]) continue;
                hog[a][b] = hog[x][y] + 1;
                h_q.push(make_pair(a, b));
            }
        }
    }

    if(hog[d_n][d_m]==-1) {
        printf("KAKTUS\n");
    }
    else {
        printf("%d\n", hog[d_n][d_m]);
    }
    return 0;
}