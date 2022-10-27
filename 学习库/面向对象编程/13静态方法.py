'''
静态方法
1.需要使用@staticmethod来作为声明
2.没有像(cls)和(self)这样的必须输入的参数
'''
class Dog:
    @staticmethod  # 静态方法需要使用@staticmethod来作为声明
    def intro():
        print('狗是人类的好朋友。')
    def __init__(self, name0, height0, blood0, power0):
        self.name = name0
        self.height = height0
        self.blood = blood0
        self.power = power0

d1 = Dog('大黄', 0.7, 12, 3)  # 第一个实例
d2 = Dog('二黑', 0.5, 10, 4)  # 第二个实例

d1.intro()
d2.intro()
Dog.intro()
