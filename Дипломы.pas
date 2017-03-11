program project1;
 
{$mode objfpc}{$H+}
 
uses Math;
var
  W,H,N,arr: qword;
function CheckOk(a: qword): boolean;
begin
  Result := (a div W) * (a div H) >= N;
end;
 
function BinSearch (position,l,r: qword): qword;
begin
  if (r-l<=2) and (CheckOk(position)=true) then exit(position);
  if (not CheckOk(position)) then
  begin
    l := position;
    position := l + ((r - l) div 2);
    if (r-l<=1) then position := r;
    Result := BinSearch(position,l,r);
  end else
  begin
    r := position;
    position := l + ((r - l) div 2);
    if (r-l<=1) then position := l;
    Result := BinSearch(position,l,r);
  end;
end;
 
begin
  Assign(input,'diploma.in');
  Assign(output,'diploma.out');
  reset(input);
  read(W, H, N);
  close(input);
  arr := 1000000000000000000;
  rewrite(output);
  write(BinSearch(arr div 2,1,arr));
  close(output);
end.
