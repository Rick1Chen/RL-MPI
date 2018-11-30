#include "RlmpiInitializer.hxx"
#include <iostream>
#include <vector>
using namespace std;
#ifdef SUNWAY
extern "C" {
#include "RlmpiShared.h"
#include <athread.h>
    void slave_test(RlmpiInfo* data);
    void slave_test_athread_get(double* in);
}
#endif

int main() {
#ifdef SUNWAY
    athread_init();
#endif
    
    RlmpiInfo *rlmpi_info = new RlmpiInfo;

    RlmpiInitializer rlmpi_init;
    vector<vector<int32> > sendList(64);
    for (int i = 0; i < 64; i++) {
        int ntimes = 1;
        int s = 0;
        for (int b = 0; b < ntimes; b++) {
            for (int j = 0; j < 64; j++) {
                int col_dst = COL(j);
                int col_src = COL(i);
                if (j != i) {
                    sendList[i].push_back(j);
                }
            }
        }
    }
    rlmpi_init.init(sendList);
    rlmpi_init.copyRlmpiInfo(rlmpi_info);





#ifdef SUNWAY
    __real_athread_spawn((void *) slave_initRlmpiInfo, rlmpi_info);
    athread_join();
#endif

#ifdef SUNWAY
    __real_athread_spawn((void *) slave_test, rlmpi_info);
    athread_join();
#endif



#ifdef SUNWAY
    __real_athread_spawn((void *) slave_destroyRlmpiInfo, rlmpi_info);
    athread_join();
#endif


#ifdef SUNWAY
    athread_halt();
#endif
}
