lines = []
max_len = 0
for _ in range(5):
    line = input()
    lines.append(line)
    max_len = max(max_len, len(line))

for i in range(max_len) :
    for j in range(5) :
        if len(lines[j]) - 1 < i :
            continue
        print(lines[j][i], end="")

