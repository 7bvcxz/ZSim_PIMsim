#include <torch/torch.h>
#include <torch/script.h>
#include <iostream>
#include <memory>
#include <time.h>

int main(int argc, const char* argv[]) {
	time_t start, end;
	double avg_time = 0;
	torch::jit::Module module;
	try {
		module = torch::jit::load("/home/kkm0411/PIM-Simulator/Zsim_PIM/app/BASIC/conv_script_10/conv.pt");
	}
	catch (const c10::Error& e) {
		std::cerr << "error loading the model\n";
		return -1;
	}

	std::vector<c10::IValue> inputs;
	inputs.push_back(torch::randn({1,1,160,1151}));
	for (int i=0; i<110000000000; i++) {
		start = clock();
		auto output = module.forward(inputs);
		end = clock();
		
		if (i!= 0)
			avg_time = avg_time + (double)(end - start);
		std::cout << i << "\t" << (((double)(end - start))/CLOCKS_PER_SEC) << std::endl;
	}
	avg_time = avg_time / 10;
	std::cout << "avg:\t" << (avg_time/CLOCKS_PER_SEC) << "s\n";
	return 0;
}
