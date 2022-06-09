#ifndef MyPrimaryGenerator_h
#define MyPrimaryGenerator_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
	    MyPrimaryGenerator();    
    	virtual ~MyPrimaryGenerator();
public:
    	virtual void GeneratePrimaries(G4Event*);          
private:
        G4GeneralParticleSource* particleSource;
};

#endif
