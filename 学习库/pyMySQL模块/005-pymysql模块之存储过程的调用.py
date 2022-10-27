import pymysql

# 建立链接
con = pymysql.connect(
    host='192.168.1.77',
    port=3306,
    user='fsw',
    password='123',
    db='db2',
    charset='utf8'
)
# 拿到游标
cs = con.cursor()  # 普通方式打印游标

# 调用 sql程式
print('----------------------------无参数“过程”调用----------------------------------')
cs.callproc('p1')  # 调用 procedure 过程
print(cs.fetchall())
print('----------------------------有参数“过程”调用----------------------------------')
cs.callproc('p2', (2, 4, 0))  # 相当于 @_p2_0=2 @_p2_1=4 @_p2_2=0
print(cs.fetchall())
print('----------------------------打印传出参数----------------------------------')
cs.execute('select @_p2_2')
print(cs.fetchone())

# 关闭游标
cs.close()
con.close()
