void printArray(float* array,int dataLen){
	for(int i=0;i<dataLen;i++){
		printf("%1.0f ",array[i]);
	}
	printf("\n");
}

void printArray(int* array,int dataLen){
	for(int i=0;i<dataLen;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

void assertTwoEqual(int* array1, int* array2, int dataLen){
	bool succeed=true;
	for(int i=0;i<dataLen;i++){
		if(array1[i]!=array2[i])
		{
			succeed=false;
			break;
		}
	}
	printf("test result is %d\n",succeed);
}

void assertTwoEqual(float* array1, float* array2, int dataLen){
	bool succeed=true;
	for(int i=0;i<dataLen;i++){
		if(array1[i]!=array2[i])
		{
			succeed=false;
			break;
		}
	}
	printf("test result is %d\n",succeed);
}

void printMacdBlocks(macdBlock* blocks,int dataLen){
	printf("print blocks \n");
	for(int i=0;i<dataLen;i++){
		printf("start %d ",blocks[i].start);
		printf("end %d ",blocks[i].end);
		printf("peak %1.1f ",blocks[i].peak);
		printf("size %1.1f ",blocks[i].size);
		printf("spliter %d ",blocks[i].spliter);
		printf("macd %1.1f ",blocks[i].macd);
		printf("mIndex %d ",blocks[i].macdIndex);
		printf("\n");
	}
}