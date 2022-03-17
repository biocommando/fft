#include <stdio.h>
#include <math.h>
#include "fft.h"

int main(int argc, char **argv)
{
    cplx data[64];
    
    printf("Input = 3 sine waves at frequencies 0.1 f, 0.5 f, 1.5 f\n");

    double p1 = 0, p2 = 0, p3 = 0;
    for (int i = 0; i < 64; i++)
    {
        data[i].r = sin(p1) + sin(p2) + sin(p3);
        data[i].i = 0;
        p1 += 0.1;
        p2 += 0.5;
        p3 += 1.5;
    }
    fft(data, 64);
    printf("Spectrum graph:\n");
    for (int db_lim = 0; db_lim > -60; db_lim -= 5)
    { 
        char s[33];
        for (int i = 0; i < 32; i++)
        {
            s[i] = fft_db_amplitude(data + i) > db_lim ? 'x' : '_';
        }
        s[32] = 0;
        printf("|%s|__ %d dB\n", s, db_lim);
    }
    printf("\n");
    return 0;
}