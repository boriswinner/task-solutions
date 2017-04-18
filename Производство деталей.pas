//решение на паскале
program hotkeys;
{$mode objfpc}{$H+}
uses Sysutils;
type
  waytoproduce = record
    cost: Int64;
    usedverticles: string;
    numofverticles: Longint;
  end;
 
var
  graph: array of array of Longint; //связи между вершинами
  costs: array of Longint; //стоимости прохода через вершину
  visited: array of boolean; //посещённые в DFS вершины
  i,n,j,k,t: Longint;
  way: waytoproduce; //выходные данные
procedure DFS(v: longint);
var
  i: integer;
begin
  visited[v] := true;
  way.cost := way.cost + costs[v];
  inc(way.numofverticles);
  for i := low(graph[v]) to high(graph[v]) do
  begin
    if (not visited[graph[v][i]]) then
      DFS(graph[v][i]);
  end;
  way.usedverticles:=way.usedverticles+IntToStr(v+1)+' ';
end;
begin
  assign(input,'details.in');
  assign(output,'details.out');
  reset(input);
  readln(n);
  setlength(graph,n);
  setlength(costs,n);
  setlength(visited,n);
  for i := 0 to high(costs) do
    read(costs[i]);
  readln;
  for i := 0 to high(graph) do
    begin
      read(k);
      setlength(graph[i],k);
      for j := 0 to k-1 do
      begin
        read(t);
        graph[i][j] := t-1;
      end;
      readln;
    end;
  close(input);
  rewrite(output);
  DFS(0);
  write(way.cost,' ');
  writeln(way.numofverticles);
  write(way.usedverticles);
  close(output);
end.
