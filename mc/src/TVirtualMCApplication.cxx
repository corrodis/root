// Author: Ivana Hrivnacova, 27.3.2002 (Ivana.Hrivnacova@cern.ch)

#include "TVirtualMCApplication.h"
#include "TError.h"

ClassImp(TVirtualMCApplication)

TVirtualMCApplication* TVirtualMCApplication::fgInstance = 0;

//_____________________________________________________________________________
TVirtualMCApplication::TVirtualMCApplication(const char *name, 
                                             const char *title) 
  : TNamed(name,title)
{
//
// Standard constructor
//

  if (fgInstance) {
    Fatal("TVirtualMCApplication", 
          "Attempt to create two instances of singleton.");
  }
      
  fgInstance = this;
}

//_____________________________________________________________________________
TVirtualMCApplication::TVirtualMCApplication()
  : TNamed()
{    
  //
  // Default constructor
  //
}

//_____________________________________________________________________________
TVirtualMCApplication::~TVirtualMCApplication() 
{
  //
  // Destructor  
  //
  
  fgInstance = 0;
}
