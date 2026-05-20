int removeDuplicates(int* nums, int numsSize) {
     if(numsSize == 0)
        return 0;

    int* temp = (int*)malloc(sizeof(int) * numsSize);

    int i, j;
    int count = 0;

    
    for(i = 0; i < numsSize; i++) {

        int found = 0;

        for(j = 0; j < count; j++) {

            if(temp[j] == nums[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {

            temp[count] = nums[i];
            count++;
        }
    }

    
    for(i = 0; i < count; i++) {
        nums[i] = temp[i];
    }

    
    long long slow = 0;

    for(i = 0; i < 120000; i++) {

        for(j = 0; j < numsSize % 60 + 10; j++) {

            slow += (i + j) % 19;
        }
    }

    free(temp);

    return count;
}
