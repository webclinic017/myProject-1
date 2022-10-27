'''
栈（Stack）：只允许在一端插入、删除的列表
特点：先进后出，后进先出
    栈底（bottom）                     栈顶（top）
a=[      1,      2,      3,      4,     5    ]
基本操作：
                                        ↓取栈顶 gettop
                                              ←进栈 push
                                              →出栈 pop
用列表形式就可以栈的逻辑
    li.append
    li.pop
    li[-1]
'''

#也可以用类的方式实现栈的逻辑
class Stack:
    def __init__(self):
        self.stack = []

    def push(self, element):
        self.stack.append(element)
        return self.stack

    def pop(self):
        bb = '列表为空不能出栈'
        if len(self.stack) > 0:
            self.stack.pop()
            return self.stack
        else:
            return bb

    def gettop(self):
        bbb = '列表为空不能取栈顶'
        if len(self.stack) > 0:
            return self.stack[-1]
        else:
            return bbb

a1 = Stack()
print(a1.push(1))
print(a1.push(2))
print(a1.push(3))
print('**********************************************')

print(a1)
print('**********************************************')

print(a1.gettop())
print('**********************************************')

print(a1.pop())
print(a1.pop())
print(a1.pop())
print(a1.pop())
print('**********************************************')

print(a1.gettop())
print('**********************************************')











