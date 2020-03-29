#include <iostream>
#include <algorithm>

using namespace std;

int D[101][100001];
int V[101];
int W[101];

int main(void) {
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        cin >> W[i] >> V[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(W[i]>j)
                D[i][j] = D[i-1][j];
            else
                D[i][j] = max(V[i]+D[i-1][j-W[i]], D[i-1][j]);
        }
    }

    cout << D[n][k] << '\n';
    return 0;
}