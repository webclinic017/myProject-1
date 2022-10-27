class Dog:  # 父亲类
    def __init__(self, name, height, power):
        self.name = name
        self.height = height
        self.blood = 10
        self.power = power
    def bark(self):
        print(f'我的名字叫{self.name},身高{self.height}，血量{self.blood}，攻击力{self.power}。')
    def test(self):
        print('子类调用不到，调用了父类。')
'''现在有些特殊的狗：'''
'''1.牧羊犬：'''
class SheepDog(Dog):
    def __init__(self, name, height, power, num_of_sheep):
        super().__init__(name, height, power)
        self.num_of_sheep = num_of_sheep
    def bark(self):
        print(f'我属于牧羊犬类，我能看管{self.num_of_sheep}只羊，',end='')  # ---独属于自己的bark内容
        super().bark()  # -------------------------------------------------调用父类的bark内容
'''--------------------------细分牧羊犬(德国、边牧等)-------------------------------'''
class ClassifiedSheepDog(SheepDog):
    def __init__(self, name, height, power, num_of_sheep, category):
        super().__init__(name, height, power, num_of_sheep)
        self.category=category
    def bark(self):
        print(f'我是一只{self.category}，',end='')  # -----------------------”独属于“自己的bark内容
        super().bark()  # -------------------------------------------------”再一次“调用父类的bark内容

'''2.警犬：'''
class PoliceDog(Dog):
    def __init__(self, name, height, power, ability):
        super().__init__(name, height, power)
        self.ability=ability
    def bark(self):
        print(f'我属于警犬，我能搜查{self.ability}个地方，',end='')  # ---------独属于自己的bark内容
        super().bark()  # -------------------------------------------------调用父类的bark内容

'''3.宠物犬：'''
class PetDog(Dog):
    def __init__(self, name, height, power, price):
        super().__init__(name, height, power)
        self.price=price
    def bark(self):
        print(f'我属于宠物犬，我的市场价是{self.price}元，',end='')  # ---------独属于自己的bark内容
        super().bark()  # -------------------------------------------------调用父类的bark内容

d1 = Dog('大黄', 0.7, 3)  # 第一个普通狗
d2 = Dog('二黑', 0.5, 4)  # 第二个普通狗
dd1 = SheepDog('小牧', 0.8, 2, 5)  # 一只牧羊犬
dd2 = PoliceDog('小察', 0.85, 3, 4)  # 一只警犬
dd3 = PetDog('小逗', 0.15, 1, 2700)  # 一只宠物犬
dd1_1 = ClassifiedSheepDog('小德',  0.9, 2.3, 9, '德国牧羊犬')  # 一只德牧
dd1_2 = ClassifiedSheepDog('边边',  0.85, 2.47, 7, '边境牧羊犬')  # 一只边牧

'''1.当子类有想调用的方法时，优先调用子类的方法
   2.子类没有此方法，则调用父类的
   3.父类没有此方法，则调用父类的父类的
   4.再没有，就报错'''
d1.bark()
print('*********************')
d2.bark()
print('*********************')
dd1.bark()
print('*********************')
dd1_1.bark()
print('~~~~~~~~')
dd1_1.test()
print('*********************')
dd1_2.bark()
print('*********************')
dd2.bark()
print('*********************')
dd3.bark()
print('*********************')


