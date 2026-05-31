queue = []

def enqueue():
    value = int(input("Enter value to enqueue: "))
    queue.append(value)
    print("Enqueued:", value)
    print("Queue now:", queue)

def dequeue():
    if len(queue) == 0:
        print("Queue is empty")
    else:
        print("Dequeued:", queue.pop(0))
        print("Queue now:", queue)

def peek():
    if len(queue) == 0:
        print("Queue is empty")
    else:
        print("Front element is:", queue[0])

while True:
    print("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit")
    choice = int(input("Enter choice: "))

    if choice == 1:
        enqueue()
    elif choice == 2:
        dequeue()
    elif choice == 3:
        peek()
    elif choice == 4:
        break
    else:
        print("Invalid choice")