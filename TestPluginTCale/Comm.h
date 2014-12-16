float Abs(float in){
	if(in>=0) return in;
	else return in*(-1);
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