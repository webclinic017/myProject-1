class Dog:
    num_of_dogs=0  # 本条添加的是一条类属性
    def __init__(self, name0, height0, blood0, power0):
        # 以下添加的都是实例属性 而非类属性
        self.name = name0
        self.height = height0
        self.blood = blood0
        self.power = power0
        print(f'{self.name}出生了，汪汪汪！')

d1 = Dog('大黄', 0.7, 12, 3)  # 第一个实例
d2 = Dog('二黑', 0.5, 10, 4)  # 第二个实例

'''1.类属性只有一份，所有实例都共用这一份类属性'''
'''2.可以通过类名or实例名访问到这一份类属性'''
print(d1.num_of_dogs)  # 通过实例名访问
print(d2.num_of_dogs)  # 通过实例名访问
print(Dog.num_of_dogs)  # 通过类名访问
print('*********')
'''3.修改类属性需要用类名'''
Dog.num_of_dogs=2
'''4.用实例名修改类属性时，会创建一个同名的实例属性，而非修改类属性'''
d1.num_of_dogs=1
'''5.当实例属性的变量名与类属性变量名相同时，使用实例名优先访问的是实例属性'''
print(d1.num_of_dogs)  # 通过实例名访问
print(d2.num_of_dogs)  # 通过实例名访问
print(Dog.num_of_dogs)  # 通过类名访问
