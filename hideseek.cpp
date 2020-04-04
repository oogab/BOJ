#include <iostream>
#include <cstring>
#include <queue>
#define MAX 100000

using namespace std;

bool check[MAX+1];
int dist[MAX+1];

void ClearQueue(queue<int> &someQueue)
{
    queue<int> empty;
    swap(someQueue, empty);
}

int find(int n, int k) {
    queue<int> q;
    q.push(n); dist[n] = 0; check[n] = true;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(now==k) {
            ClearQueue(q);
            return dist[now];
        }
        if(now+1 <= MAX && !check[now+1]) {
            q.push(now+1);
            dist[now+1] = dist[now] + 1;
            check[now+1] = true;
        }
        if(0 <= now-1 && !check[now-1]) {
            q.push(now-1);
            dist[now-1] = dist[now] + 1;
            check[now-1] = true;
        }
        if(2*now <= MAX && !check[2*now]) {
            q.push(2*now);
            dist[2*now] = dist[now] + 1;
            check[2*now] = true;
        }
    }
    return 0;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(check, false, sizeof(check));
    memset(dist, 0, sizeof(dist));
    printf("%d\n", find(n, k));
    return 0;
}