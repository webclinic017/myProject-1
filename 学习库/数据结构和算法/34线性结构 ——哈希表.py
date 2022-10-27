'''
字典和集合 都是用哈希表实现的
哈希表：
    通过哈希函数来计算数据存储位置，支持以下操作：
        1.inser(key,value)
        2.get(key) 返回value
        3.delet(key) 删除键值对


key        =        [key1,      key2,   ...    key10   ]
哈希函数h(key)套一下  [h(key1),  h(key2),  ...   h(key10) ]
哈希函数h(key)的值    [ 015,       078,    ...     043    ]
对应到寻址表上                       ↓
大小为100 的寻址表T    [001,  002,  003,  ...  100  ]
'''
'''
哈希表：由一个直接寻址表 和 一个哈希函数 组成。

'''
class LinkList:
    class Node:
        def __init__(self,item=None):
            self.item=item
            self.next=None
    class LinkListIterator:
        def __init__(self, node):
            self.node = node
        def __next__(self):
            if self.node:
                cur_node = self.node
                self.node = cur_node.next
                return cur_node.item
            else:
                raise StopIteration
        def __iter__(self):
            return self

    def __init__(self, iterable=None):
        self.head=None
        self.tail=None
        if iterable:
            self.extend(iterable)
    def append(self, obj):
        s = LinkList.Node(obj)
        if self.head:  # 如果链表不是空链表 head有值
            self.tail.next = s
            self.tail = s
        else:  # 空链表
            self.head = self.tail = s
    def extend(self, iterable):
        for obj in iterable:
            self.append(obj)
    def find(self, obj):
        for n in self:
            if n == obj:
                return True
    def __iter__(self):
        return self.LinkListIterator(self.head)
    def __repr__(self):
        return '<<'  +  ','.join(map(str, self))  +  '>>'
# ------------------------------------------------------------------------------
lk = LinkList([1,2,3,4,5])
print(lk)
for element in lk:
    print(element)
print('------------------------------------------------------------------------')

class Hash:
    def __init__(self, size = 20):
        self.size = size
        self.T = [LinkList() for i in range(self.size)]
    def h(self, k):
        return k % self.size
    def insert(self, k):
        i = self.h(k)
        # 设计不能重复插入
        if self.find(k):
            print('重复插入！')
        else:
            self.T[i].append(k)
    def find(self, k):
        i =self.h(k)
        return self.T[i].find(k)
# -----------------------------------------------------------------------
h1 = Hash(10)
h1.insert(1)
h1.insert(1)
h1.insert(3)
h1.insert(5)
h1.insert(7)
h1.insert(9)
h1.insert(11)
h1.insert(12)
h1.insert(13)
h1.insert(15)
h1.insert(17)
h1.insert(181)
print(' '.join(map(str,h1.T)))
print(h1.find(0))


# 哈希表的实现还是有难度的 我是懂大致懂 但是写不出来