/**
  * @purpose     FFT Window functions library
  *
  * @description http://en.wikipedia.org/wiki/Window_function
  *
  * @author      Ashish
  * @license     MIT license
  * @version     1.0, Doxygen compatible comments
  */

#include<stdio.h>
#include<math.h>
#include "libfft_windows.h"

#ifndef M_PI
#define M_PI 3.14
#endif

#ifndef SINC
#define SINC(x) (sin(M_PI * x) / (M_PI * x))
#endif

double hanning (int n, int N) {
    return (0.5 * (1.0 - cos(2.0 * M_PI * (double)n / (double)(N - 1))));
}

double hamming (int n, int N) {
    return (0.54 - 0.46 * cos(2.0 * M_PI * (double)n / (double)(N - 1)));
}

double blackman (int n, int N) {
    return (0.42 - 0.5 * cos(2.0 * M_PI * (double)n / (double)(N - 1))
                + 0.08 * cos(4.0 * M_PI * (double)n / (double)(N - 1))
            );
}

double blackman_nutall(int n, int N) {
    return (0.3635819 - 0.4891775 * cos(2 * M_PI * (double)n / (double)(N - 1))
                + 0.1365995 * cos(4 * M_PI * (double)n / (double)(N - 1))
                - 0.0106411 * cos(6 * M_PI * (double)n / (double)(N - 1))
           );
}

double blackman_harris(int n, int N) {
    return (0.35875 - 0.48829 * cos(2 * M_PI * (double)n / (double)(N - 1))
                + 0.14128 * cos(4 * M_PI * (double)n / (double)(N - 1))
                - 0.01168 * cos(6 * M_PI * (double)n / (double)(N - 1))
           );
}

double flattop(int n, int N) {
    return (1 - 1.93 * cos(2 * M_PI * (double)n / (double)(N - 1))
                + 1.29 * cos(4 * M_PI * (double)n / (double)(N - 1))
                - 0.338 * cos(6 * M_PI * (double)n / (double)(N - 1))
                + 0.028 * cos(8 * M_PI * (double)n / (double)(N - 1))
            );
}

double cosine(int n, int N) {
    return (sin(M_PI * (double)n / (double)(N - 1)));
}

double bartlett_hann(int n, int N) {
    return (0.62 - 0.48 * abs((double)n / (double)(N - 1) - 0.5)
                - 0.38 * cos(2 * M_PI * (double)n / (double)(N - 1))
            );    
}

double lanczos(int n, int N) {
    return (SINC((2 * (double)n) / (double)(N - 1)) - 1);
}
