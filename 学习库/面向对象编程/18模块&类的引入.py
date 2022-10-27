# 这里引用了一个文件
import dog_18
# 这里就看出了文件不能随意命名 必须符合规范 否则不能正确引用
sd=dog_18.SheepDog('小可爱', 0.75, 2, 16)
print(sd.power)
sd.bark()