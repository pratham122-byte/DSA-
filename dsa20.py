# Deque using user input

from collections import deque

dq = deque()

n = int(input("Enter number of elements: "))

for i in range(n):
    x = int(input("Enter element: "))
    dq.append(x)

print("Deque:", dq)

# Insert at left
left = int(input("Enter element to insert at left: "))
dq.appendleft(left)

# Insert at right
right = int(input("Enter element to insert at right: "))
dq.append(right)

print("Deque after insertion:", dq)

# Delete from left
dq.popleft()

# Delete from right
dq.pop()

print("Deque after deletion:", dq)