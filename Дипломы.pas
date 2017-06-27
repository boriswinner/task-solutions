program new_diploma;
{$mode objfpc}
uses Math;

const
  size = 1000000000000000000;
var
  W,H,N: qword;

function Check(a: qword): boolean;
begin
  Result := (a div W) * (a div H) >= N;
end;

function BinSearch (l,r: qword): qword;
var
  m: qword;
begin
  while (l < r - 1) do
  begin
    m := (l + r) div 2;
    if Check(m) then r := m else l := m;
  end;
  exit(r);
end;

begin
  Assign(input,'diploma.in');
  Assign(output,'diploma.out');
  reset(input);
  read(W, H, N);
  close(input);
  rewrite(output);
  write(BinSearch(0,size));
  close(output);
end.
