'''
类方法：
1.类方法可以通过类名or实例名调用
2.类方法需要加上@classmethod
3.类方法的第一个参数必须为class (cls)
作业1：写一个类方法num_of_big_dogs,返回高度大于等于0.5米的狗的数量。
作业2：写一个类方法shortest,返回最矮的狗的身高。
'''
class Dog:
    dogs=[]       # 这是一个类属性
    dogs_name=[]  # 这是一个类属性
    @classmethod  # 类方法需要加上@classmethod
    def num_of_dogs(cls): # 类方法的第一个参数必须为class (cls)
        return len(cls.dogs)
    @classmethod
    def highest(cls):
        max_height=-0.1
        for d in cls.dogs:
            if d.height > max_height:
                max_height=d.height
        return max_height
    @classmethod
    def shortest(cls):
        min_height=Dog.highest()
        for d in cls.dogs:
            if d.height < min_height:
                min_height=d.height
        return min_height
    @classmethod
    def num_of_high_dogs(cls):
        count=0
        for d in cls.dogs:
            if d.height >= 0.5:
                count+=1
        return count
    def __init__(self, name0, height0, blood0, power0):
        # 以下添加的都是实例属性 而非类属性
        self.name = name0
        self.height = height0
        self.blood = blood0
        self.power = power0
        print(f'{self.name}出生了，汪汪汪！')
        Dog.dogs.append(self)
        Dog.dogs_name.append(self.name)

d1 = Dog('大黄', 0.7, 12, 3)  # 第一个实例
d2 = Dog('二黑', 0.5, 10, 4)  # 第二个实例
d3 = Dog('三灰', 0.65, 18, 2)  # 第三个实例
d4 = Dog('四白', 0.45, 9, 3)  # 第四个实例
d5 = Dog('五花', 0.2, 4, 1)  # 第五个实例
d6 = Dog('六棕', 0.35, 8, 2)  # 第六个实例
print('*****************')
print(d1.dogs)  # 通过实例名访问
print(d2.dogs[0])  # 通过实例名访问
print(Dog.dogs[-1])  # 通过类名访问
print('*****************')
print(d1.dogs_name)  # 通过实例名访问
print(d2.dogs_name[0])  # 通过实例名访问
print(Dog.dogs_name[-1])  # 通过类名访问
print('*****************')
print(d1.num_of_dogs())  # 通过实例名访问
print(d2.num_of_dogs())  # 通过实例名访问
print(Dog.num_of_dogs())  # 通过类名访问
print('*****************')
print('最高的狗身高：', d1.highest())  # 通过实例名访问
print('最矮的狗身高：', d2.shortest())  # 通过实例名访问
print('超过0.5米狗的只数：', Dog.num_of_high_dogs())  # 通过类名访问