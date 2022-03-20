progresses = [93, 30, 55]
speeds = [1, 30, 5]

def solution(progresses, speeds):
    answer = []

    start = 0
    deploy_num = 0
    while start < len(progresses):
        for idx in range(start, len(progresses)):
            if progresses[idx] < 100:
                progresses[idx] += speeds[idx]
        
        for idx in range(start, len(progresses)):
            if progresses[idx] >= 100:
                deploy_num += 1
                start += 1
            else:
                break
        if deploy_num:
            answer.append(deploy_num)
            deploy_num = 0

    return answer

result = solution(progresses, speeds)
print(result)