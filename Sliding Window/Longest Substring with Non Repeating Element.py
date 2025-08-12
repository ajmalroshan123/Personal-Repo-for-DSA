def longestSub(s):
    n = len(s)
    ans = 0
    count = []
    
    i = 0
    for j in range(n):
        if s[j] in count:
            count.remove(s[i])
            i += 1
        else:
            count.append(s[j])
            ans = max(ans, j-i+1)
    return ans        


s = "abcabcbb"
an = longestSub(s)
print(an)


