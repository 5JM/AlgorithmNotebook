import sys
from queue import Queue

'''
    queue를 list로 구현했을 때,
    양 끝 값을 제거하면 다른 값을을 한칸씩 이동시켜야함으로
    O(N)의 시간복잡도가 걸림.
'''
if __name__ == '__main__':
    N = int(sys.stdin.readline().strip())
    
    cards = Queue()

    for i in range(1, N+1):
        cards.put(i)

    while cards.qsize() > 1:
        cards.get()

        tmp = cards.get()
        cards.put(tmp)

    print(cards.get())