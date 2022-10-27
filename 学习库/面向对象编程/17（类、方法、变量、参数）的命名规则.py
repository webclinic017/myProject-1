'''
类名：驼峰命名法。Dog, SheepDog, HelloWorld
方法名，变量名，参数名：
    1.全小写
    2.多个单侧用下划线连接
    dog  sheep_dog  hello_world
文件名:
    1.全小写
    2.可以不用下划线
    dog  sheepdog  helloworld
私有属性：
    变量名前 加一个下划线
    如：self._secrect 这就是希望别人不要访问这个私有属性
    但是强行访问还是能访问到，这只是一个约定
Python解释器御用的方法：
    __init__()
    __class__()
'''
class Dog:
    def __init__(self, name0, height0, power0):
        self.name = name0
        self.height = height0
        self.power = power0
        self._secrect = 9527  # 一个私有属性

d1 = Dog('大黄', 0.7, 3)
d2 = Dog('二黑', 0.5, 4)
print('强行访问还是能访问到',d1._secrect)
