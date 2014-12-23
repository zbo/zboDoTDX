int ding_fx_pogao(FX* fx,int fxln,KX* kx,int dataln){
	int i=0;
	for(i=0;i<fxln;i++){
		int idx=fx[i].PeakIndex;
		float peak=fx[i].Peak;//gao dian
		if(idx+2>dataln-1) continue;
		if(kx[idx+2].H>peak)
		{
			fx[i].PeakIndex=0;
		}
	}
	return fxln;
}
int di_fx_podi(FX* fx,int fxln,KX* kx,int dataln){
	int i=0;
	for(i=0;i<fxln;i++){
		int idx=fx[i].PeakIndex;
		float peak=fx[i].Peak;//di dian
		if(idx+2>dataln-1) continue;
		if(kx[idx+2].L<peak)
		{
			fx[i].PeakIndex=0;
		}
	}
	return fxln;
}