program broshura;
uses Math;
{$mode objfpc}
var
  f1,f2: text;
  A, B: longint;
begin
  AssignFile (f1,'input.txt');
  AssignFile (f2,'output.txt');
  reset(f1);
  read(f1,A);
  read(f1,B);
  close(f1);
  rewrite(f2);
  if ((max(A,B)+min(A,B)-1) mod 4 = 0) THEN write(f2,max(A,B)+min(A,B)-1) else write (f2,0);
  close(f2);
end.
