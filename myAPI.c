#include "myAPI.h"
#include<string.h>
int add(int a, int b, int * c)
{
	*c = a + b ;
	return a+b+ *c;
}

void str_re(char *input, char *output)
{
	int i = strlen(input);
	int j;
	for (i, j = 0; i > 0; j++) {
		output[j] = input[i-1];
		i--;
	}
}


void cmplx64_test(cmplx128 *input, cmplx128 *output)
{

		output->re = (input->re * 2.0);
		output->im = (input->im * input->im);
		//(*output)->re = (float)((*input)->re * 2.0);
		//(*output)->im = (*input)->im*(*input)->im;
		//input++;
		//output++;
	
}

void cmplx64_test_copy(cmplx128 *input, cmplx128 *output,int len)
{
	for (int i = 0; i < len; i++) {
		if (input[i].re < 0) {
			output[i].re = (float)(input[i].re * 3.0);
		}
		else {
			output[i].re = (float)(input[i].re * 3.0*-1);
		}
		
		output[i].im = (float)(input[i].im * input[i].im*(-1));
	}
	//(*output)->re = (float)((*input)->re * 2.0);
	//(*output)->im = (*input)->im*(*input)->im;
	//input++;
	//output++;

}
_DLL_API void struct_test(TD1 * inTD, TD1 * outTD,int i)
{
	int j = 0;
	while (j < i) {
		outTD[j].DBL = inTD[j].DBL*2;
		j++;
	}
	

	/*
	i = strlen(input->string);
	int j;
	for (i, j = 0; i > 0; j++) {
		output->string[j] = input->string[i - 1];
		i--;
	}
	*/
//	for (i = 0; i < 50; i++) {
//		output->array[i] = inTD->array[i] * 2;
//	}
	
}

_DLL_API void sin_test(double * in, double * out, int len)
{
	int m = 0;
	for (int i = len / 2; i < len; i++,m++) {
		out[m] = in[i];
	}
}

/*
_DLL_API void struct_str_test(TD1 * input, char * output)
{
	int i = strlen(input->string);
	int j;
	for (i, j = 0; i > 0; j++) {
		output[j] = input->string[i - 1];
		i--;
	}
}
*/




_DLL_API int qpsk(bitstream in, cmplx128* out,int i)
{
	bitstream in_bit = in;
	int temp = 0;
	while (temp < i) {

//		out[temp].re = (float)((*in));
//		out[temp].im = (float)(*(in+1));
		if (0 == (*in_bit)) {
			if (0 == (*(in_bit + 1))) {
				out[temp].re = (double)((-1) / sqrtf(2));
				out[temp].im = (double)((-1) / sqrtf(2));
			}
			else {
				out[temp].re = (double)((-1) / sqrtf(2));
				out[temp].im = (double)(1 / sqrtf(2));
			}
		}
		else {
			if (0 == (*(in_bit + 1))) {
				out[temp].re = (double)(1 / sqrtf(2));
				out[temp].im = (double)((-1) / sqrtf(2));
			}
			else {
				out[temp].re = (double)((1) / sqrtf(2));
				out[temp].im = (double)((1) / sqrtf(2));
			}
		}
		in_bit = in_bit + 2;
//		out++;
		temp++;
	}
	return temp;
}

_DLL_API void qpsk_CDB(cmplx128 *in, int len)
{
	for (int i = 0; i < len; i++) {
		if ((0 == in[i].re)) {
			if (0 == in[i].im) {
				in[i].re = ((-1) / sqrtf(2));
				in[i].im = ((-1) / sqrtf(2));
			}
			else {
				in[i].re = ((-1) / sqrtf(2));
				in[i].im = (1 / sqrtf(2));
			}
		}
		else {
			if (0 == in[i].im) {
				in[i].re = (1 / sqrtf(2));
				in[i].im = ((-1) / sqrtf(2));
			}
			else {
				in[i].re = ((1) / sqrtf(2));
				in[i].im = ((1) / sqrtf(2));
			}
		}
	}
}

