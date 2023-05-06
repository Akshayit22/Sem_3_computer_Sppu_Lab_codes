def Sequential_Search(dlist, item):

    pos = 0
    found = False
    for i in range (0,len(dlist)):
        if(dlist[i] == item):
            print("element found at position ",i+1)
            found = True
            return
    if(i==len(dlist)):
        print("element not found")
    return

print(Sequential_Search([11,23,58,31,56,77,43,12,65,19],19))
