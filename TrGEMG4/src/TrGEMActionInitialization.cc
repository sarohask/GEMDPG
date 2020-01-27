
#include "GEANT4_Simulation_Code/TrGEMG4/interface/TrGEMActionInitialization.hh"
#include "GEANT4_Simulation_Code/TrGEMG4/interface/TrGEMPrimaryGeneratorAction.hh"
#include "GEANT4_Simulation_Code/TrGEMG4/interface/TrGEMRunAction.hh"
#include "GEANT4_Simulation_Code/TrGEMG4/interface/TrGEMEventAction.hh"
#include "GEANT4_Simulation_Code/TrGEMG4/interface/TrGEMSteppingAction.hh"
#include "GEANT4_Simulation_Code/TrGEMG4/interface/TrGEMStackingAction.hh"
#include "GEANT4_Simulation_Code/TrGEMG4/interface/TrGEMTrackingAction.hh"

#include "G4String.hh"

TrGEMActionInitialization::TrGEMActionInitialization(char* particleName)
	: G4VUserActionInitialization(), partName(particleName)
	{}

TrGEMActionInitialization::~TrGEMActionInitialization()
	{}

void TrGEMActionInitialization::BuildForMaster() const 
	{
  	TrGEMRunAction* runAction = new TrGEMRunAction;
		SetUserAction(runAction);
	}

void TrGEMActionInitialization::Build() const 
	{
  	SetUserAction(new TrGEMPrimaryGeneratorAction(partName));
	
  	TrGEMRunAction* runAction = new TrGEMRunAction;
  	SetUserAction(runAction);

  	TrGEMEventAction* eventAction = new TrGEMEventAction();
  	SetUserAction(eventAction);

  	TrGEMSteppingAction* steppingAction = new TrGEMSteppingAction();
  	SetUserAction(steppingAction);

  	TrGEMStackingAction* stackingAction = new TrGEMStackingAction();
  	SetUserAction(stackingAction);
  
  	TrGEMTrackingAction* trackingAction = new TrGEMTrackingAction();
  	SetUserAction(trackingAction);
	}
