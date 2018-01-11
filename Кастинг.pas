program project1;
var
  a,b,c,n,z,res,min,max,sred,defect: integer;
  f1,f2:text;
begin
assign (f1,'casting.in');
assign (f2,'casting.out');
reset (f1);
rewrite (f2);

readln (f1,z);
read (f1,n);
read (f1,a);
read (f1,b);
read (f1,c);
{writeln (n);
writeln (a);
writeln (b);
writeln (c);
readln;}


   if (a<b) then
    min := a
   else
    min := b;
    if (min>c) then
     min := c;

    if (a>b) then
     max := a
    else
     max := b;
     if (max<c) then
      max := c;

if (max=a) and (min=b) or (min=a) and (max=b)then
 sred := c;
if (max=a) and (min=c) or (min=a) and (max=c)then
 sred := b;
if (max=b) and (min=c) or (min=b) and (max=c)then
 sred := a;

{writeln (max);
writeln (sred);
writeln (min);
writeln (n);
readln; }
if (z=2) then
 res := min;

if (z=1) then
 begin
   {raznsredmax := max - sred;
   sred := sredn - raznsredmax;
   if (sred < 0) then
    res := 0;
   res := min - razsrednmax;}
  defect := (n-max) + (n-sred)+ (n-min);
  res := n - defect;
  if (res <0) then
   res := 0;
 end;
write(f2,res);
close (f1);
close (f2);
end.
