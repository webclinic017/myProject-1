'''
AVL树（自平衡二叉搜索树）
所有节点的左、右子树高度差不超过1
插入一个节点后只有这个插入节点到根节点路径上的平衡会被改变 如图 8→9→11→5→7
找到第一个被破坏了平衡的节点 定义为k 然后对k进行旋转。 如图 k=11
旋转分四种情况：
    1.k的右孩子的右子树 左旋
    2.k的左孩子的左子树 右旋
    3.k的右孩子的左子树 右旋+左旋
    4.k的左孩子的右子树 左旋+右旋
                              17
                    5←                    →35
            2←           →11          29←      →38
                     9←
                 8←
-----------------------------变为----------------------------------
                              17
                    5←                    →35
            2←           →9          29←      →38
                     8←     →11
树的每个节点引入一个balance变量 记录左右两边的高度差 balance = 右子树高度-左子树高度
    左边长是 -1
    一样长是 0
    右边长是 1
balance 的变化规律 从插入位置的父亲一直到祖宗的节点都有可能变化
    一旦路径上有一个变成了0就停止了变化


'''
import random


class AVLNode:
    def __init__(self, data):
        self.data = data
        self.lchild = None
        self.rchild = None
        self.father = None
        self.balance = 0


class AVLTree:
    def __init__(self, li=None):
        self.root = None
        if li:
            # self.root = AVLNode(li[0])  # 这里试过很多次了 需要先有个非空的根节点 递归建表才能建立
            for i in li[:]:
                self.insert_normal(i)

    # 左旋转
    def rotate_left(self, p, c):
        # 旋转操作
        s2 = c.lchild
        p.rchild = s2
        if s2:
            s2.father = p
        c.lchild = p
        p.father = c
        # 更新balance
        p.balance = 0
        c.balance = 0
        return c

    # 右旋转
    def rotate_right(self, p, c):
        # 旋转操作
        s2 = c.rchild
        p.lchild = s2
        if s2:
            s2.father = p
        c.rchild = p
        p.father = c
        # 更新balance
        p.balance = 0
        c.balance = 0
        return c

    # 右旋+左旋
    def rotate_right_left(self, p, c):
        g = c.lchild
        # 右旋
        s3 = g.rchild
        c.lchild = s3
        if s3:
            s3.father = c
        g.rchild = c
        c.father = g
        # 左旋
        s2 = g.lchild
        p.rchild = s2
        if s2:
            s2.father = p
        g.lchild = p
        p.father = g
        # 更新balance
        if g.balance > 0:  # g的右孩子多1
            p.balance = -1  # p的左孩子多1
            c.balance = 0
        elif g.balance < 0:  # g的左孩子多1
            p.balance = 0
            c.balance = 1  # c的右孩子多1
        else:  # g.balance=0 表示插入的是g本身
            p.balance = 0
            c.balance = 0
        g.balance = 0
        return g

    # 右旋+左旋
    def rotate_left_right(self, p, c):
        g = c.rchild
        # 右旋
        s2 = g.lchild
        c.rchild = s2
        if s2:
            s2.father = c
        g.lchild = c
        c.father = g
        # 左旋
        s3 = g.rchild
        p.lchild = s3
        if s3:
            s3.father = p
        g.rchild = p
        p.father = g
        # 更新balance
        if g.balance > 0:
            p.balance = 0
            c.balance = -1
        elif g.balance < 0:
            p.balance = 1
            c.balance = 0
        else:  # g.balance=0 表示插入的是g本身
            p.balance = 0
            c.balance = 0
        g.balance = 0
        return g

    # 插入操作（非递归）
    def insert_normal(self, val):
        # 第一步先和二叉搜索树一样 进行插入
        p = self.root  # 用一个值来进行储存和比较
        if not p:  # 当这棵树是空树的时候 直接插入 这时候没有左孩子、右孩子、父亲。
            self.root = AVLNode(val)
            return
        while True:
            if val < p.data:
                if not p.lchild:
                    p.lchild = AVLNode(val)
                    p.lchild.father = p
                    node = p.lchild  # node储存的是插入的节点
                    break
                else:
                    p = p.lchild
            elif val > p.data:
                if not p.rchild:
                    p.rchild = AVLNode(val)
                    p.rchild.father = p
                    node = p.rchild
                    break
                else:
                    p = p.rchild
            else:  # (val = node.data)
                return
        # 第二步 更新balance
        while node.father:  # 保证node的父亲不是空 这样就一直循环到root为止
            if node == node.father.lchild:  # node的传递是从左子树来的
                if node.father.balance < 0:  # 原来是-1 更新后变成-2
                    # 要做旋转
                    # 看看node是哪边沉
                    k = node.father.father  # 这个k 是最后用来链接回到整颗树中的
                    x = node.father  # 旋转之前子树的根
                    if node.balance > 0:  # 右边沉 先左旋再右旋
                        n = self.rotate_left_right(node.father, node)
                    else:  # 左边沉 右旋
                        n = self.rotate_right(node.father, node)
                elif node.father.balance > 0:  # 原来是1 更新后变成0
                    node.father.balance = 0
                    break
                else:  # 原来是0 更新后变成-1
                    node.father.balance = -1
                    node = node.father
                    continue
            else:  # node的传递是从右子树来的
                if node.father.balance > 0:  # 原来是1 更新后变成2
                    # 要做旋转
                    # 看看node是哪边沉
                    k = node.father.father  # 这个k 是最后用来链接回到整颗树中的
                    x = node.father  # 旋转之前子树的根
                    if node.balance < 0:  # 左边沉 先右旋再左旋
                        n = self.rotate_right_left(node.father, node)
                    else:  # 右边沉 左旋
                        n = self.rotate_left(node.father, node)
                    # 最后把 k 和 n 链起来
                elif node.father.balance < 0:  # 原来是-1 更新后变成0
                    node.father.balance = 0
                    break
                else:  # 原来是0 更新后变成1
                    node.father.balance = 1
                    node = node.father
                    continue

            n.father = k  # 先定父关系
            if not k:  # k是空 空是没有孩子的
                self.root = n
                break
            else:  # k不是空   # 再定子关系
                if x == k.lchild:
                    k.lchild = n
                else:
                    k.rchild = n
                break

    # 1.前序遍历
    def pre_order(self, root):  # 传参传入root
        if root:
            print(root.data, end=',')
            self.pre_order(root.lchild)  # 递归左孩子
            self.pre_order(root.rchild)  # 递归右孩子

    # 2.中序遍历
    def mid_order(self, root):  # 传参传入root
        if root:
            self.mid_order(root.lchild)  # 递归左孩子
            print(root.data, end=',')
            self.mid_order(root.rchild)  # 递归右孩子

    # 查询(非递归法)
    def search_normal(self, val):
        p = self.root
        if not p:
            return None
        while True:
            if val < p.data:
                if p.lchild:
                    p = p.lchild
                else:
                    return None
            elif val > p.data:
                if p.rchild:
                    p = p.rchild
                else:
                    return None
            else:
                return p


list2 = list(range(1, 15))
random.shuffle(list2)
list1 = [9, 10, 7, 6, 5, 4, 3, 2, 1]
list3 = []

aim = list2
tree = AVLTree(aim)
print('--------前序----------')
tree.pre_order(tree.root)
print()
print('--------中序----------')
tree.mid_order(tree.root)
print()
print('--------后序----------')

print('--------查找----------')
print('找1', tree.search_normal(10))
print('找100', tree.search_normal(100))
print('--------其他信息----------')
print('源列表', aim)
print('根节点value', tree.root.data)

print('--------删除----------')
i = 9
