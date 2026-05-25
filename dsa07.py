import array
arr = array.array('i', [])
n=int(input("how many time :"))
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
print("\nElements in the array are:")
for i in arr:
    print(i)