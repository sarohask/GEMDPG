
#include "GEMDPG/TrGEMG4/interface/TrGEMPrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4Geantino.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include <TMath.h>
#include <fstream>

TrGEMPrimaryGeneratorAction::TrGEMPrimaryGeneratorAction(char* partName_, G4double energy_) 
	: partName(partName_), energy(energy_)
	{
  	G4int n_particle = 1;
  	G4ParticleDefinition* particlen = G4ParticleTable::GetParticleTable()-> FindParticle(partName);

  	std::string temp = partName;
  	if (temp == "neutron" || temp == "gamma" || temp == "e-" || temp == "e+" || temp == "alpha" || temp == "mu-") angRange = -85.0 ;
  	else throw;

  	fParticleGun  = new G4ParticleGun(particlen,n_particle);
  	
	}

TrGEMPrimaryGeneratorAction::~TrGEMPrimaryGeneratorAction()
	{
  	delete fParticleGun;
	}

void TrGEMPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
	{
  	G4double xxx,yyy;
  	G4double primaryEne;
  	
  	yyy=G4UniformRand();
  	
  	//angle = TMath::Power(10, (yyy-1)*angRange);
  	angle = (yyy-1)*angRange;
	if (angle< 0.5)    G4cout<<"angle...........................= "<<angle<<G4endl;
  	// set direction and angle
  	fParticleGun->SetParticleMomentumDirection((G4ThreeVector(0.,cos((90-angle) * M_PI/180.0),cos(angle * M_PI/180.0))));
  	//fParticleGun->SetParticleMomentumDirection(G4ThreeVector(-1., 0., 0.));

  	//set position  
  	G4double gX = G4UniformRand()*10.-5.;
  	G4double gY = G4UniformRand()*10.-5.;
  	//G4double gX = (gY + 2224.42207)/11.10822 ;
  	fParticleGun->SetParticlePosition(G4ThreeVector(gX,gY,-3.0));
  
  	// set energy
  	fParticleGun->SetParticleEnergy(energy*MeV);
  	
  	//create vertex   
  	fParticleGun->GeneratePrimaryVertex(anEvent);
  	
  	primPDG = fParticleGun->GetParticleDefinition()->GetPDGEncoding() ;
  	primAngle = angle;
  	primPosX = fParticleGun->GetParticlePosition().x() ;
  	primPosY = fParticleGun->GetParticlePosition().y() ;
  	primPosZ = fParticleGun->GetParticlePosition().z() ;
  	//G4cout<<"Primary enrgy 1.............................................................. = "<<primaryEne<<G4endl;
    //G4cout<<"Primary enrgy 2............................................................ = "<<primEnergy<<G4endl;
  	TrGEMAnalysis::GetInstance()->SavePrimary(primAngle, primPDG, primPosX, primPosY, primPosZ);
}

