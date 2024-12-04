import sys

if __name__ == '__main__':
    inputs = sys.stdin.readline().strip()

    stack = []
    cnt = 0
    prev = None
    
    for i in inputs:
        if i == '(':
            stack.append(i)
        
        else:
            if len(stack):
                if prev == '(': # razer
                    del stack[-1]
                    
                    cnt+=len(stack) 

                else: # end of bar
                    del stack[-1]

                    cnt+=1
        prev = i
    print(cnt)