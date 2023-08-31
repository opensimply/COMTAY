/******************************************************************************

  This is an example using COMTAY coroutine manager.

  Download COMTAY at https://opensimply.org/comtay/
  
******************************************************************************/

#include <iostream>
#include <string>
#include "comtay.hpp"           // COMTAY functions.

// WARNING: Stack check must be disabled in your projects when using COMTAY.

#ifdef _MSC_VER           
#pragma runtime_checks( "s", off)      // Is already disabled for MS Visual C++
#endif

using namespace comtay; 
using namespace std;

class CoTask1 : public CoTask
{
protected:
  void body() override;
};

class CoTask2 : public CoTask
{
protected:
    void body() override;
};

CoTask1* pCoTask1 = nullptr;
CoTask2* pCoTask2 = nullptr;

int main()
{
  initializeComtay();

  pCoTask1 = new CoTask1{};
  pCoTask2 = new CoTask2{};

  pCoTask1->resumeAsMain();             

  delete pCoTask1;
  delete pCoTask2;

  cout << "\nPress ENTER for program termination" << endl;
  cin.get();

  finalizeComtay();
  return 0;
}

void CoTask1::body()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Hello, ";
        resume(pCoTask2);
    }
};

void CoTask2::body()            
{
   do
    {
       cout << "World!" << endl;
       suspend();         
    }
    while (true);
}
