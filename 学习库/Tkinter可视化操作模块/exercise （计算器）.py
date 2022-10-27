import tkinter as tk

# region 计算器 重写版
window = tk.Tk()
window.title('计算器')
window.geometry('195x182')


def caculate():
    if v.get() == '请输入' or v.get() == '':
        v.set('0')
    try:
        v.set(eval(v.get()))
    except:
        v.set('输入错误')


def show(p):
    if v.get() == '请输入':
        v.set('')
    tmp = v.get()
    v.set(tmp + p)


v = tk.StringVar()
v.set('请输入')
l = tk.Label(window, bg='white', textvariable=v, height=1, width=27, justify='left').grid(row=0, column=0, columnspan=4)
c = tk.Button(window, text='C', width=4, height=1, bg='white', command=lambda: v.set('')).grid(row=1, column=0, ipadx=6, pady=1)
d = tk.Button(window, text='D', width=4, height=1, bg='white', command=lambda: v.set('')).grid(row=1, column=1, ipadx=6, pady=1)
bk = tk.Button(window, text='←', width=4, height=1, bg='white', command=lambda: v.set(v.get()[:-1])).grid(row=1, column=2, ipadx=6, pady=1)
eq = tk.Button(window, text='=', width=4, height=1, bg='white', command=caculate).grid(row=1, column=3, ipadx=6, pady=1)
b7 = tk.Button(window, text='7', width=4, height=1, bg='white', command=lambda: show('7')).grid(row=2, column=0, ipadx=6, pady=1)
b8 = tk.Button(window, text='8', width=4, height=1, bg='white', command=lambda: show('8')).grid(row=2, column=1, ipadx=6, pady=1)
b9 = tk.Button(window, text='9', width=4, height=1, bg='white', command=lambda: show('9')).grid(row=2, column=2, ipadx=6, pady=1)
jia = tk.Button(window, text='+', width=4, height=1, bg='white', command=lambda: show('+')).grid(row=2, column=3, ipadx=6, pady=1)
b4 = tk.Button(window, text='4', width=4, height=1, bg='white', command=lambda: show('4')).grid(row=3, column=0, ipadx=6, pady=1)
b5 = tk.Button(window, text='5', width=4, height=1, bg='white', command=lambda: show('5')).grid(row=3, column=1, ipadx=6, pady=1)
b6 = tk.Button(window, text='6', width=4, height=1, bg='white', command=lambda: show('6')).grid(row=3, column=2, ipadx=6, pady=1)
jian = tk.Button(window, text='-', width=4, height=1, bg='white', command=lambda: show('-')).grid(row=3, column=3, ipadx=6, pady=1)
b1 = tk.Button(window, text='1', width=4, height=1, bg='white', command=lambda: show('1')).grid(row=4, column=0, ipadx=6, pady=1)
b2 = tk.Button(window, text='2', width=4, height=1, bg='white', command=lambda: show('2')).grid(row=4, column=1, ipadx=6, pady=1)
b3 = tk.Button(window, text='3', width=4, height=1, bg='white', command=lambda: show('3')).grid(row=4, column=2, ipadx=6, pady=1)
chen = tk.Button(window, text='*', width=4, height=1, bg='white', command=lambda: show('*')).grid(row=4, column=3, ipadx=6, pady=1)
b0 = tk.Button(window, text='0', width=4, height=1, bg='white', command=lambda: show('0')).grid(row=5, column=0, ipadx=30, pady=1, columnspan=2)
dian = tk.Button(window, text='.', width=4, height=1, bg='white', command=lambda: show('.')).grid(row=5, column=2, ipadx=6, pady=1)
chu = tk.Button(window, text='/', width=4, height=1, bg='white', command=lambda: show('/')).grid(row=5, column=3, ipadx=6, pady=1)

window.mainloop()
# endregion


