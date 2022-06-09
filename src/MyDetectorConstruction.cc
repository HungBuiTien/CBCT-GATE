#include "MyDetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction :: Construct()
{
	// *****************************************************************************
	//								FIND MATERIALS
	// *****************************************************************************
	G4NistManager* nist = G4NistManager::Instance();
	G4Material *Air = nist->FindOrBuildMaterial("G4_AIR");
	G4Material* Alumium = G4NistManager::Instance()->FindOrBuildMaterial("G4_Al");
	// Steel as non-NIST material
	G4Element* elI = G4NistManager::Instance()->FindOrBuildElement("I");
	G4Element* elCs = G4NistManager::Instance()->FindOrBuildElement("Cs");
	G4Element* elTl = G4NistManager::Instance()->FindOrBuildElement("Tl");
	G4Material* CsI = new G4Material("CsI", 7.0 * g / cm3, 3);
	CsI->AddElement(elI, 49.95 * perCent);
	CsI->AddElement(elCs, 49.95 * perCent);
	CsI->AddElement(elTl, 0.1 * perCent);

	// Visualisation attributes of all elements colours 
	G4VisAttributes* grayAl = new G4VisAttributes(G4Colour(0.7, 0.7, 0.7));
	grayAl->SetVisibility(true);
	grayAl->SetForceSolid(true);

	G4VisAttributes* colorAir = new G4VisAttributes(G4Colour(0., 0.3, 0.3));
	colorAir->SetVisibility(true);
	colorAir->SetForceSolid(true);
	
	// *****************************************************************************
	//									DEFINE GEOMETRIES
	// *****************************************************************************

	// World volume
	G4Box* solidWorld = new G4Box("solidWorld", 100 * cm, 100 * cm, 100 * cm);
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, Air, "logicWorld");
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0,
										G4ThreeVector(0., 0., 0.), 
										logicWorld, 
										"physWorld", 
										0, false, 0, true);
	

	// Sample
	G4Tubs* solidTubs1 = new G4Tubs("solidTubs1", 1.2 * cm, 1.8 * cm, 0.25 * cm, 0, 360 * deg);
	G4Tubs* solidTubs2 = new G4Tubs("solidTubs2", 1.2 * cm, 1.7 * cm, 0.25 * cm, 0, 360 * deg);
	G4Tubs* solidTubs3 = new G4Tubs("solidTubs3", 1.2 * cm, 1.6 * cm, 0.25 * cm, 0, 360 * deg);
	G4Tubs* solidTubs4 = new G4Tubs("solidTubs4", 1.2 * cm, 1.4 * cm, 0.5 * cm, 0, 360 * deg);
	G4Tubs* solidTubs5 = new G4Tubs("solidTubs5", 1.2 * cm, 1.6 * cm, 0.25 * cm, 0, 360 * deg);
	G4Tubs* solidTubs6 = new G4Tubs("solidTubs6", 1.2 * cm, 1.7 * cm, 0.25 * cm, 0, 360 * deg);
	G4Tubs* solidTubs7 = new G4Tubs("solidTubs7", 1.2 * cm, 1.8 * cm, 0.25 * cm, 0, 360 * deg);

	G4RotationMatrix rotm = G4RotationMatrix();
	G4ThreeVector position1 = G4ThreeVector(84.11 * cm, 0., -1.75 * cm);
	G4ThreeVector position2 = G4ThreeVector(84.11 * cm, 0., -1.25 * cm);
	G4ThreeVector position3 = G4ThreeVector(84.11 * cm, 0., -0.75 * cm);
	G4ThreeVector position4 = G4ThreeVector(84.11 * cm, 0.,  0. * cm);
	G4ThreeVector position5 = G4ThreeVector(84.11 * cm, 0.,  0.75 * cm);
	G4ThreeVector position6 = G4ThreeVector(84.11 * cm, 0.,  1.25 * cm);
	G4ThreeVector position7 = G4ThreeVector(84.11 * cm, 0.,  1.75 * cm);
	G4Transform3D tr1 = G4Transform3D(rotm, position1);
	G4Transform3D tr2 = G4Transform3D(rotm, position2);
	G4Transform3D tr3 = G4Transform3D(rotm, position3);
	G4Transform3D tr4 = G4Transform3D(rotm, position4);
	G4Transform3D tr5 = G4Transform3D(rotm, position5);
	G4Transform3D tr6 = G4Transform3D(rotm, position6);
	G4Transform3D tr7 = G4Transform3D(rotm, position7);

	G4MultiUnion* munion_solid = new G4MultiUnion("Solid_Sample");
	munion_solid->AddNode(*solidTubs1, tr1);
	munion_solid->AddNode(*solidTubs2, tr2);
	munion_solid->AddNode(*solidTubs3, tr3);
	munion_solid->AddNode(*solidTubs4, tr4);
	munion_solid->AddNode(*solidTubs5, tr5);
	munion_solid->AddNode(*solidTubs6, tr6);
	munion_solid->AddNode(*solidTubs7, tr7);
	munion_solid->Voxelize();

	G4LogicalVolume* lvol =
		new G4LogicalVolume(munion_solid,         // its solid
			Alumium,							  // its material
			"Boxes_Union_LV");					  // its name

	new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), lvol, "Sample", logicWorld, false, 0, true);
	logicWorld->SetVisAttributes(G4VisAttributes::GetInvisible());


	// Detector
	//G4Box* solidBox1 = new G4Box("solidBox1", 0.015 * cm, 7.2864 * cm, 5.812 * cm);
	//G4LogicalVolume* logicBox1 = new G4LogicalVolume(solidBox1, CsI, "logicBox1");
	//new G4PVPlacement(0, G4ThreeVector(99.315 * cm, 0., 0.), logicBox1, "Detector", logicWorld, false, 0, true);

	G4float OriginalSize = 0.00495;
	G4int BinningMode = 16;
	G4Box* solidDetector = new G4Box("solidDetector", 0.015 * cm, 0.0792 /2 * cm, 0.0792 /2 * cm);
	logicDetector = new G4LogicalVolume(solidDetector, CsI, "logicDetector");
	for (G4int i = 0; i < 2944/BinningMode; i++)
	{
		for (G4int j = 0; j < 2352/BinningMode; j++)
		{
			G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(99.315 * cm, ((-7.2864 + 0.0792 /2) + (i * 0.0792)) * cm, ((-5.8212 + 0.0792 /2) + (j * 0.0792)) * cm),
				logicDetector, "physDetector", logicWorld, false, j + i * 1000, false);
		}
	}

	// Alumium filter
	/*G4Box* solidBox2 = new G4Box("solidBox2", 0.15 * cm, 22 * cm, 22 * cm);
	G4LogicalVolume* logicBox2 = new G4LogicalVolume(solidBox2, Alumium, "logicBox2");
	new G4PVPlacement(0, G4ThreeVector(20.7 * cm, 0., 0.), logicBox2, "Filter", logicWorld, false, 0, true);
	*/
	return physWorld;
}
