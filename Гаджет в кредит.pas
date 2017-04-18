program GadzhetKredit;
 
{$mode objfpc}{$H+} {$R+}
uses Math;
var
  N,P,C,res,dolg: int64;
 
function CheckOk(M: int64): boolean;
var
  i: integer;
  afterpay: int64;
  coeff: double;
begin
  dolg := C;
  afterpay := dolg - m;
  coeff := (P/100) + 1;
  if (afterpay*coeff > C) then
  begin
    Result := false;
    exit;
  end;
  for i := 1 to N*12 do
  begin
    if (afterpay*coeff > C) then
    begin
      Result := false;
      exit;
    end;
    if (dolg < 0 ) then
    begin
      Result := true;
      exit;
    end;
    dolg := ceil((dolg-M)*(1+P/100));
  end;
  //writeln ('M ',M);
  //writeln('Dolg ',dolg);
  if (Dolg <= 0) then Result := true else Result := false;
end;
 
procedure BinSearch (key,l,r: int64);
begin
  if (r-l<=1) and (CheckOk(key)=true) then
  begin
    res := key;
    exit;
  end;
  if (CheckOk(key) = false) then
  begin
    l := key;
    key := l + ((r - l) div 2);
    if (r-l<=1) then key := r;
    BinSearch(key,l,r);
  end else
  begin
    r := key;
    key := l + ((r - l) div 2);
    if (r-l<=1) then key := l;
    BinSearch(key,l,r);
  end;
end;
begin
  Assign(input,'input.txt');
  Assign(output,'output.txt');
  reset(input);
  read(N);
  read(P);
  read(C);
  close(input);
  rewrite(output);
  BinSearch(C div 2,1,C);
  write(res);
  close(output);
end.
