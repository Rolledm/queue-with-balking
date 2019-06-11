import matplotlib.pyplot as plt
import numpy as np

file = open("output/arrive_time.txt", "rt")

line = file.readline()

spl = line.split(" ")
l = []
for i in spl[:-1]:
    print(len(i))
    print(i)
    l.append(float(i))

numpyArray = np.array(l)


x = np.array(range(0,100))

plt.scatter(x, numpyArray, s=1)
plt.show()