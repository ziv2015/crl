// crl_test.cpp : Defines the entry point for the console application.
//

#include <crl/crl.h>
#include <iostream>

int main() {
	crl::queue testQueue;
	for (auto i = 0; i != 1000; ++i) {
		testQueue.async([i] { std::cout << "Hi from serial queue: " << i << std::endl; });
		if ((i % 100) == 99) {
			crl::async([i] { std::cout << "Hi from async: " << i << std::endl; });
			testQueue.sync([i] { std::cout << "Hi from queue sync: " << i << std::endl; });
		}
	}

	std::cout << "Hello, World!" << std::endl;
	int a = 0;
	std::cin >> a;
	return 0;
}
