def solution(n):
    answer = []

    def hanoi(num, start, end, via):
        if num == 1:
            answer.append([start, end])
            return

        hanoi(num - 1, start, via, end)
        answer.append([start, end])
        hanoi(num - 1, via, end, start)

    hanoi(n, 1, 3, 2)
    return answer