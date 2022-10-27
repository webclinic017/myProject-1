import tkinter as tk
import tkinter.messagebox


# region 窗口1（标签label 和 按钮button）
window1 = tk.Tk('点击测试窗口')  # Tk()表示建立一个窗口
window1.title('点击测试')  # 重新命名
window1.geometry('900x100')  # 窗口大小：注意格式：'宽x高' 中间用x

val = tk.StringVar()  # 定义一个字符串变量
hit_on_off = False  # 击打状态


def hit_me():
    global hit_on_off
    if hit_on_off == False:
        val.set('you hit me!')
        hit_on_off = True
    else:
        hit_on_off = False
        val.set('')  # 设置为空字符时要有''


# 设置标签 【主关键词主体，副关键词顺序可变：text表示固定文本 textvariable表示可变文本，bg背景色，font字体字号 width宽度（单位：字符）height长度】
l = tk.Label(window1, bg='gray', textvariable=val, font=('Arial', 12), width=25, height=1)
l.pack()  # 安置方式：上下左右

b = tk.Button(window1, text='hit me', width=15, height=1, command=hit_me)
b.pack()  # 安置方式：上下左右

window1.mainloop()  # 运行窗口，mainloop是一种相当于whileTrue的循环方式
# endregion



# region 窗口2 （entry 和 text）
window2 = tk.Tk()
window2.title('输入框和文本框')
window2.geometry('500x500')
e = tk.Entry(window2, width=4, show=None)  # 密码：show='*'
t = tk.Text(window2, width=20, height=2)


def insert_point():
    val = e.get()
    t.insert('insert', val)  # 'insert'这个参数就表示 插入到鼠标当前的位置


def insert_end():
    val = e.get()
    t.insert('end', val)  # insert(2.3, val) 插入到第二行的第三位 


b1 = tk.Button(window2, text='insert point', width=15, height=1, command=insert_point)
b2 = tk.Button(window2, text='insert end', width=15, height=1, command=insert_end)

e.pack()
b1.pack()
b2.pack()
t.pack()
window2.mainloop()  # 运行窗口，mainloop是一种相当于whileTrue的循环方式
# endregion



# region 窗口3 （列表部件 Listbox）
window3 = tk.Tk()
window3.title('列表部件 Listbox')
window3.geometry('500x500')
val1 = tk.StringVar()
l = tk.Label(window3, width=10, height=1, bg='green', font=('Arial', 20), textvariable=val1)
val2 = tk.StringVar()
val2.set(('a', 'b', 'c', 'd', 'e'))  # 直接把可变字符串定义为一个元组
lb = tk.Listbox(window3, height=22, listvariable=val2)
list1 = [1, 2, 3, 4]
for i in list1:
    lb.insert('end', i)
lb.insert(0, 'first')  # 插到最前面
lb.insert('end', 'last')  # 插到最后面
lb.delete(1)  # 删除1位置上的值
lb.delete(5)


def print_selection():
    if lb.curselection():
        tmp = lb.get(lb.curselection())  # 把光标选定的东西赋值给tmp 选定的东西lb.curselection()
        val1.set(tmp)
        lb.delete(lb.curselection())
    else:
        val1.set('没有了！')


b = tk.Button(window3, text='print selection', width=15, height=1, command=print_selection)

l.pack()
b.pack()
lb.pack()
window3.mainloop()  # 运行窗口，mainloop是一种相当于whileTrue的循环方式
# endregion



# region 窗口4 （Radiobutton 选择按钮）
window4 = tk.Tk()
window4.title('Radiobutton 选择按钮')
window4.geometry('500x500')

l = tk.Label(window4, width=20, height=1, bg='brown', font=('Arial', 20), text='请选择选项')


def print_radiobutton():
    l.config(text='您选择了选项：' + val1.get())  # 1.config()是改变参数的命令 即使不是可变参数 也可以改变 2.这里val1必须加get() 把可变字符串get成不变字符串才能输出

    if val1.get() == 'A':  # 这里val1必须加get() 把可变字符串get成不变字符串
        l.config(bg='red')
    elif val1.get() == 'B':  # 这里val1必须加get() 把可变字符串get成不变字符串
        l.config(bg='yellow')
    else:
        l.config(bg='blue')


val1 = tk.StringVar()  # 先定义个可改变变量 方便下面去改变其赋值
r1 = tk.Radiobutton(window4, text='选项A：红色', variable=val1, value='A', command=print_radiobutton)
#       Radiobutton(  长在            显示        改变的目标变量      储藏值                命令         )
r2 = tk.Radiobutton(window4, text='选项B：黄色', variable=val1, value='B', command=print_radiobutton)
r3 = tk.Radiobutton(window4, text='选项C：蓝色', variable=val1, value='C', command=print_radiobutton)

