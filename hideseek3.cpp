#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1000000

using namespace std;

bool check[MAX];
int dist[MAX];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    queue<int> q;
    queue<int> qplus;
    //memset(check, false, sizeof(check));
    //memset(dist, 0, sizeof(dist));

    q.push(n);
    check[n] = true;
    dist[n] = 0;

    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(!check[2*x] && 2*x < MAX) {
            q.push(2*x);
            check[2*x] = true;
            dist[2*x] = dist[x];
        }
        if(!check[x-1] && x-1 >= 0) {
            qplus.push(x-1);
            check[x-1] = true;
            dist[x-1] = dist[x] + 1;
        }
        if(!check[x+1] && x+1 < MAX) {
            qplus.push(x+1);
            check[x+1] = true;
            dist[x+1] = dist[x] + 1;
        }
        if(q.empty()) {
            q = qplus;
            qplus = queue<int>();
        }
    }
    printf("%d\n", dist[k]);
    return 0;
}