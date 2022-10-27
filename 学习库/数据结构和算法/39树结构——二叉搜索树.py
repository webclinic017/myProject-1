'''
二叉搜索树：Binary Search Tree
    左孩子的值永远比自己小
    右孩子的值永远比自己大
                              17
                    5←                    →35
            2←           →11          29←      →38
                     9←
                 8←
操作：插入(建立) 遍历 查询
      删除
'''
import random


# 二叉树的节点实现
class BiTreeNode:
    def __init__(self, data):
        self.data = data
        self.lchild = None
        self.rchild = None
        self.father = None


# 建根 建树
class BinarySearchTree:
    def __init__(self, li=None):
        self.root = None
        if li:
            self.root = BiTreeNode(li[0])  # 这里试过很多次了 需要先有个非空的根节点 递归建表才能建立
            for i in li[1:]:
                self.insert_recursion(self.root, i)  # 递归法
                # self.insert_normal(i)               #普通法

    # 递归的写法
    def insert_recursion(self, node, val):
        if not node:  # 当这棵树是空树的时候 直接插入 这时候没有左孩子、右孩子、父亲。
            node = BiTreeNode(val)
        elif val < node.data:  # 当val小于node的值时，总体思想往左边插。
            node.lchild = self.insert_recursion(node.lchild, val)  # 对左孩子进行操作。一次递归操作。
            node.lchild.father = node  # 上面一步已经把 孩子关系确定了。这里我们把父亲关系也搞定。
        elif val > node.data:  # 当val大于node的值时，总体思想往右边插。
            node.rchild = self.insert_recursion(node.rchild, val)  # 对右孩子进行操作。一次递归操作。
            node.rchild.father = node  # 上面一步已经把 孩子关系确定了。这里我们把父亲关系也搞定。
        else:  # (val = node.data)
            pass
        return node

    # 非递归的写法
    def insert_normal(self, val):
        p = self.root  # 用一个值来进行储存和比较
        if not p:  # 当这棵树是空树的时候 直接插入 这时候没有左孩子、右孩子、父亲。
            self.root = BiTreeNode(val)
            return
        while True:
            if val < p.data:
                if not p.lchild:
                    p.lchild = BiTreeNode(val)
                    p.lchild.father = p
                    return
                else:
                    p = p.lchild
            elif val > p.data:
                if not p.rchild:
                    p.rchild = BiTreeNode(val)
                    p.rchild.father = p
                    return
                else:
                    p = p.rchild
            else:  # (val = node.data)
                return

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

    # 3.后序遍历
    def post_order(self, root):  # 传参传入root
        if root:
            self.post_order(root.lchild)  # 递归左孩子
            self.post_order(root.rchild)  # 递归右孩子
            print(root.data, end=',')

    # 1.查询(递归法)
    def search_recursion(self, node, val):
        if not node:
            return None
        elif val < node.data:
            return self.search_recursion(node.lchild, val)
        elif val > node.data:
            return self.search_recursion(node.rchild, val)
        else:
            return node

    # 2.查询(非递归法)
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

    ''' 
    ***********************二叉搜索树的 删除操作*****************************
                                   17
                        5←                    →35
                2←           →11          29←      →38
                         9←                             →40
                     7←
                        →8
    1.叶子节点：直接删除
    2.单孩子节点：直接删除 + 爷爷和孙子链起来
        例如 要删38 就要把35和40链起来
    3.双孩子节点：把此节点右子树 的 最小值拿过来替换它
        例如 要删除5 就要把7拿来替换5的位置 同时9和8连起来
                                   17
                        7←                    →35
                2←           →11          29←      →38
                         9←                             →40
                     8←
    ***********************二叉搜索树的 删除操作*****************************
    '''

    def test(self):
        return 'ok'

    def __remove_node_scenario1(self, node):
        # 情况1：叶子节点
        if not node.father:  # 如果也是根节点
            self.root = None
        else:  # 如果不是根节点
            if node.father.lchild == node:  # 如果是它父亲的左孩子
                node.father.lchild = None  # 它父亲跟左孩子撇清关系
            else:  # 如果是它父亲的右孩子
                node.father.rchild = None  # 它父亲跟右孩子撇清关系

    def __remove_node_scenario2(self, node):
        # 情况2：单孩子节点
        if not node.father:  # 如果也是根节点
            if node.lchild:  # 如果是拥有一个左孩子的根节点
                self.root = node.lchild
                self.root.father = None
            elif node.rchild:  # 如果是拥有一个右孩子的根节点
                self.root = node.rchild
                self.root.father = None
            else:
                self.root = None
        else:  # 如果不是根节点
            if node.father.lchild == node:  # 如果是它父亲的左孩子
                if node.lchild:  # 如果它拥有一个左孩子
                    node.father.lchild = node.lchild
                    node.lchild.father = node.father
                elif node.rchild:  # 如果它拥有一个右孩子
                    node.father.lchild = node.rchild
                    node.rchild.father = node.father
            else:  # 如果是它父亲的右孩子
                if node.lchild:  # 如果它拥有一个左孩子
                    node.father.rchild = node.lchild
                    node.lchild.father = node.father
                elif node.rchild:  # 如果它拥有一个右孩子
                    node.father.rchild = node.rchild
                    node.rchild.father = node.father

    def delete(self, val):
        if not self.root:  # 空树
            print('你的数是空树，不能再删除了！')
            return False
        else:
            node = self.search_normal(val)
            if not node:
                print('树中没有你要删除的数')
                return False
            elif not node.lchild and not node.rchild:
                self.__remove_node_scenario1(node)
            elif not node.lchild or not node.rchild:
                self.__remove_node_scenario2(node)
            else:
                p = node.rchild  # 先定义成右子树的根
                while p.lchild:
                    p = p.lchild  # 右子树最小的值
                node.data = p.data  # 把node值换一下就可以了 关系不用变
                # 接下来就是一个delete(p)过程，只有情况1 或者情况2 两种情况
                if p.rchild:
                    self.__remove_node_scenario2(p)
                else:
                    self.__remove_node_scenario1(p)


list2 = list(range(1, 15))
random.shuffle(list2)
list1 = [10, 6, 8, 7, 9, 4, 3, 5, 15, 14, 16]
list3 = []

aim = list2
tree = BinarySearchTree(aim)
print('--------前序----------')
tree.pre_order(tree.root)
print()
print('--------中序----------')
tree.mid_order(tree.root)
print()
print('--------后序----------')
tree.post_order(tree.root)
print()
print('--------查找----------')
print('找1', tree.search_recursion(tree.root, 1))
print('找1', tree.search_normal(10))
print('找100', tree.search_recursion(tree.root, 100))
print('找100', tree.search_normal(100))
print('--------其他信息----------')
print('源列表', aim)
print('根节点value', tree.root.data)

print('--------删除----------')
tree.delete(14)
tree.mid_order(tree.root)

