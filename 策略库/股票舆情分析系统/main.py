"""
Python 3.7
IDE:Pycharm
package
    re 2.2.1
    lxml 4.6.3
    requests 2.24.0
    aip 4.15.5
    matplotlib 3.2.1
"""
import requests
import matplotlib
import matplotlib.pyplot as plt
import pandas as pd
from lxml import etree
from aip import AipNlp
import time

# 获取url下的最大page数
def get_max_page(url):
    page_data = requests.get(url).content.decode("gbk")
    data_tree = etree.HTML(page_data)
    """
    if page_data.find("page_newslib"):
        max_page = data_tree.xpath("//*[@class=\"page_newslib\"]//a[last()-1]/text()")
        return int(max_page[0])
    else:
        return 1
    """
    return 1


# 解析指定页面的数据并保存至本地
def download_page(url, code):
    try:
        page_data = requests.get(url).content.decode("gbk")
        data_tree = etree.HTML(page_data)
        titles = data_tree.xpath("//*[@class = \"newlist\"]//li/span/a/text()")
        for title in titles:
            title = title + "\r\n"
            with open('./news/' + str(code) + ".txt", "a") as file:
                file.write(title)
                file.flush()
        return
    except:
        print("服务器超时")

# 解析每个页面的数据
def parse_pages(url, code):
    max_page = get_max_page(url)
    for i in range(1, max_page + 1):
        if i != 1:
            url = "http://stock.jrj.com.cn/share," + str(code) + ",ggxw_" + str(i) + ".shtml"
        download_page(url, code)


# 下载指定的股票的新闻数据
def download_news(codes):
    for code in codes:
        print(code)
        url = "http://stock.jrj.com.cn/share," + str(code) + ",ggxw.shtml"
        parse_pages(url, code)


# 对指定股票的所有新闻数据进行情感分析并进行统计
def analyze(code):
    APP_ID = '百度APP_ID'
    API_KEY = '百度API_KEY'
    SECRET_KEY = '百度SECRET_KEY'
    positive_nums = 0
    nagative_nums = 0
    count = 0
    aipNlp = AipNlp(APP_ID, API_KEY, SECRET_KEY)
    lines = open('./news/' + str(code) + ".txt").readlines()
    for line in lines:
        if not line.isspace():
            line = line.strip()
            try:
                time.sleep(0.5)
                result = aipNlp.sentimentClassify(line)
                print(result)
                positive_prob = result['items'][0]['positive_prob']
                nagative_prob = result['items'][0]['negative_prob']
                count += 1
                if positive_prob >= nagative_prob:
                    positive_nums += 1
                else:
                    nagative_nums += 1
            except:
                print(result['error_msg'])
    avg_positive = positive_nums / count
    avg_nagative = nagative_nums / count
    print('总数：', count, '消极次数', nagative_nums, '积极次数', positive_nums)
    print('股票代码：', code, '消极比例：', avg_nagative, '积极比例：', avg_positive)
    return {'股票代码':code, '消极比例':avg_nagative, '积极比例':avg_positive}


# 对指定的股票进行情感分析并保存到本地
def analyze_stocks(codes):
    df = pd.DataFrame()
    for code in codes:
        print(code)
        stock_dict = analyze(code)
        df = df.append(stock_dict, ignore_index=True)
    df.to_csv('./stocks.csv')

def show():
    matplotlib.rcParams['font.sans-serif'] = ['SimHei']
    matplotlib.rcParams['axes.unicode_minus'] = False
    df = pd.read_csv('./stocks.csv', index_col='股票代码', usecols=['股票代码', '消极比例','积极比例'])
    df.plot(kind='barh', figsize=(10, 8))
    plt.show()

if __name__ == "__main__":
    codes = ['600000','000001','600519', '603288']
    download_news(codes)
    analyze_stocks(codes)
    show()