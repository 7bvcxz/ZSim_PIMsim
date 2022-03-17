import torch

class Conv(torch.nn.Module):
    def __init__(self):
        super(Conv, self).__init__()
        self.weight = torch.nn.Conv2d(1, 32, (41,11), (2,2), (20,5))

    def forward(self, input):
        output = self.weight(input)
        return output

example = torch.rand(1, 1, 160, 1151)
model = Conv()
conv_script = torch.jit.trace(model, example)
print(conv_script)
print(conv_script(torch.randn(1, 1, 160, 1151)))
conv_script.save('conv.pt')
