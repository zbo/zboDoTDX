#include "Comm.h"
#include <stdlib.h>

int findPeak(int last,int now,float* macd){
	int peak=last;
	for(int i=last;i<=now;i++){
		if(Abs(macd[i])>Abs(macd[peak])){
			peak=i;
		}
	}
	return peak;
}

void getPeak(float* macd,int*peaks,int dataLen){
	int i,last=0;
	for(i=1;i<dataLen;i++)
	{
		if(macd[i]*macd[i-1]<0 || macd[i]==0)
		{
			int now=i;
			int peak=0;
			peak=findPeak(last,now,macd);
			peaks[peak]=1;
			last=now;
		}
	}
	for(i=0;i<dataLen;i++){
		if(macd[i]==0) {
			peaks[i]=0;
			if(i>0)peaks[i-1]=0;
			if(i<dataLen-1)peaks[i+1]=0;
		}
		if(macd[i]*macd[i-1]<0){
			peaks[i]=0;
			peaks[i-1]=0;
		}
	}
}

int getMacdPieces(float* macd,int* pieces,int dataLen){
	pieces[0]=0;
	for(int i=1;i<dataLen;i++){
		if(macd[i]==0) pieces[i]=1;
		else if(macd[i]*macd[i-1]<0){pieces[i]=1;pieces[i-1]=1;} 
		else pieces[i]=0;
	}
	return dataLen;
}

int getMacdBlocks(float* macd,macdBlock* blocks,int dataLen){
	int blockLen=0,i=0,blockIndex=0,start=0,peakIndex=0;
	float abspeak=0;
	float size=0;
	int* pieces=new int[dataLen];
	getMacdPieces(macd,pieces,dataLen);
	//¼ÆËãstart end size
	for(i=0;i<dataLen;i++){
		size=size+macd[i];
		if(Abs(macd[i])>abspeak){
			abspeak=Abs(macd[i]);
			peakIndex=i;
		}
		if(pieces[i]==1&&pieces[i-1]!=1){
			blocks[blockIndex].size=size;
			blocks[blockIndex].end=i;
			blocks[blockIndex].start=start;
			blocks[blockIndex].peak=macd[peakIndex];
			blocks[blockIndex].macdIndex=peakIndex;
			size=0;
			peakIndex=0;
			abspeak=0;
			blockIndex++;
		}
		if(pieces[i]!=1&&pieces[i-1]==1){
			start=i;
		}	
	}
	//¸³Öµmacd
	for(i=0;i<dataLen;i++){
		blocks[i].spliter=pieces[i];
		blocks[i].macd=macd[i];
	}
	return blockLen;
}

//plug functions
void macd_plugin(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	float* dea=pfINa;
	float* dif=pfINb;
	float* macd=new float[DataLen];
	for(int i=0;i<DataLen;i++){
		macd[i]=2*(dea[i]-dif[i]);
		pfOUT[i]=macd[i];
	}
	macdBlock* blocks=(macdBlock*)malloc(DataLen*sizeof(macdBlock));
	getMacdBlocks(macd,blocks,DataLen);
	delete []macd;
}


