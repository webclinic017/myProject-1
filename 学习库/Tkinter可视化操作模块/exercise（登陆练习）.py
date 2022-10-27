import tkinter as tk
import tkinter.messagebox

# region 窗口 （一个登陆窗口）
window = tk.Tk()
window.title('一个登陆窗口')
window.geometry('450x300')
canvas = tk.Canvas(window, height=200, width=500)
pic_file = tk.PhotoImage(file='welcome.jpg')
image = canvas.create_image(0, 0, anchor='nw', image=pic_file)
canvas.pack()
dict1 = {'fsw': '123'}
l1 = tk.Label(window, text='用户名', width=4, height=1)
l2 = tk.Label(window, text='密码', width=4, height=1)
tishi = tk.StringVar()
tishi.set('example@python.com')
e1 = tk.Entry(window, textvariable=tishi, width=20, show=None)
e2 = tk.Entry(window, width=20, show='*')


def login():
    if e2.get() == '':
        tkinter.messagebox.showwarning(title='登陆失败', message='密码不能为空')
    else:
        for key in dict1.keys():
            if key == e1.get():
                if dict1[key] == e2.get():
                    tkinter.messagebox.showinfo(title='登陆成功', message='恭喜您账号密码正确')
                    window.quit()
                    # 加上登陆操作
                    break
                else:
                    tkinter.messagebox.showwarning(title='登陆失败', message='密码错误')
                    break
        else:
            r = tkinter.messagebox.askyesno(title='登陆失败', message='您的账户信息不存在，是否注册')
            if r == True:
                regist()
            else:
                window.quit()


def regist():
    window_regist = tk.Toplevel(window)  # 是在原窗口上新建一个小窗口
    window_regist.title('请注册')
    window_regist.geometry('240x150')

    l11 = tk.Label(window_regist, text='用户名', width=6, height=1)
    l22 = tk.Label(window_regist, text='密码', width=6, height=1)
    l33 = tk.Label(window_regist, text='确认密码', width=6, height=1)
    e11 = tk.Entry(window_regist, width=20, show=None)
    e22 = tk.Entry(window_regist, width=20, show='*')
    e33 = tk.Entry(window_regist, width=20, show='*')

    def regist_confirm():
        if e11.get() == '':
            tkinter.messagebox.showerror(title='错误', message='用户名不能为空')
        elif e22.get() == '':
            tkinter.messagebox.showerror(title='错误', message='密码不能为空')
        elif e22.get() != e33.get():
            tkinter.messagebox.showerror(title='错误', message='两次密码必须相同')
        else:
            dict1[e11.get()] = e22.get()
            tkinter.messagebox.showinfo(title='成功', message='恭喜您注册成功')
            window_regist.destroy()

    def regist_quit():
        window_regist.destroy()

    b11 = tk.Button(window_regist, text='注册', width=5, height=1, bg='white', command=regist_confirm)
    b22 = tk.Button(window_regist, text='退出', width=5, height=1, bg='white', command=regist_quit)
    l11.place(x=10, y=10)
    l22.place(x=10, y=40)
    l33.place(x=10, y=70)
    e11.place(x=80, y=10)
    e22.place(x=80, y=40)
    e33.place(x=80, y=70)
    b11.place(x=45, y=110)
    b22.place(x=140, y=110)


b1 = tk.Button(window, text='登陆', width=5, height=1, bg='white', command=login).place(x=140, y=230)
b2 = tk.Button(window, text='注册', width=5, height=1, bg='white', command=regist).place(x=260, y=230)
l1.place(x=110, y=150)
l2.place(x=110, y=185)
e1.place(x=165, y=150)
e2.place(x=165, y=185)
window.mainloop()
# endregion