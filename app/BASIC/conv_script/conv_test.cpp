#include <torch/torch.h>
#include <torch/script.h>
#include <iostream>
#include <memory>
#include <time.h>

int main(int argc, const char* argv[]) {
	time_t start, end;
    double result;
 
	torch::jit::Module module;
	try {
		module = torch::jit::load("/home/kkm0411/PIM-Simulator/Zsim_PIM/app/BASIC/conv_script/conv.pt");
	}
	catch (const c10::Error& e) {
		std::cerr << "error loading the model\n";
		return -1;
	}

	std::vector<c10::IValue> inputs;

	inputs.push_back(torch::randn({1,1,160,1151}));
	start = clock();
	auto output = module.forward(inputs);
	end = clock();
	result = (double)(end - start);
	std::cout.precision(6);
	std::cout << "time taken: " << (result/CLOCKS_PER_SEC) << "s\n";
}
