class Dog:  # 父亲类
    def __init__(self, name, height, power):
        self.name = name
        self.height = height
        self.blood = 10
        self.power = power
    def bark(self):
        print(f'我是{self.name},身高{self.height}，血量{self.blood}，攻击力{self.power}')
'''现在有些特殊的狗，它们有普通狗的属性，也有自己特殊的属性&方法：'''
'''1.牧羊犬：②有protect()方法'''
class SheepDog(Dog):
    def __init__(self, name, height, power, num_of_sheep):
        super().__init__(name, height, power)
        self.num_of_sheep = num_of_sheep
    def protect(self,order_num):                # 很简单，与父类的方法定义一样
        print(f'开始保护第{order_num}只小羊！')

'''2.警犬：②有detect()方法'''
class PoliceDog(Dog):
    def __init__(self, name, height, power, ability):
        super().__init__(name, height, power)
        self.ability=ability
    def detect(self,order_num):                # 很简单，与父类的方法定义一样
        print(f'开始搜查第{order_num}个搜差点！')

'''3.宠物犬：②有sing()方法'''
class PetDog(Dog):
    def __init__(self, name, height, power, price):
        super().__init__(name, height, power)
        self.price=price
    def sing(self,order_num):                # 很简单，与父类的方法定义一样
        print(f'开始唱您点的《{order_num}》！')

d1 = Dog('大黄', 0.7, 3)  # 第一个普通狗
d2 = Dog('二黑', 0.5, 4)  # 第二个普通狗
dd1 = SheepDog('小牧', 0.8, 2, 5)  # 一只牧羊犬
dd2 = PoliceDog('小察', 0.85, 3, 4)  # 一只警犬
dd3 = PetDog('小逗', 0.15, 1, 2700)  # 一只宠物犬

dd1.bark()
dd1.protect(3)
print('*********************')

dd2.bark()
dd2.detect(4)
print('*********************')

dd3.bark()
dd3.sing('Lemon')