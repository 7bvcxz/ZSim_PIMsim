from torch import randn, set_num_threads, set_grad_enabled
from torch.nn import Conv2d
from hwcounter import count, count_end
import time
import os

print("import torch ended!")

if 0:
    num_thr = input("set thr: ")
    num_thr = int(num_thr)
else:
    num_thr = 8
print("num_threads: ", num_thr)

set_grad_enabled(False)
set_num_threads(num_thr)

conv = Conv2d(1,32,kernel_size=(41,11), stride=(2,2), padding=(20,5))

print("now, let's run")

avg_time = 0
avg_cycle = 0
start = 0
end = 0
for i in range(21):
    x = randn(1, 1, 160, 1151)
    #start = time.time()
    cpu_start = count()
    y = conv(x)
    cpu_end = count()
    #end = time.time()
    print(i, "\t%.6f\t%d" %(end-start, cpu_end-cpu_start))
    if (i!=0):
        #avg_time = avg_time + end - start
        avg_cycle = avg_cycle + cpu_end - cpu_start
#avg_time = avg_time / 20
avg_cycle = avg_cycle / 20
print("avg:\t%.6fs\t%d" %(avg_time, avg_cycle))
