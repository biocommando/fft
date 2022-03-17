#ifndef FFT_H
#define FFT_H

typedef struct
{
    double r, i;
} cplx;

void fft(cplx *buf, int n);
double fft_amplitude(const cplx *c);
double fft_db_amplitude(const cplx *c);

#endif