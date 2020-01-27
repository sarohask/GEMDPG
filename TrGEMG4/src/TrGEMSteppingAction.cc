
#include "/TrGEMG4/interface/TrGEMSteppingAction.hh"
#include "/TrGEMG4/interface/TrGEMAnalysis.hh"

#include "G4SteppingManager.hh"
#include "G4TouchableHistory.hh"
#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4HCtable.hh"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"
#include <string>
#include <sstream>
#include <iostream>

TrGEMSteppingAction::TrGEMSteppingAction() 
	: G4UserSteppingAction(), stepManager(0)
	{}

TrGEMSteppingAction::~TrGEMSteppingAction() 
	{}
	
void TrGEMSteppingAction::SetSteppingManagerPointer(G4SteppingManager *stepManager)
	{}

void TrGEMSteppingAction::UserSteppingAction(const G4Step* aStep)
	{}


