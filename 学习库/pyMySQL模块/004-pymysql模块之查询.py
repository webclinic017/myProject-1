import pymysql

# 建立链接
con = pymysql.connect(
    host='192.168.1.77',
    port=3306,
    user='fsw',
    password='123',
    db='db1',
    charset='utf8'
)
# 拿到游标
cs = con.cursor()                               # 普通方式打印游标
cs = con.cursor(pymysql.cursors.DictCursor)   # 用字典的方式打印游标

# 执行sql 增/删/改
sql = 'select * from usbiao'
rows = cs.execute(sql)

for i in range(rows):
    print(cs.fetchone())
print('-------------------------------或者---------------------------------------')

cs.scroll(0, mode='absolute')  # 绝对位置移动 从头开始数 第0个位置
print(cs.fetchmany(rows))  # 打印rows条
print('-------------------------------或者---------------------------------------')

cs.scroll(-rows, mode='relative')  # 相对当前位置移动 从当前位置 移动-rows个位置 刚好归零
print(cs.fetchall())  # 打印所有



# 关闭游标
cs.close()
con.close()

