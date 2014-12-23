#include "../bi.h"
void bi_test_entrance2(){
	printf("bi test start!\n");
	float h[5]={1239,1159,799,1423,1674};
	float l[5]={832,700,584,699,1210};
	float o[5]={0,0,0,0,0};
	float c[5]={0,0,0,0,0};
	int dataln=5;
	Plugin_BI(dataln,o,h,l,c);

}
void bi_test_entrance(){
	printf("bi test start!\n");
	float h[5]={1,2,3,2,1};
	float l[5]={0,1,2,1,0};
	float o[5]={0,0,0,0,0};
	float c[5]={0,0,0,0,0};
	int dataln=5;
	Plugin_BI(dataln,o,h,l,c);

}