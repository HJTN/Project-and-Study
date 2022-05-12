# 신고 결과 받기 문제 (Feat. Programmers)
def solution(id_list, report, k):
    answer=[]
    id_dict = {}
    for idx, id in enumerate(id_list):
        id_dict[id] = {'id': idx,'report_num':0, 'report_user':[]}
        answer.append(0)
    print(id_dict)
    for re in report:
        user, target = re.split()
        if id_dict[user]['id'] not in id_dict[target]['report_user']:
            id_dict[target]['report_num'] += 1
            id_dict[target]['report_user'].append(id_dict[user]['id'])
    print(id_dict)
    for id in id_dict.keys():
        if id_dict[id]['report_num'] >= k:
            for user in id_dict[id]['report_user']:
                answer[user] += 1
    return answer

if __name__=="__main__":
    id_list = ['con','ryan']
    report = ['ryan con', 'ryan con', 'ryan con', 'ryan con']
    k = 3
    print(solution(id_list,report,k))