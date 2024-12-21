CXX = g++
CXXFLAGS = -Wall 

TARGET = nbs

SOURCES = main.cpp Classes/Server.cpp Classes/Bytestream.cpp Classes/ChecksumEncoder.cpp Classes/Player.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
