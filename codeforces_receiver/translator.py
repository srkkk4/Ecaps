
#百度通用翻译API,不包含词典、tts语音合成等资源，如有相关需求请联系translate_api@baidu.com
# coding=utf-8
 
import http.client
import hashlib
import urllib
import random
import json
# from pip._vendor.distlib.compat import raw_input

# 百度appid和密钥需要通过注册百度【翻译开放平台】账号后获得
appid = '20240809002119938'        # 填写你的appid
secretKey = 'D4TpLXmAEEQdm9q7Cxjv'    # 填写你的密钥
 
httpClient = None
myUrl = '/api/trans/vip/translate'  # 通用翻译API HTTP地址
 
fromLang = 'auto'       # 原文语种
toLang = 'zh'           # 译文语种
salt = random.randint(32768, 65536)
# 手动录入翻译内容，q存放
def trans(inputs):
    # time.sleep(1)
    output = None
    q = inputs
    sign = appid + q + str(salt) + secretKey
    sign = hashlib.md5(sign.encode()).hexdigest()
    myurl = myUrl + '?appid=' + appid + '&q=' + urllib.parse.quote(q) + '&from=' + fromLang + \
            '&to=' + toLang + '&salt=' + str(salt) + '&sign=' + sign
    
    # 建立会话，返回结果
    try:
        httpClient = http.client.HTTPConnection('api.fanyi.baidu.com')
        httpClient.request('GET', myurl)
        # response是HTTPResponse对象
        response = httpClient.getresponse()
        result_all = response.read().decode("utf-8")
        result = json.loads(result_all)
    
        output = result['trans_result']
    
    except Exception as e:
        output = result['error_code']
    finally:
        if httpClient:
            httpClient.close()
    ret = []
    for each in output:
        ret.append(each['dst'])
    return ret
# 原文链接：https://blog.csdn.net/weixin_44259720/article/details/104648444

# qq = trans('apple\n\n banana')
# print(qq)
