#include <torch/torch.h>
#include <torch/script.h>
#include <iostream>
#include <memory>

int main(int argc, const char* argv[]) {
	torch::jit::Module module;
	try {
		module = torch::jit::load("/home/kkm0411/PIM-Simulator/Zsim_PIM/app/BASIC/resnet_script/resnet.pt");
	}
	catch (const c10::Error& e) {
		std::cerr << "error loading the model\n";
		return -1;
	}

	std::vector<c10::IValue> inputs;
	inputs.push_back(torch::ones({1, 3, 224, 224}));
	auto output = module.forward(inputs);
	std::cout << output << std::endl;
}
