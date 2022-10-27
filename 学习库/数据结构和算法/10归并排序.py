'''
2   4   6   8 || 1  3   5   7
i          mid mid+1        high
1   2   3   4   5   6   7   8
'''
def merge(li,low,mid,high):
    i=low
    j=mid+1
    li_tmp=[]
    while i<=mid and j<=high:  # 左右两边ij都有数 就相互比较
        if li[i]<=li[j]:
            li_tmp.append(li[i])
            i+=1
        else:
            li_tmp.append(li[j])
            j+=1
    #到这里肯定有一边没数了
    while i<=mid:
        li_tmp.append(li[i])
        i+=1
    while j<=high:
        li_tmp.append(li[j])
        j+=1
    li[low:high+1]=li_tmp[:]  # 注意li[low:high+1]只是整个li的一部分

#  用’递归‘的方法实现归并排序
def merge_sort(li,low,high):  # merge_sort--->归并排序  #
    if low<high:
        mid=(low+high)//2           # 第一步：找到中间点把两边分开
        merge_sort(li,low,mid)      # 第二部：把左边归并排序
        merge_sort(li,mid+1,high)   # 第三部：把右边归并排序
        merge(li,low,mid,high)      # 第四部：把两边归并

list1=list(range(1,26))
import random
random.shuffle(list1)
print(list1)
print('*******归并后*******')
merge_sort(list1,0,len(list1)-1)
print(list1)
