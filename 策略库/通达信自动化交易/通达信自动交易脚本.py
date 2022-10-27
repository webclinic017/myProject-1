#!/usr/bin/env python
# coding: utf-8
import win32gui, win32con,win32api
import pyautogui
import time
import pandas as pd
import os
import re
import logging


# email发送错误信息
from email.mime.multipart import MIMEMultipart # 一封邮件
from email.mime.text import MIMEText # 邮件内容
from email.mime.image import MIMEImage # 图片
from email.mime.application import MIMEApplication # 附件
import smtplib # 发送功能
def send_email(text, subject = '无题', filepath='', to_list = ['12757205@qq.com'], cc_list = []):
    sender = "pyerrorsend@163.com"
    license_code = 'IESOZGAJEOAHRWHP'
    
    em = MIMEMultipart() # 一封邮件 （其实就是message.Message对象的一个子类）
    em['Subject'] = subject # 邮件主题
    em['From'] = sender # 发件人
    em['To'] = ','.join(to_list) # 发送对象
    em['Cc'] = ','.join(cc_list) # 抄送对象
    
    content = MIMEText(text) # 把普通文字转换为邮件正文
    em.attach(content) # 把邮件的正文丢给邮件的主体
    
    if filepath == '':
        pass
    else:
        app = MIMEApplication(open(filepath, mode='rb').read()) # 把文件读进来
        app.add_header("content-disposition", "attachment", filename="运行状况.gif") # 给文件重新命一个下载名
        em.attach(app)

    smtp = smtplib.SMTP() # 先创建一个SMTP对象
    smtp.connect('smtp.163.com') # 连上对应的服务器
    
    smtp.login(sender, license_code)
    
    smtp.send_message(em)
    
    smtp.close()


# 日志记录
logger = logging.getLogger(name='通达信交易终端') # 日志器
console_handler = logging.StreamHandler() # 控制台处理器
file_handler = logging.FileHandler('./log.txt', mode='a', encoding='utf-8') # 文本处理器
# 显示等级
logger.setLevel(level='INFO')
console_handler.setLevel(level='INFO')
file_handler.setLevel(level='INFO')
# 格式
console_fmt = '%(asctime)s --- %(message)s --- 来自函数：%(funcName)s'
file_fmt    = '%(asctime)s --- %(message)s --- 来自函数：%(funcName)s'
# 格式器
fmt1 = logging.Formatter(fmt=console_fmt)
fmt2 = logging.Formatter(fmt= file_fmt)
# 消息处理器中加入格式器
console_handler.setFormatter(fmt1)
file_handler.setFormatter(fmt2)
# 日志器中加入消息处理器
logger.addHandler(console_handler)
logger.addHandler(file_handler)

# logger.debug('这是debug信息')
# logger.info('这是info信息')
# logger.warning('这是warning信息')
# logger.error('这是error信息')
# logger.critical('这是critical信息')


# 用全屏的坐标点击
def click_screen(screen_x,screen_y): #输入为全屏的自由坐标。
    pos = (screen_x,screen_y)
    handle= win32gui.WindowFromPoint(pos) # 获取坐标所指的子窗口的handle
    # print('鼠标所指的子窗口的handle:',handle)
    client_pos =win32gui.ScreenToClient(handle,pos) # 获取全屏坐标在该子窗下的坐标
    tmp=win32api.MAKELONG(client_pos[0],client_pos[1]) # 鼠标后台移动到该子窗的该坐标
    win32gui.PostMessage(handle, win32con.WM_ACTIVATE,win32con.WA_ACTIVE,0) # 激活鼠标下的东西
    win32gui.PostMessage(handle, win32con.WM_LBUTTONDOWN,win32con.MK_LBUTTON,tmp) # 左键按下
    win32gui.PostMessage(handle, win32con.WM_LBUTTONUP,win32con.MK_LBUTTON,tmp) # 左键弹起


# 端内坐标转化为全屏坐标
def p(client_x,client_y):
    pos = win32gui.ClientToScreen(Handle, (client_x,client_y)) 
    return pos[0],pos[1]


# 用客户端内坐标点击
def click_it(client_x, client_y, click=True): #输入为金融客户端的端内坐标。
    pos = win32gui.ClientToScreen(Handle, (client_x,client_y)) # 端内坐标转化为全屏坐标
    handle= win32gui.WindowFromPoint(pos) # 获取全屏坐标所指的子窗口的handle
    # print('鼠标所指的子窗口的handle:',handle)
    if click==True:
        client_pos =win32gui.ScreenToClient(handle,pos) # 获取全屏坐标在该子窗下的坐标
        tmp=win32api.MAKELONG(client_pos[0],client_pos[1]) # 鼠标后台移动到该子窗的该坐标
        win32gui.PostMessage(handle, win32con.WM_ACTIVATE,win32con.WA_ACTIVE,0) # 激活鼠标下的东西
        win32gui.PostMessage(handle, win32con.WM_LBUTTONDOWN,win32con.MK_LBUTTON,tmp) # 左键按下
        win32gui.PostMessage(handle, win32con.WM_LBUTTONUP,win32con.MK_LBUTTON,tmp) # 左键弹起
        time.sleep(0.02)
    else:
        pass
    return handle


