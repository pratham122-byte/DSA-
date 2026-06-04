queue = []

def enqueue(value):   # ✅ FIXED
    queue.append(value)
    print(f"{value} added to queue")
    print("Queue:", queue)

def dequeue():
    if len(queue) == 0:
        print("Queue is empty")
    else:
        removed = queue.pop(0)
        print(f"{removed} removed from queue")
        print("Queue:", queue)


# Example
enqueue(10)
enqueue(20)
enqueue(30)

dequeue()
dequeue()