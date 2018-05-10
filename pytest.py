import random
import time


def d_swap(l1, l2):
    l1[0], l1[1] = l1[1], l1[0]
    l2[0], l2[1] = l2[1], l2[0]
    # print('ss')


def swap(l, c):
    l[0], l[1] = l[1], l[0]
    # print('s%c' % c)


def push(l1, l2, c):
    l2.insert(0, l1[0])
    l1.pop(0)
    # print('p%c' % c)


def rotate(l, c):
    a = l.pop(0)
    l.append(a)
    # print('r%c' % c)


def d_rotate(l, c):
    a = l.pop(len(l) - 1)
    l.insert(0, a)
    # print('rr%c' % c)


def is_sorted(l):
    l_sorted = sorted(l)
    return True if l is l_sorted else False


def is_rev_sorted(l):
    l_rev_sorted = sorted(l).reverse()
    return True if l is l_rev_sorted else False


def main():
    LIST_SIZE = 5
    MAX_OP = int(LIST_SIZE * 2 + (LIST_SIZE / 2))
    e_la = random.sample(range(LIST_SIZE), LIST_SIZE)
    lb = []
    la_sorted = sorted(e_la)

    print('List to sort = %s' % e_la)
    tests = []
    for i in range(100000):
        tests.append([int(7 * random.random()) for i in range(MAX_OP)])

    sol = []

    for test in tests:
        l1, l2 = e_la[:], []
        for op_index, op in enumerate(test):
            if l1 == la_sorted:
                sol.append(test[0:op_index])
                break
            try:
                if op is 0:
                    push(l1, l2, 'a')
                elif op is 1:
                    push(l2, l1, 'b')
                elif op is 2:
                    swap(l1, 'a')
                elif op is 3:
                    swap(l2, 'b')
                elif op is 4:
                    d_swap(l1, l2)
                elif op is 5:
                    rotate(l1, 'a')
                elif op is 6:
                    rotate(l2, 'b')
                elif op is 7:
                    d_rotate(l1, 'a')
                elif op is 8:
                    d_rotate(l2, 'b')
            except:
                break

    print('Found %d solutions.' % len(sol))
    if not len(sol):
        return
    best_sol = min(sol, key=len)
    print('Best solution has %d moves.' % (len(best_sol)))

    ops = {0: 'pa',
           1: 'pb',
           2: 'sa',
           3: 'sb',
           4: 'ss',
           5: 'ra',
           6: 'rb',
           7: 'rra',
           8: 'rrb'}

    for op in best_sol:
        print(ops[op])


    # while la is not la_sorted:
    #     if not is_sorted(la) and not is_rev_sorted(la):
    #         if len(la) >= 2 and len(lb) >= 2 and la[0] > la[1] and lb[0] > lb[1]:
    #             d_swap(la, lb)
    #         elif len(la) > 2 and la[0] > la[1]:
    #             swap(la, 'a')
    #         elif len(lb) > 2 and lb[0] > lb[1]:
    #             swap(lb, 'b')
    #         elif la:
    #             print('2')
    #             if not lb or la[0] > lb[0]:
    #                 push(la, lb, 'b')
    #             else:
    #                 rotate(lb, 'b')
    #     elif lb:
    #         push(lb, la, 'a')
    #     else:
    #         rotate(la, 'a')
    #     print(la, lb)
    #     time.sleep(1)



if __name__ == '__main__':
    main()