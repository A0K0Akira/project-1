
CXX = g++


CXXFLAGS = -Wall -g


TARGET = test


SOURCES = main.cpp Book.cpp Date.cpp Librarian.cpp Member.cpp Person.cpp

OBJECTS = $(SOURCES:.cpp=.o)


$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f $(TARGET) $(OBJECTS)
