import random


def swap(l, c):
    l[0], l[1] = l[1], l[0]
    print('s%c' % c)

def push(l1, l2, c):
    l2.insert(0, l1[0])
    l1.pop(0)
    print('p%c' % c)

def rotate(l, c):
    a = l.pop(0)
    l.append(a)
    print('r%c' % c)

def d_rotate(l, c):
    a = l.pop(len(l) - 1)
    l.insert(0, a)
    print('rr%c' % c)

def main():
    la = random.sample(range(4), 4)
    lb = []
    la_sorted = sorted(la)



if __name__ == '__main__':
    main()