all : make

make : src/main.cpp
	g++ -std=c++17 src/main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF

test : src/main.cpp
	g++ -std=c++17 src/main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF
	./SRF test

triangle : src/main.cpp
	g++ -std=c++17 src/main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF
	./SRF triangle

user : src/main.cpp
	g++ -std=c++17 src/main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF
	./SRF user