import sys

n = int(sys.stdin.readline())

for _ in range(n):
    left = []
    right = []
    line = sys.stdin.readline().strip()
    
    for ch in line:
        if ch == '<':
            if left:
                right.append(left.pop())
        elif ch == '>':
            if right:
                left.append(right.pop())
        elif ch == '-':
            if left:
                left.pop()
        else:
            left.append(ch)

    print("".join(left + right[::-1]))
