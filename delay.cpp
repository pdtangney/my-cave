#include "delay.h"
#include <chrono> 	// Needed for sleep()
#include <thread> 	// ^                ^
#include <limits> 	// Needed for ignoreInput()
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
