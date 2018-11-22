# define variables
opt =-O2  
default:
ifeq ($(platform),sw)	
	sw5CC $(opt) -w -DSUNWAY -host src/RlmpiInitializer.cxx src/rlmpi.h src/RlmpiShared.h -c -o RlmpiInitializer.o
	sw5cc $(opt) -w -DSUNWAY -slave -msimd src/rlmpi.c src/rlmpi.h src/RlmpiShared.h -c -o rlmpi.o 
	sw5CC $(opt) -w -DSUNWAY -host  src/main.cxx -c -o main.o
	sw5cc $(opt) -slave -msimd  src/test.c -c -o test.o
	swar  -rv librlmpi.a RlmpiInitializer.o rlmpi.o
	mpiCC -hybrid -w $(opt) test.o main.o -o  main.sw -L./ -lrlmpi
	
	
endif
ifeq ($(platform),x86)	
	mpiicpc -w -g  -o  RlmpiInitializer.o -c src/RlmpiInitializer.cxx  
	#sw5cc -w -slave -msimd src/prgrpcgc_slave.c src/prgrpcgc_slave.h src/DataTypeSlaveAndHost.h -c -o prgrpcgc_slave.o 
	mpiicpc -w   -g src/main.cxx -c -o main.o
	#sw5cc -slave -msimd  src/test.c -c -o test.o
	mpiicpc  -w -g RlmpiInitializer.o main.o -o  main.x 
	
	./main.x
endif
clean:
	rm -rf src/*.o *.o *.a *.sw


