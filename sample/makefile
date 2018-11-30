# define variables
opt =-O2  
default:
	
	
	sw5CC $(opt) -w -DSUNWAY -host  main.cxx -c -o main.o -I ../rlmpi
	sw5cc $(opt) -slave -msimd  test.c -c -o test.o -I../rlmpi
	
	mpiCC -hybrid -w $(opt) test.o main.o -o  main.sw -L../rlmpi -lrlmpi
	
	


clean:
	rm -rf src/*.o *.o *.a *.sw


