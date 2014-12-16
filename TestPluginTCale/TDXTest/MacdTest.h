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

void assertTwoEqual(int* array1, int* array2, int dataLen){
	bool succeed=true;
	for(int i=0;i<dataLen;i++){
		if(array1[i]!=array2[i])
		{
			succeed=false;
			break;
		}
	}
	printf("test result is %d\n",succeed);
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
	float macd[21] = {-0.04,-0.01,0.07,0.09,0.07,0.06,0.06,0.03,0.01,-0.01,-0.02,-0.03,-0.03,-0.01,-0.01,0.00,-0.01,0.13,0.16,0.16,0.14};
	int expectPeaks[100]={0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
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