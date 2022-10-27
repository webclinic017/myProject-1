import requests

HOST = '192.168.192.10'  # 服务端ip
PORT = 10086  # 服务端端口
# 买功能   "method": "buy"   "param": ["股票代码","价格","股数"]
params = {"method": "buy",
          "param": ["600000","6.13","100"]}

# 卖功能   "method": "sell"   "param": ["股票代码","价格","股数"]
params = {"method": "sell",
          "param": ["600000","7.61","100"]}

# 查看可撤单列表   "method": "withdraw"   "param": []
params = {"method": "withdraw",
          "param": []}

# 撤单    "method": "withdraw"   "param": ['订单编号']
params = {"method": "withdraw_query",
          "param": ['100859']}
          
# 查看可用资金
params = {"method": "unUsed_captical"}

# 查看当前持仓
params = {"method": "stock_hold"}

if __name__ == "__main__":
    res = requests.get(f"http://{HOST}:{PORT}", params=params)
    print(res.text)
