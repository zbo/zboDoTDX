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