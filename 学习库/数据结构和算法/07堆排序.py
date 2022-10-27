from cal_time import *

def sift(li,low,high): # sift不标准堆 的调整
    '''
    :param li: 待调整列表
    :param low: 堆 的根节点
    :param high: 堆 的最后一个元素
    :return:
    '''
    i=low  # i 的初始指向为根节点
    j=2*i+1  # j 的初始指向为左孩子
    tmp=li[low]  # 把堆顶的值储存到tmp
    while j<=high:  # j不能超过最后一个元素
        if j+1 <= high and li[j]<li[j+1]:  # 比较左右孩子谁大，而且右孩子要存在
            j=j+1  # 左右孩子 谁大取谁
        if li[j]>tmp:  # 如果孩子比储存值大
           li[i]=li[j]  # 子占父位
           i=j          # 同时往下看一层
           j=2*i+1
        else:           # 如果孩子比储存值小
            li[i]=tmp   # 父亲接受储存值tmp
            break       # 跳出循环
    else:
        li[i]=tmp  # 如果找到最后叶子节点上都没有父位能接受tmp tmp只能原地放在叶子节点上

@cal_time
def heap_sort(li):  # heap_sort '堆排序'
    n=len(li)
    for k in range((n-2)//2,-1,-1):  # 倒序遍历每一个小树苗的根
        sift(li,k,n-1)               # 从下往上调整每一个小树苗
    print(li)

    print('---------正式排序----------')
    for b in range(n-1,-1,-1):
        li[0],li[b] = li[b],li[0]
        sift(li,0,b-1)
    print(li)


list1=[]
for l in range(1,1000000):
    list1.append(l)
print('原始列表为:',list1)
print('---------构造堆----------')
heap_sort(list1)




