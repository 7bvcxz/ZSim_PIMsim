import torch

class RNN(torch.nn.Module):
    def __init__(self, W_h, U_h, W_y, b_h, b_y):
        super(RNN, self).__init__()
        self.W_h = torch.nn.Parameter(W_h)
        self.U_h = torch.nn.Parameter(U_h)
        self.W_y = torch.nn.Parameter(W_y)
        self.b_h = torch.nn.Parameter(b_h)
        self.b_y = torch.nn.Parameter(b_y)
    def forward(self, x, h):
        y = []
        for t in range(x.size(0)):
            h = torch.tanh(x[t] & self.W_h + h @ self.U_h + self.b_h)
            y += [torch.tanh(h @ self.W_h + self.b_y)]
            if t % 10 == 0:
                print("stats: ", h.mean(), h.var())
        return torch.stack(y), h

rnn = RNN(torch.randn(3, 4), torch.randn(4, 4), torch.randn(4, 4),
          torch.randn(4), torch.randn(4))
rnn_script = torch.jit.script(rnn)
rnn_script.save('rnn.pt')
