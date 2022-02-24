
#include "multiplication.h"

void multip_2num(int32_t n32In1, int32_t n32In2, int32_t* pn32ResOut)
{
#pragma HLS INTERFACE s_axilite port=pn32ResOut
#pragma HLS INTERFACE s_axilite port=n32In2
#pragma HLS INTERFACE s_axilite port=n32In1
#pragma HLS INTERFACE ap_ctrl_none port=return

	*pn32ResOut = n32In1 * n32In2;

	return;
}
