#ifndef TrGEMAnalysis_h
#define TrGEMAnalysis_h 1

#include "GEMDPG/TrGEMG4/interface/TrGEMHit.hh"

#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include "TH1.h"
#include "snprintf.h"

#include <iostream>
#include <fstream>

#include "globals.hh"
#include <vector>
#include <map>

using namespace std; 

class G4Run;
class G4Event;
class TFile;
class TTree;
class TString;

class TrGEMAnalysis 
	{
		public:
    	static TrGEMAnalysis* GetInstance();
    	~TrGEMAnalysis();
    	
    	void SetFileName(const G4String name);
    	void PrepareNewEvent();
    	void EndOfEvent();
    	void PrepareNewRun();
    	void EndOfRun();
    	void SavePrimary(G4double aPrimAngle, G4int aPrimParticlePDG, G4double aPrimPositionX, G4double aPrimPositionY, G4double aPrimPositionZ);
    	void SetValuesForInteractingEvents ( G4int evtNo, G4int hitTNo, G4int hitNo, TrGEMHit* hit);
    	void SetValuesForNonInteractingEvents(G4int evtNo, G4int hitTNo);
    	void SetKickStart(G4bool aKickstart) ;
    	bool GetKickStart()																										{ return aKickStart ;}
    	//inline void SetNumInteraction (G4int numInter) 												{ aNumInteraction_ = numInter; }
    	//inline G4int GetNumInteraction() 																			{ return aNumInteraction_; }
    	
  	private:
  		TrGEMAnalysis();
			static TrGEMAnalysis* singleton;
		
		public:
    	TFile*    		file;
    	TTree*    		tHits;
    	G4bool 				aKickStart ; 
    	G4int 				eventCounter ;
    	G4String 			fileName;	
    	G4int 				eventID_;
    	G4int 				trackID_;
  		G4int					charge_;	
   		G4int					stepNum_;
   		string		 		volName_;
   		
  		//tEvents  		
  		G4double 					primaryAngle;
  		
	};

#endif 
