program matches;
uses sysutils;
{$H-}

type block = record
  a,b,l: integer;
end;

const
  num = 62;
var
  i, j, n, c: integer;
  blocks: array of block;
  ans: array[0..100] of block;
  ians: integer;

procedure brute(length: integer; block_number: integer; cnt: integer);
var
  i, k: integer;
  tpath: string;
begin
  if (length + 3 >= n) then exit;
  for i := block_number to high(blocks) do
  begin
    if (length + blocks[i].l < n) then
    begin
      inc(ians);
      ans[ians].a := blocks[i].a;
      ans[ians].b := blocks[i].b;
      brute(length + blocks[i].l, i, cnt+1);
      dec(ians);
    end else
    if (length + blocks[i].l = n) then
    begin
      write(cnt+1);
      for k := low(ans) to ians do
      begin
        write(' ');
        write(ans[k].a);
        write(' ');
        write(ans[k].b);
      end;
      write(' ');
      write(blocks[i].a);
      write(' ');
      writeln(blocks[i].b);
      if (i = high(blocks)) then exit;
      continue;
    end;
  end;
end;
begin
  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);
  readln(n);
  close(input);
  for i := 1 to num do
  begin
    for j := 1 to num do
    begin
      if (j < i) then continue;
      c := i*(j + 1) + j*(i + 1);
      if (c > n) then break;
      setlength(blocks,length(blocks)+1);
      with (blocks[high(blocks)]) do
       begin
         a := i;
         b := j;
         l := c;
       end;
    end;
  end;
  ians := -1;
  brute(0,0, 0);
  close(output);
end.
