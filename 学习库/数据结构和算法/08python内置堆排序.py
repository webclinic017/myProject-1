import heapq
import random
li=list(range(10))
random.shuffle(li)
print(li)
heapq.heapify(li)
print(li)
for i in range(len(li)):
    a=heapq.heappop(li)
    print(a,end='//')
    print(li)
