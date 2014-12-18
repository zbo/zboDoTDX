#include "../TwentyDay.h"
void test1(){
	int DataLen=10;
	printf("should mark areas!\n");
	int* result=(int*)malloc(DataLen*sizeof(int));
	float MA[10]={1,1,1,1,5,6,7,8,9,10};
	float Close[10]={1,2,3,4,4,4,4,4,4,4};
	MABlock* blocks=(MABlock*)malloc(DataLen*sizeof(MABlock));
	PutMarkTwentyDay( DataLen, MA, Close, result);
	printf("should gen blocks!\n");
	int shortLen=GenChartBlock( DataLen, MA, Close, result,blocks);
	GenChartPoint(shortLen,blocks,DataLen,Close);
}

void test2(){
	int DataLen=10;
	printf("should mark areas!\n");
	int* result=(int*)malloc(DataLen*sizeof(int));
	float MA[10]={1,1,1,1,1,1,1,1,1,1};
	float Close[10]={1,2,3,2,1,2,3,2,1,2};
	MABlock* blocks=(MABlock*)malloc(DataLen*sizeof(MABlock));
	PutMarkTwentyDay( DataLen, MA, Close, result);
	printf("should gen blocks!\n");
	int shortLen=GenChartBlock( DataLen, MA, Close, result,blocks);
	GenChartPoint(shortLen,blocks,DataLen,Close);
}

void fb_test_20day_entrance(){
	printf("start 20 day ma test!\n");
	test1();
	test2();
}