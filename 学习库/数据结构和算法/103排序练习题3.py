list1=[1,2,5,4,3]
value=3
def sum_equal(li,val):
    x=0
    y=0
    count=0
    for a in range(0,len(li)):
        val1=li[a]
        for b in range(a+1,len(li)):
            val2=li[b]
            if val1+val2==val:
                count+=1
                x=a
                y=b
            else:
                pass
    if count==1:
        print(x,y)
    else:
        print('no')
sum_equal(list1,10)