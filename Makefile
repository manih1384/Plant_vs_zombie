
CXX = g++ 
CXXFLAGS = -std=c++20 
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
SOURCES = main.cpp system.cpp plants.cpp zombie.cpp projectile.cpp icons.cpp sun.cpp totalsun.cpp global.cpp
HEADERS = system.hpp plants.hpp zombie.hpp projectile.hpp icons.hpp sun.hpp totalsun.hpp global.hpp zombiesglobal.hpp
OBJECTS = $(SOURCES:.cpp=.o)  
TARGET = pvz.out  


all: $(TARGET)


%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<


$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)


clean:
	rm -f $(OBJECTS) $(TARGET)
