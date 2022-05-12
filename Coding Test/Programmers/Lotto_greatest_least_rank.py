# 로또의 최고 순위와 최저 순위 (Feat. Programmers)
def solution(lottos, win_nums):
    answer=[]
    rank = {6:1, 5:2, 4:3, 3:4, 2:5, 1:6, 0:6}
    total = 0
    # Greatest Case
    for num in lottos:
        if (num in win_nums) or num == 0:
            total += 1
    answer.append(rank[total])
    total = 0
    # Least Case
    for num in lottos:
        if num in win_nums:
            total += 1
    answer.append(rank[total])
    return answer

if __name__=="__main__":
    lottos = [45, 4, 35, 20, 3, 9]
    win_nums = [20, 9, 3, 45, 4, 35]
    print(solution(lottos, win_nums))