def hanota(n, a, b, c):
    if n > 0:
        hanota(n - 1, a, c, b)
        print('moving from %s to %s' % (a, c))
        hanota(n - 1, b, a, c)

hanota(5, '一', '二', '三')