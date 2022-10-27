def compare_str(str1,str2):
    list1=list(str1)
    list2=list(str2)
    list1.sort()
    list2.sort()
    print(list1)
    print(list2)
    if list1==list2:
        return True
    else:
        return False
print(compare_str('abcdefsw','macbdsew'))


# # def compare_str2(str1,str2):
# str1='abcdefsw'
#     for i in str1:
#         if i is in str2:
#             pass
#         else:
#             return False
#             break
#