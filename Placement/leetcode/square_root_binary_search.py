def squareroot(num):
    start,end = 0,num
    ans = 0
    while(start<=end):
        mid =  (start+end)/2
        if mid*mid == num:
            ans = mid
            break
        if mid*mid<num:
            start = mid+1
            ans = mid
        else:
            end = mid-1
    return ans

print(squareroot(81))