#include "stdafx.h"
#include "TCalcFuncSets.h"
#include "Macd.h"
#include "TwentyDay.h"
#include "BH.h"

//生成的dll及相关依赖dll请拷贝到通达信安装目录的T0002/dlls/下面,再在公式管理器进行绑定

void TestPlugin2(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	float* dea=pfINa;
	float* dif=pfINb;
	int* peakIndex=new int[DataLen];
	float* macd=new float[DataLen];
	int i=0;
	for(i=0;i<DataLen;i++){
		pfOUT[i]=0;
		peakIndex[i]=0;
		macd[i]=2*(dea[i]-dif[i]);
	}
	getPeak(macd,peakIndex,DataLen);
	for(i=0;i<DataLen;i++){
		pfOUT[i]=peakIndex[i];
	}
	delete []macd;
	delete []peakIndex;
}


//加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&TestPlugin1},
	{2,(pPluginFUNC)&TestPlugin2},
	{3,(pPluginFUNC)&macd_plugin},
	{0,NULL},
};

//导出给TCalc的注册函数
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
	if(*pFun==NULL)
	{
		(*pFun)=g_CalcFuncSets;
		return TRUE;
	}
	return FALSE;
}
