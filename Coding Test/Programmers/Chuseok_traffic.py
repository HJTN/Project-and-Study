# 추석 트래픽 (Feat. Programmers)
from concurrent.futures import process
from tabnanny import process_tokens
from time import time


def solution(lines):
    answer = []
    time_list = {}
    for idx, line in enumerate(lines):
        first, second, third = line.split()
        _, _, day = first.split('-')
        hour, minute, sec = second.split(':')
        processing = third.strip('s')
        time_list[idx] = {}
        if float(sec) - float(processing) >= 0:
            time_list[idx]['start'] = dict([('day',int(day)),('hour',int(hour)),('minute',int(minute)),('sec',round(float(sec)-float(processing)+0.001,3))])
        elif int(minute) - 1 >= 0:
            time_list[idx]['start'] = dict([('day',int(day)),('hour',int(hour)),('minute',int(minute)-1),('sec',round(float(sec)-float(processing)+0.001+60,3))])
        elif int(hour) - 1 >= 0:
            time_list[idx]['start'] = dict([('day',int(day)),('hour',int(hour)-1),('minute',int(minute)-1+60),('sec',round(float(sec)-float(processing)+0.001+60,3))])
        elif int(day) - 1 >= 0:
            time_list[idx]['start'] = dict([('day',int(day)-1),('hour',int(hour)-1+24),('minute',int(minute)-1+60),('sec',round(float(sec)-float(processing)+0.001+60,3))])
        time_list[idx]['end'] = dict([('day',int(day)),('hour',int(hour)),('minute',int(minute)),('sec',float(sec))])
        print(time_list[idx])
    return answer

if __name__=='__main__':
    lines = [
    "2016-09-15 20:59:57.421 0.351s",
    "2016-09-15 20:59:58.233 1.181s",
    "2016-09-15 20:59:58.299 0.8s",
    "2016-09-15 20:59:58.688 1.041s",
    "2016-09-15 20:59:59.591 1.412s",
    "2016-09-15 21:00:00.464 1.466s",
    "2016-09-15 21:00:00.741 1.581s",
    "2016-09-15 21:00:00.748 2.31s",
    "2016-09-15 21:00:00.966 0.381s",
    "2016-09-15 21:00:02.066 2.62s"
    ]
    print(solution(lines))