program zad1;
var
  n,i,m,k1,k2,k:integer;
  a:array[1..2500] of char;
  b:array[1..2500] of integer;
  f1,f2: text;
begin
assign (f1,'cities.in');
assign (f2,'cities.out');
reset (f1);
rewrite (f2);
readln (f1,n);
for i := 1 to n do
 begin
   for m := 1 to n-1 do
    read (f1,a[m+(i-1)*n]);
   readln (f1,a[n+(i-1)*n]);
 end;
{writeln (n);
for i := 1 to n*n do
writeln (a[i]);
readln;}
{k1,k2 - кол-во у гос-в}
k:= 0;
for i := 1 to N*N do
 begin
  b[i] := 1;
  if (a[i]='C') then
  k := k+1;
 end;
i:=N*N;
k1 := k;
while (k1<>k2) do
begin
 if (a[i]='C') then
  begin
    k2 := k2+1;
    k1 := k1-1;
  end;
 
 b[i]:=2;
 i := i-1;
end;
 
{writeln (k);
writeln (k1);
writeln (k2);
readln;}
for i := 1 to n do
 begin
   for m := 1 to n-1 do
    write (f2,b[m+(i-1)*n]);
   writeln (f2,b[n+(i-1)*n]);
 end;
close (f1);
close (f2);
end.
