CXXFLAGS = -g -Wall -fmessage-length=0 

OBJS =	PA5_Mushatt.o Customer.o Event.o EventQueue.o Teller.o TellerQueue.o

CXX = GPP

LIBS =

TARGET =	PA5_Mushatt

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) *.cpp

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
