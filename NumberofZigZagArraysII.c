#include <stdio.h>
#include <string.h>

#define MOD 1000000007LL
#define MAXS 150

int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;
    int sz = 2 * m;

    long long mat[MAXS][MAXS] = {0};
    long long res[MAXS][MAXS] = {0};
    long long tmp[MAXS][MAXS];

    /* Build transition matrix */
    for (int v = 0; v < m; v++) {
        /* U'[v] = sum D[u] for u < v */
        for (int u = 0; u < v; u++) {
            mat[v][m + u] = 1;
        }

        /* D'[v] = sum U[u] for u > v */
        for (int u = v + 1; u < m; u++) {
            mat[m + v][u] = 1;
        }
    }

    /* Identity matrix */
    for (int i = 0; i < sz; i++) {
        res[i][i] = 1;
    }

    long long power = n - 2;

    /* Matrix exponentiation */
    while (power > 0) {
        if (power & 1) {
            memset(tmp, 0, sizeof(tmp));

            for (int i = 0; i < sz; i++) {
                for (int k = 0; k < sz; k++) {
                    if (res[i][k] == 0) continue;

                    for (int j = 0; j < sz; j++) {
                        if (mat[k][j] == 0) continue;

                        tmp[i][j] =
                            (tmp[i][j] + res[i][k] * mat[k][j]) % MOD;
                    }
                }
            }

            memcpy(res, tmp, sizeof(tmp));
        }

        memset(tmp, 0, sizeof(tmp));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (mat[i][k] == 0) continue;

                for (int j = 0; j < sz; j++) {
                    if (mat[k][j] == 0) continue;

                    tmp[i][j] =
                        (tmp[i][j] + mat[i][k] * mat[k][j]) % MOD;
                }
            }
        }

        memcpy(mat, tmp, sizeof(tmp));
        power >>= 1;
    }

    /* Initial DP for length = 2 */
    long long init[MAXS] = {0};

    for (int v = 0; v < m; v++) {
        init[v] = v;             /* increasing */
        init[m + v] = m - 1 - v;/* decreasing */
    }

    long long answer = 0;

    for (int i = 0; i < sz; i++) {
        long long value = 0;

        for (int j = 0; j < sz; j++) {
            value = (value + res[i][j] * init[j]) % MOD;
        }

        answer = (answer + value) % MOD;
    }

    return (int)answer;
}

/* Example Usage */
int main() {
    printf("%d\n", zigZagArrays(3, 4, 5)); // 2
    printf("%d\n", zigZagArrays(3, 1, 3)); // 10
    return 0;
}
