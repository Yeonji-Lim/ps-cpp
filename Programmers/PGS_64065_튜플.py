def solution(s):
    answer = []
    s = s.replace("{", "").replace("}", "")
    num = [int(n) for n in s.split(",")]
    counter = {}
    for value in num:
        if value in counter:
            counter[value] += 1
        else:
            counter[value] = 1
    counter = dict(sorted(counter.items(), key = lambda item: item[1], reverse = True))
    return list(counter.keys())