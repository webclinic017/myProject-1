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
        if j+1 <= high and li[j] > li[j+1]:  # 比较左右孩子谁大，而且右孩子要存在
            j=j+1  # 左右孩子 谁大取谁
        if li[j]<tmp:  # 如果孩子比储存值大
           li[i]=li[j]  # 子占父位
           i=j          # 同时往下看一层
           j=2*i+1
        else:           # 如果孩子比储存值小
            li[i]=tmp   # 父亲接受储存值tmp
            break       # 跳出循环
    else:
        li[i]=tmp  # 如果找到最后叶子节点上都没有父位能接受tmp tmp只能原地放在叶子节点上

@cal_time
def heap_sort_k(li,k):
    print('********1.建堆【0：k】*********')
    li_topk=li[0:k]
    n=len(li_topk)
    for m in range((n-2)//2,-1,-1):
        sift(li_topk,m,n-1)
    print(li_topk)

    print('********2.遍历【k:high】的所有元素*********')
    for b in range(k,len(li)-1):
        if li[b]>li_topk[0]:
            li_topk[0]=li[b]
            sift(li_topk,0,k-1)
    print(li_topk)

    print('********2.把最小的数依次拿到最后面，形成从大到小长度为k的数*********')
    for a in range(k-1,-1,-1):
        li_topk[0],li_topk[a]=li_topk[a],li_topk[0]
        sift(li_topk,0,a-1)
    print(li_topk)

#

import random
list1=[]
for l in range(1,10001):
    list1.append(l)
random.shuffle(list1)
print('原始列表为:',list1)
print('---------构造堆----------')
heap_sort_k(list1,20)
