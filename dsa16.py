stack = []

exp = ["2", "3", "4", "*", "+"]

for i in exp:
    if i.isdigit():
        stack.append(int(i))
    else:
        b = stack.pop()
        a = stack.pop()

        if i == '+':
            stack.append(a + b)
        elif i == '-':
            stack.append(a - b)
        elif i == '*':
            stack.append(a * b)
        elif i == '/':
            stack.append(a / b)

print("Result:", stack[0])