'''
双向队列：两边都可以进队和出队
       队头front                                 队尾rear
a = [      1,      2,      3,      4,      5,       6      ]
    ←出队                                                   ←入队
    入队→                                                   出队→
四个操作 两边都可以
--------------------------------------
队列的内置模块:
collections 模块中的 deque方法 'de'表示双向
append() 右进
appendleft() 左进
pop() 右出
popleft() 左出
'''
from collections import deque
q = deque([2, 3, 4], 5)  # deque( , ) 两个参数可以缺省 第一个参数表示初始队列 第二个参数表示最大长度
                         # 1.这里的最大长度为5 表示可以最多存放5个而不是4个
                         # 2.当队满的时候 会自动出队
print(q)
print('------------------------------')

q.append(5)  # 队尾进队
q.appendleft(1)  # 队首进队
print(q)
print('------------------------------')

q.append('右')   # 队尾进队 队首自动出队
print(q)
print('------------------------------')

q.appendleft('左')  # 队首进队 队尾自动出队
print(q)
print('------------------------------')

print(q.popleft())  # 队首出队
print(q.popleft())
print(q.pop())      # 队尾出队
print(q.pop())
print(q.pop())
print(q)
print('-------------------\n---------------------')


'''deque的一个妙用：读取一个txt文档的最后5行'''
def tail(n):  # 定义一个函数
    with open('support26.txt', 'r') as s:  # 读取文档存成列表
        q1 = deque(s, n)
        return q1
aim = tail(5)
print(aim)
print('------------------------------')

for i in aim:
    print(i, end='')





