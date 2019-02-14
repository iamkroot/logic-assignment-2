from string import ascii_lowercase

import random
al = list(ascii_lowercase)
ops = ['~', 'V', '^', '>']
rules = {
    2: ['^i', '>e', 'MT'],
    1: ['^e1', '^e2', 'Vi1', 'Vi2'],
    0: ['P']
}


def valid1a(l=30):
    if random.uniform(0, 1) < 0.2 or l <= 0:
        return random.choice(al)
    s = ""
    s += '('
    op = random.choice(ops)
    if op != '~':
        a = ''
        while not a:
            a = random.choices(al + [valid1a(l - 1)], [1] * 26 + [400], k=1)

        # print(a)
        s += a[0]
    s += op
    a = ''
    while not a:
        a = random.choices(al + [valid1a(l - 1)], [1] * 26 + [104], k=1)
    # print(a)
    s += a[0]
    s += ')'
    return s


exp = valid1a()
print(exp)
a = 0
for i in exp:
    if i in ascii_lowercase:
        a += 1
print(a)