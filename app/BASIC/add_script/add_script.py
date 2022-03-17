import torch
import time

add_script = torch.jit.load('add.pt')

print(add_script)
print(add_script(torch.rand(2,2), torch.rand(2,2)))
