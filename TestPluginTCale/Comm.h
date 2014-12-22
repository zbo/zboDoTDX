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