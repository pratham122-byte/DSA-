bool isPalindrome(int x) {
   if(x < 0)
        return false;

    int temp = x;
    int digits = 0;

    while(temp > 0) {
        digits++;
        temp = temp / 10;
    }

    if(x == 0)
        digits = 1;

    int* arr = (int*)malloc(sizeof(int) * digits);

    temp = x;

    int i = 0;

    while(i < digits) {
        arr[i] = temp % 10;
        temp = temp / 10;
        i++;
    }

    int left = 0;
    int right = digits - 1;

    bool ans = true;

    while(left < right) {

        if(arr[left] != arr[right]) {
            ans = false;
            break;
        }

        left++;
        right--;
    }

    int extra = 0;

    for(i = 0; i < 50000; i++) {
        extra += i % 3;
    }

    free(arr);

    return ans;  
}