_DLL_API int offset_qpsk(int samples, float *i,float *q, float *out,int j)
{
	float *q_out = q;
	float *i_out = i;
	int n = 0;
	int temp =(int) (samples / 2);
	while (temp < j*samples) {
		out[temp] = q_out[n] + i_out[temp];
		temp++;
		n++;
	}
	return n;
}

_DLL_API int offset_im(int samples, float *q, float *out, int j)
{
	float *q_out = q;
	int n = 0;
	int temp = (int)(samples / 2);
	while (temp < j*samples) {
		out[temp] = q_out[n];
		n++;
	}
	return n;
}
_DLL_API void offset_CDB(cmplx128 * in, cmplx128 * out_off, int len, int samples)
{
	int temp = samples / 2;
	int temp_len = len - temp;
	for (int i = 0; i < temp_len; i++) {
		out_off[i].re = in[i + temp].re;
		out_off[i].im = in[i].im;
	}
}
		/*
		if (0 == *in)
			if (0 == *(in + 1)) {
				(*out)->re = 0;
				(*out)->im = 0;
			}
			else {
				(*out)->re = 0;
				(*out)->im = 1;

			}
		else if (1 == *(in + 1)) {
			(*out)->re = 1;
			(*out)->im = 1;

		}
		else {
			(*out)->re = 1;
			(*out)->im = 0;
		}
		*/

_DLL_API void qpsk_bit(uint8_t i, uint8_t q, cmplx128 *out)
{
	if (0 == i) {
		if (0 == q) {
			out->re = (-1) / sqrtf(2);
			out->im = (-1) / sqrtf(2);
		}
		else {
			out->re = (-1) / sqrtf(2);
			out->im = 1 / sqrtf(2);
		}
	}
	else {
		if (0 == q) {
			out->re = 1 / sqrtf(2);
			out->im = (-1) / sqrtf(2);
		}
		else {
			out->re = 1 / sqrtf(2);
			out->im = 1 / sqrtf(2);
		}
	}
}
	//    01 | 11           00
	//   ---------     10---------01
	//    00 | 10           11

_DLL_API void relativecode(bitstream re, bitstream im, cmplx128 *out, int len)
{
	int temp, i;
	for (i = 0; i < 4; i++) {
		out[i].re = 1;
		out[i].im = 1;
	}
	out[4].re = 0;//还需要设置参考位
	out[4].im = 0;
	for (i = 4; i < len; i++) {
		temp = absolute_to_relative(re[i], im[i], out[i].re, out[i].im);  //temp为值0，1，2，3 对应上方差分编码的坐标。
		switch (temp)
		{
		case 0: {
			out[i + 1].re = 0;
			out[i + 1].im = 1;
		} break;
		case 90: {
			out[i + 1].re = 0;
			out[i + 1].im = 0;
		} break;
		case 180: {
			out[i + 1].re = 1;
			out[i + 1].im = 0;
		} break;
		case 270: {
			out[i + 1].re = 1;
			out[i + 1].im = 1;
		} break;
		}
	}
}
int absolute_to_relative(uint8_t shi, uint8_t xu, double out_re, double out_im) //out_last为一个复数
{
	int temp_out = judge_out(out_re, out_im);
	if ((0 == shi) && (0 == xu)) {
		switch (temp_out) {
		case 0: return 0;
		case 1: return 90;
		case 2: return 270;
		case 3: return 180;
		}
	}else
	if ((0 == shi) && (1 == xu)) {
		switch (temp_out) {
		case 0: return 270;
		case 1: return 0;
		case 2: return 180;
		case 3: return 90;
		}
	}
	if ((1 == shi) && (0 == xu)) {
		switch (temp_out) {
		case 0: return 90;
		case 1: return 180;
		case 2: return 0;
		case 3: return 270;
		}
	}
	if ((1 == shi) && (1 == xu)) {
		switch (temp_out) {
		case 0: return 180;
		case 1: return 270;
		case 2: return 90;
		case 3: return 0;
		}
	}
}
int judge_out(double re, double im)
{
	if (0 == re)
		if (0 == im) {
			return 0;
		}
		else {
			return 1;
		}
	else {
		if (0 == im) {
			return 2;
		}
		else {
			return 3;
		}
	}
}

