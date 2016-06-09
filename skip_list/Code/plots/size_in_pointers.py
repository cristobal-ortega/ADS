#!/usr/bin/python
from matplotlib import pyplot as plt
import numpy as np
from itertools import cycle
cycol = cycle('bgrcmk').next
plt.style.use('ggplot')

# evenly sampled time at 200ms intervals
p0 = [1001,2001,3001,4001,5001,6001,7001,8001,9001,10001]
p1 = [1106.2,2214.9,3325.8,4455.9,5561.8,6656.7,7773,8892.1,10000.4,11114.6]
p2 = [1246.9,2497.2,3752.4,4995.3,6261.1,7525.4,8741.9,9991.3,11228.3,12467.4]
p3 = [1426.6,2855.9,4271.3,5717.1,7142.5,8567.8,9980.2,11443.4,12873.5,14307.4]
p4 = [1654.6,3331.2,4993.6,6645.9,8324.7,9960.9,11642.6,13381.3,15013.7,16650.4]
p5 = [1987.8,4011.8,5974.8,7991,9959.8,11966.9,13950.4,15986.6,18067,19963.3]
p6 = [2460.3,5002.6,7500.2,9973.6,12436.9,14971.3,17493.3,20029.7,22437.1,25017]
p7 = [3330.9,6610.6,10067.5,13266.6,16657.7,19789.1,23156.6,26443.5,29796.9,33270.3]
p8 = [4904.9,9745.5,14665,19395.3,24259.8,29148.9,34006.6,38959.5,43589.5,48577.2]
p9 = [8135.7,16361.9,24335.5,32474,40746.3,49046.9,56939.6,65260.1,73314.5,81773.1]
p10 = [16000,32000,48000,64000,80000,96000,112000,128000,144000,160000]
pTeorical = [1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]


n = ['1000','2000','3000','4000','5000','6000','7000','8000','9000','10000']
p = ['0','0.1','0.2','0.3','0.4','0.5','0.6','0.7','0.8','0.9','1']

# red dashes, blue squares and green triangles
plt.xticks(range(len(n)),n)
plt.plot(p0, c=cycol(),label="p = 0")
plt.plot(p1, c=cycol(),label="p = 0.1")
plt.plot(p2, c=cycol(),label="p = 0.2")
plt.plot(p3, c=cycol(),label="p = 0.3")
plt.plot(p4, c=cycol(),label="p = 0.4")
plt.plot(p5, c=cycol(),label="p = 0.5")
plt.plot(p6, c=cycol(),label="p = 0.6")
plt.plot(p7, c=cycol(),label="p = 0.7")
# plt.plot(p8, c=cycol(),label="p = 0.8")
# plt.plot(p9, c=cycol(),label="p = 0.9")
# plt.plot(p10, c=cycol(),label="p = 1")
plt.plot(pTeorical, c=cycol(),label="n",linewidth=2,marker='*')
plt.yscale('log')

plt.xlabel("Size of the generated skip list")
plt.ylabel("Number of pointers in use\nLogarithmic scale")
plt.legend(loc=2,fontsize=10)
# plt.show()
plt.savefig('pointers_teorical.png')

