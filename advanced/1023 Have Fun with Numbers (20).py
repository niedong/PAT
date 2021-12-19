
def main():
    n, d = int(input()), dict()
    for i in range(10):
        d[i] = 0
    v = n
    while v != 0:
        d[v % 10] += 1
        v = v // 10
    n = n * 2
    v = n
    while v != 0:
        d[v % 10] -= 1
        if d[v % 10] < 0:
            return print('No'), print(n)
        v = v // 10
    for i in range(10):
        if d[i] != 0:
            return print('No'), print(n)
    print('Yes')
    print(n)

if __name__ == '__main__':
    main()
