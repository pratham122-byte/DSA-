#include <stdio.h>

int maxNumberOfBalloons(char* text) {
    int freq[26] = {0};

    for (int i = 0; text[i] != '\0'; i++) {
        freq[text[i] - 'a']++;
    }

    /* balloon = b(1), a(1), l(2), o(2), n(1) */
    freq['l' - 'a'] /= 2;
    freq['o' - 'a'] /= 2;

    int min = freq['b' - 'a'];

    if (freq['a' - 'a'] < min)
        min = freq['a' - 'a'];

    if (freq['l' - 'a'] < min)
        min = freq['l' - 'a'];

    if (freq['o' - 'a'] < min)
        min = freq['o' - 'a'];

    if (freq['n' - 'a'] < min)
        min = freq['n' - 'a'];

    return min;
}

int main() {
    char text1[] = "nlaebolko";
    char text2[] = "loonbalxballpoon";
    char text3[] = "leetcode";

    printf("%d\n", maxNumberOfBalloons(text1)); // 1
    printf("%d\n", maxNumberOfBalloons(text2)); // 2
    printf("%d\n", maxNumberOfBalloons(text3)); // 0

    return 0;
}
