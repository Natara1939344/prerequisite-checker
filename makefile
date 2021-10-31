CPP_EX := .c++

CPPSRC := $(wildcard ./src/*$(CPP_EX))

ARGS := -Wall -Wpedantic -Wunused -std=gnu++2a
WINARGS := $(ARGS) -D__WINDOWS__ -o ./prerequisite-checker.exe
WSLARGS := $(ARGS) -D__POSIX__ -o ./prerequisite-checker

# designed to work on my system that uses msys64
windows:
	@echo "Building for Windows..."
	g++ $(CPPSRC) $(WINARGS)
#designed to work for my wsl2 build on Windows 11
wsl2:
	@echo "Building for WSL2..."
	g++-10 $(CPPSRC) $(WSLARGS)