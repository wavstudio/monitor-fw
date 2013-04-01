MAKE=make
MV=mv
RM=rm -f

.PHONY:all
all:
	$(MAKE) -C src
	$(MV) src/decide bin/

.PHONY:test
test:
	$(MAKE) -C test
	$(MV) test/decidetester bin/       

.PHONY:clean
clean:   
	$(MAKE) clean -C src
	$(MAKE) clean -C test
	$(RM) bin/*
	
