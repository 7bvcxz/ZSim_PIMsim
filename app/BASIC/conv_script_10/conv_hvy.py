from torch import randn, set_num_threads, set_grad_enabled
from torch.nn import Conv2d
import time

#num_thr = input("set thr: ")
#num_thr = int(num_thr)
num_thr = 8
print("num_threads: ", num_thr)

set_grad_enabled(False)
set_num_threads(num_thr)

conv = Conv2d(1,32,kernel_size=(41,11), stride=(2,2), padding=(20,5))

avg_time = 0
for i in range(21):
    x = randn(1, 1, 160, 1151)
    start = time.time()
    y = conv(x)
    end = time.time()
    print(i, "\t%.6f" %(end-start))
    if (i!=0):
        avg_time = avg_time + end - start
avg_time = avg_time / 20
print("avg:\t%.6fs" %avg_time)
