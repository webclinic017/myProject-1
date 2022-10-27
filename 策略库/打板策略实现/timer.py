# -*- coding: gbk -*-
import time

def timer():
    time_str = time.strftime('%H%M%S', time.localtime())
    HH = int(time_str[:2])
    MM = int(time_str[2:4])
    SS = int(time_str[4:])
    kaipan  = (9,  30, 00)
    zhongwu = (11, 30, 00)
    xiawu   = (13, 00, 00)
    shoupan = (15, 00, 00)

    second = HH * 3600 + MM * 60 + SS

    if (kaipan[0] * 3600 + kaipan[1] * 60 + kaipan[2] < second and second < zhongwu[0] * 3600 + zhongwu[1] * 60 + zhongwu[2]) or\
            (xiawu[0] * 3600 + xiawu[1] * 60 + xiawu[2] < second and second < shoupan[0] * 3600 + shoupan[1] * 60 + shoupan[2]):
        print("now is time ", time_str)
        return True
        # every_3_seconds = second % 3
        # if every_3_seconds == 0:
        #     print("now is time ", time_str)
        #     return True
        # else:
        #     # print(f"please wait for {every_3_seconds} seconds")
        #     return False
    else:
        # print(f"{time_str} not in trade time!")
        return False

if __name__ == "__main__":
    # while True:
    #     a = timer()
    #     if a is True:
    #         print("do something...")
    #         time.sleep(1)

    print((-3)%2)

