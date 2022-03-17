import torch
import time

device = torch.device('cpu')

x = torch.ones(30)
y = torch.ones(30)

start = time.time()
z = x + y
end = time.time()

print(z)
print(end - start, "sec")
