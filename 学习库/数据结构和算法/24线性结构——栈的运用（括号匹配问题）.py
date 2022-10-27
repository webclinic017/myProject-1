'''
给一串字符串'{([([{}])])}'、'[]{}()'、'{]}[' 问：改字符串中的括号是否匹配
    思路  例如：[]{}([])
         从左到右依次读取括号
         设计一个空栈，
            1如果读到左括号就进栈

            2如果读到右括号看 栈里是否是否存在括号（是不是空栈）
                2.1不存在————不匹配

                2.2存在看是否匹配
                    2.2.1左右匹配————出栈
                    2.2.2左右不匹配——不匹配
'''

a1 = input('请输入括号：')
l_brackets = '([{'
r_brackets = ')]}'
brackets = l_brackets + r_brackets
# 先判断是否输入错误
for i in a1:
    if i not in brackets:
        print('您的输入有误！')
        exit()  # 这里要用exit直接退出程序
                # 若用break 就算输入有误 也有部分代码会执行
# 设计一个空栈
stack = []
for i in a1:
    if i in l_brackets:  # 如果读到左括号就进栈
        stack.append(i)
    else:                # 如果读到右括号看 栈里是否是否存在括号（是不是空栈）
        if len(stack) == 0:  # 不存在  空栈
            print('不匹配！')
            exit()
        else:                # 存在看是否左右匹配
            l = stack[-1]
            r = i
            if l_brackets.find(l) == r_brackets.find(r):  # 左右匹配
                stack.pop()
            else:                                         # 左右不匹配
                print('不匹配！')
                exit()
if len(stack) == 0:
    print('匹配！')
else:
    print('不匹配！')
'''
老师在这里用的是字典的方法 
match={  '}':'{',  ']':'[',  ')':'('  }
match[']']  得到--->  '['      这样就不同find两次下标了
'''