l.pack()
r1.pack()
r2.pack()
r3.pack()
window4.mainloop()  # 运行窗口，mainloop是一种相当于whileTrue的循环方式
# endregion



# region 窗口5 （Scale 尺度）
window5 = tk.Tk()
window5.title('Scale 尺度')
window5.geometry('1000x200')
l = tk.Label(window5, width=20, height=1, bg='white', font=('Arial', 15), text='请调节空调温度')


def print_scale(a):
    l.config(text='目标温度：' + a)


# 注意Scale作为滑条比较特殊，它在调用函数的时候回默认传出一个值a 就是它的变动值
s = tk.Scale(window5, label='滑动滑条以改变室内温度', from_=16, to=35, orient=tk.HORIZONTAL, length=950, showvalue=True, tickinterval=1, resolution=0.1, command=print_scale)
#   tk.Scale(长在        说明标签                     最低值    最高值   滑条方向（VERTICAL垂直） 滑条长度（像素点）  是否显示值       最小分割单位      最小变动单位             命令       )


l.pack()
s.pack()

window5.mainloop()  # 运行窗口，mainloop是一种相当于whileTrue的循环方式
# endregion



# region 窗口6 （Checkbutton 勾选项）
window6 = tk.Tk()
window6.title('Checkbutton 勾选项')
window6.geometry('500x500')
l = tk.Label(window6, width=20, height=1, bg='white', font=('Arial', 15), text='请选择语言')


def print_checkbutton():
    if var1.get() == var2.get() == 0:
        l.config(text='我都不会！')
    elif var1.get() == 1 and var2.get() == 0:
        l.config(text='我会Python！')
    elif var1.get() == 0 and var2.get() == 1:
        l.config(text='我会C++！')
    else:
        l.config(text='我都会！')


# var1=var2=tk.IntVar() 我一开始是这样写的 两个选项会同时选或同时取消
var1 = tk.IntVar()
var2 = tk.IntVar()
c1 = tk.Checkbutton(window6, text='Python', variable=var1, onvalue=1, offvalue=0, command=print_checkbutton)
c2 = tk.Checkbutton(window6, text='C++', variable=var2, onvalue=1, offvalue=0, command=print_checkbutton)
#    tk.Checkbutton(长在        说明标签          赋值目标        勾选值       不勾选值                命令          )


l.pack()
c1.pack()
c2.pack()
window6.mainloop()  # 运行窗口，mainloop是一种相当于whileTrue的循环方式
# endregion



# region 窗口7 （Canvas 画布）
window7 = tk.Tk()
window7.title('Canvas 画布')
window7.geometry('500x500')
canvas = tk.Canvas(window7, bg='blue', height=400, width=500)
x1, y1, x2, y2 = 50, 50, 200, 200
line = canvas.create_line(x1, y1, x2, y2)  # 直线
oval = canvas.create_oval(x1, y1, x2, y2, fill='red')  # 椭圆形
arc = canvas.create_arc(300, 100, 350, 150, start=0, extent=90, fill='yellow')  # 扇形
rect = canvas.create_rectangle(400, 0, 450, 50, fill='green')  # 矩形


def movement():
    canvas.move(rect, 0, 2)


b = tk.Button(window7, text='移动', command=movement)
canvas.pack()
b.pack()
window7.mainloop()
# endregion



# region 窗口8 （Menubar 菜单）
window8 = tk.Tk()
window8.title('Menubar 菜单')
window8.geometry('500x500')
l = tk.Label(window8, width=20, height=1, bg='white', text='')
count = 1


def do_job():
    global count
    l.config(text='do  ' + str(count))
    count += 1


