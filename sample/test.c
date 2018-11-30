#include <slave.h>
#include <dma.h>
#include <unistd.h>
#include <simd.h>
#include "rlmpi.h"

void test(RlmpiInfo* data) {

    int i = 0;
    for (i = 0; i < _total_send_pcg; i++) {
        _sPacks[i].data[0] = 1.0 / 10000.0 + _sPacks[i].src_id;
        _sPacks[i].data[1] = 2.0 / 10000.0 + _sPacks[i].src_id;
        _sPacks[i].data[2] = 3.0 / 10000.0 + _sPacks[i].src_id;
        _sPacks[i].data[3] = 4.0 / 10000.0 + _sPacks[i].src_id;
        _sPacks[i].data[4] = 5.0 / 10000.0 + _sPacks[i].src_id;
        _sPacks[i].data[5] = 6.0 / 10000.0 + _sPacks[i].src_id;
    }

    transform_data();

    int n;
    if (_MYID == 40) {

        for (n = 0; n < _total_recv_pcg; n++) {
            for (i = 0; i < 6; i++) {
                printf("%f ", _rPacks[n].data[i]);
            }
            printf("\n");
        }
    }

}

