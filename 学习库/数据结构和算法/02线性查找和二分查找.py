# 线性查找
def line_search(li,val):
    for ind,v in enumerate(li):
        if v==val:
            return ind
        else:
            return None

# 二分查找
def binary_search(li,val):
    left=0
    right=len(li)-1
    while left<=right:
        mid=(left+right)//2
        if li[mid]==val:
            return mid
        elif li[mid]>val:
            right=mid-1
        else:
            left=mid+1
    else:
        return False
list1=[1,3,5,7,9,11,13,15,17,19,21,23,25,27,29]
print(binary_search(list1,15))