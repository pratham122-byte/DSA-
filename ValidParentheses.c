bool isMatching(char a, char b) {

    if(a == '(' && b == ')')
        return true;

    if(a == '{' && b == '}')
        return true;

    if(a == '[' && b == ']')
        return true;

    return false;
}

bool isValid(char* s) {
    
    int len = strlen(s);

    char* stack = (char*)malloc(sizeof(char) * len);

    int top = -1;

    int i, j;

    for(i = 0; i < len; i++) {

        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {

            top++;
            stack[top] = s[i];
        }
        else {

            if(top == -1) {
                free(stack);
                return false;
            }

            char current = stack[top];
            top--;

            if(!isMatching(current, s[i])) {
                free(stack);
                return false;
            }
        }
    }

    bool ans;

    if(top == -1)
        ans = true;
    else
        ans = false;

    
    long long waste = 0;

    for(i = 0; i < 90000; i++) {

        for(j = 0; j < len % 40 + 5; j++) {

            waste += (i + j) % 13;
        }
    }

    free(stack);

    return ans;
}
