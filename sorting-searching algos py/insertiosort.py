
def insertionSort(arr): 


    for i in range(1, len(arr)): 

  

        key = arr[i] 

        j = i-1

        while j >=0 and key < arr[j] : 

                arr[j+1] = arr[j] 

                j -= 1

        arr[j+1] = key 
        print(key,"----",arr)
  

  
# Driver code to test above 

arr = [12, 11, 13, 5, 6] 
print("Array given is :\n",arr)
insertionSort(arr) 

print ("\nSorted array is:") 
print(arr)
#for i in range(len(arr)): 

#    print ("%d" %arr[i]) 

  