menubar = tk.Menu(window8)  # menubar长在window8上 （定子父关系、生长关系）
filemenu = tk.Menu(menubar, tearoff=True)  # filemenu长在menubar上,tearoff代表分不分开（定子父关系、生长关系）
menubar.add_cascade(label='File', menu=filemenu)  # add_cascade(),menubar中的一个menu是filemenu（定父子关系）
filemenu.add_command(label='New', command=do_job)  # 下拉菜单中的功能都用 add_command
filemenu.add_command(label='Save', command=do_job)
filemenu.add_command(label='Open', command=do_job)
filemenu.add_command(label='Close', command=do_job)
filemenu.add_separator()
filemenu.add_command(label='Exit', command=window8.quit)
# 下面是一个submenu 做法和filemenu一样 sub——file之间建立一个父子关系 就行了
submenu = tk.Menu(filemenu, tearoff=False)  # submenu长在filemenu上,tearoff代表分不分开（定子父关系、生长关系）
filemenu.add_cascade(label='Import', menu=submenu)  # add_cascade(),filemenu中的一个menu是submenu（定父子关系）
submenu.add_command(label='project1', command=do_job)  # submenu的下拉菜单中的功能都用 add_command
# 下面复制一下 做了一个Edit菜单
editmenu = tk.Menu(menubar, tearoff=True)
menubar.add_cascade(label='Edit', menu=editmenu)
editmenu.add_command(label='Copy', command=do_job)
editmenu.add_command(label='Paste', command=do_job)
editmenu.add_command(label='Cut', command=do_job)
editmenu.add_command(label='Delate', command=do_job)
editmenu.add_separator()
editmenu.add_command(label='Undo', command=do_job)
# 下面复制一下 做了一个Help菜单
helpmenu = tk.Menu(menubar, tearoff=False)
menubar.add_cascade(label='Help', menu=helpmenu)
helpmenu.add_command(label='Tips', command=do_job)
helpmenu.add_command(label='Help', command=do_job)
helpmenu.add_command(label='Update', command=do_job)
helpmenu.add_command(label='Register', command=do_job)
helpmenu.add_separator()
helpmenu.add_command(label='About', command=do_job)

window8.config(menu=menubar)  # 菜单的放置和其他元件的放置不同 是一种对窗口参数的重新定义
l.pack()
window8.mainloop()
# endregion



# region 窗口9 （Frame 窗口中的小框架）
window9 = tk.Tk()
window9.title('Frame 窗口中的小框架')
window9.geometry('500x500')

l = tk.Label(window9, width=5, height=1, bg='white', font=('Arial', 15), text='主标签')
frm = tk.Frame(window9)
frm_left = tk.Frame(frm)
frm_right = tk.Frame(frm)
l1 = tk.Label(frm_left, width=5, height=1, bg='white', font=('Arial', 15), text='左标签')
l2 = tk.Label(frm_right, width=5, height=1, bg='white', font=('Arial', 15), text='右标签')

l.pack()
frm.pack()
frm_left.pack(side='left')
frm_right.pack(side='right')
l1.pack()
l2.pack()

window9.mainloop()
# endregion



# region 窗口10 （messagebox 弹窗）
window10 = tk.Tk()
window10.title('messagebox 弹窗')
window10.geometry('500x500')


def hit10():
    tkinter.messagebox.showinfo(title='傻逼', message='hahahaha')
    tkinter.messagebox.showwarning(title='傻逼', message='nononowarnning')
    tkinter.messagebox.showerror(title='傻逼', message='nononoerror')
    print(tkinter.messagebox.askquestion(title='傻逼', message='告诉我'))  # return yes/no
    print(tkinter.messagebox.askyesno(title='傻逼', message='告诉我'))  # return True/False
    print(tkinter.messagebox.askretrycancel(title='傻逼', message='告诉我'))  # return True/False
    print(tkinter.messagebox.askokcancel(title='傻逼', message='告诉我'))  # return True/False


b = tk.Button(window10, text='点击', width=5, height=1, bg='white', font=('Arial', 15), command=hit10)

b.pack()

window10.mainloop()
# endregion



# region 窗口11 （pack/grid/place 放置位置）
window11 = tk.Tk()
window11.title('pack/grid/place 放置位置')
window11.geometry('500x500')

tk.Button(window11, text='点击', bg='white', command=None).pack(side='top')
tk.Button(window11, text='点击', bg='white', command=None).pack(side='bottom')
tk.Button(window11, text='点击', bg='white', command=None).pack(side='left')
tk.Button(window11, text='点击', bg='white', command=None).pack(side='right')
# -------------------------------------------------------------------------------------------------
window111 = tk.Tk()
window111.title('pack/grid/place 放置位置')
window111.geometry('500x500')
# grid(x,y) 表示相对的位置
for i in range(4):
    for j in range(3):
        tk.Button(window111, text='点击', width=10, height=2, bg='white', command=None).grid(row=i, column=j, padx=1, pady=1)
        #                             row → 第几行   column → 第几列   padx/pady → 外部的扩展（变紧）     ipadx/ipady → 内部的扩展(变大)
# -------------------------------------------------------------------------------------------------
window112 = tk.Tk()
window112.title('pack/grid/place 放置位置')
window112.geometry('500x500')
tk.Button(window112, text='点击', bg='white', command=None).place(x=10, y=10)
tk.Button(window112, text='点击', bg='white', command=None).place(x=60, y=60)
tk.Button(window112, text='点击', bg='white', command=None).place(x=110, y=110)
tk.Button(window112, text='点击', bg='white', command=None).place(x=160, y=160, anchor='ne')
window11.mainloop()
window111.mainloop()
window112.mainloop()

# endregion


