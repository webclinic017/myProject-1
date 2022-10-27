'''
1.参考英雄联盟 创建相应的类 和 实例
2.要求至少有3个类
3.要求必须有继承关系
4.要求必须有实例属性 和 类属性
5.要求必须有实例方法 和 类方法
生物：（野怪） ，英雄
装备:
防御塔


'''
class Object:
    all_objects=[]
    @classmethod
    def attack(cls,someone1,someone2):
        for a in cls.all_objects:
            if someone2.name == a.name:
                for b in cls.all_objects:
                    if someone1.name == b.name:
                        a.blood -= b.attack_damage*(1-a.resistance)
                        if a.blood <= 0:
                            print(f'{b.name}击杀了{a.name}')
                        else:
                            print(f'{b.name}攻击了一下{a.name}，'
                                  f'{a.name}的{a.resistance}抗性为它格挡了{b.attack_damage*a.resistance}伤害，'
                                  f'实际造成{b.attack_damage*(1-a.resistance)}伤害，'
                                  f'{a.name}的血量变为{a.blood}')
    def __init__(self, name, blood, resistance, attack_damage, attack_distance):
        self.name = name
        self.blood = blood
        self.resistance = resistance
        self.attack_damage = attack_damage
        self.attack_distance = attack_distance
        Object.all_objects.append(self)
class Turret(Object):
    def __init__(self, name, blood, resistance, attack_damage, attack_distance, position):
        super().__init__(name, blood, resistance, attack_damage, attack_distance)
        self.position = position
class Animal(Object):
    def __init__(self, name, blood, resistance, attack_damage, attack_distance, speed):
        super().__init__(name, blood, resistance, attack_damage, attack_distance)
        self.speed = speed
class Hero(Animal):
    def __init__(self, name, blood, resistance, attack_damage, attack_distance, speed, skill_name, skill_damage):
        super().__init__(name, blood, resistance, attack_damage, attack_distance, speed)
        self.skill_name = skill_name
        self.skill_damage = skill_damage
    def skill(self,hero):
        if hero.blood > self.skill_damage*(1-hero.resistance):
            hero.blood -= self.skill_damage*(1-hero.resistance)
            print(f'{self.name}使用技能\'{self.skill_name}\'命中{hero.name}，'
                  f'{hero.name}的{hero.resistance}抗性为它格挡了{self.skill_damage * hero.resistance}伤害，'
                  f'实际造成{self.skill_damage * (1-hero.resistance)}伤害，'
                  f'{hero.name}的血量变为{hero.blood}')
        else:
            hero.blood=0
            print(f'{self.name}使用技能\'{self.skill_name}\'击杀了{hero.name}，')


b1=Object('前排兵', 150, 0.2, 7, 50)
b2=Object('后排兵', 100, 0.1, 10, 120)
b3=Object('炮车', 300, 0.15, 12, 160)
t1=Turret('一塔', 1200, 0.3, 40, 700, '中路')
t2=Turret('二塔', 1000, 0.4, 50, 700, '下路')
y1=Animal('蛤蟆', 450, 0.25, 28, 160, 200)
y2=Animal('石甲虫', 500, 0.27, 22, 130, 130)
h1=Hero('剑圣', 1250, 0.4, 120, 300, 450, '阿尔法突袭', 250)
h2=Hero('诺手', 1680, 0.6, 95, 300, 395, '大杀四方', 180)


print(Object.all_objects)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(h1,h2)
Object.attack(t1,y2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)
h1.skill(h2)








