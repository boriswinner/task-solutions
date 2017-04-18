program max_perepad;
var
  f1,f2: text;
  i,j,N,max: integer;
  a: array of array of integer;
begin
  max := 0;
  AssignFile(f1,'input.txt');
  AssignFile(f2,'output.txt');
  reset(f1);
  readln(f1,N);
  setlength(a,N,N);
  for i := 0 to N-1 do
  begin
    for j := 0 to N-1 do
    begin
      if (j+1 mod N <> 0) then read (f1,a[i][j]) else readln(f1,a[i][j]);
    end;
  end;
  close(f1);
  for i := 0 to N-1 do
  begin
    for j := 0 to N-1 do
    begin
      if (j-1>=0) and ((a[i][j]-a[i][j-1])>max) then max := a[i][j]-a[i][j-1];
      if (j+1<=N-1) and ((a[i][j]-a[i][j+1])>max) then max := a[i][j]-a[i][j+1];
      if (i+1<=N-1) and ((a[i][j]-a[i+1][j])>max) then max := a[i][j]-a[i+1][j];
      if (i-1>=0) and ((a[i][j]-a[i-1][j])>max) then max := a[i][j]-a[i-1][j];
    end;
  end;
  rewrite(f2);
  write(f2,max);
  close(f2);
end.
