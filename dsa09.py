import array
arr = []
n=int(input("enter number of element :"))
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
print("array:",arr)
indx=int(input("enter the index  value for inserting:"))
val=int(input("enter the value "))
arr.append(0)
for i in range(n,indx-1,-1):
    arr[i]=arr[i-1]
arr[indx-1]=val
n=n+1
print("array after insertion:",arr)
indx=int(input("enter the index  value for delection:"))
for i in range(indx-1,n-1):
    arr[i]=arr[i+1]
arr.pop()
n=n-1
print("array after insertion:",arr)

