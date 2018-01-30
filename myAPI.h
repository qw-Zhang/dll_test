#pragma once
#include<stdint.h>
#include<stdlib.h>
#include<math.h>
#ifndef _DLL_API  
#define _DLL_API _declspec(dllexport)  
#else  
#define _DLL_API _declspec(dllimport)  
#endif  

typedef struct cmplx128 {
	double re;
	double im;
}cmplx128;

typedef struct TD1 {
	double DBL;
//	char *string;
	int array[50];

}TD1;

/*
typedef struct {
	cmplx64 cmp[10];
}cmp_cluster;

*/

typedef uint8_t* bitstream;

_DLL_API int add(int a, int b,int *c);
_DLL_API void str_re(char *input, char *output);
_DLL_API void cmplx64_test(cmplx128 *input, cmplx128 *output);
_DLL_API void cmplx64_test_copy(cmplx128 *input, cmplx128 *output, int len);
_DLL_API void struct_test(TD1 *input, TD1 *output,int i);
_DLL_API void struct_str_test(TD1 *input, char *output);
_DLL_API void sin_test(double *in, double *out, int len);

_DLL_API int qpsk(bitstream in, cmplx128 * out,int i);
_DLL_API void qpsk_CDB(cmplx128 *in, int len);
_DLL_API int offset_qpsk(int samples, float * i, float *q, float *out, int j);
_DLL_API int offset_im(int samples, float *q, float *out, int j);
_DLL_API void offset_CDB(cmplx128 *in, cmplx128 *out_off, int len, int samples);
_DLL_API void qpsk_bit(uint8_t a, uint8_t b, cmplx128 *out);
_DLL_API void random_bit(int a, bitstream out);
_DLL_API void bitstream_iq(bitstream in, bitstream i, bitstream q, int len);
_DLL_API void samples_symbol(cmplx128 *in, cmplx128 *out, int len, int samples);
_DLL_API void cmplx_iq(cmplx128 * in, double *i, double *q);
_DLL_API void cmplx_reim(cmplx128 * in, uint8_t *re, uint8_t *im, int len);
_DLL_API void cmplx_array();
_DLL_API void sample_symbol_mapping(cmplx128 *in, cmplx128 *Zarray, int a, int b);

_DLL_API void early_late(cmplx128 *in, cmplx128 *out , int IQrate_rate, int length);

_DLL_API void demod_test(cmplx128 *in, cmplx128 *out, int length, int len_symbol);
_DLL_API void demod(double * i, double * q, double * i_out, double * q_out, int length);
_DLL_API void demod_CDB(cmplx128 *in, cmplx128 *out, int length, int len_symbol);
_DLL_API void demod_offset(cmplx128 * in, double *out_re, double *out_im, int length, int per_symbol, int len_symbol);
_DLL_API void demod_CSG_test(cmplx128 *in, cmplx128 *out, int length, int len_symbol);
_DLL_API void demod_mapping(cmplx128 * in, cmplx128 * out, cmplx128 *out1, int length_symbol);

_DLL_API void relativecode(bitstream re, bitstream im, cmplx128 *out, int len);
int absolute_to_relative(uint8_t shi, uint8_t xu, double out_re, double out_im);
int judge_out(double re, double im);
_DLL_API void absolutecode(cmplx128 *in, bitstream re, bitstream im, int len);
int relative_to_absolute(double i_1_re, double i_1_im);
