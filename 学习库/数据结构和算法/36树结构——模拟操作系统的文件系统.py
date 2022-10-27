
class Node:  # 实现创建一个文件夹的功能
    def __init__(self, name, type):
        self.name = name
        self.type = type
        self.children = []
        self.father = None
    def __repr__(self):
        return self.name
        # 把<__main__.Node object at 0x000000000245A250>变成我们想要看到的东西

class FileSystem:
    def __init__(self):
        self.root = Node('/', 'dir')
        self.now = self.root
    def makedir(self, name):
        if name[-1] != '/':
            name += '/'
        node = Node(name, 'dir')
        for child in self.now.children:
            if child.name == node.name:
                raise '当前目录下存在同名文件夹'
        self.now.children.append(node)
        node.father = self.now
        # self.now = node  # 自动跳转到所创建的目录
    def ls(self):
        return self.now.children
    def cd(self, name):
        if name[-1] != '/':
            name += '/'
        if name == '../':
            self.now = self.now.father
            return
        for child in self.now.children:
            if child.name == name:
                self.now = child
                return
        else:
            raise '找不到目标路径'


tree1 = FileSystem()
tree1.makedir('user')
tree1.makedir('bin')
tree1.makedir('sdcard')
tree1.makedir('history')
print(tree1.root.children)
print(tree1.ls())
print('------------------')
print('当前目录', tree1.now)
print('下辖目录', tree1.ls())
tree1.cd('user')
print('当前目录', tree1.now)
print('下辖目录', tree1.ls())
tree1.cd('..')
print('当前目录', tree1.now)
print('下辖目录', tree1.ls())
tree1.cd('../')
print('当前目录', tree1.now)



