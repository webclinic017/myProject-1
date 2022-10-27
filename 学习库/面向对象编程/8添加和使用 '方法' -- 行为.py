class Dog:
    # 构造方法(__init__方法)
    def __init__(self, name0, height0, blood0, power0):
        self.name = name0
        self.height = height0
        self.blood = blood0
        self.power = power0
    # 添加‘方法1’--给爷叫一声 行为
    def bark(self):  # 每个实例方法必须至少有‘self’
      # f'*****{变量1}*****{变量2}*******'  f后面跟{}可以直接打印参数
        print(f'我是{self.name},身高{self.height}，血量{self.blood}，攻击力{self.power}')
        return \
            f'我是{self.name},身高{self.height}'
    # 添加‘方法2’--狗咬狗 行为
    def attack(self,dog_another):  # 每个实例方法必须至少有‘self’
        dog_another.blood-=self.power

d1 = Dog('大黄', 0.7, 12, 3)  # 第一个实例
d2 = Dog('二黑', 0.5, 10, 4)  # 第二个实例

print(d1.bark())
d2.bark()
print('*'*50)
d1.attack(d2)
d2.bark()



