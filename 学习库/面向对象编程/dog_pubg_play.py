from dog_pubg import *
import time
import random
for i in range(1,100):
    if i % 3 == 1:
        Dog(i)
    if i % 3 == 2:
        SheepDog(i)
    if i % 3 == 0:
        PoliceDog(i)

while True:
    if len(Dog.dogs)==1:
        print('******游戏结束******')
        print('******大吉大利******')
        print('******今晚吃鸡******')
        print(f'今晚的幸存者是{Dog.dogs[0].name}号{Dog.dogs[0].type}狗狗!!')
        break

    d1, d2 = random.sample(Dog.dogs, 2)
    d2.bit(d1)
    time.sleep(0.01)











