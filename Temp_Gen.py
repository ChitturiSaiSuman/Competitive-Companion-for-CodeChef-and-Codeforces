import random, sys

seed = int(sys.argv[1])
random.seed(seed)

tests = 1

print(tests)

for test in range(tests):
    N = random.randint(4, 5)
    s1 = ''.join([chr(random.randint(97, 99)) for i in range(N)])
    s2 = ''.join([chr(random.randint(97, 99)) for i in range(N)])
    print(s1, s2)
    q = random.randint(8, 10)
    print(q)
    for i in range(q):
        index = random.randint(0, N - 1)
        ch = chr(random.randint(97, 99))
        dest = list(s1)
        dest[index] = ch
        s1 = ''.join(dest)
        print(index, ch, s1)