# 用客户端内坐标找handle
def get_it(client_x, client_y): #输入为金融客户端的端内坐标。
    pos = win32gui.ClientToScreen(Handle, (client_x,client_y)) # 端内坐标转化为全屏坐标
    handle= win32gui.WindowFromPoint(pos) # 获取全屏坐标所指的子窗口的handle
    # print('鼠标所指的子窗口的handle:',handle)


# 初始化
def initiallize(password='87148095'):
    global Handle
    Handle = win32gui.FindWindow('TdxW_MainFrame_Class', None) # 通达信模拟交易终端V8.09 - [行情报价-自选股]
    if Handle == 0:
        raise ValueError("找不到窗口句柄")
    if win32gui.IsIconic(Handle):
        # print('最小化了')
        win32gui.ShowWindow(Handle,win32con.SW_RESTORE)
        print('已恢复')
    else:
        # print('没最小化')
        pass
    win32gui.SetWindowPos(
        Handle, 
        win32con.HWND_TOPMOST, 
        0, 0, 640, 480, 
        win32con.SWP_SHOWWINDOW)
    
    # 判断是否上锁
    while True:
        anchor = pyautogui.locateOnScreen(
            'password_pic.png', 
            region=(340, 170, 375, 210),
            # confidence=0.9,  # 精度 需要安装openCV包
            grayscale=True     # 灰度 可提升找图速度
        ) 
        if anchor:
            a, b = pyautogui.position() # 保存鼠标的当前坐标
            pyautogui.doubleClick(183, 193) # 双击密码输入框
            pyautogui.typewrite(message=password, interval=0.08)
            time.sleep(0.08)
            pyautogui.press('enter')
            pyautogui.moveTo(x=a, y=b)
        else:
            break
            
    # 清理各种乱七八糟的弹窗
    for title in ['提示','买入交易确认','卖出交易确认','输出','请输入验证码']:          
        clear_handle = win32gui.FindWindow('#32770',title)
        if clear_handle!=0:
            win32gui.PostMessage(clear_handle, win32con.WM_CLOSE, 0, 0)
            
            if title == '请输入验证码': # 外挂检测窗口单独处理一下
                time.sleep(0.2)
                clear_handle = win32gui.FindWindow('#32770','提示')
                win32gui.PostMessage(clear_handle, win32con.WM_CLOSE, 0, 0)


# 寻找子窗口句柄函数
def find_brother_Handle(pHandle, winClass, index=0):
    """
    已知子窗口的窗体类名
    寻找第index号个同类型的兄弟窗口
    """
    assert type(index) == int and index >= 0
    handle = win32gui.FindWindowEx(pHandle, 0, winClass, None)
    while index > 0:
        handle = win32gui.FindWindowEx(pHandle, handle, winClass, None)
        index -= 1
    return handle


