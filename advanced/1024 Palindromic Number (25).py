
def isPalindromic(n):
    return str(n) == str(n)[::-1]

def main():
    n, k = list(int(i) for i in input().split())
    s, t = n, 0
    while t < k:
        if isPalindromic(s):
            break
        s = s + int(str(s)[::-1])
        t = t + 1
    print(s)
    print(t)

if __name__ == '__main__':
    main()
