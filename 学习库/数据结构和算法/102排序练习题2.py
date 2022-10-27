list01=[
    [1,3,5,7],
    [10,11,16,20],
    [23,30,34,50]
]

def find_if_exist(li,val):
    left=0
    right=len(li)-1

    while left<=right:
        mid=(left+right)//2
        if li[mid][0] <= val <= li[mid][len(li[mid])-1]:
            if val in li[mid]:
                return True
            else:
                break
        elif val > li[mid][len(li[mid])-1]:
            left=mid+1
        else:
            right=mid-1
    else:
        pass




def find_if_exist_teacher(li,val):
    w = len(li[0])
    h = len(li)
    left = 0
    right = w * h - 1
    while left<=right:
        mid=(left+right)//2
        i = mid // 4
        j = mid % 4
        if li[i][j]==val:
            return i,j
        elif li[i][j]>val:
            right=mid-1
        else:
            left=mid+1
    else:
        return False



v=22
print(find_if_exist(list01, v))
print(find_if_exist_teacher(list01,v))










