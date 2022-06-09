#include <iostream>
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "MyDetectorConstruction.hh"
#include "MyPhysicsList.hh"
#include "MyActionInitialization.hh"

int main(int argc, char** argv)
{	
	G4RunManager *runManager = new G4RunManager();
	runManager->SetUserInitialization(new MyDetectorConstruction());
	runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new MyActionInitialization());
	runManager->Initialize();
		
	
	G4UIExecutive* ui = 0;
	if (argc == 1)
	{
		ui = new G4UIExecutive(argc, argv);
	}
	
	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();
	
	G4UImanager* UImanager = G4UImanager::GetUIpointer();
	if (ui)
	{
		UImanager->ApplyCommand("/control/execute vis.mac");
		UImanager->ApplyCommand("/control/execute GPS.in");
		ui->SessionStart();
	}
	else
	{
		G4String command = "/control/execute";
		G4String fileName = argv[1];
		UImanager->ApplyCommand(command + fileName);
	}

	return 0;
}
