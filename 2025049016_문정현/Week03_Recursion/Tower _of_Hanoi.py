def solution(n):
    result = []
    
    def ToH(n, f, s, t):
        if n == 1:
            result.append([f, t])
            return
        
        ToH(n-1, f, t, s)
        result.append([f, t])
        ToH(n-1, s, f, t)
    
    ToH(n, 1, 2, 3)

    return result

n = int(input())
print(solution(n))