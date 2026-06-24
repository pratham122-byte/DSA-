#include <stdio.h>
#include <stdlib.h>

int zigZagArrays(int n, int l, int r) {
    const int MOD = 1000000007;
    int m = r - l + 1;

    long long *up = (long long *)calloc(m, sizeof(long long));
    long long *down = (long long *)calloc(m, sizeof(long long));

    /* Length = 1 */
    for (int i = 0; i < m; i++) {
        up[i] = 1;
        down[i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        long long *nup = (long long *)calloc(m, sizeof(long long));
        long long *ndown = (long long *)calloc(m, sizeof(long long));

        long long pref = 0;

        /* ndown[i] = sum(up[0..i-1]) */
        for (int i = 0; i < m; i++) {
            ndown[i] = pref;
            pref = (pref + up[i]) % MOD;
        }

        long long suff = 0;

        /* nup[i] = sum(down[i+1..m-1]) */
        for (int i = m - 1; i >= 0; i--) {
            nup[i] = suff;
            suff = (suff + down[i]) % MOD;
        }

        free(up);
        free(down);

        up = nup;
        down = ndown;
    }

    long long ans = 0;

    for (int i = 0; i < m; i++) {
        ans = (ans + up[i] + down[i]) % MOD;
    }

    free(up);
    free(down);

    return (int)ans;
}

int main() {
    printf("%d\n", zigZagArrays(3, 4, 5)); // 2
    printf("%d\n", zigZagArrays(3, 1, 3)); // 10

    return 0;
}
