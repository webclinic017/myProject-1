'''
这是我自己的方法 老师的方法我还没学会 有空回去学习一下
这是我自己的方法 老师的方法我还没学会 有空回去学习一下
这是我自己的方法 老师的方法我还没学会 有空回去学习一下
这是我自己的方法 老师的方法我还没学会 有空回去学习一下
这是我自己的方法 老师的方法我还没学会 有空回去学习一下
'''

maze = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    [1, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    [1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 0, 0, 0, 1],
    [1, 0, 0, 0, 1, 0, 1, 0, 1, 1],
    [1, 0, 1, 0, 0, 0, 1, 0, 0, 1],
    [1, 0, 1, 1, 1, 0, 1, 1, 0, 1],
    [1, 1, 0, 0, 0, 0, 0, 1, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
]
from collections import deque

dirs =[
    lambda x, y :( x -1, y),
    lambda x, y :(x, y+ 1),
    lambda x, y: (x + 1, y),
    lambda x, y: (x, y - 1),
]


def maze_path(x1, y1, x2, y2):
    start_pos = (x1, y1)
    maze[x1][y1] = 2 # 起始位置先封死
    queue = deque([], 100)  # 空队列
    queue.append(start_pos)  # 第一位置进队列
    dict0 = {}   # 创建字典
    flag = True
    flag2 = '死迷宫'
    while flag:   # 满足条件退出 比break好 break只能跳出一层循环 这种能跳出指定循环
        if len(queue)==0:
            return flag2    # 当所有元素出队时 表示是死迷宫
        now_pos = queue[0]    # 只看队首 因为队首不满足就popleft掉了 每次的队首都是新队首
        for direct in dirs:  # 每个方向都看看能不能走
            next_pos = direct(now_pos[0], now_pos[1])    # 即将要走过去的地方位置
            if maze[next_pos[0]][next_pos[1]] == 0:       # 看看能不能走
                maze[next_pos[0]][next_pos[1]] = 2       # 如果能走 就走过去 然后封路
                dict0[next_pos] = now_pos               # 把新位置与老位置作为键和值存到字典中 方便以后查找
                queue.append(next_pos)                   # 新位置入队
                if next_pos[0] == x2 and next_pos[1] == y2:  # 如果走过去的新位置是终点
                    flag = False    # 就结束

        queue.popleft()   # 如果这个老位置没有新位置可以走 就出队

    list0 = [(x2, y2)]  # 从最后的目的地开始往回走
    while list0[-1][0] != x1 or list0[-1][0] != y1:   # 当走到起点时退出循环
        temp = dict0[list0[-1]]  # 在字典中查找新位置对应的老位置
        list0.append(temp)    # 把老位置加到列表中
    list0.reverse()  # 倒转列表
    return list0







print(maze_path(1, 1, 8, 8))


