program project1;
const
   max_n=4000000;
var
  vx, vy: array[0..MAX_N] of extended;
  x, y: array[0..MAX_N] of extended;
  i,agent_j:integer;
  m,k,alpha:real;
  t,v_n:extended;
  f1,f2:text;



  begin
    assign(f1,'input.txt');
    assign(f2,'output.txt');
    reset(f1);
    rewrite(f2);


    read(f1,m);
    read(f1,v_n);
    read(f1,alpha);
    read(f1,k);
    alpha:=(alpha/180)*pi;
    vx[0]:=v_n*cos(alpha);
    vy[0]:=v_n*sin(alpha);
    x[0]:=0;
    y[0]:=0;
    agent_j:=0;

    for i:=1 to MAX_N do
       begin
         vx[i]:=vx[i-1]-(k*vx[i-1]/m*0.00005);
         vy[i]:=vy[i-1]-((9.8+(k*vy[i-1])/m)*0.00005);
         x[i]:=x[i-1]+vx[i-1]*0.00005;
         y[i]:=y[i-1]+vy[i-1]*0.00005;
         if y[i]<0 then break;
         agent_j:=agent_j+1;

       end;
    t:=agent_j*0.00005;

    writeln(f2,t:0:3);
    writeln(f2,x[agent_j]:0:3);
    close(f1);
    close(f2);




  end.

