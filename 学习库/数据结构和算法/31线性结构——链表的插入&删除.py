class Node:
    def __init__(self, item):
        self.item = item
        self.next = None
def make_linklist(li):
    tail = head = Node(li[0])
    for element in li[1:]:
        node = Node(element)
        tail.next = node
        tail = node
    return head
def print_linklist(he):
    while he:
        print(he.item, end=' ')
        he = he.next

list1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
he1 = make_linklist(list1)
print_linklist(he1)
print()
'''
head 就是一个一个链表的头
这个链表的实际形状大概是这样
[he1, he1.next, he1.next.next, he1.next.next.next, ......]
#########
在'd' 'e' 中插入一个’狗‘  相当于：
[he1,  p,  he1.next, he1.next.next, he1.next.next.next, ......]
'''
p = Node('狗')
p.next = he1.next
he1.next = p
print_linklist(he1)
print()

he1.next = p.next
del p
print_linklist(he1)
print()



