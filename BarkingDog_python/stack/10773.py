import sys

if __name__ == '__main__':
    K = int(sys.stdin.readline().strip())
    num_list = []
    for _ in range(K):
        num = int(sys.stdin.readline().strip())

        if num == 0:
            if len(num_list) > 0:
                del num_list[-1]

            continue
        
        num_list.append(num)
    
    print(sum(num_list))