# 如何正规地创建一个列表
class Node:
    def __init__(self, item):
        self.item = item
        self.next = None

'''头插法'''
def make_linklist_headmethod(li):  # 把普通列表创建一个链表的逻辑关系
    head = Node(li[0])
    for element in li[1:]:
        node = Node(element)
        node.next = head
        head = node
    return head  # 返回这个逻辑关系的头

'''尾插法'''
def make_linklist_tailmethod(li):  # 把普通列表创建一个链表的逻辑关系
    tail = head = Node(li[0])
    for element in li[1:]:
        node = Node(element)
        tail.next = node
        tail = node
    return head  # 返回这个逻辑关系的头

'''遍历列表'''
def print_linklist(he):  # 遍历链表
    while he:
        print(he.item, end=' ')
        he = he.next


list1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
he1 = make_linklist_headmethod(list1)
print_linklist(he1)
print()


he2 = make_linklist_tailmethod(list1)
print_linklist(he1)
print()