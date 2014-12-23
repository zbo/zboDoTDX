float Abs(float in){
	if(in>=0) return in;
	else return in*(-1);
}

void CopyTo(int* from,int* to,int dataLen){
	for(int i=0;i<dataLen;i++){
		to[i]=from[i];
	}
}

void CopyTo(float* from,float* to,int dataLen){
	for(int i=0;i<dataLen;i++){
		to[i]=from[i];
	}
}


/*data structure*/


struct KX{
	float H;
	float L;
	int index;
};

struct KXLIST{
	KX* list;
	int start;
	int len;
};

struct FX{
	KXLIST left;
	KXLIST mid;
	KXLIST right;
	KX leftBH;
	KX rightBH;
	KX midBH;
	int BH;//生成fx用的包含方式
	int DD;//顶分型还是底分型
	float Peak;
	int PeakIndex;
};

struct JD{
	int idx;
	int DD;
};

struct JDLIST{
	JD* list;
	int len;
}; 
int GenKX(int dataln,float* H,float* L,KX* kx){
	for(int i=0;i<dataln;i++){
		kx[i].L=L[i];
		kx[i].H=H[i];
		kx[i].index=i;
	}
	return dataln;
}

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
void copyfx(FX* workingFX,int workinglen,FX* fx,int index){
	workingFX[workinglen].DD=fx[index].DD;
	workingFX[workinglen].Peak=fx[index].Peak;
	workingFX[workinglen].PeakIndex=fx[index].PeakIndex;
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