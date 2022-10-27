def select_sort(li):
    for i in range(0,len(li)-1):#第i趟
        min_log=i
        for j in range(i,len(li)):
            if li[j]<li[min_log]:
                li[j],li[min_log]=li[min_log],li[j]
        print(li)
list1=[10,9,8,7,6,5,4,1,2,3]
select_sort(list1)
print(list1)