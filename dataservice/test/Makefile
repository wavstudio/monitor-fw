TARGET=dataservicetester

CXX=g++
CXXFLAGS=-g -Wall
RM=rm -rf
MV=mv

INCLUDES=-I. -I/usr/include/cppunit
LIB_PATH=-L/usr/lib/ -L../lib/ 
LIBS=-lcppunit -ldataservice -lmysqlclient

SOURCES=dataservicetester.cpp

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES)) 

.PHONY:all
all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIB_PATH) -o $(TARGET) $(OBJECTS) $(LIBS)
	
$(OBJECTS):%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
        
.PHONY:clean
clean:   
	$(RM) $(TARGET) *.o
