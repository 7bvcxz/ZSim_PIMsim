#include <torch/torch.h>
#include <torch/script.h>
#include <iostream>
#include <memory>

int main(int argc, const char* argv[]) {
	torch::jit::Module module;
	try {
		module = torch::jit::load("/home/kkm0411/PIM-Simulator/Zsim_PIM/app/BASIC/rnn_script/rnn.pt");
	}
	catch (const c10::Error& e) {
		std::cerr << "error loading the model\n";
		return -1;
	}
	
	auto input = torch::rand({1, 3, 224, 224});
	auto output = module.forward({input});
	std::cout << output << std::endl;
}
