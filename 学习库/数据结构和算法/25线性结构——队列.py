'''
队列：queue：只允许一端进行插入，另一端进行删除 先进先出
       队头front                                 队尾rear
a = [      1,      2,      3,      4,      5,       6      ]
    ←出队                                                   ←入队
简单的通过列表不能很确切的表现队列的功能，会浪费很多空间，也会把时间复杂度提高一个数量级
我们构建————环形队列
假设一个队列长度为 4
一开始：front=0，rear=0 —— 空队列
进队：rear+1             0,   1,   2,   3,   4,    5,    6...
出队：front+1            0,   1,   2,   3,   4,    5,    6...
改进：
    进队：(rear+1) % 4   0,   1,   2,   3,   0,    1,    2...
    出队：(rear+1) % 4   0,   1,   2,   3,   0,    1,    2...
队空条件：front=rear
队满条件：front=(rear+1) % 4
'''

# 环形队列的实现
class Queue:  # 创建一个 队类
       def __init__(self, size=100):  # 只传入一个参数就是大小size
              self.size = size
              self.queue = [0 for _ in range(size)]  # 创建一个空队 以0填满
              self.front = 0
              self.rear = 0

       def push(self, element):  # 元素入队
              if self.is_full():
                     raise IndexError('队满')
              else:                                     # 队不满的时候
                     self.rear = (self.rear + 1) % self.size  # 队尾+1
                     self.queue[self.rear] = element  # 添上元素
       def pop(self):
              if self.is_empty():
                     raise IndexError('队空')
              else:                                # 队不空的时候
                     self.queue[self.front] = 0  # 先删除目前队首的值
                     self.front = (self.front + 1) % self.size  # 队首+1
                     return self.queue[self.front]     # 取出现在队首的值

       def is_empty(self):
              return self.front == self.rear
       def is_full(self):
              return self.front == (self.rear + 1) % self.size

d1=Queue(10)  # size为10的队列只能填9个 就队满了
print('队首是：', d1.queue[d1.front])
print('队尾是：', d1.queue[d1.rear])
print('---------------------------------------')
for i in ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']:  # a-i 九个
       d1.push(i)
       print('队首是：', d1.queue[d1.front])
       print('队尾是：', d1.queue[d1.rear])
       print('---------------------------------------')

print(d1.queue)
print('---------------------------------------')

print(d1.pop())
print('队首是：', d1.queue[d1.front])
print('队尾是：', d1.queue[d1.rear])
print('---------------------------------------')
print(d1.pop())
print('队首是：', d1.queue[d1.front])
print('队尾是：', d1.queue[d1.rear])
print('---------------------------------------')
print(d1.pop())
print('队首是：', d1.queue[d1.front])
print('队尾是：', d1.queue[d1.rear])
print('---------------------------------------')
print(d1.queue)
print('---------------------------------------')

d1.push('j')
print(d1.queue)
d1.push('k')
print(d1.queue)
d1.push('l')
print(d1.queue)
print('---------------------------------------')

print('队首是：', d1.queue[d1.front])
print('队尾是：', d1.queue[d1.rear])


