#include "CalibMesytec.h"
#include <stdio.h>
#include <stdlib.h>
#include "TString.h"

CalibMesytec::CalibMesytec(){
  //CalibMesytec::Class()->IgnoreTObjectStreamer;
  CalibMesytec::Clear();
}

//void CalibMesytec::ReadCalibPar(char* ptr)
//{
//	char *from=line;
//	char *to=line;
//	while (*from) {
//		if (*from>32) {*to=*from;to++;}
//		from++;
//	}
//	*to=0;
//	if (*line==0) return; // line is empty
//	
//	char* val=strchr(line,'=');
//	if (!val) printf("Missing = in input file, line: '%s'\n",line);
//	*val=0;
//	
//	// trim param name
//	char* trm=val-1;
//	while (*trm<=32) *(trm--)=0;
//	
//	val++;
//	if (*val==0) printf("Value missing for parameter %s",line);
//	
//	// parse float parameter (if any)
//	float v;
//	sscanf(val,"%f",&v);
//	if (strcmp(line,"YDD")==0)	Ydd = v;
//	if (strcmp(line,"YDR1")==0)	Yd1r = v;
//	if (strcmp(line,"YDR2")==0)	Yd2r = v;
//	if (strcmp(line,"SD1D")==0)	Sd1d = v;
//	if (strcmp(line,"SD2D")==0)	Sd2d = v;
//	if (strcmp(line,"SDR1")==0)	Sdr1 = v;
//	if (strcmp(line,"SDR2")==0)	Sdr2 = v;
//}

void CalibMesytec::ReadFilenames(char* line)
{
	bool expect_val=true;
	char *from=line;
	char *to=line;
	while (*from) {
		if (*from>32) {*to=*from;to++;}
		from++;
	}
	*to=0;
	if (*line==0) return; // line is empty
	
	char* val=strchr(line,'=');
	if (!val){ 
		val=strchr(line, '!');
		expect_val=false;
	}
	if (!val) printf("Missing = or ! in input file, line: '%s'\n",line);
	*val=0;
	
	// trim param name
	char* trm=val-1;
	while (*trm<=32) *(trm--)=0;
	
	val++;
	if (*val==0 && expect_val) printf("Value missing for parameter %s",line);

	char cval[256];	
	TString strval;
	sscanf(val,"%s",cval);
	strval=cval;
	
	//	parameter of type string:
	if (strcmp(line,"PATH")==0){ 
		installPath = strval;
		fileGeometry = strval;
		fileELoss = strval;
		fileIC = strval;
		fileCsI1 = strval;
		fileCsI2 = strval;
		fileSd1r = strval;
		fileSd1s = strval;
		fileSd2r = strval;
		fileSd2s = strval;
		fileSur = strval;
		fileSus = strval;
		fileYd = strval;
		fileYu = strval;
	}
	if (strcmp(line,"GEOMETRY")==0){
		fileGeometry += strval;
		boolGeometry =kTRUE;
	}
	if (strcmp(line,"ELOSS")==0){
		fileELoss += strval;
		boolELoss =kTRUE;
	}
	if (strcmp(line,"IC")==0){
		fileIC += strval;
		boolIC =kTRUE;
	}
	if (strcmp(line,"CSI1")==0){
		fileCsI1 += strval;
		boolCsI1 =kTRUE;
	}
	if (strcmp(line,"CSI2")==0){
		fileCsI2 += strval;
		boolCsI2 =kTRUE;
	}
	if (strcmp(line,"SD1R")==0){
		fileSd1r += strval;
		boolSd1r =kTRUE;
	}
	if (strcmp(line,"SD1S")==0){
		fileSd1s += strval;
		boolSd1s =kTRUE;
	}
	if (strcmp(line,"SD2R")==0){
		fileSd2r += strval;
		boolSd2r =kTRUE;
	}
	if (strcmp(line,"SD2S")==0){
		fileSd2s += strval;
		boolSd2s =kTRUE;
	}
	if (strcmp(line,"SUR")==0){
		fileSur += strval;
		boolSur =kTRUE;
	}
	if (strcmp(line,"SUS")==0){
		fileSus += strval;
		boolSus =kTRUE;
	}
	if (strcmp(line,"YD")==0){
		fileYd += strval;
		boolYd =kTRUE;
	}
	if (strcmp(line,"YS")==0){
		fileYu += strval;
		boolYu =kTRUE;
	}
	if (strcmp(line,"ASCII")==0){
		boolASCII =kTRUE;
	}
}

