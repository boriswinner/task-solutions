program project1;
var
  n, result: longint;
  f1,f2: text;
begin
  assign (f1,'input.txt');
  assign (f2,'output.txt');
  reset (f1);
  read (f1, n);
  close (f1);
 
  result := n div 18 + (n-1) div 18 + 1;
  rewrite (f2);
  write (f2,result);
  close (f2);
end.
