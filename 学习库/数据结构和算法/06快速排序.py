def partition(li,left,right):
    tmp=li[left]                            #把第一个值暂时赋给tmp
    while left<right:
        while left<right and li[right]>=tmp: #从右边找比tmp小的数
            right-=1                         #找不到往左移动一位
        li[left]=li[right]
        while left<right and li[left]<=tmp: #从左边找比tmp大的数
            left+=1                        #找不到往右移动一位
        li[right]=li[left]
    li[left]=tmp                           #最中间的数赋值tmp的值上去
    return left
def quick_sort(li,left,right):
    if left<right:                         #左右标重叠退出递归函数
        mid=partition(li,left,right)       #执行一次partition 找出中间值，分开左右两边，左小右大，
        quick_sort(li,left,mid-1)          #对左半部分执行递归
        quick_sort(li,mid+1,right)         #对右半边执行递归
list1=[5,7,4,6,3,1,2,9,8,15,14,16,18,17,17,16,16,15,15]
quick_sort(list1,0,len(list1)-1)
print(list1)