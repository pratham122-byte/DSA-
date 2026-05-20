int removeElement(int* nums, int numsSize, int val) {
    int size = numsSize;
    int i = 0;

    while (i < size) {
        if (nums[i] == val) {
            /* Shift every element left by one — O(n) per removal */
            for (int j = i; j < size - 1; j++) {
                nums[j] = nums[j + 1];
            }
            size--;
            /* Don't advance i — the shifted element needs checking */
        } else {
            i++;
        }
    }

    return size;
}
