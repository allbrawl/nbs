CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = nbs

SOURCE = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET) 

.PHONY: all clean
