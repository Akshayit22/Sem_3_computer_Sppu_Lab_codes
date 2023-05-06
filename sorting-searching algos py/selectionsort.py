
import sys 

A = [64, 25, 12, 22, 11, 1] 
print("array given is:\n",A)
print("\n")  


for i in range(len(A)): 

    min_idx = i 

    for j in range(i+1, len(A)): 

        if A[min_idx] > A[j]: 

            min_idx = j

    print(A[j])
    A[i], A[min_idx] = A[min_idx], A[i]
    print(A) 

  
# Driver code to test above 

print ("Sorted array") 

print(A)