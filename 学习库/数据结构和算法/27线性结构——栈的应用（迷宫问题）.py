'''
给一个二维列表：
0表示通道 1表示围墙 求一条走出迷宫的路径
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
[1, 起, 0, 1, 0, 0, 0, 1, 0, 1]
[1, 0, 0, 1, 0, 0, 0, 1, 0, 1]
[1, 0, 0, 0, 0, 1, 1, 0, 0, 1]
[1, 0, 1, 1, 1, 0, 0, 0, 0, 1]
[1, 0, 0, 0, 1, 0, 0, 0, 0, 1]
[1, 0, 1, 0, 0, 0, 1, 0, 0, 1]
[1, 0, 1, 1, 1, 0, 1, 1, 0, 1]
[1, 1, 0, 0, 0, 0, 0, 0, 终, 1]
[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
栈的方法：回溯法（深度优先搜索）
    思路：从一个节点开始，任意找到下一个能走的节点（上右下左），
         走不通就回来继续下一个节点。
         “使用栈储存当前路径：
            能走：进栈
            不能走：出栈“
'''
maze = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    [1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
    [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 1, 1, 0, 1],
    [1, 1, 0, 0, 0, 0, 0, 0, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
]
# print(maze[7][8])

def up(tup):
    li = list(tup)
    li[0] = li[0] - 1
    tup = tuple(li)
    return tup
def down(tup):
    li = list(tup)
    li[0] = li[0] + 1
    tup = tuple(li)
    return tup
def left(tup):
    li = list(tup)
    li[1] = li[1] - 1
    tup = tuple(li)
    return tup
def right(tup):
    li = list(tup)
    li[1] = li[1] + 1
    tup = tuple(li)
    return tup
'''
dirs=[
    lambda x,y:(x+1,y),       老师用四个隐藏函数，拼成四元素列表，遍历这个列表，就有了四个移动方向
    lambda x,y:(x-1,y),
    lambda x,y:(x,y+1),
    lambda x,y:(x,y-1),
]
'''
# n = (1, 1)
# n = up(n)
# print(n)

def maze_path(x1, y1, x2, y2):
    stack = []  # 先建一个栈
    start_position = (x1, y1)   # 找好初始位置
    stack.append(start_position)    # 把初始位置元组先填到空栈里
    maze[x1][y1] = 2  # 初始位置走过了标记为2
    while len(stack) > 0:  # 当stack没有被弹光时，我们继续循环。
        now_pos = stack[-1]  # 当前位置永远是栈顶，这样我们就不用担心当前位置不对了。


        '''走到终点怎么判断？'''
        if now_pos[0] == x2 and now_pos[1] == y2:
            print('走到了终点！')
            print('成功的路径为：', stack)
            break
        '''从break出来之后，新的循环开始了，我们又重新拿到了一个当前节点。只需判断当前节点是否是终点。'''


        for next_pos in [up(now_pos),down(now_pos),left(now_pos),right(now_pos)]:  # 遍历四个方向
            if maze[next_pos[0]][next_pos[1]] == 0:  # 表示下一位置能走过去
                stack.append(next_pos)               # 入栈 表示走过去
                maze[next_pos[0]][next_pos[1]] = 2   # 标记走到的位置，以免以后误以为还能走
                break
        else:  # 表示当前位置 没有可以走的路
            stack.pop()  # 退回一步


    else:  # stack弹光光 表示死迷宫。
        print('死迷宫!!!')
maze_path(1, 3 , 8, 8)
print(maze)

