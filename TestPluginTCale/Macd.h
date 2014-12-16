#include "Comm.h"
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
	for(i=0;i<dataLen;i++)
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

