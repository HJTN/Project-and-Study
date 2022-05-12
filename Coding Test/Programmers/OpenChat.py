# 오픈채팅방 (Feat. Programmers)
def solution(record):
    answer = []
    user_dict = {}
    record_list = []
    for re in record:
        if len(re.split()) == 2:
            cmd, user_id = re.split()
        else:
            cmd, user_id, nick = re.split()
        if cmd == 'Enter':
            user_dict[user_id] = nick
        elif cmd == 'Change':
            user_dict[user_id] = nick
        record_list.append(' '.join([cmd, user_id]))
    #print(record_list)
    for li in record_list:
        cmd, user_id = li.split()
        if cmd == 'Enter':
            answer.append(f'{user_dict[user_id]}님이 들어왔습니다.')
        elif cmd == 'Leave':
            answer.append(f'{user_dict[user_id]}님이 나갔습니다.')
    return answer

if __name__=="__main__":
    record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    print(solution(record))