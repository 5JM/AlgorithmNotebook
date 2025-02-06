def digit_sum_in_str(str):
    return sum([int(i) for i in str if i.isdigit()])

def serial_sort(serial_list):
    serial_list = sorted(serial_list, key = lambda x: [len(x), digit_sum_in_str(x), x])

    return serial_list

if __name__ == '__main__':
    N = int(input())

    arr = [input() for _ in range(N)]

    print(*serial_sort(arr), sep='\n')