_DLL_API void absolutecode(cmplx128 * in, bitstream re, bitstream im, int len)
{
	int i,temp_i,temp;
	for (i = 0; i < 4; i++) {
		re[i] = 1;
		im[i] = 1;
	}
	//假设初始参考位为00, in数组比re,im比特流长度大1
	for (i = 4; i < len; i++) {
		temp = relative_to_absolute(in[i + 1].re, in[i + 1].im);
		temp_i = judge_out(in[i].re, in[i].im);
		if (0 == temp_i) {
			switch (temp)
			{
			case 0: {
				re[i] = 0;
				im[i] = 0;
			} break;
			case 90: {
				re[i] = 1;
				im[i] = 0;
			} break;
			case 180: {
				re[i] = 1;
				im[i] = 1;
			} break;
			case 270: {
				re[i] = 0;
				im[i] = 1;
			} break;
			}
		}
		if (1 == temp_i) {
			switch (temp)
			{
			case 0: {
				re[i] = 0;
				im[i] = 1;
			} break;
			case 90: {
				re[i] = 0;
				im[i] = 0;
			} break;
			case 180: {
				re[i] = 1;
				im[i] = 0;
			} break;
			case 270: {
				re[i] = 1;
				im[i] = 1;
			} break;
			}
		}
		if (2 == temp_i) {
			switch (temp)
			{
			case 0: {
				re[i] = 1;
				im[i] = 0;
			} break;
			case 90: {
				re[i] = 1;
				im[i] = 1;
			} break;
			case 180: {
				re[i] = 0;
				im[i] = 1;
			} break;
			case 270: {
				re[i] = 0;
				im[i] = 0;
			} break;
			}
		}
		if (3 == temp_i) {
			switch (temp)
			{
			case 0: {
				re[i] = 1;
				im[i] = 1;
			} break;
			case 90: {
				re[i] = 0;
				im[i] = 1;
			} break;
			case 180: {
				re[i] = 0;
				im[i] = 0;
			} break;
			case 270: {
				re[i] = 1;
				im[i] = 0;
			} break;
			}
		}
	}
}
int relative_to_absolute(double i_1_re, double i_1_im)
{
	int temp_i_1 = judge_out(i_1_re, i_1_im);
	switch (temp_i_1)
	{
	case 0: return 90; break;
	case 1: return 0; break;
	case 2: return 180; break;
	case 3: return 270; break;
	}
}

_DLL_API void random_bit(int num, bitstream out)
{
	int tmp = 0;
	/*
	while (tmp > 0) {
		*out = rand() % 2;
		tmp--;
		out++;
	}
	*/
	
	while (tmp < num) {
		out[tmp] = (uint8_t)(rand() % 2);
		tmp++;
//		out++;
	}
}

_DLL_API void bitstream_iq(bitstream in, bitstream i, bitstream q, int len)
{
	int temp = len / 2;
	for (int j = 0; j < temp; j++) {
		i[j] = in[2 * j];
		q[j] = in[2 * j + 1];
	}
}

_DLL_API void samples_symbol(cmplx128 * in, cmplx128 * out, int len, int samples)
{
	int j = 0;
	int k = 0;
	for (int i = 0; i < len; i++) {
		for (k = 0; k < samples; k++) {
			out[j].re = in[i].re;
			out[j].im = in[i].im;
			j++;
		}
	}
}

_DLL_API void cmplx_iq(cmplx128 * in, double *i, double *q)
{
	*i = in->re;
	*q = in->im;
}

