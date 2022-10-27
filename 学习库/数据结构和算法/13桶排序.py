def bin_sort(li,n=100,max_num=10000):
    baskets=[[] for _ in range(n)]  # 创建桶
    for i in li:
        k = min(i//(max_num//n), n-1)  # k表示 放到几号桶
                                # 注意10000//(max_num//n)=100超过了桶的下标，所以用n-1
        baskets[k].append(i)  # 把i放到对应的桶里

        # 利用冒泡排序直接把桶里的数变成有序
        for j in range(len(baskets[k])-1,0,-1):
            if baskets[k][j]<baskets[k][j-1]:
                baskets[k][j],baskets[k][j-1]=baskets[k][j-1],baskets[k][j]
    # 把二维的有序桶列表 extend到li中
    li.clear()
    for v in baskets:
        li.extend(v)
    return li


import random
list1=[random.randint(1,100) for _ in range(20)]
print(list1)
bin_sort(list1,10,100)
print(list1)
