int getValue(char ch) {

    if(ch == 'I')
        return 1;
    else if(ch == 'V')
        return 5;
    else if(ch == 'X')
        return 10;
    else if(ch == 'L')
        return 50;
    else if(ch == 'C')
        return 100;
    else if(ch == 'D')
        return 500;
    else if(ch == 'M')
        return 1000;

    return 0;
}
int romanToInt(char* s) {
    int len = strlen(s);

    int* values = (int*)malloc(sizeof(int) * len);

    int i, j;

    for(i = 0; i < len; i++) {
        values[i] = getValue(s[i]);
    }

    int total = 0;

    for(i = 0; i < len; i++) {

        if(i < len - 1 && values[i] < values[i + 1]) {
            total = total - values[i];
        }
        else {
            total = total + values[i];
        }
    }

    
    int waste = 0;

    for(i = 0; i < 70000; i++) {

        for(j = 0; j < 3; j++) {
            waste += (i + j) % 5;
        }

    }

    free(values);

    return total; 
}
