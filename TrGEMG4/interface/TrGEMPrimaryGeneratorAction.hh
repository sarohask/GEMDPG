
#ifndef TrGEMPrimaryGeneratorAction_h
#define TrGEMPrimaryGeneratorAction_h 1

#include "GEMDPG/TrGEMG4/interface/TrGEMAnalysis.hh"

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

using namespace std;

class G4Event;

class TrGEMPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
	{
  	public:
    	TrGEMPrimaryGeneratorAction(char*, G4double ener);        
    	~TrGEMPrimaryGeneratorAction();

  	public:
    	virtual void GeneratePrimaries(G4Event*);
    	G4ParticleGun* GetParticleGun() { return fParticleGun;} ;
            
  	private:
    	char*           		partName;
    	G4double						energy;
    	G4double						angle;
    	G4ParticleGun*  		fParticleGun;
    	G4int           		fixedEnergy;
    	G4double						angRange;
    	G4int           		primPDG;
    	G4double						primAngle ;
    	G4double						primPosX ;
    	G4double						primPosY ;
    	G4double						primPosZ ;
    	vector<G4double> 		cdf;
    	vector<G4double> 		ene;
	};

#endif
