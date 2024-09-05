# Github：https://github.com/CurrenWong

# 导入库
import urllib.request
import bs4
import translator
import time
from bs4 import BeautifulSoup

def divTextProcess(div):
    """
    处理<div>标签中<p>的文本内容
    """
    strBuffer = ''
    # 遍历处理每个<p>标签
    for each in div.find_all("p"):
        for content in each.contents:
            # 如果不是第一个，加换行符
            if (strBuffer != ''):
                strBuffer += '\n\n'
            # 处理
            if (type(content) != bs4.element.Tag):
            # 如果是文本，添加至字符串buffer中
                strBuffer += content.replace("       ", " ").replace("$$$", "$")
            else:
            # 如果是html元素，如span等，加上粗体
                strBuffer += "**" + content.contents[0].replace("       ", " ").replace("$$$", "$") + "**" 
    # 返回结果
    return strBuffer

def catcher(problemSet, problemId):
    # 题目属性
    # problemSet = "1353"
    # problemId = "B"

    # 题目链接
    Url = f"https://codeforces.com/problemset/problem/{problemSet}/{problemId}"
    req = urllib.request.Request(url=Url, headers={'User-Agent': 'Mozilla/5.0 3578.98 Safari/537.36'})
    # 获取网页内容
    html = urllib.request.urlopen(req).read()
    # 格式化
    soup = BeautifulSoup(html,'lxml')
    # 存储
    data_dict = {}
    head = {'Input': '输入', 'Output': '输出', 'Title': '标题','Problem Description': '题目描述','Time Limit': '时限','Memory Limit': '空限','Source': '链接'}
    # 找到主体内容
    mainContent = soup.find_all(name="div", attrs={"class" :"problem-statement"})[0]
    # Limit
    # 找到题目标题、时间、和内存限制
    # Title
    data_dict['Title'] = f"CodeForces {problemSet} " + mainContent.find_all(name="div", attrs={"class":"title"})[0].contents[-1]
    # Time Limit
    data_dict['Time Limit'] = mainContent.find_all(name="div", attrs={"class":"time-limit"})[0].contents[-1]
    # Memory Limit
    data_dict['Memory Limit'] = mainContent.find_all(name="div", attrs={"class":"memory-limit"})[0].contents[-1]

    # 处理题目描述
    data_dict['Problem Description'] = divTextProcess(mainContent.find_all("div")[10])

    div = mainContent.find_all(name="div", attrs={"class":"input-specification"})[0]
    data_dict['Input'] = divTextProcess(div)

    div = mainContent.find_all(name="div", attrs={"class":"output-specification"})[0]
    data_dict['Output'] = divTextProcess(div)
    # print(data_dict)
    # exit()
    out = {}
    for each in data_dict.keys():
        out[each] = translator.trans(str(data_dict[each].replace("\n\n**", "**").replace("**\n\n", "**")))
        time.sleep(2)
    # print(out)
    with open("./output.md","w+",encoding="utf-8") as fout:
        for each in data_dict.keys():
            fout.write('### ' + head[each] + '\n')
            for line in out[each]:
                fout.write(line)
                fout.write('\n\n')
        fout.close()

catcher('1999', 'B')






