class Dog:
    # 构造方法(__init__方法)
    def __init__(self, name0, height0, power0):
        self.name = name0
        self.height = height0
        self.blood = 10
        self.power = power0
    def bark(self):
        print(f'我是{self.name},身高{self.height}，血量{self.blood}，攻击力{self.power}')
    def attack(self,dog_another):
        
        # 一个方法中也可以引入另一个方法，注意逻辑要通顺
        dog_another.reduce_blood(self.power)

    # 通过引入reduce_blood方法，加入判断语句 使得每条狗的血量最低降到0
    def reduce_blood(self,reduce_value):
        if reduce_value > self.blood:
            self.blood=0
        else:
            self.blood-=reduce_value

d1 = Dog('大黄', 0.7, 3)  # 第一个实例
d2 = Dog('二黑', 0.5, 4)  # 第二个实例

d1.bark()
d1.reduce_blood(4)
d1.bark()
d1.reduce_blood(4)
d1.bark()
d1.reduce_blood(4)
d1.bark()
d1.reduce_blood(4)
d1.bark()
d1.reduce_blood(4)
d1.bark()

print('*'*50)

d2.bark()
d1.attack(d2)
d2.bark()
d1.attack(d2)
d2.bark()
d1.attack(d2)
d2.bark()
d1.attack(d2)
d2.bark()
d1.attack(d2)
d2.bark()
