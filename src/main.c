#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <fftw3.h>

int main ( ){
    int n = 40000;

    fftw_complex *in;
    fftw_complex *in2;
    fftw_complex *out;
    fftw_plan plan_backward;
    fftw_plan plan_forward;

    //thread parameters
    int nbthreads=2;
    fftw_init_threads();
    fftw_plan_with_nthreads(nbthreads);

    in = fftw_malloc ( sizeof ( fftw_complex ) * n );
    out = fftw_malloc ( sizeof ( fftw_complex ) * n );

    // forward fft
    plan_forward = fftw_plan_dft_1d ( n, in, out, FFTW_FORWARD, FFTW_ESTIMATE );
    fftw_execute ( plan_forward );

    // backward fft
    in2 = fftw_malloc ( sizeof ( fftw_complex ) * n );
    plan_backward = fftw_plan_dft_1d ( n, out, in2, FFTW_BACKWARD, FFTW_ESTIMATE );
    fftw_execute ( plan_backward );

    fftw_destroy_plan ( plan_forward );
    fftw_destroy_plan ( plan_backward );
    fftw_cleanup_threads();

    fftw_free ( in );
    fftw_free ( in2 );
    fftw_free ( out );
    return 0;
}
