all : make

make : main.cpp
	g++ -std=c++11 main.cpp parser.cpp -o bipartitionParser
