program project1;
var
  a,result: integer;
  f1,f2: text;
function proizv(a:integer): integer;
begin
 proizv := 1;

 if (a=0) then
   proizv := 0;

 while (a > 0) do
 begin
   proizv := proizv * (a mod 10);
   a := a div 10;
 end;
end;
begin
 assign (f1,'input.txt');
 assign (f2,'output.txt');
 reset (f1);
 read (f1,a);
 close (f1);

 result := 1;
 while (a > 9) do
 begin
  result := result + 1;
  a := proizv(a);
  {writeln (a);
  write (result);
  readln; }
 end;

 rewrite (f2);
 write (f2,result);
 {write (result);
 readln; }
 close (f2);
end.

