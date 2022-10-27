class Dog:
    # 构造方法(__init__方法)
    def __init__(self, name0, height0, blood0, power0):
        self.name = name0
        self.height = height0
        self.blood = blood0
        self.power = power0

d1 = Dog('大黄', 0.7, 12, 3)
d2 = Dog('二黑', 0.5, 10, 4)

print(d1.blood)  # 访问blood属性
d1.blood=10      # 修改属性
print(d1.blood)
