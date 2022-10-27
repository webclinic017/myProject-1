'''
1.汽车:
创建一个名为Car的类，其方法__init__() 设置两个属性:name和brand(品牌)。
定义一个名为show()的方法，功能是打印出汽车的名称和品牌。
定义一个名为run()的方法，打印:汽车XX跑起来了。其中XX表示汽车的name.
根据这个类创建一个名为car的实例，先通过属性直接打印其两个属性，再调用上面的两个方法。
'''
class Car:
    def __init__(self,name,brand,max_people):
        self.name=name
        self.brand=brand
        self.number_of_people=0
        self.max_people=max_people
    def show(self):
        print(f'这辆名字叫{self.name}的汽车属于{self.brand}品牌')
    def run(self):
        print(f'汽车{self.name}跑起来了。')
    def set_people(self,num):
        if num > self.max_people:
            self.number_of_people=self.max_people
        else:
            self.number_of_people=num
    def increase_people(self):
        if self.number_of_people >= self.max_people:
            pass
        else:
            self.number_of_people+=1
    def reduce_people(self):
        if self.number_of_people > 0:
            self.number_of_people-=1
        else:
            pass


car=Car('悦动2007青春版','北京现代',5)
print(car.name)
print(car.brand)
car.show()
car.run()
print('-'*100)


'''
2. 5辆汽车:
根据在练习1而编写的类创建5个实例，并对每个实例调用方法show方法。
'''
car1=Car('明锐','大众斯柯达',5)
car2=Car('卡罗拉','丰田',6)
car3=Car('福克斯','福特',5)
car4=Car('S90','沃尔沃',7)
car5=Car('揽胜','路虎',8)
car1.show()
car2.show()
car3.show()
car4.show()
car5.show()
print('-'*100)


'''
3. Pig:
创建一个名为Pig的类，其中包含属性name和weight
定义一个名为show()方法，打印Pig的基本信息;
再定义一个名为run() 的方法，打印：'XX: 没吃过猪肉，让你看看猪跑！'。
创建多个表示不同猪的实例，并对每个实例都调用上述两个方法。
'''
class Pig:
    def __init__(self,name,weight):
        self.name=name
        self.weight=weight
    def show(self):
        print(f'这头猪名字叫{self.name}，称重{self.weight}公斤')
    def run(self):
        print(f'{self.name}: 没吃过猪肉，让你看看猪跑！')
pig1=Pig('宁乡花猪',233.5)
pig2=Pig('藏猪',279)
pig3=Pig('淮猪',311)
pig4=Pig('太湖猪',336)
pig5=Pig('金华两头乌',198)
pig1.show()
pig2.show()
pig3.show()
pig4.show()
pig5.show()
print('-'*10)
pig1.run()
pig2.run()
pig3.run()
pig4.run()
pig5.run()
print('-'*100)


'''
4 就餐人数:
在为完成练习1的Car类中，添加一个名为number_of_people的属性，并将其默认值设置为0。添加一个名为max_people的属性，表示车上最多可以有几个人。修改相应的构造方法，传入max_people的值。
添加一个名为set_people() 的方法，它让你能够设置车上的人数，但是不能超过max_people的限制。
添加一个名为increase_people()的方法，每次调用这个方法就会让车上的人数加1，但是不能超过max_people的限制。
添加一个名为reduce_people()的方法，每次调用这个方法就会让车上的人数减少1，但是最多减少为0.
根据这个类创建一个名为car的实例，先通过属性直接打印其两个属性，再调用上面的两个方法。;打印有多少人在车上，然后多次调用以上3个方法，并打印车上的人数。
'''
car0=Car('Smart','奔驰',3)
car0.show()
car0.run()
print(car0.number_of_people)

print('-'*10)
car0.set_people(1)
print(car0.number_of_people)

print('-'*10)
car0.increase_people()
print(car0.number_of_people)
car0.increase_people()
print(car0.number_of_people)
car0.increase_people()
print(car0.number_of_people)

print('-'*10)
car0.reduce_people()
print(car0.number_of_people)
car0.reduce_people()
print(car0.number_of_people)
car0.reduce_people()
print(car0.number_of_people)
car0.reduce_people()
print(car0.number_of_people)
