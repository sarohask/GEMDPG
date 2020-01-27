
#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"
#include "FTFP_BERT_HP.hh"
#include "QGSP_BERT.hh"
// #include "TROOT.h"
#include "G4EmLivermorePhysics.hh"
#include "G4VModularPhysicsList.hh"
#include "G4RadioactiveDecayPhysics.hh"

#ifdef G4UI_USE
#include "G4VisExecutive.hh"
#endif
#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include "G4VisExecutive.hh"

#include "/TrGEMG4/interface/TrGEMDetectorConstruction.hh"
#include "/TrGEMG4/interface/TrGEMActionInitialization.hh"
#include "/TrGEMG4/interface/TrGEMAnalysis.hh"
#include "/TrGEMG4/interface/TrGEMPhysicsList.hh"

#include "Randomize.hh"

int main(int argc, char** argv) 
	{
  	// Set the Random engine
  	G4Random::setTheEngine(new CLHEP::RanecuEngine());
  	G4Random::setTheSeed(time(NULL)+38999008.);  
  
  	G4RunManager* runManager = new G4RunManager;

  	runManager->SetUserInitialization(new TrGEMDetectorConstruction ) ;
  	G4VUserPhysicsList* physics = new FTFP_BERT_HP();
  	//G4VUserPhysicsList* physics = new QGSP_BERT();

  	runManager->SetUserInitialization(physics);
  	runManager->SetUserInitialization(new TrGEMActionInitialization(argv[1]));

  	// initialize G4 kernel
  	runManager->Initialize();

#ifdef G4VIS_USE
 		G4VisManager* visManager = new G4VisExecutive;
   	visManager->Initialize();
#endif    
          
  	// get the pointer to the UI manager
  	G4UImanager* UImanager = G4UImanager::GetUIpointer();
  
 		if ( argc == 1 ) 
 			{
				// interactive mode : define UI session
#ifdef G4UI_USE				
				G4UIExecutive* ui = new G4UIExecutive(argc, argv);
#endif
	
#ifdef G4VIS_USE
    		UImanager->ApplyCommand("/control/execute init_vis.mac");     
#endif
				
				ui->SessionStart();
				delete ui;
	
#ifdef G4VIS_USE
      	delete visManager;
#endif     
			}
		else
			{
				G4String temp = argv[2];
  			//UImanager->ApplyCommand("/run/setCut 1 nm");
  			TrGEMAnalysis::GetInstance()->SetFileName(temp);
  			G4String command = "/run/beamOn ";
  			temp = argv[3];
  			UImanager->ApplyCommand("/control/verbose 0");
  			UImanager->ApplyCommand("/run/verbose 0");
  			UImanager->ApplyCommand("/event/verbose 0");
  			//UImanager->ApplyCommand("/tracking/verbose 2");
  			UImanager->ApplyCommand("/run/initialize");
  			UImanager->ApplyCommand("/cuts/setLowEdge 10 eV");
  			UImanager->ApplyCommand(command+temp);
			}
  	// job termination
  	delete runManager;
  	return 0;
	}
