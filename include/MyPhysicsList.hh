#ifndef MyPhysicsList_h
#define MyPhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

class MyPhysicsList: public G4VModularPhysicsList
{
public:
  MyPhysicsList();
  virtual ~MyPhysicsList();

  virtual void SetCuts();
};

#endif

