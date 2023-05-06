 

def bubbleSort(arr):

    n = len(arr)
 


    for i in range(n-1):


 
        print("pass :",i+1)

        for j in range(0, n-i-1):
 

            if arr[j] > arr[j + 1] :

                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            print(arr)

        print("\n")        
''' 
# Driver code to test above
n = int(input("How many elements to be store in array : "))
arr = []
print("Enter the elements of array : ")
for i in range(n):
    y = input()
    arr.append(y)

print("input array is : ",arr)
'''
arr = [90,45,88,75,60,89,98,21,1,3,0,2]
 
bubbleSort(arr)
 

print ("Sorted array is:",arr)

