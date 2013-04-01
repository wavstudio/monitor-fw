MAKE=make
MV=mv
RM=rm -f

.PHONY:all
all:
	$(MAKE) -C src
	$(MV) src/libdataservice.so lib/

.PHONY:test
test:
	$(MAKE) -C test
	$(MV) test/dataservicetester bin/       

.PHONY:clean
clean:   
	$(MAKE) clean -C src
	$(MAKE) clean -C test
	$(RM) lib/* bin/libdataservicetester
	
