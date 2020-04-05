#include <iostream>
#include <cstring>
#include <deque>
#define MAX 100000

bool c[MAX+1];
int d[MAX+1];

using namespace std;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(c, false, sizeof(c));
    memset(d, 0, sizeof(d));
    deque<int> q;
    q.push_back(n);
    c[n] = true;
    d[n] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop_front();
        if(2*now <= MAX) {
            if(!c[2*now]) {
                q.push_front(2*now);
                c[2*now] = true;
                d[2*now] = d[now];
            }
        }
        if(now-1 >= 0) {
            if(!c[now-1]) {
                q.push_back(now-1);
                c[now-1] = true;
                d[now-1] = d[now] + 1;
            }
        }
        if(now+1 <= MAX) {
            if(!c[now+1]) {
                q.push_back(now+1);
                c[now+1] = true;
                d[now+1] = d[now] + 1;
            }
        }
    }
    printf("%d\n", d[k]);
    return 0;
}