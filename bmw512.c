#include "sph/sph_bmw.h"
#include "bmw512.h"
#include <string.h>

void bmw512_hash(const char* input, char* output)
{
        char outhash[64];
        sph_bmw512_context ctx_bmw;

        sph_bmw512_init(&ctx_bmw);
        sph_bmw512(&ctx_bmw, input, 80);
        sph_bmw512_close(&ctx_bmw, outhash);

        memcpy(output, outhash, 32);
}
