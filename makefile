all : make

make : main.cpp
	g++ -std=c++17 main.cpp parser.cpp -o bipartitionParser
