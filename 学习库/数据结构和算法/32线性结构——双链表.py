# 双链表：在链表的基础上 可以从后往前找
class dubleNode:
    def __init__(self,item):
        self.item = item
        self.prior = None
        self.next = None
def make_duble_linklist(li):
    head = tail = dubleNode(li[0])
    for element in li[1:]:
        node = dubleNode(element)
        tail.next = node
        node.prior = tail
        tail = node
    return head
    # return tail
def print_duble_linklist(kk):
    while kk:
        print(kk.item, end=' ')
        kk = kk.next
        # kk = kk.prior
'''创建'''
list1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i']
head1 = make_duble_linklist(list1)
print_duble_linklist(head1)
print()

'''插入'''
p = dubleNode('狗')
p.next = head1.next
head1.next.prior = p
head1.next = p
p.prior = head1
print_duble_linklist(head1)
print()

'''删除'''
head1.next = head1.next.next
head1.next.prior = head1
del p
print_duble_linklist(head1)