void CalibMesytec::Load(TString filename){	

	boolGeometry=kFALSE;
	boolELoss=kFALSE;
	boolIC=kFALSE;
	boolCsI1=kFALSE;
	boolCsI2=kFALSE;
	boolSd1r=kFALSE;
	boolSd1s=kFALSE;
	boolSd2r=kFALSE;
	boolSd2s=kFALSE;
	boolSur=kFALSE;
	boolSus=kFALSE;
	boolYd=kFALSE;
	boolYu=kFALSE;
	boolASCII=kFALSE;

	char line[256];
	FILE* file=fopen(filename.Data(),"rb");
	if (!file)
	{
		printf("Cannot open config file '%s' for reading. Stop.\n",filename.Data());
		exit(0);
	}
	
	printf("Reading config file '%s'\n",filename.Data());
	
	while (!feof(file))
	{
		if (!fgets(line,256,file)) break;
		printf("%s",line);
		// skip leading white spaces
		char* ptr=line;
		while ((*ptr>0) && (*ptr<32)) ptr++;
		//printf("%s\n",ptr[0]);
		switch (ptr[0])
		{
			case 0   :
			case '#' :
			case '/' :  continue;
			default  :  ReadFilenames(ptr);
		}
	}
	fclose(file);
	file=NULL;
}

void CalibMesytec::Print(){
	printf("\n********************************\n");
	printf("** Mesytec calibration files: **\n");
	if(boolGeometry)	printf("Experiment geometry: %s\n",fileGeometry.Data());
	else	printf("No experiment geometry specified.\n");
	if(boolELoss)	printf("Energy loss root file: %s\n",fileELoss.Data());
	else	printf("No energy loss root file specified.\n");
	if(boolIC)	printf("Ionization chamber calibration: %s\n",fileIC.Data());
	else	printf("No ionization chamber calibration specified.\n");
	if(boolCsI1)	printf("CsI1 calibration: %s\n",fileCsI1.Data());
	else	printf("No CsI1 calibration specified.\n");
	if(boolCsI2)	printf("CsI2 calibration: %s\n",fileCsI2.Data());
	else	printf("No CsI2 calibration specified.\n");
	if(boolSd1r)	printf("Sd1r calibration: %s\n",fileSd1r.Data());
	else	printf("No Sd1r calibration specified.\n");
	if(boolSd1s)	printf("Sd1s calibration: %s\n",fileSd1s.Data());
	else	printf("No Sd1s calibration specified.\n");
	if(boolSd2r)	printf("Sd2r calibration: %s\n",fileSd2r.Data());
	else	printf("No Sd2r calibration specified.\n");
	if(boolSd2s)	printf("Sd2s calibration: %s\n",fileSd2s.Data());
	else	printf("No Sd2s calibration specified.\n");
	if(boolSur)	printf("Sur calibration: %s\n",fileSur.Data());
	else	printf("No Sur calibration specified.\n");
	if(boolSus)	printf("Sus calibration: %s\n",fileSus.Data());
	else	printf("No Sus calibration specified.\n");
	if(boolYd)	printf("Yd calibration: %s\n",fileYd.Data());
	else	printf("No Yd calibration specified.\n");
	if(boolYu)	printf("Yu calibration: %s\n",fileYu.Data());
	else	printf("No Yu calibration specified.\n");
	printf("********************************\n\n");
}
void CalibMesytec::Clear(){
}
