 #circuler queue
size = 5
queue = [None] * size
front = -1
rear = -1

def enqueue(x):
    global front, rear
    if (rear + 1) % size == front:
        print("Queue is Full")
    elif front == -1:
        front = rear = 0
        queue[rear] = x
    else:
        rear = (rear + 1) % size
        queue[rear] = x

def dequeue():
    global front, rear
    if front == -1:
        print("Queue is Empty")
    elif front == rear:
        print("Removed:", queue[front])
        front = rear = -1
    else:
        print("Removed:", queue[front])
        front = (front + 1) % size

def display():
    if front == -1:
        print("Queue is Empty")
    else:
        i = front
        while True:
            print(queue[i], end=" ")
            if i == rear:
           …
[10:33 am, 16/04/2026] +91 81508 40664: #queue
queue = []

def enqueue():
    value = int(input("Enter value: "))
    queue.append(value)
    print("Inserted:", value)

def dequeue():
    if len(queue) == 0:
        print("Queue is empty")
    else:
        print("Removed:", queue.pop(0))

def display():
    print("Queue:", queue)

while True:
    print("\n1.Enqueue 2.Dequeue 3.Display 4.Exit")
    ch = int(input("Enter choice: "))

    if ch == 1:
        enqueue()
    elif ch == 2:
        dequeue()
    elif ch == 3:
        display()
    elif ch == 4:
        break
[10:35 am, 16/04/2026] +91 81508 40664: #simple queue
queue = []

queue.append(10)
queue.append(20)
queue.append(30)

print("Queue:", queue)

queue.pop(0)

print("After Dequeue:", queue)