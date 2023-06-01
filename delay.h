#ifndef DELAYS_V01_H
#define	DELAYS_V01_H

#include <chrono>
#include <thread>
#include <string>
#include <iostream>

namespace Delay
{
	void pressKey(std::string prompt);
	void sleep(int time);
}
#endif
