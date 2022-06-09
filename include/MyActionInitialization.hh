#ifndef MyActionInitialization_h
#define MyActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "MyPrimaryGenerator.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
public:
	MyActionInitialization();
	virtual ~MyActionInitialization();

    	virtual void Build() const;
};

#endif

    
