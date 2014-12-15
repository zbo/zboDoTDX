#include "../Macd.h"
void printArray(float* array,int dataLen){
	for(int i=0;i<dataLen;i++){
		printf("%1.0f ",array[i]);
	}
	printf("\n");
}

void printArray(int* array,int dataLen){
	for(int i=0;i<dataLen;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

void test1MacdPeak(){
	printf("===start macd get peak test====!\n");
	float macd[16] = {1,2,3,4,5,6,5,4,3,2,1,0,-1,-2,1,2};
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
}