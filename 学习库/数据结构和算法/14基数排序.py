import math
def radix_sort(li):

    n=math.floor(math.log(max(li),10))  # 99--2 888---3 1000---4
                                        # 个位数标0,十位标1，找到最大数的最大位数
    i=0
    while i<=n:  # 遍历所有位数 每一位都做桶排序
        baskets=[[] for _ in range(10)] #建立下标0-9的空桶
        for val in li:  # 每一个数都以第i位为基准做桶排序
            # 1%10=1     12%10=2       123%10=3      1234%10=4
            # 01//10%10=0     12//10%10=1       123//10=2      1234//10%10=3
            # 001//10//10%10=0     012//10//10%10=0       123//10//10%10=1      1234//10//10%10=2
            # ......
            k=(val//(10**i))%10  # k是此数在第i位的值
            baskets[k].append(val)  # 把这个数放到 第i位对应下标的桶中

        li.clear()
        for basket in baskets:
            li.extend(basket)   # li重新把桶接收过来
        i+=1






import random

list1=list(random.randint(1,1000) for _ in range(15))
print(list1)
radix_sort(list1)
print(list1)