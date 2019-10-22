
CXXFLAGS := -Wall -Wextra -O2 -g -std=c++11

LDFLAGS := -lm -lz

HEADERS := \
	dynamic_array.h \
	str.h

SRC := \
	file.cpp \
	memory.cpp \
	tokenizer.cpp

OBJECTS := $(SRC:%.cpp=%.o)

%.o: %.cpp %.h $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: wsjrep

wsjrep: main.cpp $(OBJECTS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ main.cpp $(OBJECTS)

CLEAN := $(OBJECTS) wsjrep
clean:
	rm -f $(CLEAN)

