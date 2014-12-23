#include "Comm.h"
#include "po.h"
#include <stdlib.h>

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
		else if(kx[nowidx].H>=workingKX[workinglen].H&&kx[nowidx].L<=workingKX[workinglen].L){
			
			float h1=kx[nowidx].H;
			float l1=workingKX[workinglen].L;
			int idx1=kx[nowidx].index;
			copykx(workingKX,workinglen,h1,l1,idx1);
			while(workingKX[workinglen].H>=workingKX[workinglen-1].H&&workingKX[workinglen].L<=workingKX[workinglen-1].L)
			{
				float h2=workingKX[workinglen].H;
				float l2=workingKX[workinglen-1].L;
				int idx2=workingKX[workinglen].index;
				copykx(workingKX,workinglen,h2,l2,idx2);
				workinglen--;
			}
		}
		else{
			workinglen++;
			copykx(workingKX,workinglen,kx,nowidx);
		}
		//if fx chengli
		if(isDing(workingKX,workinglen)){
			fx[dingln].Peak=workingKX[workinglen-1].H;
			fx[dingln].PeakIndex=workingKX[workinglen-1].index;
			fx[dingln].DD=1;
			dingln++;
		}
		nowidx++;
	}
	ding_fx_pogao(fx,dingln,kx,dataln);
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
		else if(kx[nowidx].H>=workingKX[workinglen].H&&kx[nowidx].L<=workingKX[workinglen].L){
			
			float h1=workingKX[workinglen].H;
			float l1=kx[nowidx].L;
			int idx1=kx[nowidx].index;
			copykx(workingKX,workinglen,h1,l1,idx1);
			while(workingKX[workinglen].H>=workingKX[workinglen-1].H&&workingKX[workinglen].L<=workingKX[workinglen-1].L)
			{
				float h2=workingKX[workinglen-1].H;
				float l2=workingKX[workinglen].L;
				int idx2=workingKX[workinglen].index;
				copykx(workingKX,workinglen,h2,l2,idx2);
				workinglen--;
			}
		}
		else{
			workinglen++;
			copykx(workingKX,workinglen,kx,nowidx);
		}
		//if fx chengli
		if(isDi(workingKX,workinglen)){
			fx[diln].Peak=workingKX[workinglen-1].L;
			fx[diln].PeakIndex=workingKX[workinglen-1].index;
			fx[diln].DD=-1;
			diln++;
		}
		nowidx++;
	}
	di_fx_podi(fx,diln,kx,dataln);
	delete []workingKX;
	return diln;
}

int merge_ding_di(FX* fx_ding_di,FX* ding,int dingln,FX* di,int diln){
	int i=0;
	int workingln=0;
	for(i=0;i<diln;i++){
		copyfx(fx_ding_di,workingln,di,i);
		workingln++;
	}
	for(i=0;i<dingln;i++){
		copyfx(fx_ding_di,workingln,ding,i);
		workingln++;
	}
	return diln+dingln;
}

void gen_pfOUT(KXLIST* kxlist,float* pfOUT){
	int i=0,jdln=0;
	int dataln=kxlist[0].len;
	KX* kx=kxlist[0].list;
	FX* fstfx_up_ding=(FX*)malloc(sizeof(FX)*dataln);
	FX* fstfx_up_di=(FX*)malloc(sizeof(FX)*dataln);
	FX* fstfx_down_ding=(FX*)malloc(sizeof(FX)*dataln);
	FX* fstfx_down_di=(FX*)malloc(sizeof(FX)*dataln);
	FX* fx_ding_di=(FX*)malloc(sizeof(FX)*dataln);

	int dingln=find_fx_up_ding(fstfx_up_ding,kx,dataln);
	int diln=find_fx_down_di(fstfx_down_di,kx,dataln);

	int mergeln=merge_ding_di(fx_ding_di,fstfx_up_ding,dingln,fstfx_down_di,diln);

	for(i=0;i<dataln;i++){
		pfOUT[i]=0;
	}
	for(i=0;i<mergeln;i++){
		if(fx_ding_di[i].PeakIndex!=0)
		{
			if(fx_ding_di[i].DD==1)
				pfOUT[fx_ding_di[i].PeakIndex]=1;
			if(fx_ding_di[i].DD==-1)
				pfOUT[fx_ding_di[i].PeakIndex]=-1;
		}
	}
	/*for(i=0;i<dingln;i++){
		if(fstfx_up_ding[i].PeakIndex!=0)
			pfOUT[fstfx_up_ding[i].PeakIndex]=1;
	}
	for(i=0;i<diln;i++){
		if(fstfx_down_di[i].PeakIndex!=0)
			pfOUT[fstfx_down_di[i].PeakIndex]=-1;
	}*/
	delete []fstfx_up_ding;
	delete []fstfx_up_di;
	delete []fstfx_down_ding;
	delete []fstfx_down_di;
	delete []fx_ding_di;
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
