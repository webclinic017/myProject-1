import random
class Dog:
    dogs = []
    def __init__(self, name):
        self.name = name
        self.blood = 100
        self.attack = 10
        self.defense = 0.5
        self.type = '土狗'
        print(f'狗狗{self.name}问世！')
        Dog.dogs.append(self)

    def bit(self, d):
        if d.blood > self.attack * (1 - d.defense):
            d.blood -= self.attack * (1 - d.defense)
            print(f'{self.name}咬了{d.name}一口，'
                  f'{d.name}的抗性为它格挡了{self.attack * d.defense}伤害，'
                  f'实际造成{self.attack * (1 - d.defense)}伤害，'
                  f'{d.name}的血量变为{d.blood}！')
        else:
            d.blood = 0
            print(f'{self.name}咬死了{d.name}！')
            Dog.dogs.remove(d)

'''1.牧羊犬：'''
class SheepDog(Dog):
    def __init__(self, name):
        super().__init__(name)
        self.attack = random.randint(5, 10)
        self.defense = random.randint(5000, 7000) / 10000
        self.type = '牧羊犬'

'''2.警犬：'''
class PoliceDog(Dog):
    def __init__(self, name):
        super().__init__(name)
        self.attack = random.randint(10, 15)
        self.defense = random.randint(3000, 5000) / 10000
        self.type = '警犬'
