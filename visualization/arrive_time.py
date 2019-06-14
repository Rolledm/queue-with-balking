import matplotlib.pyplot as plt
import numpy as np
import os

#os.system("build/queue")

"""file = open("output/arrive_time.txt", "rt")

line = file.readline()

spl = line.split(" ")
l = []
for i in spl[:-1]:
    print(len(i))
    print(i)
    l.append(float(i))

numpyArray = np.array(l)


x = np.array(range(0,10))

plt.scatter(x, numpyArray, s=1)
plt.show()"""

file = open("output/queue_size.txt")

line = file.readline()

spl = line.split(" ")
size = []
time = []
for i in spl[:-1]:
    temp = i.split(":")
    time.append(float(temp[0]))
    size.append(int(temp[1]))

#print(size)
#print(time)

size = np.array(size)
time = np.array(time)

plt.plot(time, size)
plt.show()

sum = 0
for i in size:
    sum += i
print(sum / len(size))