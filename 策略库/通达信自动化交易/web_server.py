import socket
from trade_core import buy,sell,withdraw_query,withdraw,unUsed_captical,stock_hold

HOST = "192.168.192.10"  # ip地址
PORT = 10086  # 端口


def get_method_and_param(binary_data):
    """解析请求数据，获取请求的文件名"""
    data = binary_data.decode()
    lines = data.split("\n")
    url = lines[0].split()[1]
    key_string = url.split("?")[1]
    key_string_list = key_string.split("&")
    method = key_string_list[0].split("=")[-1]
    params = []
    for i in key_string_list[1:]:
        params.append(i.split("=")[-1])
    # print("method:",method)
    # print("param_list:", params)
    return method, params

def trading(method, params):
    if method == "buy":
        msg = buy(params[0],params[1],params[2])
    elif method == "sell":
        msg = sell(params[0],params[1],params[2])
    elif method == "withdraw_query":
        msg = withdraw_query()
        if type(msg) is not str:
            df = msg
            msg = ""
            for i in range(len(df)):
                msg = msg + df.iloc[i].to_string() + "\n\n==========================\n\n"
    elif method == "withdraw":
        msg = withdraw(params[0])
    elif method == "unUsed_captical":
        msg = unUsed_captical()
    elif method == "stock_hold":
        msg = stock_hold()
        if type(msg) is not str:
            df = msg
            msg = ""
            for i in range(len(df)):
                msg = msg + df.iloc[i].to_string() + "\n\n==========================\n\n"
    else:
        raise ValueError(f"method={method}错误 无此功能！")
    return msg





def get_response(msg):
    if msg:
        data = "HTTP/1.1 200 " + "\r\n\r\n" + str(msg)  # 构造文件存在时的响应数据
    else:
        data = "HTTP/1.1 404 \r\n\r\n404 Not Found"  # 构造404的响应数据
    return data.encode()


def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:  # AF_INET表示地址是用ipv4协议，SOCK_STREAM表示我们这是TCP连接
        s.bind((HOST, PORT))  # 这个socket绑定这个端口
        s.listen(1)  # 监听此端口，参数为1表示只接收1个连接，这里会阻塞

        conn, addr = s.accept()  # 如果接收到连接，获取这个连接对象和它的地址
        while conn:
            with conn:
                try:
                    print('Connected by', addr)
                    binary_data = conn.recv(1024)  # 接收数据，数据的最大值为1024bit
                    print(binary_data)  # 打印一下请求的数据

                    method, params = get_method_and_param(binary_data)
                    msg = trading(method, params)
                    response_data = get_response(msg)
                except Exception as e:
                    response_data = get_response(str(e))

                conn.sendall(response_data)  # 发送响应数据


            conn, addr = s.accept()


if __name__ == '__main__':
    main()