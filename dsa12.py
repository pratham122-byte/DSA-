stack = []

stack.append(10)
stack.append(20)
stack.append(30)

print("Stack after push:", stack)

removed = stack.pop()
print("Popped element:", removed)
print("Stack after pop:", stack)

top = stack[-1]
print("Top element (peek):", top)

if len(stack) == 0:
    print("Stack is empty")
else:
    print("Stack is not empty")