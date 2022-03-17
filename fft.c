#include "fft.h"
#include <stdlib.h>
#include <math.h>

/*Complex*/

void cplxSet(cplx *result, double r, double i)
{
    result->r = r;
    result->i = i;
}

void cexpIZ(cplx *result, double z) // exp(I * z)
{
    cplxSet(result, cos(z), sin(z));
}

void cplxAdd(cplx *result, cplx *operand1, cplx *operand2, double sign)
{
    cplxSet(result, operand1->r + operand2->r * sign, operand1->i + operand2->i * sign);
}

void cplxMult(cplx *result, cplx *operand1, cplx *operand2)
{
    // (a+ib)(c+id)=ac+ibc+aid+ibid=ac-bd+i(bc+ad)
    double a = operand1->r;
    double b = operand1->i;
    double c = operand2->r;
    double d = operand2->i;
    cplxSet(result, a * c - b * d, b * c + a * d);
}

void cplxCopy(cplx *result, cplx *source)
{
    result->r = source->r;
    result->i = source->i;
}

/*FFT*/

void _fft_internal(cplx *buf, cplx *out, int n, int step)
{
    const double PI = acos(-1);
    if (step < n)
    {
        _fft_internal(out, buf, n, step * 2);
        _fft_internal(out + step, buf + step, n, step * 2);

        for (int i = 0; i < n; i += 2 * step)
        {
            cplx et;
            cexpIZ(&et, -PI * i / n);
            cplx t;
            cplxMult(&t, &et, &out[i + step]);
            cplxAdd(&buf[i / 2], &out[i], &t, 1);
            cplxAdd(&buf[(i + n) / 2], &out[i], &t, -1);
        }
    }
}

void fft(cplx *buf, int n)
{
    cplx *out = (cplx *)malloc(sizeof(cplx) * n);
    for (int i = 0; i < n; i++)
        cplxCopy(&out[i], &buf[i]);

    _fft_internal(buf, out, n, 1);
    free(out);
    // normalization
    for (int i = 0; i < n; i++)
        cplxSet(&buf[i], buf[i].r / n, buf[i].i / n);
}

double fft_amplitude(const cplx *c)
{
    return sqrt(c->r * c->r + c->i * c->i);
}

double fft_db_amplitude(const cplx *c)
{
    return 20 * log10(fft_amplitude(c));
}