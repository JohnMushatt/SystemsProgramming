CXXFLAGS =	-O2 -g -Wall -fmessage-length=0


# added the new classes to make
OBJS =		qSim.o TellerQueue.o TellerQueueNode.o Event.o CustomerEvent.o TellerEvent.o  EventQueue.o

LIBS =

TARGET =	Test

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f *.o $(TARGET)
#	rm -f $(OBJS) $(TARGET)  <=== Replaced this
	