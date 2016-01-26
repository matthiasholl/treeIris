//IDet.cxx
//#include "TObject.h"
//#include "TClass.h"
#include "IDet.h"
#include <math.h>
//ClassImp(IDet);
IDet::IDet(){
  //IDet::Class()->IgnoreTObjectStreamer;
  IDet::Clear();
}

void IDet::Clear()
{
  //  TEfull=0;
  	TYdMul=0;  
  	for(int i=0;i<128;i++){
		TYdEnergy[i]=0.;
  		TYdTheta[i]=0.;// Yd theta angle                                                                       
		TYdChannel[i]=-1;
		TYdNo[i]=-1;
		TYdRing[i]=-1;
	}
	TCsI1Mul=0;
	TCsI2Mul=0;
	for(int i=0;i<16;i++){
		TCsIEnergy[i]=0;
  		TCsI1Energy[i]=0;
  		TCsI2Energy[i]=0;
  		TCsIEnergy[i]=0;
  		TCsI1ADC[i]=0;
  		TCsI2ADC[i]=0;
		TCsIChannel[i]=-1;
		TCsI1Channel[i]=-1;
		TCsI2Channel[i]=-1;
	}

   	TICEnergy=0;
	TICChannel=-1;

	TSd1rMul=0;
	TSd1sMul=0;
	TSd2rMul=0;
	TSd2sMul=0;
  	TSdETot=0;
  	TSdThetaCM=0;
	for(int i=0;i<32;i++){
  		TSd1rEnergy[i]=0;
		TSd1rChannel[i]=-1;
  		TSd1sEnergy[i]=0;
		TSd1sChannel[i]=-1;
  		TSd1sADC[i]=0;
  		TSd2rEnergy[i]=0;
		TSd2rChannel[i]=-1;
  		TSd2rADC[i]=0;
  		TSd2sEnergy[i]=0;
		TSd2sChannel[i]=-1;
  		TSd2sADC[i]=0;
  		TSdTheta[i]=0;
  		TSdPhi[i]=0;
	}
// 	TSd2rEnergy2=0;
// 	TSd2sEnergy2=0;
// 	TSd2rEnergyCal=0;
// 	TSd1rEnergy2=0;
// 	TSd1sEnergy2=0;
  	SSB=0;
  	TQv1=0; // Q-value  
  	TQv2=0; // Q-value
  	QValue1=sqrt(-1.);//Not a number (nan) AS
  	QValue2=sqrt(-1.);//                                                                                
  	QValue=sqrt(-1.);//                                                                                
  	TBE=0; //Beam energy                                                                             
  	TIC03=0;
  	TIC07=0;
  	TIC11=0;
  	TIC15=0;
//  TTime=0;
//  TtRef=0;
	
	//TYdChannel2=-1;

	//TSd2rChannel2=-1;
	//TSd2sChannel2=-1;
	//TSd1rChannel2=-1;
	//TSd1sChannel2=-1;
}

