# count=[0 for _ in range(100)]  # 生成下标为0-99的值全为0的列表
# print(count)

def count_sort(li,max_count=100):
    count=[0 for _ in range(max_count+1)]
    for i in li:
        count[i]+=1
    # print(count)
    li.clear()
    for ind,val in enumerate(count):
        for i in range(val):
            li.append(ind)


import random
list1=[random.randint(0,10) for _ in range(20)]
print(list1)
count_sort(list1,10)
print(list1)