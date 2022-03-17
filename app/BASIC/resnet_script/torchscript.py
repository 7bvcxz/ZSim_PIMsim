import torch
import torchvision

model = torchvision.models.resnet18()

example = torch.rand(1, 3, 224, 224)

resnet_script = torch.jit.trace(model, example)
resnet_script.save('resnet.pt')
