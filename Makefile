files := maze.cpp delay.cpp
flags := -Wall -Wextra -pedantic-errors -Wsign-conversion
debug := -ggdb

maze_ready: 
	g++ $(files) $(flags) -o maze
	
maze_db: 
	g++ $(files) $(flags) $(debug) -o maze_db

rm_debug:
	rm maze_db
