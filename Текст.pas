{$H+}
program ztext;
var
  f1,f2: text;
  k,i,cnt,pos: integer;
  s,s1: string;
label goback;
begin
  AssignFile(f1,'text.in');
  AssignFile(f2,'text.out');
  reset(f1);
  readln(f1,k);
  readln(f1,s);
  close(f1);
  rewrite(f2);
  goback:
  cnt := 0; //счетчик длины текущего куска
  for i := low(s) to high(s) do
  begin
    if(s[i]=' ') and (s[i+1]=' ') then
    begin
      delete(s,i+1,1);
      GOTO goback;
    end;
    inc(cnt); //счетчик длины слова
    if(s[i]=' ') then pos := i;//запоминаем позицию пробела
    if (cnt > k) then
    begin
      s1 := copy(s,low(s),pos-1);
      delete(s,low(s),pos);
      writeln(f2,s1);
      GOTO goback;
    end;
  end;
  write(f2,s);
  close(f2);
end.