_DLL_API void cmplx_reim(cmplx128 * in, uint8_t *re, uint8_t *im,int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (in[i].re > 0) {
			re[i] = 1;
		}
		else {
			re[i] = 0;
		}
		if (in[i].im > 0) {
			im[i] = 1;
		}
		else {
			im[i] = 0;
		}
		
	}
}

_DLL_API void sample_symbol_mapping(cmplx128 *in, cmplx128 * Zarray, int a, int b)
{
	int temp = a*b;
	int k = 0;
	int i, j;
	for (i = 0; i < a; i++)
		for (j = 0; j < b; j++) {
			Zarray[k++].re = in[i].re;
			Zarray[k++].im = in[i].im;
		}
			
}

_DLL_API void demod_test(cmplx128 *in, cmplx128 *out, int length, int len_symbol)
{

	for (int i = 0; i < length; i++) {
		if (in[i].re > 0) {
			out[i].re = 0.0;
		}
//		out[i].re = in[i].re;
		out[i].im = in[i].im;
	}

	//length为5000 10ms
	int m, n, k;
	int temp = 0;
	for (m = 0; m < length; m++) {
		if ((in[m].re > 0) && (in[m + 4].re > 0) && (in[m].im > 0) && (in[m + 4].im > 0)) {
			//开始进行检测帧头
			for (n = 0; n < 16; n++) {
				if (in[m].re > 0 && in[m].im > 0) {
					temp++; m++;
				}
				else {
					temp = 0;
					break;
				}
			}
			if (temp == 16) { //sample per symbol.标记位为连续4位<0
				m = m - 16;
				for (k = 0; k < len_symbol; k++) {
					out[k].re = (in[m].re + in[m + 1].re + in[m + 2].re + in[m + 3].re) / 4;
					out[k].im = (in[m].im + in[m + 1].im + in[m + 2].im + in[m + 3].im) / 4;
					m = m + 4;
				}
				break;
			}
			//如果temp不等于16，意味着不是帧头继续向下寻找
		}
	}

}

_DLL_API void demod(double * i, double * q, double * i_out, double * q_out, int length)
{
	//length为5000 10ms
	int m, n, k;
	int temp = 0;
	for (m = 0; m < length; m++) {
		if ((i[m] > 0) && (i[m + 4] > 0) && (q[m] > 0) && (q[m + 4] > 0)) {
			//开始进行检测帧头
			for (n = 0; n < 16; n++) {
				if (i[m] > 0 && q[m] > 0) {
					temp++; m++;
				}
				else {
					temp = 0;
					break;
				}
			}
			if (temp == 16) { //sample per symbol.标记位为连续4位<0
				m = m - 16;
				for (k = 0; k < 30; k++) {
					i_out[k] = (i[m] + i[m + 1] + i[m + 2] + i[m + 3]) / 4;
					q_out[k] = (q[m] + q[m + 1] + q[m + 2] + q[m + 3]) / 4;
					m = m + 4;
				}
				break;
			}
			//如果temp不等于16，意味着不是帧头继续向下寻找
		}
	}
}

_DLL_API void demod_CDB(cmplx128 *in, cmplx128 *out, int length, int len_symbol)
{
	//length为5000 10ms
	int m, n, k;
	int temp = 0;
	for (m = 0; m < length; m++) {
		if ((in[m].re > 0) && (in[m + 4].re > 0) && (in[m].im > 0) && (in[m + 4].im > 0)) {
			//开始进行检测帧头
			for (n = 0; n < 16; n++) {
				if (in[m].re > 0 && in[m].im > 0) {
					temp++; m++;
				}
				else {
					temp = 0;
					break;
				}
			}
			if (temp == 16) { //sample per symbol.标记位为连续4位<0
				m = m - 16;
				for (k = 0; k < len_symbol; k++) {
					out[k].re = (in[m].re + in[m + 1].re + in[m + 2].re + in[m + 3].re) / 4;
					out[k].im = (in[m].im + in[m + 1].im + in[m + 2].im + in[m + 3].im) / 4;
					m = m + 4;
				}
				break;
			}
			//如果temp不等于16，意味着不是帧头继续向下寻找
		}
	}
}

