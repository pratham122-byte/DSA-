# Simple Singly Linked List

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
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = new_node

# Display Linked List
temp = head

print("Linked List:")

while temp:
    print(temp.data, end=" -> ")
    temp = temp.next

print("None")