#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<char> ie, vector<int> max) {
    for(int i=0; i<ie.size(); i++) {
        if(ie[i] == '<') {
            if(max[i] > max[i+1]) {
                return false;
            }
        }
        if(ie[i] == '>') {
            if(max[i] < max[i+1]) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    vector<char> ie;
    vector<int> max;
    vector<int> min;
    
    char c;
    int num;
    cin >> num;
    int cnt = num+1;

    while(num--) {
        cin >> c;
        ie.push_back(c);
    }

    for(int i=9; i>9-(cnt); i--) {
        max.push_back(i);
    }
    for(int i=0; i<cnt; i++) {
        min.push_back(i);
    }

    do {
        if(check(ie, max))
            break;
    } while(prev_permutation(max.begin(), max.end()));

    for(int i=0; i<cnt; i++) {
        printf("%d", max[i]);
    }
    puts("");

    do {
        if(check(ie, min))
            break;
    } while(next_permutation(min.begin(), min.end()));

    for(int i=0; i<cnt; i++) {
        printf("%d", min[i]);
    }
    puts("");

    return 0;
}