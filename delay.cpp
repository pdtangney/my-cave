#include "delay.h"
#include <chrono>
#include <thread>
#include <limits>
#include <string>
#include <iostream>


namespace Delay
{
	void ignoreInput() {
		std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.putback('\n');
	}

	void pressKey(std::string prompt) {
		do {
			std::cout << '\n' << prompt;
			ignoreInput();
		} while(std::cin.get() != '\n');
	}

	void sleep(int time) {
		std::this_thread::sleep_for(std::chrono::seconds(time));
	}
}
