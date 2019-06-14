import matplotlib.pyplot as plt
import numpy as np
import os

#os.system("build/queue")

file = open("output/queue_size.txt")

line = file.readline()

spl = line.split(" ")
size = []
time = []
for i in spl[:-2]:
    temp = i.split(":")
    time.append(float(temp[0]))
    size.append(int(temp[1]))

size = np.array(size)
time = np.array(time)

plt.plot(time, size)
plt.title("Customers in the system")
plt.xlabel("Time, minutes")
plt.ylabel("Customers, number")
plt.show()

sum = 0
for i in size:
    sum += i

L = sum / len(size)

sum = 0
for i in size:
    if i != 0:
        sum += i - 1
Lq = sum/len(size)

sum = 0
for i in size:
    if i != 0:
        sum += 1
ro = sum/len(size)

l = spl[-1].split(":")
A = float(l[0])/float(l[1])

w = float(l[2])/float(l[0])

wq = float(l[3])/float(l[0])


print("Mean count of working canals: ")
print(round(ro, 3))

print("Relax time: ")
print(round((1 - ro), 3))

print("Absolute bandwidth:")
print(round(A, 3))

print("Mean count of customers in the system: ")
print(round(L, 3))

print("Mean count of customers in the queue: ")
print(round(Lq, 3))

print("Time in system:")
print(round(w, 3))

print("Time in queue:")
print(round(wq, 3))


file = open("output/arrive_time.txt", "rt")

line = file.readline()

spl = line.split(" ")
l = []
for i in spl[:-1]:
    l.append(float(i))

numpyArray = np.array(l)

x = np.array(range(0,len(numpyArray)))

plt.title("Time before arrival of customer")
plt.xlabel("Number of customer")
plt.ylabel("Time before arrival, minutes")
plt.scatter(x, numpyArray, s=1)
plt.show()



file = open("output/serve_time.txt", "rt")

line = file.readline()

spl = line.split(" ")
l = []
for i in spl[:-1]:
    l.append(float(i))

numpyArray = np.array(l)

x = np.array(range(0,len(numpyArray)))

plt.title("Time to serve customer")
plt.xlabel("Number of customer")
plt.ylabel("Time to serve, minutes")
plt.scatter(x, numpyArray, s=1)
plt.show()