# 交易确认函数
def tips():
    Handle_tips = win32gui.FindWindow('#32770','提示')
    Handle_tips_message = find_brother_Handle(Handle_tips,'Static',1)
    Handle_tips_yes = find_brother_Handle(Handle_tips,'Button',0)
    # print('提示3句柄：',Handle_tips,Handle_tips_message,Handle_tips_yes)
    message = win32gui.GetWindowText(Handle_tips_message)
    if Handle_tips!=0 and Handle_tips_message!=0 and Handle_tips_yes!=0:
        win32gui.PostMessage(Handle_tips_yes, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(Handle_tips_yes, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(Handle_tips_yes, win32con.WM_LBUTTONUP, win32con.MK_LBUTTON, 0)
        return message
    else:
        return '提示窗口不存在'


def confirm(buyORsell='买入',operate_keyword = 'no'):
    Handle_confirm = win32gui.FindWindow('#32770',buyORsell+'交易确认')
    Handle_confirm_message = find_brother_Handle(Handle_confirm,'Static',1)
    Handle_confirm_yes = find_brother_Handle(Handle_confirm,'Button',0)
    Handle_confirm_no  = find_brother_Handle(Handle_confirm,'Button',1)
    # print(buyORsell+'确认4句柄：',Handle_confirm,Handle_confirm_message,Handle_confirm_yes,Handle_confirm_no)
    if operate_keyword == 'no':
        operate = Handle_confirm_no
    elif operate_keyword == 'yes':
        operate = Handle_confirm_yes
    elif operate_keyword == 'message':
        return '待补充message操作'
    else:
        return '输入操作码不对'
    
    if Handle_confirm!=0 and Handle_confirm_message!=0 and Handle_confirm_yes!=0 and Handle_confirm_no!=0:
        win32gui.PostMessage(operate, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(operate, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(operate, win32con.WM_LBUTTONUP, win32con.MK_LBUTTON, 0)
        time.sleep(0.5)
        contract_id = tips()
        return contract_id
    else:
        return buyORsell+'确认窗口不存在'


# 输出确认框
def output_confirm(path):
    Handle_withdraw = win32gui.FindWindow('#32770','输出')
    out_as_txt = find_brother_Handle(Handle_withdraw,'Button',0)
    out_as_txt_path = find_brother_Handle(Handle_withdraw,'Edit',0)
    out_yes = find_brother_Handle(Handle_withdraw,'Button',8)
    out_no = find_brother_Handle(Handle_withdraw,'Button',9)
    if Handle_withdraw!=0 and out_as_txt!=0 and out_as_txt_path!=0 and out_yes!=0 and out_no!=0:
        # 选择：输出到Excel表格button
        win32gui.PostMessage(out_as_txt, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(out_as_txt, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(out_as_txt, win32con.WM_LBUTTONUP, win32con.MK_LBUTTON, 0)
        time.sleep(0.1)
        # 填写路径
        win32api.SendMessage(out_as_txt_path, win32con.WM_SETTEXT, 0, path)
        time.sleep(0.1)
        # 点确认
        win32gui.PostMessage(out_yes, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(out_yes, win32con.WM_LBUTTONDOWN, win32con.MK_LBUTTON, 0)
        win32gui.PostMessage(out_yes, win32con.WM_LBUTTONUP, win32con.MK_LBUTTON, 0)
        time.sleep(0.1)
        return '文件已经输出'
    else:
        return '当前无法输出文件'
        


# 买入卖出鼠标操作函数
# 填入股票代码后可能由于网络不好而没来得及刷新
def buy(code,price,amount,t=0.05,max_try = 3):
    for times in range(max_try):
        initiallize()
        a, b = pyautogui.position() # 保存鼠标的当前坐标
        pyautogui.click(p(232, 41)) # 左击买
        pyautogui.moveTo(x=a, y=b)  # 鼠标返回原先位置
        pyautogui.typewrite(message=str(code), interval=t)
        time.sleep(t*10)
        h = click_it(321, 133, click=False) # 价格输入窗
        if len(str(price)) > 0:
            win32api.SendMessage(h, win32con.WM_SETTEXT, 0, str(price))
        time.sleep(t)
        h = click_it(317, 208, click=False) # 数量输入窗
        win32api.SendMessage(h, win32con.WM_SETTEXT, 0, str(amount))
        time.sleep(t)
        h = click_it(363, 233, click=True) # 下单按钮
        time.sleep(t*3)
        message=confirm('买入','yes')
        result=re.search('合同号是(.*?)$', message)

        if result:
            return result.group(1)
        else:
            logger.info(f'尝试第{times}次。|{message} ')
            time.sleep(1)
    else:
        # 发送邮件
        send_email(message,'买入错误')
        return message


def sell(code,price,amount,t=0.05,max_try = 3):
    for times in range(max_try):
        initiallize()
        a, b = pyautogui.position() # 保存鼠标的当前坐标
        pyautogui.click(p(264, 41)) # 左击卖
        time.sleep(t)
        pyautogui.moveTo(x=a, y=b)  # 鼠标返回原先位置
        time.sleep(0.6)
        pyautogui.typewrite(message=str(code), interval=t)
        time.sleep(t)
        h = click_it(300, 135, click=False) # 价格输入窗
        if len(str(price)) > 0:
            win32api.SendMessage(h, win32con.WM_SETTEXT, 0, str(price))
        time.sleep(t)
        h = click_it(293, 194, click=False) # 数量输入窗
        win32api.SendMessage(h, win32con.WM_SETTEXT, 0, str(amount))
        time.sleep(t)
        h = click_it(367, 217, click=True) # 下单按钮
        time.sleep(t*10)
        message=confirm('卖出','yes')
        result=re.search('合同号是(.*?)$', message)
        if result:
            return result.group(1)
        else:
            logger.info(f'尝试第{times}次。|{message} ')
            time.sleep(1)
    else:
        # 发送邮件
        send_email(message,'卖出错误')
        return message


# 查询可撤单列表
def withdraw_query(max_try=3):
    for times in range(max_try):
        initiallize()
        # a, b = pyautogui.position() # 保存鼠标的当前坐标
        click_it(296, 41) # 左击撤单
        time.sleep(0.2)
        click_it(705, 73) # 左击输出
        time.sleep(0.2)
        # pyautogui.moveTo(x=a, y=b)
        path = r'C:\Users\Administrator\Desktop\temporary.txt'

        message = output_confirm(path)
        if message == '当前无法输出文件':
            logger.info(f'尝试第{times}次。| {message}')
        else:
            df = pd.read_table(path, encoding='gbk',sep='\s+',skiprows=1)
            time.sleep(0.1)
            txt_handle = win32gui.FindWindow('Notepad', 'temporary.txt - 记事本')
            win32gui.PostMessage(txt_handle, win32con.WM_CLOSE, 0, 0)
            os.remove(path) # 删除临时txt文件
            time.sleep(0.1)
            return df


# 撤单函数
def withdraw(contract_id, max_try=3):
    for times in range(max_try):
        initiallize()
        # a, b = pyautogui.position() # 保存鼠标的当前坐标
        click_it(296, 41) # 左击撤单
        time.sleep(0.2)
        click_it(705, 73) # 左击输出
        time.sleep(0.2)
        # pyautogui.moveTo(x=a, y=b)
        path = r'C:\Users\Administrator\Desktop\temporary.txt'

        message = output_confirm(path)
        if message == '当前无法输出文件':
            logger.info(f'尝试第{times}次。| {message}')
        else:
            df=pd.read_table(path, encoding='gbk',sep='\s+',skiprows=1)
            nrows=df.shape[0] # 获取总行数

            time.sleep(0.1)
            txt_handle = win32gui.FindWindow('Notepad', 'temporary.txt - 记事本')
            win32gui.PostMessage(txt_handle, win32con.WM_CLOSE, 0, 0)
            os.remove(path) # 删除临时txt文件
            time.sleep(0.1)

            for i in range(0,nrows):
                cell = str(df.iloc[i,2]) # 把该列第i个单元格转化为字符串，目的是下一步的关键字比对
                if cell == contract_id: # 进行关键字比对，包含关键字返回1，否则返回0
                    pyautogui.doubleClick(435, 111+17*i)
                    time.sleep(0.25)
                    tips()
                    time.sleep(0.25)
                    message = tips()
                    time.sleep(0.25)
                    # message = '撤单成功'
                    return message
            else:
                message = '撤单列表里没有匹配的合同号'
                logger.info(f'尝试第{times}次。| {message}')
                time.sleep(1)
    else:
        # 发送邮件
        send_email(message,'撤单错误')
        return message


# 获取可用资金
# 买入标签卡中输入股票代码查询
def unUsed_captical(max_try=3):
    for times in range(max_try):
        try:
            t = 0.01
            initiallize()
            a, b = pyautogui.position() # 保存鼠标的当前坐标
            pyautogui.click(p(232, 41)) # 左击买
            pyautogui.moveTo(x=a, y=b)  # 鼠标返回原先位置
            pyautogui.typewrite(message='600002', interval=t)
            time.sleep(t*25)
            h = click_it(300, 153, click=False) # 可用资金窗
            money = win32gui.GetWindowText(h)
            if money:
                return float(money)
            else:
                logger.info(f'尝试第{times}次。| 获取不到可用资金')
                time.sleep(1)
        except Exception as e:
            logger.info(f'尝试第{times}次。| {e}')
    
    # 发送邮件
    send_email('获取不到可用资金','获取可用资金错误')


# 持仓
def stock_hold(max_try=3):
    for times in range(max_try):
        initiallize()
        click_it(361, 41) # 左击持仓
        time.sleep(1.5)
        click_it(704, 124) # 左击输出
        time.sleep(0.1)
        path = r'C:\Users\Administrator\Desktop\temporary.txt'
        message = output_confirm(path)
        time.sleep(0.1)
        if message == '当前无法输出文件':
            logger.info(f'尝试第{times}次。| {message}')
        else:
            time.sleep(0.1)
            txt_handle = win32gui.FindWindow('Notepad', 'temporary.txt - 记事本')
            time.sleep(0.1)
            win32gui.PostMessage(txt_handle, win32con.WM_CLOSE, 0, 0) # 关闭临时txt文件
            time.sleep(0.1)
            df = pd.read_table(path, encoding='gbk', sep='\s\s+',skiprows=2)
            time.sleep(0.1)
            os.remove(path) # 删除临时txt文件
            time.sleep(0.1)
            if pd.isnull(df.iloc[0,1]):
                return f'持仓：{df.iloc[0,0]}'
            else:
                return df
    # 发送邮件
    send_email(message,'获取持仓错误')