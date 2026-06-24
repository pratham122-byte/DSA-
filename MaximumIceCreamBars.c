#include <stdio.h>
#include <stdlib.h>

int maxIceCream(int* costs, int costsSize, int coins) {
    int maxCost = 0;

    /* Find maximum cost */
    for (int i = 0; i < costsSize; i++) {
        if (costs[i] > maxCost) {
            maxCost = costs[i];
        }
    }

    /* Frequency array */
    int *freq = (int *)calloc(maxCost + 1, sizeof(int));

    for (int i = 0; i < costsSize; i++) {
        freq[costs[i]]++;
    }

    int count = 0;

    /* Buy cheapest bars first */
    for (int cost = 1; cost <= maxCost; cost++) {
        while (freq[cost] > 0 && coins >= cost) {
            coins -= cost;
            count++;
            freq[cost]--;
        }
    }

    free(freq);
    return count;
}

int main() {
    int costs1[] = {1, 3, 2, 4, 1};
    int coins1 = 7;

    int costs2[] = {10, 6, 8, 7, 7, 8};
    int coins2 = 5;

    int costs3[] = {1, 6, 3, 1, 2, 5};
    int coins3 = 20;

    printf("%d\n", maxIceCream(costs1, 5, coins1)); // 4
    printf("%d\n", maxIceCream(costs2, 6, coins2)); // 0
    printf("%d\n", maxIceCream(costs3, 6, coins3)); // 6

    return 0;
}
