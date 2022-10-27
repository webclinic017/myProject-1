import turtle as t
class MyTurtle(t.Turtle):
    # 这里就不用__init__构造传参了 我们直接用turtle的参数
    def big_circle(self):
        self.color('black')
        self.circle(100,180,4)

s = t.Screen()  # 调用一个窗口
t = MyTurtle()
t.big_circle()
s.mainloop()  # 让窗口不要关闭，在原地等着我

'''B站搜索：麦叔 迷宫。有小海龟标准库继承更深层次的运用'''



