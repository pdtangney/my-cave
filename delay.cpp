#include "delay.h"
#include <chrono>
#include <thread>
#include <climits>
#include <string>
#include <iostream>

namespace Delay
{
	void pressKey(std::string prompt) {
		do {

			std::cin.clear();
			std::cout << '\n' << prompt;
		} while(std::cin.get() != '\n');
		std::cin.clear();
	}

	void sleep(int time) {
		std::this_thread::sleep_for(std::chrono::seconds(time));
	}
}
