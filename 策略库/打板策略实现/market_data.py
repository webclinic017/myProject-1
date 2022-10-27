# -*- coding: gbk -*-
# 此段代码用了特殊的数据源，请替换为自己可以得到的行情数据
# 最好是3秒的tick数据，打板对数据的及时性有较高要求
'''
field_list = [
    'time',
    'last',
    'open',
    'high',
    'low',
    'close',
    'preclose',
    'limit_down',
    'limit_up',
    'askprice5',
    'askprice4',
    'askprice3',
    'askprice2',
    'askprice1',
    'bidprice1',
    'bidprice2',
    'bidprice3',
    'bidprice4',
    'bidprice5',
    'askvolume5',
    'askvolume4',
    'askvolume3',
    'askvolume2',
    'askvolume1',
    'bidvolume1',
    'bidvolume2',
    'bidvolume3',
    'bidvolume4',
    'bidvolume5',
]

def get_market_quote(symbol_str):
    """
    获取指定symbol的（五档、三秒）行情报价
    :param symbol_str: like '002806.SZ,688234.SH,603927.SH,603650.SH,300522.SZ,600000.SH,000001.SZ,600759.SH'
    :return: pd.Dataframe
                e.g.
                                time    last    open  ...  bidvolume4  bidvolume5  isLimited
                002806.SZ  150000000   12.59   12.16  ...       45600       18200          0
                688234.SH  150845000  129.25  125.90  ...         200         200          1
                603927.SH  150509000   26.43   26.44  ...        5100         400          0
                603650.SH  150503000   33.01   31.00  ...       21300        2680          1
                300522.SZ  150003000   11.23   11.05  ...         800        8400          0
                600000.SH  150530000    6.84    6.88  ...      679727      291100          0
                000001.SZ  150000000   10.65   10.70  ...      592109     1100800          0
                600759.SH  150506000    2.26    2.29  ...      368500      127300          0
    """
    df, msg = dapi.quote(symbol=symbol_str, fields=', '.join(field_list))
    df = df[field_list]  # 按field_list排序
    df['isLimited'] = 0
    df.loc[(abs(df['limit_up'] - df['last']) <= 0.0001), 'isLimited'] = 1  # 标记此刻涨停股票
    return df

if __name__ == "__main__":
    with open("symbols.txt") as f:
        symbol_str = f.readline()
    print(symbol_str)
    market_data = get_market_quote(symbol_str)
'''