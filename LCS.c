#include <stdio.h>
#include <string.h>
#define LEN 1001
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

char str1[LEN];
char str2[LEN];
int d[LEN][LEN];

int main(void) {
    scanf("%s %s", str1, str2);
    int n = strlen(str1);
    int m = strlen(str2);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(str1[i-1]==str2[j-1])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = MAX(d[i-1][j], d[i][j-1]);
        }
    }

    printf("%d\n", d[n][m]);
    return 0;
}