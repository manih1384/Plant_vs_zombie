# Variables
CXX = g++  # The C++ compiler
CXXFLAGS = -std=c++20  # Compiler flags (you can set your C++ standard here)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system  # Libraries to link with SFML
SOURCES = main.cpp system.cpp peashooter.cpp sunflower.cpp wallnut.cpp# The source files (add more if you have other files)
HEADERS = system.hpp peashooter.hpp global.hpp sunflower.hpp wallnut.hpp
OBJECTS = $(SOURCES:.cpp=.o)  # Object files derived from source files
TARGET = pvz.out  # The output executable name

# Default target to compile and link the program
all: $(TARGET)

# Compile object files
%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)
