all : make

make : main.cpp
	g++ -std=c++17 main.cpp src/parser.cpp src/bipartitions.cpp -o bipartitionParser
