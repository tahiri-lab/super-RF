all : make

make : main.cpp
	g++ -std=c++17 main.cpp src/parser.cpp src/bipartitions.cpp tests/unitTests.cpp -o SRF

test :main.cpp
	g++ -std=c++17 main.cpp src/parser.cpp src/bipartitions.cpp tests/unitTests.cpp -o SRF
	./SRF test
