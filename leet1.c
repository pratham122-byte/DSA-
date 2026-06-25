#include <stdio.h>

int countMajoritySubarrays(int* nums, int numsSize, int target) {
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int targetFreq = 0;

        for (int j = i; j < numsSize; j++) {
            if (nums[j] == target)
                targetFreq++;

            int len = j - i + 1;

            if (targetFreq > len / 2)
                count++;
        }
    }

    return count;
}

int main() {
    int nums[] = {1, 2, 2, 3};
    int target = 2;
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = countMajoritySubarrays(nums, n, target);

    printf("Number of subarrays: %d\n", result);

    return 0;
}
