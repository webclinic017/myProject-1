import pymysql
user = input('用户名: ').strip()
password = input('密码: ').strip()
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
cs = con.cursor()

# 执行sql 增/删/改
sql = 'insert into usbiao(user,password) values(%s,%s)'
rows = cs.execute(sql, (user, password))
# rows = cs.executemany(sql, [(user, password), (user, password), (user, password)])

# sql = 'delete from usbiao where user=%s -- %s'
# rows = cs.execute(sql, (user, password))

# sql = 'update usbiao set password=%s where user =%s'
# rows = cs.execute(sql, (password, user))

print(rows)

con.commit()  # 注意涉及数据变动的一定要 做一步提交
# 关闭游标
cs.close()
con.close()

