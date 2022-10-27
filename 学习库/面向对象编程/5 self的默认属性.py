class Dog:
    # 构造方法(__init__方法)
    def __init__(self, name0, height0, power0):
        self.name = name0
        self.height = height0
        self.blood = 100  # 这里我们把血量固定为100，init中就可以不用写血量参数
        self.power = power0

d1 = Dog('大黄', 0.7, 3)  # 第一个实例
d2 = Dog('二黑', 0.5, 4)  # 第二个实例
print(d1.name)
print(d2.name)
print(d1.blood)
print(d2.blood)
