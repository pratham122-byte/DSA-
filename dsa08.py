import array
arr = []
n=int(input("enter number of element :"))
for i in range(n):
    num = int(input("Enter element: "))
    arr.append(num)
print("array:",arr)
indx=int(input("enter the index  value for inserting:"))
val=int(input("enter the value "))
arr.insert(indx,val)
print("array after inserting values:",arr)
indx=int(input("enter the index value for delection"))
arr.pop(indx)
print("array after delection:",arr)
