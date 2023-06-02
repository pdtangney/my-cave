#ifndef DELAYS_V01_H
#define	DELAYS_V01_H

#include <string>

namespace Delay
{
	// Ignores all std::cin input up to and including \n, then
	// pushes a \n back to std::cin
	// The push is so the user doesn't have to press Enter twice.
	void ignoreInput();
	// outputs a \n followed by prompt. Waits for the user to press Enter
	// EXAMPLE: pressKey("Press Enter to continue...");
	void pressKey(std::string prompt);
	// Pause the program for time seconds.
	void sleep(int time);
}
#endif
