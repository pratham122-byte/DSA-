#include <stdlib.h>

typedef struct {
    int n;
    int *bit;
} Fenwick;

void update(Fenwick *fw, int idx, int val) {
    while (idx <= fw->n) {
        fw->bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(Fenwick *fw, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += fw->bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int lowerBound(int *arr, int size, int x) {
    int l = 0, r = size;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    int *pref = (int *)malloc((numsSize + 1) * sizeof(int));
    pref[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
    }

    int *vals = (int *)malloc((numsSize + 1) * sizeof(int));
    for (int i = 0; i <= numsSize; i++)
        vals[i] = pref[i];

    qsort(vals, numsSize + 1, sizeof(int), cmp);

    int m = 0;
    for (int i = 0; i <= numsSize; i++) {
        if (i == 0 || vals[i] != vals[i - 1])
            vals[m++] = vals[i];
    }

    Fenwick fw;
    fw.n = m;
    fw.bit = (int *)calloc(m + 1, sizeof(int));

    long long ans = 0;

    for (int i = 0; i <= numsSize; i++) {
        int idx = lowerBound(vals, m, pref[i]) + 1;

        // count previous prefix sums strictly smaller than current
        ans += query(&fw, idx - 1);

        update(&fw, idx, 1);
    }

    free(pref);
    free(vals);
    free(fw.bit);

    return ans;
}
