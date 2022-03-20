from queue import Queue


priorities = [9,1,9,1,1,1]
location = 1

def solution(priorities, location):
    answer = 0
    
    pri_queue = Queue()
    for pri in priorities:
        pri_queue.put(pri)

    while location != 0 or pri_queue.queue[location] < max(pri_queue.queue):
        pri = pri_queue.get()
        if pri < max(pri_queue.queue):
            pri_queue.put(pri)
        else:
            answer += 1
        
        if location == 0:
            location = pri_queue.qsize()-1
        else:
            location -= 1

    answer += 1
    
    return answer

result = solution(priorities, location)
print(result)