queue = []

def enqueue(value):
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

enqueue(10)
enqueue(20)
enqueue(30)

peek()

dequeue()
dequeue()

peek()