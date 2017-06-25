program project1;
const inf = 10000000;
type
  spisok=record
    apex: array of integer; //вершина графа, до которой идёт путь
    path2apex: array of integer; //расстояние до этой вершины графа
  end;
var
  graph1: array [1..1000] of spisok;
  d: array [1..1000] of integer;
  z: array [1..1000] of integer;
  Y: array [1..1000] of boolean; //множество посещённых вершин
  N,M,S,i,j,u,minmetka,v: integer;
  {
  i,j,z - рабочие переменные
  N - множество вершин графа
  M - количество рёбер
  S - вершина a (начальная вершина)
  d[u] - по окончании работы алгоритма равно длине кратчайшего пути из a до вершины u
  }
  f1,f2: text;
begin
  //инициализация
  assign (f1, 'input.txt');
  assign (f2, 'output.txt');
 
 
  //чтение
  reset (f1);
  read (f1, N);
  read (f1, M);
  readln (f1, S);
 
  for i := 1 to M do
  begin
    read (f1, j); //читаем номер вершины старта
    inc (z[j]);
    setlength(graph1[j].apex, z[j] + 1);
    read (f1, graph1[j].apex[z[j]]); //читаем номер вершины конца
    setlength(graph1[j].path2apex, z[j] + 1);
    readln (f1, graph1[j].path2apex[z[j]]); //читаем длину ребра
  end;
  close (f1);
 
  for i := 1 to N do
    if (i <> S) then
       d[i] := inf;
 
 
  for i := 1 to N do
  begin
    minmetka := inf;
    for j := 1 to N do
      if (not Y[j]) and (d[j] <= minmetka) then
        begin
          v := j;
          minmetka := d[j];
        end;
 
    for j := 1 to z[v] do
       if (d[v]+graph1[v].path2apex[j]<d[graph1[v].apex[j]]) THEN
         d[graph1[v].apex[j]] := d[v]+graph1[v].path2apex[j];
    Y[v] := TRUE;
  end;
 
  rewrite (f2);
  for i := 1 to N do
    begin
      if (d[i] <> inf) THEN
        write (f2,d[i])
      else
        write (f2,'-1');
      write (f2,' ');
    end;
  close (f2);
end.Dijkstra
