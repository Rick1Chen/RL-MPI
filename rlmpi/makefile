# define variables
opt =-O2  
default:
	
	sw5CC $(opt) -w -DSUNWAY -host RlmpiInitializer.cxx rlmpi.h RlmpiShared.h -c -o RlmpiInitializer.o
	sw5cc $(opt) -w -DSUNWAY -slave -msimd rlmpi.c rlmpi.h RlmpiShared.h -c -o rlmpi.o 
	
	swar  -rv librlmpi.a RlmpiInitializer.o rlmpi.o
	


clean:
	rm -rf src/*.o *.o *.a *.sw


