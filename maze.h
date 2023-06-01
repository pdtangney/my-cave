#ifndef MAZE_V001_H
#define MAZE_VOO1_H

#include "delay.h"
#include <random>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

int randomizer(int choices);
void displayIntro(std::vector<int> doors);
int chooseDoor(std::vector<int> doors);
void checkDoor(int chosenDoor, std::vector<int> doors);
bool newGame();

#endif
