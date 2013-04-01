TARGET=decide

CXX=g++
CXXFLAGS=-g -Wall
RM=rm -rf
MV=mv

INCLUDES=-I. -I/usr/include -I/usr/local/include
LIB_PATH=-L/usr/lib/ -L/usr/local/lib
LIBS=-lACE

SOURCES=Decide.cpp \
		ConnectionManager.cpp \
		ThreadPool.cpp \
		JobManager.cpp 

				
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))

.PHONY:all
all:$(TARGET)

$(TARGET):$(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIB_PATH) -o $(TARGET) $(OBJECTS) $(LIBS)
	
$(OBJECTS):%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
        
.PHONY:clean
clean:   
	$(RM) $(TARGET) *.o
