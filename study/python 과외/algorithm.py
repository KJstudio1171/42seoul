n = 5
arr1 = [9,20,28,18,11]
arr2 = [30,1,21,17,28]

def solution(n, arr1, arr2):
    t = 0
    answer = [[' 'for i in range(n)]for j in range(n)]
    print(answer)
    for k in arr1:
        k = format(k,'b')
        p = 0
        for i in range(5-len(k)):
            p += 1

        for i in k:
            if i == '1':
                answer[t][p] = '#'
            p += 1
            if p == n:
                break
        t += 1
        if t == n:
            break
    t = 0
    for k in arr2:
        k = format(k,'b')
        p = 0
        for i in range(5-len(k)):
            p += 1
        for i in k:
            if i == '1':
                answer[t][p] = '#'
            p += 1
            if p == n:
                break
        t += 1
        if t == n:
            break
    for i in range(n):
        answer[i] = ''.join(answer[i])
    return answer
print(solution(n,arr1,arr2))