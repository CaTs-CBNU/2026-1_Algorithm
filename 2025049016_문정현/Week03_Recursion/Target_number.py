def solution(numbers, target):
    answer = 0
    
    def dfs(i, value):
        nonlocal answer
        
        if i == len(numbers):
            if value == 0:
                answer += 1
            return

        dfs(i+1, value + numbers[i])
        dfs(i+1, value - numbers[i])
        
    dfs(0, target)
    
    return answer

num = [1, 1, 1, 1, 1]
target = 3
print(solution(num, target))