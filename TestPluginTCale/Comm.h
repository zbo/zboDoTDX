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
struct macdBlock{
	int start;
	int end;
	float peak;
	float size;
	int spliter;
	float macd;
	int macdIndex;
};

struct MABlock{
	int start;
	int end;
	float peak;
	int index;
	bool valid;
};

struct KX{
	float H;
	float L;
	float C;
	float O;
};

struct KXPassBH{
	float H;
	float L;
	float C;
	float O;
	int index;
};

struct FX{
	float JIDIAN; //��Ϊ�������ֵ��pfOUT����float��һ��warnning (1 or -1)
	int index; //���ؼ�����DataLen�������
	bool valid; //����������֮��û��kxʱ����Ϊ���fx����Ч��
};

int GenKX(int dataln,float* H,float* L,float* O,float* C,KX* kx){
	for(int i=0;i<dataln;i++){
		kx[i].C=C[i];
		kx[i].O=O[i];
		kx[i].L=L[i];
		kx[i].H=H[i];
	}
	return dataln;
}