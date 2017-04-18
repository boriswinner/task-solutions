program project1;
{$mode objfpc}
uses strutils;
var
  input, output: text;
  s,a: string;
  i,res: integer;
  x: word;
begin
AssignFile(input,'input.txt');
AssignFile(output,'output.txt');
reset(input);
rewrite(output);
readln(input,s);
readln(input,x);
for i := 1 to x do
  begin
    readln(input,a);
    if (AnsiContainsStr(s,a) <> false) then res := 1 else res := 0;
    if (length(a)=0) then res := 1;
    write (output,res,' ');
  end;
close(input);
close(output);
end.
