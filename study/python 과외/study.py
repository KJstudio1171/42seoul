import turtle as t

j = 100
k = 0

for i in range(10):
    if k != 5:
        k += 1
    else:
        if j == 100:
            j = i
            print(j)
        else:
            print("wow")