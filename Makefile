files := maze.cpp delay.cpp
flags := -Wall -Wextra -pedantic-errors -Wsign-conversion
debug := -ggdb

maze_ready: 
	g++ $(files) $(flags) -o bin/maze
	
maze_db: 
	g++ $(files) $(flags) $(debug) -o bin/maze_db

rm_debug:
	rm maze_db
