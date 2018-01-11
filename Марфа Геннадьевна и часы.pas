program project1;
var
  f1,f2: text;
  H,M,i,g: integer;
  ugol1,ugol2,ugol: real;
  a:array[1..1000] of char;
begin
assign (f1,'input.txt');
assign (f2,'output.txt');
reset (f1);
rewrite (f2);
read (f1, H);
read (f1, M);
{gol := abs(30-H-6*M); }
{ugol1 := H*15+M*0.5;
ugol2 := H*15+M*0.25;}
{ugol1 := H*15+15*(m/60);
ugol2 := M*3;}
if (H>12) then
H := (H-12);
if (H=12) then
H := 0;
{writeln (h);
writeln (M);
readln;}
ugol1 := (H*60+M)*0.5;
ugol2 := M*6;
{writeln (ugol1:0:4);
writeln (ugol2:0:4);
readln; }
if (ugol2>ugol1) then
ugol:= ugol2-ugol1;
if (ugol1>ugol2) then
ugol:= ugol1-ugol2;
if (ugol > 180) then
ugol := 360-ugol;

{if (ugol1 < ugol2) then
ugol := ugol2-ugol1;
if (ugol1 = ugol2) then
ugol := 0;
if (ugol1 > ugol2) then
ugol := ugol1-ugol2; }
{if (ugol1 > ugol2) then
ugol := ugol1 - ugol2
else
ugol := ugol2 - ugol1;}
{ugol2hour := ugol2 div 30;
ugol1hour := ugol1 div 30;}
write (f2,ugol:0:4);
close (f1);
close (f2);
end.
