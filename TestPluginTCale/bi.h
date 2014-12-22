#include "Comm.h"
#include <stdlib.h>
void copykx(KX* workingKX,int workinglen,KX* kx,int nowidx){
	workingKX[workinglen].H=kx[nowidx].H;
	workingKX[workinglen].L=kx[nowidx].L;
	workingKX[workinglen].index=kx[nowidx].index;
}
void copykx(KX* workingKX,int workinglen,float H,float L,int idx){
	workingKX[workinglen].H=H;
	workingKX[workinglen].L=L;
	workingKX[workinglen].index=idx;
}
bool isDing(KX* workingKX, int workinglen){
	if(workinglen>=2){
		bool con1=workingKX[workinglen].H<workingKX[workinglen-1].H&&workingKX[workinglen].L<workingKX[workinglen-1].L;
		bool con2=workingKX[workinglen-2].H<workingKX[workinglen-1].H&&workingKX[workinglen-2].L<workingKX[workinglen-1].L;
		if(con1&&con2){
			return true;
		}
	}
	return false;
}
bool isDi(KX* workingKX, int workinglen){
	if(workinglen>=2){
		bool con1=workingKX[workinglen].H>workingKX[workinglen-1].H&&workingKX[workinglen].L>workingKX[workinglen-1].L;
		bool con2=workingKX[workinglen-2].H>workingKX[workinglen-1].H&&workingKX[workinglen-2].L>workingKX[workinglen-1].L;
		if(con1&&con2){
			return true;
		}
	}
	return false;
}

void initFX(FX* fx){
	fx[0].BH=1;
	fx[0].DD=1;
	fx[0].PeakIndex=0;
	fx[0].Peak=0;
}
void find_fx_up_di(FX* fx,KX* kx,int dataln){
	int nowidx=2;
	initFX(fx);
	while(nowidx<dataln){
		fx[0].PeakIndex=dataln-1;
		return;
	}
}
void find_fx_down_ding(FX* fx,KX* kx,int dataln){
	int nowidx=2;
	initFX(fx);
	while(nowidx<dataln){
		fx[0].PeakIndex=dataln-3;
		return;
	}
}
int find_fx_up_ding(FX* fx,KX* kx,int dataln){
	KX* workingKX=(KX*)malloc(sizeof(KX)*dataln);
	copykx(workingKX,0,kx,0);
	initFX(fx);
	int nowidx=1;
	int workinglen=0;
	int dingln=0;
	while(nowidx<dataln){
		if(kx[nowidx].H<=workingKX[workinglen].H&&kx[nowidx].L>=workingKX[workinglen].L)//bh
		{
			float h1=workingKX[workinglen].H;
			float l1=kx[nowidx].L;
			int idx1=workingKX[workinglen].index;
			copykx(workingKX,workinglen,h1,l1,idx1);
		}
		else{
			workinglen++;
			copykx(workingKX,workinglen,kx,nowidx);
		}
		//if fx chengli
		if(isDing(workingKX,workinglen)){
			fx[dingln].PeakIndex=workingKX[workinglen-1].index;
			dingln++;
		}
		nowidx++;
	}
	delete []workingKX;
	return dingln;
}

int find_fx_down_di(FX* fx,KX* kx,int dataln){
	KX* workingKX=(KX*)malloc(sizeof(KX)*dataln);
	copykx(workingKX,0,kx,0);
	initFX(fx);
	int nowidx=1;
	int workinglen=0;
	int diln=0;
	while(nowidx<dataln){
		if(kx[nowidx].H<=workingKX[workinglen].H&&kx[nowidx].L>=workingKX[workinglen].L)//bh
		{
			float h1=kx[nowidx].H;
			float l1=workingKX[workinglen].L;
			int idx1=workingKX[workinglen].index;
			copykx(workingKX,workinglen,h1,l1,idx1);
		}
		else{
			workinglen++;
			copykx(workingKX,workinglen,kx,nowidx);
		}
		//if fx chengli
		if(isDi(workingKX,workinglen)){
			fx[diln].PeakIndex=workingKX[workinglen-1].index;
			diln++;
		}
		nowidx++;
	}
	delete []workingKX;
	return diln;
}
void gen_pfOUT(KXLIST* kxlist,float* pfOUT){
	int i=0,jdln=0;
	int dataln=kxlist[0].len;
	KX* kx=kxlist[0].list;
	FX* fstfx_up_ding=(FX*)malloc(sizeof(FX)*dataln);
	FX* fstfx_up_di=(FX*)malloc(sizeof(FX)*dataln);
	FX* fstfx_down_ding=(FX*)malloc(sizeof(FX)*dataln);
	FX* fstfx_down_di=(FX*)malloc(sizeof(FX)*dataln);
	
	int dingln=find_fx_up_ding(fstfx_up_ding,kx,dataln);
	//find_fx_up_di(fstfx_up_di,kx,dataln);
	//find_fx_down_ding(fstfx_down_ding,kx,dataln);
	int diln=find_fx_down_di(fstfx_down_di,kx,dataln);
	for(i=0;i<dataln;i++){
		pfOUT[i]=0;
	}
	for(i=0;i<dingln;i++){
		if(fstfx_up_ding[i].PeakIndex!=0)
			pfOUT[fstfx_up_ding[i].PeakIndex]=1;
	}
	//if(fstfx_down_ding[0].PeakIndex!=0)
	//	pfOUT[fstfx_down_ding[0].PeakIndex]=1;
	//if(fstfx_up_di[0].PeakIndex!=0)
	//	pfOUT[fstfx_up_di[0].PeakIndex]=-1;
	for(i=0;i<diln;i++){
		if(fstfx_down_di[i].PeakIndex!=0)
			pfOUT[fstfx_down_di[i].PeakIndex]=-1;
	}
	delete []fstfx_up_ding;
	delete []fstfx_up_di;
	delete []fstfx_down_ding;
	delete []fstfx_down_di;
}
void Plugin_BI(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	int i=0;
	KX* kx=(KX*)malloc(DataLen*sizeof(KX));
	for(i=0;i<DataLen;i++){
		kx[i].H=pfINa[i];
		kx[i].L=pfINb[i];
		kx[i].index=i;
	}
	KXLIST* kxlist=(KXLIST*)malloc(sizeof(KXLIST));
	kxlist[0].list=kx;
	kxlist[0].len=DataLen;
	kxlist[0].start=0;
	gen_pfOUT(kxlist,pfOUT);
	delete []kx;
	delete []kxlist;
}
