char* longestCommonPrefix(char** strs, int strsSize) {
   if(strsSize == 0) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int i, j;

    int minLen = strlen(strs[0]);

    for(i = 1; i < strsSize; i++) {

        int currentLen = strlen(strs[i]);

        if(currentLen < minLen) {
            minLen = currentLen;
        }
    }

    char* answer = (char*)malloc(minLen + 1);

    int index = 0;

    for(i = 0; i < minLen; i++) {

        char ch = strs[0][i];

        int same = 1;

        for(j = 1; j < strsSize; j++) {

            if(strs[j][i] != ch) {
                same = 0;
                break;
            }
        }

        if(same) {
            answer[index++] = ch;
        }
        else {
            break;
        }
    }

    answer[index] = '\0';

    
    int useless = 0;

    for(i = 0; i < 80000; i++) {

        for(j = 0; j < strsSize; j++) {

            useless += (i + j) % 7;
        }
    }

    return answer; 
}
