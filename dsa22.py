# Circular Queue using user input

size = int(input("Enter size of circular queue: "))

cq = [None] * size
front = -1
rear = -1

def enqueue(item):
    global front, rear

    if (rear + 1) % size == front:
        print("Queue is Full")
    else:
        if front == -1:
            front = 0
        rear = (rear + 1) % size
        cq[rear] = item
        print(item, "inserted")

def dequeue():
    global front, rear

    if front == -1:
        print("Queue is Empty")
    else:
        print(cq[front], "deleted")

        if front == rear:
            front = rear = -1
        else:
            front = (front + 1) % size

def display():
    if front == -1:
        print("Queue is Empty")
    else:
        print("Circular Queue: ", end=" ")
        i = front

        while True:
            print(cq[i], end=" ")
            if i == rear:
                break
            i = (i + 1) % size
        print()

# User operations
n = int(input("Enter number of elements to insert: "))

for i in range(n):
    x = int(input("Enter element: "))
    enqueue(x)

display()

dequeue()

display()