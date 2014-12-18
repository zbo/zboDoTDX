int PutMarkTwentyDay(int DataLen,float* MA,float* Close,int* result){
	int i=0;
	float* tmp=(float*)malloc(DataLen*sizeof(float));
	for(i=0;i<DataLen;i++){
		tmp[i]=Close[i]-MA[i];
		result[i]=0;
	}
	for(i=1;i<DataLen;i++){
		if(tmp[i]==0)result[i]=1;
		if(tmp[i]*tmp[i-1]<0){result[i]=1;result[i-1]=1;}
	}
	delete[] tmp;
	return DataLen;	
}

int GenChartBlock(int DataLen,float* MA,float* Close,int* result,MABlock* blocks){
	int i=0,blockLen=0,count=0,blockStart=0;
	MABlock* tmpBlocks=(MABlock*)malloc(DataLen*sizeof(MABlock));
	for(i=0;i<DataLen;i++){
		if(i==0) continue;
		if(result[i]==1&&result[i-1]!=1){
			tmpBlocks[blockLen].start=blockStart;
			tmpBlocks[blockLen].end=i;
			
			blockLen++;
			blockStart=i;
		}
		else if(i==DataLen-1){
			if(result[blockStart+1]==1){blockStart++;}
			tmpBlocks[blockLen].start=blockStart;
			tmpBlocks[blockLen].end=i;
			blockLen++;
		}
	}
	for(i=0;i<blockLen;i++){
		tmpBlocks[i].valid=true;
		if(tmpBlocks[i].end-tmpBlocks[i].start<3)tmpBlocks[i].valid=false;
	}
	//printArray(result,DataLen);
	//printMABlock(tmpBlocks,blockLen);
	int shortLen=0;
	//ToDo........................................................
	if(blockLen>1){
		for(i=0;i<blockLen;i++){
			if(tmpBlocks[i].valid==false){
				if(i==0) tmpBlocks[i+1].start=tmpBlocks[i].start;
				else if(i==blockLen-1) blocks[shortLen-1].end=tmpBlocks[i].end;
			}
			else{
				blocks[shortLen].end=tmpBlocks[i].end;
				blocks[shortLen].valid=tmpBlocks[i].valid;
				blocks[shortLen].start=tmpBlocks[i].start;
				blocks[shortLen].index=tmpBlocks[i].index;
				shortLen++;
			}
		}
	}
	//printMABlock(blocks,shortLen);
	delete []tmpBlocks;
	return shortLen;
}

void GenChartPoint(int blockln,MABlock* blocks,int dataln,float* close){
	int i=0,j=0,index=0;
	float abspeak=0;
	for(i=0;i<blockln;i++){
		abspeak=0;
		for(j=blocks[i].start;j<=blocks[i].end;j++)
		{	
			//printf("%1.0f ",close[j]);
			if(Abs(close[j])>abspeak)
			{
				abspeak=Abs(close[j]);
				blocks[i].peak=close[j];
				blocks[i].index=j;
			}
		}
		//printf("\n");
	}
	//printMABlock(blocks,blockln);
}

void TestPlugin11(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	float* MA=pfINa;
	float* Close=pfINb;
	int i=0;
	int* result=(int*)malloc(DataLen*sizeof(int));
	//MABlock* blocks=(MABlock*)malloc(DataLen*sizeof(MABlock));
	PutMarkTwentyDay( DataLen, MA, Close, result);
	//int shortLen=GenChartBlock( DataLen, MA, Close, result, blocks);
	//GenChartPoint(shortLen,blocks,DataLen,Close);
	for(i=0;i<DataLen;i++){
		pfOUT[i]=result[i];
	}
	//for(i=0;i<shortLen;i++){
	//	int index=blocks[i].index;
	//	pfOUT[index]=1;
	//}
	delete []result;
	//delete []blocks;
}

void TestPlugin1(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc){
	int i=0;
	for(i=0;i<DataLen;i++){
		pfOUT[i]=i%3;
	}
}