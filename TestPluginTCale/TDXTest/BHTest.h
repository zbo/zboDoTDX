#include "../BH.h"

void bh_test1(){
	printf("start test1!\n");
	float high[10]={10,11,12,11,10,10,10,10,10,10};
	float low[10]={5,6,7,8,5,5,5,5,5,5};
	float open[10]={0,0,0,0,0,0,0,0,0,0};
	float close[10]={0,0,0,0,0,0,0,0,0,0};
	KX* kx=(KX*)malloc(sizeof(KX)*10);
	int dataln=GenKX(10,high,low,open,close,kx);
	//printKX(dataln,kx);
	ProcessBH(dataln,kx);
	//printKX(dataln,kx);
	if(kx[3].H==12&&kx[3].L==8&&kx[2].H==12&&kx[3].L==8) {printf("process BH succeed\n");}
	else{printf("process BH failed\n");}
	KXPassBH* kxpsbh=(KXPassBH*)malloc(10*sizeof(KXPassBH));	
	int passln=ProcessFX(10,kx,kxpsbh);
	printKXPass(passln,kxpsbh);
	delete []kxpsbh;
}

void bh_test2(){
	printf("start test2 test FX!\n");
	float high[10]={3,4,5,6,7,6,5,4,3,4};
	float low[10]={1,2,3,4,5,4,3,2,1,2};
	float open[10]={0,0,0,0,0,0,0,0,0,0};
	float close[10]={0,0,0,0,0,0,0,0,0,0};
	KX* kx=(KX*)malloc(sizeof(KX)*10);
	int dataln=GenKX(10,high,low,open,close,kx);
	ProcessBH(dataln,kx);
	printKX(dataln,kx);
	KXPassBH* kxpsbh=(KXPassBH*)malloc(10*sizeof(KXPassBH));
	int passln=ProcessFX(10,kx,kxpsbh);
	printKXPass(passln,kxpsbh);
	FX* fx=(FX*)malloc(10*sizeof(FX));
	int fxln=ProcessFXJD(passln,kxpsbh,fx);
	printFX(fxln,fx);
	int fxpassln=ProcessFXValid(fxln,fx);
	printFX(fxln,fx);
	delete []fx;
	delete []kxpsbh;
}

void bh_test3_invalid_fx(){
	printf("start test2 test FX!\n");
	float high[10]={3,4,5,4,3,4,5,6,5,4};
	float low[10]={1,2,3,2,1,2,3,4,3,2};
	float open[10]={0,0,0,0,0,0,0,0,0,0};
	float close[10]={0,0,0,0,0,0,0,0,0,0};
	KX* kx=(KX*)malloc(sizeof(KX)*10);
	FX* fx=(FX*)malloc(10*sizeof(FX));
	FX* fxpure=(FX*)malloc(10*sizeof(FX));
	KXPassBH* kxpsbh=(KXPassBH*)malloc(10*sizeof(KXPassBH));

	int dataln=GenKX(10,high,low,open,close,kx);
	ProcessBH(dataln,kx);
	printKX(dataln,kx);
	
	int passln=ProcessFX(10,kx,kxpsbh);
	printKXPass(passln,kxpsbh);
	
	int fxln=ProcessFXJD(passln,kxpsbh,fx);
	printFX(fxln,fx);
	int fxpassln=ProcessFXValid(fxln,fx);
	printFX(fxln,fx);
	int fxpureln=ProcessFXPure(10,fxpassln,fx,fxpure);
	printFX(fxpureln,fxpure);
	delete []fx;
	delete []fxpure;
	delete []kxpsbh;
	delete []kx;
}

void bh_test4_bug1(){
	printf("fix bug for szzs year!\n");
	float high[25]={127,202,1429,1558,1052,
					926.41f,1258,1510,1422.97f,1756.81f,
					2125.72f,2245.43f,1748.89f,1649.60f,1783.01f,
					1328.53f,2698.90f,6124.04f,5522.78f,3478.01f,
					3306.75f,3067.46f,2478.38f,2444.8f,3091.32
					};
	float low[25]={95.79f,104.96f,292.76f,750.46f,325.89f,
					524.43f,512.83f,870.18f,1043.02f,1047.83f,
					1361.21f,1514.86f,1339.20f,1307.40f,1259.43f,
					998.23f,1161.91f,2541.52f,1664.93f,1844.09f,
					2319.74f,2132.02f,1949.46f,1849.65f,1974.38
					};
	float open[25]={0,0,0,0,0,0,0,0,0,0};
	float close[25]={0,0,0,0,0,0,0,0,0,0};

	KX* kx=(KX*)malloc(sizeof(KX)*25);
	FX* fx=(FX*)malloc(25*sizeof(FX));
	FX* fxpure=(FX*)malloc(25*sizeof(FX));
	KXPassBH* kxpsbh=(KXPassBH*)malloc(25*sizeof(KXPassBH));

	int dataln=GenKX(25,high,low,open,close,kx);
	ProcessBH(dataln,kx);
	printf("after ProcessBH\n");
	printKX(dataln,kx);
	
	int passln=ProcessFX(25,kx,kxpsbh);
	printf("after ProcessFX\n");
	printKXPass(passln,kxpsbh);
	
	int fxln=ProcessFXJD(passln,kxpsbh,fx);
	printFX(fxln,fx);
	int fxpassln=ProcessFXValid(fxln,fx);
	printFX(fxln,fx);
	int fxpureln=ProcessFXPure(25,fxpassln,fx,fxpure);
	printFX(fxpureln,fxpure);

	delete []fx;
	delete []fxpure;
	delete []kxpsbh;
	delete []kx;
}

void bh_test_entrance()
{
	printf("start bh tests!\n");
	//bh_test1();
	//bh_test2();
	//bh_test3_invalid_fx();
	bh_test4_bug1();
}