import pymysql

user = input('用户名: ').strip()
pwd = input('密码: ').strip()

con = pymysql.connect(
    host='192.168.1.77',
    port=3306,
    user='fsw',
    password='123',
    db='db1',
    charset='utf8'
)

# 拿到游标
cs = con.cursor()

# 为游标提交命令


# sql = 'select * from usbiao where user = "%s" and password = "%s"' % (user, pwd)
# print(sql)                                     改为以下方式

sql = 'select * from usbiao where user = %s and password = %s'
rows = cs.execute(sql, (user, pwd))
# 查到的结果 到游标里面去执行 得到几个rows


# 关闭游标和链接 回收系统资源
cs.close()
con.close()
if rows:
    print('yes')
else:
    print('no')
