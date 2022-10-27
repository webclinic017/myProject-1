'''                E
        A←              →G
            →C                   →F
         B←      →D
遍历方式：
    1.前序遍历 EACBDGF
    2.中序遍历 ABCDEGF
    3.后序遍历 BDCAFGE
    4.层次遍历 EAGCFBD
'''
class BiTreeNode:
    def __init__(self, data):
        self.data = data
        self.lchild = None
        self.rchild = None
a = BiTreeNode('A')
b = BiTreeNode('B')
c = BiTreeNode('C')
d = BiTreeNode('D')
e = BiTreeNode('E')
f = BiTreeNode('F')
g = BiTreeNode('G')
e.lchild = a
e.rchild = g
a.rchild = c
c.lchild = b
c.rchild = d
g.rchild = f
root = e
print(root.lchild.rchild.lchild.data)
print('--------------------------------')

'''1.前序遍历'''
def pre_order(root):  # 传参传入root
    if root:
        print(root.data)
        pre_order(root.lchild)  # 递归左孩子
        pre_order(root.rchild)  # 递归右孩子

pre_order(root)
print('--------------------------------')

'''2.中序遍历'''
def mid_order(root):  # 传参传入root
    if root:
        mid_order(root.lchild)  # 递归左孩子
        print(root.data)
        mid_order(root.rchild)  # 递归右孩子

mid_order(root)
print('--------------------------------')

'''3.后序遍历'''
def post_order(root):  # 传参传入root
    if root:
        post_order(root.lchild)  # 递归左孩子
        post_order(root.rchild)  # 递归右孩子
        print(root.data)

post_order(root)
print('--------------------------------')

'''4.层次遍历'''
def aa_order(root):  # 传参传入root
    tmp = root
    queue=[tmp]
    while len(queue) > 0:
        if queue[0].lchild:
            queue.append(queue[0].lchild)
        if queue[0].rchild:
            queue.append(queue[0].rchild)  # 再多的孩子都可以用这种方式遍历 for x in children
        print(queue[0].data)
        queue.remove(queue[0])

aa_order(root)
print('--------------------------------')












