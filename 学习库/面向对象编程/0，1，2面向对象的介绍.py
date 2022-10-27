'''
英雄联盟
对象：英雄 地图 武器 防御塔 野怪
编程就是对现实世界的模拟
类：模板（英雄）
实例：(剑圣)
属性：(护甲魔抗)
方法：(做一次平A)，(释放一次技能)
'''

#一个简单的面向对象的例子
dog1_name='大黄'
dog1_height=0.7
dog1_blood=1.0
dog1_power=0.1

dog2_name='二黑'
dog2_height=0.8
dog2_blood=1.1
dog2_power=0.09

#dog1攻击dog2
print('dog1 attacking dog2')
dog2_blood = dog2_blood - dog1_power

#dog2攻击dog1
print('dog2 attacking dog1')
dog1_blood = dog1_blood - dog2_power
