int getDirect(float h1,float l1,float h2, float l2){
	int ret=0;
	if(h1>h2 && l1>l2) ret=-1;
	else if(h1<h2 &&l1<l2) ret=1;
	return ret;
}
bool isBH(float h1,float l1,float h2, float l2){
	if(l2<=l1 && h2>=h1) return true;
	return false;
}
int ProcessBH(int dataln, KX* kx){
	int i=0,direct=0;
	for(i=2;i<dataln;i++){
		direct=getDirect(kx[i-2].H,kx[i-2].L,kx[i-1].H,kx[i-1].L);
		if(isBH(kx[i].H,kx[i].L,kx[i-1].H,kx[i-1].L)==false) continue;
		switch (direct){
		case 1:{
			kx[i-1].L=kx[i].L;
			kx[i].H=kx[i-1].H;
			break;}
		case -1:{
			kx[i-1].H=kx[i].H;
			kx[i].L=kx[i-1].L;	
			break;}
		default:break;
		}
	}
	return dataln;
}

int ProcessFX(int dataln,KX* kx,KXPassBH* kxpsbh){
	int i=0,passln=0;
	for(i=0;i<dataln;i++){
		if(i==0){
			kxpsbh[passln].H=kx[i].H; kxpsbh[passln].L=kx[i].L;
			kxpsbh[passln].O=kx[i].O; kxpsbh[passln].C=kx[i].C;
			kxpsbh[passln].index=i; passln++; continue;
		}
		if(kx[i].H!=kx[i-1].H || kx[i].L!=kx[i-1].L){
			kxpsbh[passln].H=kx[i].H; kxpsbh[passln].L=kx[i].L;
			kxpsbh[passln].O=kx[i].O; kxpsbh[passln].C=kx[i].C;
			kxpsbh[passln].index=i; passln++; continue;
		}
	}
	return passln;
}

int ProcessFXJD(int passln,KXPassBH* kxpsbh,FX* fx){
	int i=0,fxln=0;
	for(i=1;i<passln-1;i++){
		//顶分型
		if(kxpsbh[i].H>kxpsbh[i-1].H && kxpsbh[i].H>kxpsbh[i+1].H &&kxpsbh[i].L>kxpsbh[i-1].L && kxpsbh[i].L>kxpsbh[i+1].L){
			fx[fxln].JIDIAN=1;fx[fxln].index=kxpsbh[i].index;
			fx[fxln].valid=true;
			fxln++;
		}
		//底分型
		if(kxpsbh[i].H<kxpsbh[i-1].H && kxpsbh[i].H<kxpsbh[i+1].H &&kxpsbh[i].L<kxpsbh[i-1].L && kxpsbh[i].L<kxpsbh[i+1].L){
			fx[fxln].JIDIAN=-1;fx[fxln].index=kxpsbh[i].index;
			fx[fxln].valid=true;
			fxln++;
		}
	}
	return fxln;
}

//把不合法的fx标记成false
int ProcessFXValid(int fxln,FX* fx){
	int i=0;
	for(i=0;i<fxln-1;i++){
		if((fx[i+1].index-fx[i].index<3) && fx[i].valid!=false){
			fx[i].valid=false; fx[i+1].valid=false;
		}
	}
	return fxln;
}
//去掉不合法的fx，并且加上头和尾
int ProcessFXPure(int dataln,int fxln,FX* fx,FX* fxpure){
	int i=0,fxpln=0;
	//找出第一个合法的fx是顶还是底
	float firstValidfx=1;
	for(i=0;i<fxln;i++){
		if(fx[i].valid==true){
				firstValidfx=-1*fx[i].JIDIAN;
				fxln++;
				break;
		}
	}
	//把0加到fxpure里
	fxpure[fxpln].index=0;fxpure[fxpln].JIDIAN=firstValidfx;
	fxpure[fxpln].valid=true;fxpln++;
	//把valid的fx加到fxpure里
	for(i=0;i<fxln;i++){
		if(fx[i].valid==true){
			fxpure[fxpln].index=fx[i].index;fxpure[fxpln].JIDIAN=fx[i].JIDIAN;
			fxpure[fxpln].valid=fx[i].valid;fxpln++;
		}
	}
	//把尾加到fxpure里
	fxpure[fxpln].index=dataln;fxpure[fxpln].JIDIAN=fxpure[fxpln-1].JIDIAN*(-1);
	fxpure[fxpln].valid=true;
	return fxpln;
}

void TestPlugin1(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc){
	int i=0;
	KX* kx=(KX*)malloc(DataLen*sizeof(KX));
	KXPassBH* kxpsbh=(KXPassBH*)malloc(DataLen*sizeof(KXPassBH));
	FX* fx=(FX*)malloc(DataLen*sizeof(FX));
	FX* fxpure=(FX*)malloc(DataLen*sizeof(FX));
	for(i=0;i<DataLen;i++){
		kx[i].H=pfINa[i];
		kx[i].L=pfINb[i];
	}
	ProcessBH(DataLen,kx);
	int passln=ProcessFX(DataLen,kx,kxpsbh);
	//find fx
	int fxln=ProcessFXJD(passln,kxpsbh,fx);
	int fxpassln=ProcessFXValid(fxln,fx);
	int fxpureln=ProcessFXPure(DataLen,fxpassln,fx,fxpure);
	for(i=0;i<DataLen;i++){
		pfOUT[i]=0;
	}
	for(i=0;i<fxpureln;i++){
		pfOUT[fxpure[i].index]=fxpure[i].JIDIAN;
		//pfOUT[fx[i].index]=fx[i].JIDIAN;
	}
	delete []kx;
	delete []kxpsbh;
	delete []fx;
	delete []fxpure;
}