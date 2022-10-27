'''
链表：是由一系列节点组成的元素集合，与列表有点像，但是要链起来！
每个节点包含两个部分：
        1.本身的item
        2.next指向下一个元素的指针
'''
# 手动创建一个链表
class Node:
    def __init__(self, item):
        self.item = item
        self.next = None
a=Node(1)
b=Node(2)
c=Node(3)
a.next=b
b.next=c
print(a.next)
print(a.next.item)
print(a.next.next.item)
print('-------------------------------------')




