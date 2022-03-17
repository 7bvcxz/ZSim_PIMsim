print('0'*30)
from torch import randn
from torch.nn import Conv2d
print('1'*30)
import time

print('2'*30)
#device = torch.device('cpu')

print('3'*30)
x = randn(1, 2, 1, 1)

print('4'*30)
conv = Conv2d(2,2,1)

print('5'*30)

start = time.time()
y = conv(x)
end = time.time()

print(end - start, "sec")
