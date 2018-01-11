program project1;
var
  n1,m1,n2,m2,i,kolvospic1,kolvospic2,kolvokost1,kolvokost2: integer;
  success1,success2: integer;
  p,q:array[1..40000] of integer;
  f1,f2: text;
begin
assign (f1,'input.txt');
assign (f2,'output.txt');
reset (f1);
read (f1,n1);
read (f1,m1);
read (f1,n2);
readln (f1,m2);

for i := 1 to n1 do
 begin
  readln (f1,p[i]);
  if (p[i] <> -1) then
    begin
     kolvokost1:=kolvokost1+p[i];
     kolvospic1:=kolvospic1+1;
    end;
 end;

for i := 1 to n2 do
 begin
  readln (f1,q[i]);
  if (q[i] <> -1) then
    begin
     kolvokost2:=kolvokost2+q[i];
     kolvospic2:=kolvospic2+1;
    end;
 end;
{writeln (n1);
writeln (kolvospic1);
writeln (m1);
writeln (kolvokost1);
writeln (n2);
writeln (kolvospic2);
writeln (m2);
writeln (kolvokost2);
for i := 1 to n1 do
 writeln(p[i]);
for i := 1 to n2 do
 writeln(q[i]);
readln;    }
{if (2000 < n1 < 1) or (2000 < n2 < 1) or (2000 < m1 < 1) or (2000 < n1 < 1) then
  begin
   rewrite (f2);
   write (f2,12);
   close (f2);
  end; }
while (n1 <> kolvospic1) do
begin
 if (kolvospic2 <> 0) then
   begin
    kolvospic2 := kolvospic2 - 1;
    kolvospic1 := kolvospic1 + 1;
   end
 else
 break;
end;
while (m1*n1 <> kolvokost1) do
begin
 if (kolvokost2 <> 0) then
   begin
    kolvokost2 := kolvokost2 - 1;
    kolvokost1 := kolvokost1 + 1;
   end
 else
 break;
end;

if (n1=kolvospic1) and (m1*n1=kolvokost1) then
  success1 := 1;

kolvokost1 := 0;
kolvokost2 := 0;
kolvospic1 := 0;
kolvospic2 := 0;
{writeln (n1);
writeln (kolvokost1);
writeln (m1);
writeln (kolvospic1);
readln;}
{writeln (n2);
writeln (kolvospic1);
writeln (m2);
writeln (kolvospic2);}
close (f1);
reset (f1);

read (f1,n1);
read (f1,m1);
read (f1,n2);
readln (f1,m2);

for i := 1 to n1 do
 begin
  readln (f1,p[i]);
  if (p[i] <> -1) then
    begin
     kolvokost1:=kolvokost1+p[i];
     kolvospic1:=kolvospic1+1;
    end;
 end;

for i := 1 to n2 do
 begin
  readln (f1,q[i]);
  if (q[i] <> -1) then
    begin
     kolvokost2:=kolvokost2+q[i];
     kolvospic2:=kolvospic2+1;
    end;
 end;

{writeln (n1);
writeln (kolvospic1);
writeln (m1);
writeln (kolvokost1);
writeln (n2);
writeln (kolvospic2);
writeln (m2);
writeln (kolvokost2);
for i := 1 to n1 do
 writeln(p[i]);
for i := 1 to n2 do
 writeln(q[i]);
readln;    }

while (n2 <> kolvospic2) do
begin
 if (kolvospic1 <> 0) then
   begin
    kolvospic1 := kolvospic1 - 1;
    kolvospic2 := kolvospic2 + 1;
   end
 else
 break;
end;


{writeln (n2);
writeln (kolvospic2);
writeln (m2);
writeln (kolvokost2);
readln;  }

while (m2*n2 <> kolvokost2) do
begin
 if (kolvokost1 <> 0) then
   begin
    kolvokost1 := kolvokost1 - 1;
    kolvokost2 := kolvokost2 + 1;
   end
 else
 break;
end;

{writeln (n2);
writeln (kolvospic2);
writeln (m2);
writeln (kolvokost2);
readln;     }

if (n2=kolvospic2) and (m2*n2=kolvokost2) then
  success2 := 1;

{writeln (success1);
writeln (success2);
readln;  }

rewrite (f2);
if (success1=1) and (success2=1) then
  write (f2,12);

if (success1=1) and (success2<>1) then
  write (f2,1);

if (success1<>1) and (success2=1) then
  write (f2,2);

if (success1<>1) and (success2<>1) then
  write (f2,0);

close (f1);
close (f2);
end.

