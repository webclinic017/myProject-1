def insert_sort_gap(li,gap):
    for i in range(gap,len(li)):
        tmp=li[i]
        j=i-gap
        while j>=0 and li[j]>tmp:
            li[j+gap]=li[j]
            j-=gap
        li[j+gap]=tmp


def shall_sort(li):
    d=len(li)//2
    while d>=1:
        insert_sort_gap(li,d)
        d=d//2


list1=[5,7,4,6,3,1,2,9,8]
shall_sort(list1)
print(list1)
