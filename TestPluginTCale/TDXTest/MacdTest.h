#include "../Macd.h"
#include "TestCommon.h"

void test1MacdPeak(){
	printf("===start macd test1MacdPeak====!\n");
	float macd[16] = {1,2,3,4,5,6,5,4,3,2,1,0,-1,-2,1,2};
	int expectPeaks[16]={0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
	int* peaks=new int[16];
	int i=0,dataLen=16;
	for(i=0;i<dataLen;i++){
		peaks[i]=0;
	}
	//printArray(macd,dataLen);
	getPeak(macd,peaks,dataLen);
	//printArray(peaks,dataLen);
	//printArray(expectPeaks,dataLen);
	assertTwoEqual(peaks,expectPeaks,dataLen);
}

void test2MacdPeak(){
	printf("===start macd test2MacdPeak====!\n");
	float macd[16] = {-1,-2,-3,-4,-5,-6,-1,0,0,0,0,0,1,2,1,0};
	int expectPeaks[16]={0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0};
	int* peaks=new int[16];
	int i=0,dataLen=16;
	for(i=0;i<dataLen;i++){
		peaks[i]=0;
	}
	//printArray(macd,dataLen);
	getPeak(macd,peaks,dataLen);
	//printArray(peaks,dataLen);
	//printArray(expectPeaks,dataLen);
	assertTwoEqual(peaks,expectPeaks,dataLen);
}

void test3MacdPeak(){
	printf("===start macd test3MacdPeak====!\n");
	float macd[21] = {-0.04f,-0.01f,0.07f,0.09f,0.07f,0.06f,
					   0.06f,0.03f,0.01f,-0.01f,-0.02f,-0.03f,-0.03f,
					  -0.01f,-0.01f,0.00f,-0.01f,0.13f,0.16f,0.16f,0.14f};
	int expectPeaks[100]={0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0};
	int* peaks=new int[21];
	int i=0,dataLen=21;
	for(i=0;i<dataLen;i++){
		peaks[i]=0;
	}
	//printArray(macd,dataLen);
	getPeak(macd,peaks,dataLen);
	//printArray(peaks,dataLen);
	//printArray(expectPeaks,dataLen);
	assertTwoEqual(peaks,expectPeaks,dataLen);
}

void test4MacdGetBlock(){
	printf("===start macd test4MacdGetBlock====!\n");
	int dataLen=16;
	float macd[16] = {1,2,3,4,5,6,5,4,3,2,1,0,-1,-2,-1,0};
	macdBlock blocks[16]={0};
	int len=getMacdBlocks(macd,blocks,dataLen);
	printMacdBlocks(blocks,dataLen);
	float array1[3]={blocks[0].size,blocks[1].size,blocks[2].size};
	float excepted[3]={36,-4,0};
	assertTwoEqual(array1,excepted,3);
}

void test5MacdGetPiece(){
	printf("===start macd test5MacdGetPiece====!\n");
	float macd[16] = {1,2,3,4,5,6,5,4,3,2,1,0,-1,-2,-1,0};
	int expectPieces[16]={0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1};
	int* pieces=new int[16];
	int i=0,dataLen=16;
	for(i=0;i<dataLen;i++){
		pieces[i]=0;
	}
	//printArray(macd,dataLen);
	getMacdPieces(macd,pieces,dataLen);
	//printArray(pieces,dataLen);
	//printArray(expectPieces,dataLen);
	assertTwoEqual(pieces,expectPieces,dataLen);
}

void test6MacdGetPiece(){
	printf("===start macd test6MacdGetPiece====!\n");
	float macd[16] = {1,2,3,4,5,6,5,4,3,2,1,2,-1,-2,-1,0};
	int expectPieces[16]={0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1};
	int* pieces=new int[16];
	int i=0,dataLen=16;
	for(i=0;i<dataLen;i++){
		pieces[i]=0;
	}
	//printArray(macd,dataLen);
	getMacdPieces(macd,pieces,dataLen);
	//printArray(pieces,dataLen);
	//printArray(expectPieces,dataLen);
	assertTwoEqual(pieces,expectPieces,dataLen);
}