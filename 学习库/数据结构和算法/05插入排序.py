def insert_sort(li):
    for i in range(1,len(li)):
        tmp=li[i]
        j=i-1
        while j>=0 and li[j]>tmp:
            li[j+1]=li[j]
            j-=1
        li[j+1]=tmp
        print(li)
list1=[3,6,9,2,3,2,5,5,8,1,4,7,15,30,17,16,13,20]
insert_sort(list1)
print(list1)
