# -*- coding: gbk -*-
import pandas as pd

import time
import requests
from market_data import get_market_quote
from timer import timer
HOST = '192.168.192.10'  # 服务端ip
PORT = 10086  # 服务端端口

pd.set_option('display.max_rows', 1000)
pd.set_option('display.max_columns', 10000)




with open("symbols.txt") as f:
    symbol_str = f.readline()


df = pd.DataFrame(columns=symbol_str.split(','))

while True:
    if timer() is True:
        market_data = get_market_quote(symbol_str)
        time_str = time.strftime('%H%M%S', time.localtime())
        df.loc[time_str] = market_data['isLimited'].to_list()
        # df.to_csv('df.csv')
        # print(df)





        # 2.将涨停时刻标记为1，将炸板时刻标记为-1 得到df_tmp
        df_copy1 = df.copy()
        df_copy1 = df_copy1.shift(-1) - df_copy1
        df_copy1.replace(1, 0, inplace=True)
        df_copy1.fillna(value=0, inplace=True)

        df_copy2 = df.copy()
        df_copy2 = df_copy2 - df_copy2.shift()
        df_copy2.replace(-1, 0, inplace=True)
        df_copy2.fillna(value=0, inplace=True)

        df_tmp = df_copy1 + df_copy2
        # df_tmp.to_csv("df_tmp.csv")

        # 3.将涨停和炸板的时间依次记录到time_record_df中
        time_record_df = pd.DataFrame(
            # index='002806.SZ,688234.SH,603927.SH,603650.SH,300522.SZ,600000.SH,000001.SZ,600759.SH'.split(','),
            # columns=["Feng1_time","Zha1_time","Feng2_time","Zha2_time","Feng3_time","Zha3_time","Feng4_time","Zha4_time","Feng5_time","Zha5_time",
            #          "Feng6_time","Zha6_time","Feng7_time","Zha7_time","Feng8_time","Zha8_time","Feng9_time","Zha9_time","Feng10_time","Zha10_time"]
            columns=["Feng1", "Zha1", "Feng2", "Zha2", "Feng3", "Zha3", "Feng4", "Zha4", "Feng5", "Zha5",
                     "Feng6", "Zha6", "Feng7", "Zha7", "Feng8", "Zha8", "Feng9", "Zha9", "Feng10", "Zha10"])
        for symbol in df_tmp.columns:
            # display(df[i].to_dict())
            timestamp_list = []
            for key, value in df_tmp[symbol].to_dict().items():
                if value > 0.9999:
                    # print("涨停",key)
                    timestamp_list.append(int(key))
                elif value < -0.9999:
                    # print("炸板",key)
                    timestamp_list.append(int(key))
            if len(timestamp_list) > 20:
                timestamp_list = timestamp_list[0:20]
            while len(timestamp_list) < 20:
                timestamp_list.append(0)
            # print(symbol)
            # print(timestamp_list)
            time_record_df.loc[symbol] = timestamp_list
        # time_record_df.to_csv("time_record_df.csv")

        # 4. =============== 策略下单条件 ===============
        order_df = time_record_df.copy()
        # 条件1：
        order_df = order_df.loc[order_df.Feng1 > 93000]

        # 条件2：
        order_df = order_df.loc[order_df.Zha1 - order_df.Feng1 >= 1500]

        # 条件3：
        now = int(time_str)
        order_df = order_df.loc[abs(now - order_df.Feng2) < 0.0001]
        order_df = order_df.loc[order_df.Feng2 - order_df.Zha1 >= 1500]

        # 条件4：

        # 5.执行下单
        trade_symbol_list = order_df.index.values.tolist()
        trade_dict = market_data.loc[trade_symbol_list, 'limit_up'].to_dict()
        # print(trade_dict)
        if trade_dict:
            for symbol, limit_price in trade_dict.items():
                code = symbol.split(".")[0]
                print("\ncode:", code, "price", limit_price)
                params = {"method": "buy", "param": [code, "%s" % limit_price, "100"]}
                res = requests.get(f"http://{HOST}:{PORT}", params=params)
                # print(res)
                print(res.text)

        # time.sleep(1)