_DLL_API void demod_offset(cmplx128 * in, double *out_re, double *out_im, int length, int per_symbol,int len_symbol)
{

	int m, n, k;
	int temp = 0;
	for (m = 0; m < length; m++) {
		if ((in[m].re > 0) && (in[m + 4].re > 0) && (in[m].im > 0) && (in[m + 4].im > 0)) {
			//开始进行检测帧头
			int temp_head = per_symbol * 4 - 2; //帧头比特数目为4
			for (n = 0; n < temp_head; n++) {
				if (in[m].re > 0 && in[m].im > 0) {
					temp++; m++;
				}
				else {
					temp = 0;
					break;
				}
			}
			if (temp == temp_head) { //sample per symbol.标记位为连续4位<0
				int i;
				int temp_symbol = per_symbol / 2;
				int temp_len = per_symbol*len_symbol - temp_symbol;
				i = temp_len - 1;
				m = m - 14;
				//int im1 = in[m + temp_len - 1].im;
				//int im2 = in[m + temp_len].im;
				/*
				for (i = temp_len; i < length; i++) {
				in[i].im = in[temp_len - 1].im;
				}
				*/
				int temp_m = m;
				for (k = 0; k < len_symbol; k++) { //对实部进行处理
					if (0 == k) {
						out_re[k] = (in[temp_m].re + in[temp_m + 1].re + in[temp_m].re + in[temp_m + 1].re) / 4;
						temp_m = temp_m + 2;
					}
					else {
						out_re[k] = (in[temp_m].re + in[temp_m + 1].re + in[temp_m + 2].re + in[temp_m + 3].re) / 4;
						temp_m = temp_m + 4;
					}
				}

				temp_m = m;
				for (k = 0; k < len_symbol; k++) { //对虚部进行处理
					if (len_symbol - 1 == k) {
						out_im[k] = (in[temp_m].im + in[temp_m + 1].im + in[temp_m].im + in[temp_m + 1].im) / 4;
					}
					else {
						out_im[k] = (in[temp_m].im + in[temp_m + 1].im + in[temp_m + 2].im + in[temp_m + 3].im) / 4;
						temp_m = temp_m + 4;
					}
				}
				break;
			}
			//如果temp不等于14，意味着不是帧头继续向下寻找
		}
	}
}

_DLL_API void demod_CSG_test(cmplx128 *in, cmplx128 *out, int length, int len_symbol)
{
	//length为5000 10ms
	int m, n, k;
	int temp = 0;
	for (m = 0; m < length; m++) {
		if ((in[m].re > 0) && (in[m + 1].re > 0) && (in[m].im > 0) && (in[m + 1].im > 0)) {
			//开始进行检测帧头
			for (n = 0; n < 4; n++) {
				if (in[m].re > 0 && in[m].im > 0) {
					temp++; m++;
				}
				else {
					temp = 4;
					break;
				}
			}
			if (temp == 4) { //sample per symbol.标记位为连续4位<0
				m = m - 4;
				for (k = 0; k < len_symbol; k++) {
					out[k].re = (in[m].re + in[m + 1].re) / 2;
					out[k].im = (in[m].im + in[m + 1].im) / 2;
					m=m+2;
				}
				break;
			}
			//如果temp不等于16，意味着不是帧头继续向下寻找
		}
	}
}


_DLL_API void demod_mapping(cmplx128 * in, cmplx128 * out, cmplx128 *out1, int length_symbol)
{
	for (int i = 0; i < length_symbol; i++) {
		if (in[i].re > 0) {
			out[i].re = 0.707;
			out1[i].re = 1;
		}
		else {
			out[i].re = -0.707;
			out1[i].re = 0;
		}
		if (in[i].im > 0) {
			out[i].im = 0.707;
			out1[i].im = 1;
		}
		else {
			out[i].im = -0.707;
			out1[i].im = 0;
		}
	}
}
