/***********************************************************
    complex.c --  £¡«øÙ
***********************************************************/
#include <stdio.h>  /* {\tt sprintf()} */
#include <math.h>

typedef struct {  double re, im;  } complex;  /*  £¡«øÙ∑ø */

complex c_conv(double x, double y)  /* $x$, $y$ §Ú £¡«øÙ $z = x + iy$ §À —¥π */
{
    complex z;

    z.re = x;  z.im = y;
    return z;
}

char *c_string(complex z)  /*  £¡«øÙ $z = x + iy$ §Ú ∏ª˙ŒÛ§À —¥π */
{
    static char s[40];

    sprintf(s, "%g%+gi", z.re, z.im);
    return s;
}

complex c_conj(complex z)  /* ∂¶ÃÚ £¡«øÙ $\overline{z}$ */
{
    z.im = - z.im;
    return z;
}

double c_abs(complex z)  /* ¿‰¬–√Õ $|z|$ */
{
    double t;

    if (z.re == 0) return fabs(z.im);
    if (z.im == 0) return fabs(z.re);
    if (fabs(z.im) > fabs(z.re)) {
        t = z.re / z.im;
        return fabs(z.im) * sqrt(1 + t * t);
    } else {
        t = z.im / z.re;
        return fabs(z.re) * sqrt(1 + t * t);
    }
}

double c_arg(complex z)  /*  –≥— ($-\pi \le \varphi \le \pi$) */
{
    return atan2(z.im, z.re);
}

complex c_add(complex x, complex y)  /* œ¬ $x + y$ */
{
    x.re += y.re;
    x.im += y.im;
    return x;
}

complex c_sub(complex x, complex y)  /* ∫π $x - y$ */
{
    x.re -= y.re;;
    x.im -= y.im;
    return x;
}

complex c_mul(complex x, complex y)  /* ¿— $xy$ */
{
    complex z;

    z.re = x.re * y.re - x.im * y.im;
    z.im = x.re * y.im + x.im * y.re;
    return z;
}

#if 0
complex c_div(complex x, complex y)  /* æ¶ $x / y$ (√±Ω„»«) */
{
    double r2;
    complex z;

    r2 = y.re * y.re + y.im * y.im;
    z.re = (x.re * y.re + x.im * y.im) / r2;
    z.im = (x.im * y.re - x.re * y.im) / r2;
    return z;
}
#endif

complex c_div(complex x, complex y)  /* æ¶ $x / y$ (æÂ∞Ã∑Â§¢§’§Ï¬–∫ˆ»«) */
{
    double w, d;
    complex z;

    if (fabs(y.re) >= fabs(y.im)) {
        w = y.im / y.re;  d = y.re + y.im * w;
        z.re = (x.re + x.im * w) / d;
        z.im = (x.im - x.re * w) / d;
    } else {
        w = y.re / y.im;  d = y.re * w + y.im;
        z.re = (x.re * w + x.im) / d;
        z.im = (x.im * w - x.re) / d;
    }
    return z;
}

complex c_exp(complex x)  /* ªÿøÙ¥ÿøÙ $e^x$ */
{
    double a;

    a = exp(x.re);
    x.re = a * cos(x.im);
    x.im = a * sin(x.im);
    return x;
}

complex c_log(complex x)  /* º´¡≥¬–øÙ $\log_e x$ */
{
    complex z;

    z.re = 0.5 * log(x.re * x.re + x.im * x.im);
    z.im = atan2(x.im, x.re);
    return z;
}

complex c_pow(complex x, complex y)  /* ŒﬂæË $x^y$ */
{
    return c_exp(c_mul(y, c_log(x)));
}

complex c_sin(complex x)  /* ¿µ∏π $\sin x$ */
{
    double e, f;

    e = exp(x.im);  f = 1 / e;
    x.im = 0.5 * cos(x.re) * (e - f);
    x.re = 0.5 * sin(x.re) * (e + f);
    return x;
}

complex c_cos(complex x)  /* Õæ∏π $\cos x$ */
{
    double e, f;

    e = exp(x.im);  f = 1 / e;
    x.im = 0.5 * sin(x.re) * (f - e);
    x.re = 0.5 * cos(x.re) * (f + e);
    return x;
}

complex c_tan(complex x)  /* ¿µ¿‹ $\tan x$ */
{
    double e, f, d;

    e = exp(2 * x.im);  f = 1 / e;
    d = cos(2 * x.re) + 0.5 * (e + f);
    x.re = sin(2 * x.re) / d;
    x.im = 0.5 * (e - f) / d;
    return x;
}

complex c_sinh(complex x)  /* ¡–∂ ¿˛¿µ∏π $\sinh x$ */
{
    double e, f;

    e = exp(x.re);  f = 1 / e;
    x.re = 0.5 * (e - f) * cos(x.im);
    x.im = 0.5 * (e + f) * sin(x.im);
    return x;
}

complex c_cosh(complex x)  /* ¡–∂ ¿˛Õæ∏π $\cosh x$ */
{
    double e, f;

    e = exp(x.re);  f = 1 / e;
    x.re = 0.5 * (e + f) * cos(x.im);
    x.im = 0.5 * (e - f) * sin(x.im);
    return x;
}

complex c_tanh(complex x)  /* ¡–∂ ¿˛¿µ¿‹ $\tanh x$ */
{
    double e, f, d;

    e = exp(2 * x.re);  f = 1 / e;
    d = 0.5 * (e + f) + cos(2 * x.im);
    x.re = 0.5 * (e - f) / d;
    x.im = sin(2 * x.im) / d;
    return x;
}

#define SQRT05 0.707106781186547524  /* $\sqrt{0.5}$ */

complex c_sqrt(complex x)  /*  ø ˝∫¨ $\sqrt{x}$ */
{
    double r, w;

    r = c_abs(x);
    w = sqrt(r + fabs(x.re));
    if (x.re >= 0) {
        x.re = SQRT05 * w;
        x.im = SQRT05 * x.im / w;
    } else {
        x.re = SQRT05 * fabs(x.im) / w;
        x.im = (x.im >= 0) ? SQRT05 * w : -SQRT05 * w;
    }
    return x;
}

#include <stdlib.h>

int main()  /* •∆•π•» (§¥§Ø∞Ï…Ù) */
{
    double x, y;
    complex z;

    printf("x, y ? ");  scanf("%lf%lf", &x, &y);
    z = c_conv(x, y);
    printf("z = %s\n", c_string(z));
    z = c_exp(z);
    printf("exp(z) = %s\n", c_string(z));
    z = c_log(z);
    printf("log(exp(z)) = %s\n", c_string(z));
    return EXIT_SUCCESS;
}
