CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++11 -Wno-sign-compare -Wno-comment

# Compile the main executable
main.exe: main.cpp game.cpp nba.cpp team.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump

# game: main.o nba.o game.o team.o
# 	g++ main.o nba.o game.o team.o -o game
# main.o: main.cpp
# 	g++ -c main.cpp
# nba.o: nba.cpp
# 	g++ -c nba.cpp
# game.o: game.cpp
# 	g++ -c game.cpp
# team.o: team.cpp
# 	g++ -c team.cpp
# # Remove automatically generated files
# clean :
# 	rm *.o game