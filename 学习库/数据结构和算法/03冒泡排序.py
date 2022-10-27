def bubble_sort(li):
    for i in range(0,len(li)-1):#第i趟
        exchange=False
        for j in range(0,len(li)-1-i):
            if li[j]>li[j+1]:
                li[j],li[j + 1]=li[j+1],li[j]
                exchange=True
        if not exchange: #防止重复做无用功
            return
        print(li)
list2=[10,9,8,7,1,2,3,4,5,6]
print(list2)
bubble_sort(list2)
# print(list2)