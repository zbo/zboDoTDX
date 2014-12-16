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