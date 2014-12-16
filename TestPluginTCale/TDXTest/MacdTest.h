#include "../Macd.h"
#include "TestCommon.h"


void test1MacdPeak(){
	printf("===start macd get peak test====!\n");
	float macd[16] = {1,2,3,4,5,6,5,4,3,2,1,0,-1,-2,1,2};
	int expectPeaks[16]={0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
	int* peaks=new int[16];
	int i=0,dataLen=16;
	for(i=0;i<dataLen;i++){
		peaks[i]=0;
	}
	printArray(macd,dataLen);
	getPeak(macd,peaks,dataLen);
	printArray(peaks,dataLen);
	printArray(expectPeaks,dataLen);
	assertTwoEqual(peaks,expectPeaks,dataLen);
}

void test2MacdPeak(){
	printf("===start macd get peak test====!\n");
	float macd[16] = {-1,-2,-3,-4,-5,-6,-1,0,0,0,0,0,1,2,1,0};
	int expectPeaks[16]={0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0};
	int* peaks=new int[16];
	int i=0,dataLen=16;
	for(i=0;i<dataLen;i++){
		peaks[i]=0;
	}
	printArray(macd,dataLen);
	getPeak(macd,peaks,dataLen);
	printArray(peaks,dataLen);
	printArray(expectPeaks,dataLen);
	assertTwoEqual(peaks,expectPeaks,dataLen);
}

void test3MacdPeak(){
	printf("===start macd get peak test====!\n");
	float macd[21] = {-0.04f,-0.01f,0.07f,0.09f,0.07f,0.06f,
					   0.06f,0.03f,0.01f,-0.01f,-0.02f,-0.03f,-0.03f,
					  -0.01f,-0.01f,0.00f,-0.01f,0.13f,0.16f,0.16f,0.14f};
	int expectPeaks[100]={0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0};
	int* peaks=new int[21];
	int i=0,dataLen=21;
	for(i=0;i<dataLen;i++){
		peaks[i]=0;
	}
	printArray(macd,dataLen);
	getPeak(macd,peaks,dataLen);
	printArray(peaks,dataLen);
	printArray(expectPeaks,dataLen);
	assertTwoEqual(peaks,expectPeaks,dataLen);
}