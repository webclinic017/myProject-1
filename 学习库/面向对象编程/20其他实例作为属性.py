'''普通犬——不需要狗窝'''
class Dog:
    def __init__(self, name, height, power):
        self.name = name
        self.height = height
        self.blood = 10
        self.power = power
    def bark(self):
        print(f'我的名字叫{self.name},身高{self.height}，血量{self.blood}，攻击力{self.power}。')

'''宠物犬——必须要有狗窝'''
class PetDog(Dog):
    def __init__(self, name, height, power, price, house):
        super().__init__(name, height, power)
        self.price=price
        self.house=house
    def bark(self):
        print(f'我属于宠物犬，我的市场价是{self.price}元，',end='')
        super().bark()

'''狗窝类'''
class DogHouse:
    def __init__(self, house_number):
        self.house_number=house_number


kk=DogHouse('无敌可爱号狗狗房')  # 这里的kk先是作为一个实例传入DogHouse中
pd=PetDog('小可爱', 0.17, 0.8, 9800, kk)  # 再把kk这个实例当作PetDog的属性
print(pd.name)
print(pd.price)
print(pd.house)
print(pd.house.house_number)
pd.bark()


