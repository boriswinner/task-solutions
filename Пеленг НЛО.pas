program project1;

{$mode objfpc}{$H+}
uses Math;
const
  a = 100;
var
alpha,beta, beta1, c, ac, bc,h,s,ah,p: real;
perevern : boolean;

procedure printnull;
begin
  rewrite(output);
  write('0 0');
  close(output);
end;

begin
assign (input, 'input.txt');
assign (output, 'output.txt');
reset (input);
read (alpha, beta);
close (input);

IF (alpha=0) or (beta=0) then
begin
printnull;
exit;
end;

if ((alpha > 180) and (beta < 180)) or ((alpha < 180) and (beta > 180)) then
begin
printnull;
exit;
end;

IF (alpha > 180) AND (beta > 180) then
begin
perevern := true;
alpha := alpha - 180;
beta := beta - 180;
end;

beta1 := 180 - beta;
c := 180 - alpha - beta1;

if (beta1+alpha >= 180) AND (perevern = false) then     //??????
begin
printnull;
exit;
end;

if (beta1+alpha <= 180) AND (perevern = true) then
begin
printnull;
exit;
end;

ac := a*sin((beta1*Pi)/180)/sin((c*Pi)/180);
bc := a*sin(alpha*Pi/180)/sin(c*Pi/180);
p := (a+bc+ac)/2;
s := sqrt(p*(p-a)*(p-ac)*(p-bc));
h := s*2/a;
ah := sqrt (ac*ac - h*h);
rewrite (output);

if ((alpha <= 90) and (not perevern)) or ((alpha > 90) and (perevern)) then
write (output, ah:4:4);
if (alpha <= 90) and (perevern) or ((alpha > 90) and (not perevern)) then
write (output,'-', ah:4:4);

if (not perevern) then
write (output,' ',h:4:4);
if (perevern) then
write (output,' -',h:4:4);

close (output);
end.
