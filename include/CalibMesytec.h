// CalibMesytec.h

#ifndef CalibMesytec_H
#define CalibMesytec_H
#include <TObject.h>
#include <TClass.h>
#include <string>

//Extern
//extern int gMesytecnitems;
class CalibMesytec : public TObject {
	public:
		CalibMesytec(); 
		virtual ~CalibMesytec() {} //! 

		std::string installPath;
		std::string fileGeometry;
		std::string fileELoss;
		std::string fileIC;
		std::string fileTr;
		std::string fileCsI1;
		std::string fileCsI2;
		std::string fileSd1r;
		std::string fileSd1s;
		std::string fileSd2r;
		std::string fileSd2s;
		std::string fileSur;
		std::string fileSus;
		std::string fileYd;
		std::string fileYu;
		std::string fileZdx;
		std::string fileZdy;
		std::string fileTCorrIC;
		std::string fileTCorrSi;

		Bool_t boolGeometry;
		Bool_t boolELoss;
		Bool_t boolIC;
		Bool_t boolTr;
		Bool_t boolCsI1;
		Bool_t boolCsI2;
		Bool_t boolSd1r;
		Bool_t boolSd1s;
		Bool_t boolSd2r;
		Bool_t boolSd2s;
		Bool_t boolSur;
		Bool_t boolSus;
		Bool_t boolYd;
		Bool_t boolYu;
		Bool_t boolZdx;
		Bool_t boolZdy;
		Bool_t boolTCorrIC;
		Bool_t boolTCorrSi;

		virtual void ReadFilenames(char* line);
		virtual void Load(std::string filename);
		virtual void Print();
		virtual void Clear();
//		ClassDef(CalibMesytec,1)
};

#endif
// end
