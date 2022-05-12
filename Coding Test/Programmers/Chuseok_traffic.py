# 추석 트래픽 (Feat. Programmers)

def solution(lines):
    answer = []
    time_list = dataProcessing(lines)
    day, hour, minute, second = findMin(time_list)
    
    return answer

def dataProcessing(lines):
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
    return time_list

def findMin(time_list):
    # Find Min Day
    day = time_list[0]['start']['day']
    for idx in time_list.keys():
        if day > time_list[idx]['start']['day']:
            day = time_list[idx]['start']['day']
    # Find Min Hour
    hour = time_list[0]['start']['hour']
    for idx in time_list.keys():
        if hour > time_list[idx]['start']['hour'] and day == time_list[idx]['start']['day']:
            hour = time_list[idx]['start']['hour']
    # Find Min Minute
    minute = time_list[0]['start']['minute']
    for idx in time_list.keys():
        if minute > time_list[idx]['start']['minute'] and hour == time_list[idx]['start']['hour'] and day == time_list[idx]['start']['day']:
            minute = time_list[idx]['start']['minute']
    # Find Min second
    second = time_list[0]['start']['sec']
    for idx in time_list.keys():
        if second > time_list[idx]['start']['sec'] and minute == time_list[idx]['start']['minute'] and hour == time_list[idx]['start']['hour'] and day == time_list[idx]['start']['day']:
            second = time_list[idx]['start']['sec']
    return day, hour, minute, second

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