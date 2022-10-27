class Dog:  # 父亲类
    def __init__(self, name, height, power):
        self.name = name
        self.height = height
        self.blood = 10
        self.power = power
    def bark(self):
        print(f'我的名字叫{self.name},身高{self.height}，血量{self.blood}，攻击力{self.power}。')

'''1.牧羊犬：'''
class SheepDog(Dog):
    def __init__(self, name, height, power, num_of_sheep):
        super().__init__(name, height, power)
        self.num_of_sheep = num_of_sheep
    def bark(self):
        print(f'我属于牧羊犬类，我能看管{self.num_of_sheep}只羊，',end='')
        super().bark()

'''2.警犬：'''
class PoliceDog(Dog):
    def __init__(self, name, height, power, ability):
        super().__init__(name, height, power)
        self.ability=ability
    def bark(self):
        print(f'我属于警犬，我能搜查{self.ability}个地方，',end='')
        super().bark()

'''3.宠物犬：'''
class PetDog(Dog):
    def __init__(self, name, height, power, price):
        super().__init__(name, height, power)
        self.price=price
    def bark(self):
        print(f'我属于宠物犬，我的市场价是{self.price}元，',end='')
        super().bark()