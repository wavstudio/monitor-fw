TARGET=libdataservice.so

CXX=g++
CXXFLAGS=-g -Wall -shared -fPIC
RM=rm -rf
MV=mv

INCLUDES=-I. -I../include -I/usr/include
LIB_PATH=-L/usr/lib/
LIBS=

SOURCES=MarsException.cpp \
				DataService.cpp \
				DBConnection.cpp \
				DBConnectionPool.cpp \
				KeyStoneTenantDAOImpl.cpp \
				MarsNovaClusterInfoDAOImpl.cpp \
				MarsNovaPMStatusDAOImpl.cpp \
				MarsNovaUserDAOImpl.cpp \
				MarsNovaVMClusterDAOImpl.cpp \
				NovaImagePropDAOImpl.cpp \
				NovaInstancesDAOImpl.cpp \
				NovaVolumesDAOImpl.cpp
				
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
