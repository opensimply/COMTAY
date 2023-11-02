(******************************************************************************

  This is an example using COMTAY coroutine manager.

  Download COMTAY at https://opensimply.org/comtay/ 

*******************************************************************************)


program COMTAYexample;
{$S-} 

uses
  Comtay;          // That's all you need to start using the COMTAY features.

type

  TCotask1 = class(TCoTask)
  protected
    procedure Body; override;
  end;

  TCotask2 = class(TCoTask)
  protected
    procedure Body; override;
  end;

// Description of Task #1.
procedure TCotask1.Body;
var
  i: Integer;
begin
  for i := 1 to 3 do
  begin
    Write('Hello, ');
    Resume(Cotask2);
  end;
end;

// Description of Task #2.
procedure TCotask2.Body;
begin
  repeat
    WriteLn('World!');
    Suspend;
  until false;
end;

var
  Cotask1: TCotask1;
  Cotask2: TCotask2;

begin
  InitializeComtay;             // Start using the COMTAY.

  Cotask1 := TCotask1.Create;  
  Cotask2 := TCotask2.Create;  

  Cotask1.ResumeAsMain;

  Cotask1.Free;
  Cotask2.Free;

  FinalizeComtay;               // End using the COMTAY.

  Write(EOL,'Press ENTER for program termination');
  ReadLn;
end.

