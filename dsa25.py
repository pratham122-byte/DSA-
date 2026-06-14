# Simple Circular Linked List

class Node:
    def _init_(self, data):
        self.data = data
        self.next = None

head = None

n = int(input("Enter number of nodes: "))

for i in range(n):
    x = int(input("Enter data: "))

    new_node = Node(x)

    if head is None:
        head = new_node
        head.next = head
    else:
        temp = head

        while temp.next != head:
            temp = temp.next

        temp.next = new_node
        new_node.next = head

# Display Circular Linked List
temp = head

print("Circular Linked List:")

if head is not None:
    while True:
        print(temp.data, end=" -> ")
        temp = temp.next

        if temp == head:
            break

print("(Back to Head)")