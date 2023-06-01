#include "maze.h"
#include "delay.h"
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

int randomizer(int choices) {
	//Return a random choice from 1 - choices
	std::random_device rd;
	std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
	std::mt19937 mt{ss};
	std::uniform_int_distribution<> distrib{1, choices};
	int choice = distrib(mt);
	return choice;
}

void ignoreLine() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayIntro(std::vector<int> doors) {
	std::cout << "\nYou are in a large room containing " << doors.size()
		<< " doors.\n"
		<< "You have to find your way out. Behind three of the\n"
		<< "doors lies a man-eating tiger. If you open the wrong\n"
		<< "door, you will be eaten on sight!"
		<< std::endl;
	Delay::pressKey("Press Enter to continue...");
}

int chooseDoor(std::vector<int> doors) {
	int door {0};
	while(std::find(doors.begin(), doors.end(), door) == doors.end()) {
		std::cout << "\nWhich door will you open? (1 - "
			<< doors.size() << ")> ";
		std::cin.clear();
		std::cin >> std::ws >> door;
		if(std::cin.fail()){
			std::cin.clear();
			ignoreLine();
		}
	}
	return door;
}

void checkDoor(int chosenDoor, std::vector<int>doors) {
	using namespace std;
	cout << "\nYou walk slowly to the door...\n";
	Delay::sleep(2);
	cout << "You put you ear to the door and listen...\n";
	Delay::sleep(2);
	cout << "You don't hear anything, so you cautiously turn the "
		"doorknob...\n";
	Delay::sleep(2);
	cout << "The door creaks open. You peer inside, when suddenly...\n";
	Delay::sleep(3);

	int friendlyDoor = randomizer(doors.size());

	if(chosenDoor == friendlyDoor)
		cout << "\nyour eye catches a glimmer of yellow light.\n"
			<< "You found the treasure! Congradulations!";
	else
		cout << "\nA tiger leaps at you and mauls you to death.\n"
			<< "You lost. RIP";
	std::cout << "\nDoor was: " << friendlyDoor;
}

bool newGame() {
	bool playAgain;
	std::cout << "\nWould you like to play again? (y/n)>";
	std::string input {0};
	std::cin.clear();
	std::getline(std::cin >> std::ws, input);
	if(input[0] == 'y' || input[0] == 'Y') 
		playAgain = true;
	else
		playAgain = false;
	return playAgain;
}

int main() {
	std::vector<int> doors = {1, 2, 3, 4};
	bool playAgain = true;
	while(playAgain) {
		displayIntro(doors);
		Delay::sleep(1);
		int chosenDoor = chooseDoor(doors);
		checkDoor(chosenDoor, doors);
		playAgain = newGame();
	}
	std::cout << "\nBye!";
	return 0;
}
