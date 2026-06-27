#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    long long key;
    int cnt;
    struct Node *next;
} Node;

#define SIZE 262147

Node *table[SIZE];

unsigned int hash(long long x) {
    return (unsigned int)(x % SIZE);
}

void insert(long long x) {
    unsigned int h = hash(x);
    Node *p = table[h];
    while (p) {
        if (p->key == x) {
            p->cnt++;
            return;
        }
        p = p->next;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->key = x;
    node->cnt = 1;
    node->next = table[h];
    table[h] = node;
}

int getCount(long long x) {
    unsigned int h = hash(x);
    Node *p = table[h];
    while (p) {
        if (p->key == x)
            return p->cnt;
        p = p->next;
    }
    return 0;
}

int maximumLength(int* nums, int numsSize) {
    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    for (int i = 0; i < numsSize; i++)
        insert(nums[i]);

    int ans = 1;

    // Handle number 1 separately
    int ones = getCount(1);
    if (ones > 0) {
        if (ones % 2 == 0)
            ones--;
        if (ones > ans)
            ans = ones;
    }

    for (int i = 0; i < numsSize; i++) {
        long long x = nums[i];

        if (x == 1)
            continue;

        long long cur = x;
        int len = 1;

        while (1) {
            if (cur > 1000000000LL)
                break;

            if (getCount(cur) < 2)
                break;

            if (cur > 31622LL)
                break;   // next square exceeds 1e9

            long long nxt = cur * cur;

            if (getCount(nxt) == 0)
                break;

            len += 2;
            cur = nxt;
        }

        if (len > ans)
            ans = len;
    }

    return ans;
}
