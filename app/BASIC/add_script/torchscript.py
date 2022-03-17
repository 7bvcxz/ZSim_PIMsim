import torch

@torch.jit.script
def add(x, y):
    return x + y

add_script = torch.jit.trace(add, (torch.rand(3), torch.rand(3)))
print(add_script)
print(add_script(torch.rand(2,2),torch.rand(2,2)))
add_script.save('add.pt')
