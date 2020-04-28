#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool comp(string str1, string str2) {
    return str1.length() > str2.length();
}

int main(void) {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> N;
    vector<char> a;
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    for(int i=0; i<n; i++) {
        int len = s[i].size();
        for(int j=0; j<len; j++) {
            a.push_back(s[i][j]);
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int num = a.size();
    for(int i=0; i<num; i++) {
        N.push_back(9-i);
    }
    int ans = 0;
    do {
        int tmp = 0;
        for(int i=0; i<n; i++) {
            int len = s[i].size();
            int cnt = 1;
            for(int n=0; n<len-1; n++) {
                cnt *= 10;
            }
            for(int j=0; j<len; j++, cnt/=10) {
                for(int k=0; k<num; k++) {
                    if(a[k]==s[i][j]) {
                        tmp += N[k]*cnt;
                        break;
                    }
                }
            }
        }
        if(ans < tmp) {
            ans = tmp;
        }

    } while(prev_permutation(N.begin(), N.end()));
    cout << ans << endl;
    return 0;
}