char* longestPalindrome(char* s) {
    int n = strlen(s);

    if (n <= 1)
        return s;

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {

        // Even length palindrome
        int l = i;
        int r = i + 1;

        while (l >= 0 && r < n && s[l] == s[r]) {

            int len = r - l + 1;

            if (len > maxLen) {
                start = l;
                maxLen = len;
            }

            l--;
            r++;
        }

        // Odd length palindrome
        l = i - 1;
        r = i + 1;

        while (l >= 0 && r < n && s[l] == s[r]) {

            int len = r - l + 1;

            if (len > maxLen) {
                start = l;
                maxLen = len;
            }

            l--;
            r++;
        }
    }

    char* ans = (char*)malloc(maxLen + 1);

    memcpy(ans, s + start, maxLen);

    ans[maxLen] = '\0';

    return ans;
}
