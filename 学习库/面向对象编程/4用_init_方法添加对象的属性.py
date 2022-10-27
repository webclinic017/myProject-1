class Dog:
    # 构造方法(__init__方法)
    def __init__(self, name0, height0, blood0, power0):
        self.name = name0
        self.height = height0
        self.blood = blood0
        self.power = power0

d1 = Dog('大黄', 0.7, 12, 3)  # 第一个实例
d2 = Dog('二黑', 0.5, 10, 4)  # 第二个实例
print(d1.name)
print(d2.name)
print(d1.power)
print(d2.power)
print(id(d1))  # 每个实例都有独立的内存地址
print(id(d2))
