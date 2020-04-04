#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#define MAX 1000

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);

    queue<pair<int, int> > q;
    int dist[MAX+1][MAX+1];
    
    memset(dist, -1, sizeof(dist));
    
    q.push(make_pair(1, 0));
    dist[1][0] = 0;
    while(!q.empty()) {
        int s = q.front().first;
        int c = q.front().second;
        q.pop();
        if(s == n) {
            printf("%d\n", dist[s][c]);
            break;
        }
        if(dist[s][s] < 0) {
            q.push(make_pair(s, s));
            dist[s][s] = dist[s][c]+1;
        }
        if(s+c <= n && dist[s+c][c] < 0) {
            q.push(make_pair(s+c, c));
            dist[s+c][c] = dist[s][c]+1;
        }
        if(s-1 >= 0 && dist[s-1][c] < 0) {
            q.push(make_pair(s-1, c));
            dist[s-1][c] = dist[s][c]+1;
        }
    }
    return 0;
}