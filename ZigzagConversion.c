char* convert(char* s, int numRows) {
        int len = strlen(s);
    if(numRows == 1 || len <= numRows) {
        char* ans = (char*)malloc(len + 1);
        strcpy(ans, s);
        return ans;
    }
    char** rows = (char**)malloc(sizeof(char*) * numRows);
    int* index = (int*)calloc(numRows, sizeof(int));
    int i, j;
    for(i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc(len + 1);
    }
    int currentRow = 0;
    int goingDown = 1;
    for(i = 0; i < len; i++) {
        rows[currentRow][index[currentRow]] = s[i];
        index[currentRow]++;
        if(currentRow == numRows - 1)
            goingDown = 0;
        else if(currentRow == 0)
            goingDown = 1;
        if(goingDown)
            currentRow++;
        else
            currentRow--;
    }
    char* result = (char*)malloc(len + 1);
    int pos = 0;
    for(i = 0; i < numRows; i++) {
        for(j = 0; j < index[i]; j++) {
            result[pos++] = rows[i][j];
        }
    }
    result[pos] = '\0';
    for(i = 0; i < numRows; i++) {
        free(rows[i]);
    }
    free(rows);
    free(index);
    return result;

}
