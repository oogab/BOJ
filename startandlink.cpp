#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    int S[n][n];
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        if(i<n/2) a[i] = 0;
        else a[i] = 1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &S[i][j]);
        }
    }
    int ans=1000000000;
    do {
        vector<int> s_0;
        vector<int> s_1;
        for(int i=0; i<n; i++) {
            if(a[i]==0) s_0.push_back(i);
            else s_1.push_back(i);
        }
        int t_1=0;
        int t_2=0;
        for(int i=0; i<n/2-1; i++) {
            for(int j=i+1; j<n/2; j++) {
                t_1 += S[s_0[i]][s_0[j]] + S[s_0[j]][s_0[i]];
                t_2 += S[s_1[i]][s_1[j]] + S[s_1[j]][s_1[i]];
            }
        }
        int tmp = abs(t_1-t_2);
        if(ans > tmp) ans = tmp;
    }while(next_permutation(a.begin(), a.end()));

    printf("%d\n", ans);
    return 0;
}