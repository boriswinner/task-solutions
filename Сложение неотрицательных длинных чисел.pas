program project1;
type TLong = array [0..100000] of integer;
var
  a1,a2, result: TLong;
  b: char;
  i,n: integer;
  f1,f2: text;
Procedure TRead (var a:TLong); {parametr - v kakoi massiv pisat'}
begin
 i := 0;
 while not eoln (f1) do
   begin
     read (f1,b);
     inc (i);
     a[i] := ord (b) - ord('0');
   end;
  a[0] := i; {a[0] - kol-vo tsifr}
 readln (f1);
end;
function TPerM (a: TLong): TLong;   {perevorot massiva}
var
  i,g: integer;
begin
 g := 1;
 for i := a[0] downto 1 do
 begin
   TPerM [g] := a[i];
   inc (g);
 end;
 TPerm[0] := a[0];
end;
function TSum (a,b: TLong): TLong;  {summa}
var
  g,i,lenM,carry: integer;
  c: TLong;
begin
  if a[0] > b[0] then
  begin
  lenM := a[0];
  for i := b[0]+1 to a[0] do
    a[i] := 0;
  end;
  if b[0] > a[0] then
   begin
    lenM := b[0];  {dlina result}
    for i := a[0]+1 to b[0] do
      b[i] := 0;
   end;

  if a[0] = b[0] then
   LenM := a[0];

  TSum[0] := lenM;
  carry := 0;

  for i := 1 to lenM do
  begin
    g := a[i] + b[i] + carry;
    TSum[i] := g mod 10;
    carry := g div 10;

    if (i=lenM) and (carry <> 0) then
     begin
      TSum[i+1] := carry;
      inc (lenM);
      TSum[0] := lenM;
     end;
  end;

  if carry > 0 then
  begin
    inc (lenM);
    c[lenM] := carry;
  end;

end;
begin
  assign (f1,'input.txt');
  assign (f2,'output.txt');
  reset(f1);
  rewrite (f2);
  TRead (a1);
  TRead (a2);
  writeln (a1[0]);
  writeln (a2[0]);
  a1 := TPerM (a1);
  a2 := TPerM (a2);

  {writeln ('--------');
  n := a1[0];
  for i := 1 to n do
   write (a1[i]);
  writeln;

  writeln ('--------');
  n := a2[0];
  for i := 1 to n do
   write (a2[i]);
  writeln; }

  {writeln ('--------');}
  result := TSum (a1,a2);
  {n := result[0];
  for i := 1 to n do
   write (result[i]);
  writeln;  }
  {n := a1[0];
  for i := 1 to n do
   writeln (a1[i]);}

  {writeln ('------');
  n := a2[0];
  for i := 1 to n do
   writeln (a2[i]);}

  {n := result[0];
  for i := 1 to n do
   write (result[i]); }
  {readln;}

  for i := result[0] downto 1 do
   write (f2, result[i]);

  close (f1);
  close (f2);
end.

