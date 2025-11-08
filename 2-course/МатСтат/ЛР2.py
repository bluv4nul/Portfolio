x_i = [5, 7, 9, 11, 13, 15]
x_avg = 8.3

s = 0

for x in x_i:
    s += (x-x_avg)**2

s/=60

print(s)