'''
# region 窗口（计算器）
window2 = tk.Tk()
window2.title('计算器')
window2.geometry('500x800')
x1 = 0
x2 = 0
symbol = ''
val = tk.StringVar()
l = tk.Label(window2, bg='white', textvariable=val, font=('Arial', 12), width=20, height=1)
e = tk.Entry(window2, width=20, show=None)


# t = tk.Text(window2, width=10, height=1)


def clean():
    e.delete(0, 'end')


def add_point():
    val = e.get()
    if '.' not in val:
        e.insert('end', '.')


def add_0():
    val = e.get()
    if val != '':
        e.insert('end', '0')


def add_1():
    e.insert('end', '1')


def add_2():
    e.insert('end', '2')


def add_3():
    e.insert('end', '3')


def add_4():
    e.insert('end', '4')


def add_5():
    e.insert('end', '5')


def add_6():
    e.insert('end', '6')


def add_7():
    e.insert('end', '7')


def add_8():
    e.insert('end', '8')


def add_9():
    e.insert('end', '9')


def suan(n1, n2, sym):
    global x1, x2
    if sym == '':
        pass
    elif symbol == '+':
        n1 = n1 + n2
        n2 = 0
        x1 = n1
        x2 = n2


def jia():
    global x1, x2, symbol
    v = e.get()
    if v == '':
        v = '0'
    
    symbol = '+'
    suan(x1, x2, symbol)
    e.delete(0, 'end')


# def jian():
#     global result
#     v = e.get()
#     if v != '':
#         result -= float(v)
#         e.delete(0, 'end')
#
#
# def chen():
#     global result
#     v = e.get()
#     if v != '':
#         result *= float(v)
#         e.delete(0, 'end')
#
#
# def chu():
#     global val
#     global result
#     v = e.get()
#     if v != '':
#         result /= float(v)
#         e.delete(0, 'end')
#     else:
#         val.set('被除数不能为0')

def dengyu():
    global x1, x2, symbol, val
    v = e.get()
    if v == '':
        v = '0'
    x2 = float(v)
    suan(x1, x2, symbol)
    symbol = ''
    e.delete(0, 'end')
    val.set(str(x1))


q = tk.Button(window2, text='退出', width=15, height=1, command=window2.quit)
b_point = tk.Button(window2, text='.', width=15, height=1, command=add_point)
b0 = tk.Button(window2, text='0', width=15, height=1, command=add_0)
b1 = tk.Button(window2, text='1', width=15, height=1, command=add_1)
b2 = tk.Button(window2, text='2', width=15, height=1, command=add_2)
b3 = tk.Button(window2, text='3', width=15, height=1, command=add_3)
b4 = tk.Button(window2, text='4', width=15, height=1, command=add_4)
b5 = tk.Button(window2, text='5', width=15, height=1, command=add_5)
b6 = tk.Button(window2, text='6', width=15, height=1, command=add_6)
b7 = tk.Button(window2, text='7', width=15, height=1, command=add_7)
b8 = tk.Button(window2, text='8', width=15, height=1, command=add_8)
b9 = tk.Button(window2, text='9', width=15, height=1, command=add_9)
jia = tk.Button(window2, text='+', width=15, height=1, command=jia)
# jian = tk.Button(window2, text='-', width=15, height=1, command=jian)
# chen = tk.Button(window2, text='*', width=15, height=1, command=chen)
# chu = tk.Button(window2, text='/', width=15, height=1, command=chu)
c = tk.Button(window2, text='C', width=15, height=1, command=clean)
dengyu = tk.Button(window2, text='=', width=15, height=1, command=dengyu)

l.pack()
e.pack()
b_point.pack()
b0.pack()
b1.pack()
b2.pack()
b3.pack()
b4.pack()
b5.pack()
b6.pack()
b7.pack()
b8.pack()
b9.pack()
q.pack()
c.pack()
jia.pack()
# jian.pack()
# chen.pack()
# chu.pack()
dengyu.pack()

window2.mainloop()
# endregion
'''
