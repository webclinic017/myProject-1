class Dog:  # 父亲类
    def __init__(self, name, height, power):
        self.name = name
        self.height = height
        self.blood = 10
        self.power = power
    def bark(self):
        print(f'我是{self.name},身高{self.height}，血量{self.blood}，攻击力{self.power}')

'''现在有些特殊的狗，它们有普通狗的属性，也有自己特殊的属性&方法：'''
'''1.牧羊犬：①有num_of_sheeps属性'''
class SheepDog(Dog):  # 子类—SheepDog—'驼峰命名法'；(Dog)参数是它父类的类名。
    # 子类的构造与父类的构造差不多，多出了一个自己的独有属性'num_of_sheep'
    def __init__(self, name, height, power, num_of_sheep):
        # super()是专门调用父类的关键词
        super().__init__(name, height, power)
        # 这里把父类需要的几个额外的参数传上去，注意！self不用传了

        # 再把自己的独有参数 传给自己的独有属性
        self.num_of_sheep = num_of_sheep

'''2.警犬：①有ability属性 （值1-5）'''
class PoliceDog(Dog):
    def __init__(self, name, height, power, ability):
        super().__init__(name, height, power)
        self.ability=ability

'''3.宠物犬：①有price属性 （1000-10000）'''
class PetDog(Dog):
    def __init__(self, name, height, power, price):
        super().__init__(name, height, power)
        self.price=price

d1 = Dog('大黄', 0.7, 3)  # 第一个普通狗
d2 = Dog('二黑', 0.5, 4)  # 第二个普通狗
dd1 = SheepDog('小牧', 0.8, 2, 5)  # 一只牧羊犬
dd2 = PoliceDog('小察', 0.85, 3, 4)  # 一只警犬
dd3 = PetDog('小逗', 0.15, 1, 2700)  # 一只宠物犬

print(dd1.name)
print(dd1.blood,'blood这个参数不是我们传的，是父类中默认的')
print('看管羊只数：', dd1.num_of_sheep)
dd1.bark()
print('*********************')

print(dd2.name)
print(dd2.blood,'blood这个参数不是我们传的，是父类中默认的')
print('搜查能力：', dd2.ability)
dd2.bark()
print('*********************')

print(dd3.name)
print(dd3.blood,'blood这个参数不是我们传的，是父类中默认的')
print('价格：', dd3.price)
dd3.bark()
