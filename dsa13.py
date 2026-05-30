stack = []

def push():
    value = int(input("Enter value to push: "))
    stack.append(value)
    print("Pushed:", value)
    print("Stack now:", stack)

def pop():
    if len(stack) == 0:
        print("Stack is empty")
    else:
        print("Popped:", stack.pop())
        print("Stack now:", stack)

def peek():
    if len(stack) == 0:
        print("Stack is empty")
    else:
        print("Top element is:", stack[-1])

while True:
    print("\n1. Push\n2. Pop\n3. Peek\n4. Exit")
    choice = int(input("Enter choice: "))

    if choice == 1:
        push()
    elif choice == 2:
        pop()
    elif choice == 3:
        peek()
    elif choice == 4:
        break
    else:
        print("Invalid choice")