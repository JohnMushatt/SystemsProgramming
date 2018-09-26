CXXFLAGS = -g -Wall -fmessage-length=0

OBJS =	testFile.o Organism.o Ant.o Doodlebug.o

LIBS =

TARGET =	testFile

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
