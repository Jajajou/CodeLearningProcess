
Var t,i,x,y,j,max,a,b: longint;
  p: array[1..20000000] Of byte;
Procedure giai;
Begin
  t := 1;
  max := 20000000;
  For i:=2 To trunc(sqrt(max)) Do
    If p[i]=0 Then
      Begin
        j := i*i;
        While j<=max Do
          Begin
            p[j] := 1;
            j := j+i;
          End;
      End;
  readln(t);
  For i:=1 To t Do
    Begin
      readln(x);
      If (p[x]=0) And (x>2) Then
        Begin
          a := x;
          b := x;
          Repeat
            dec(a)
          Until p[a]=0;
          Repeat
            inc(b)
          Until p[b]=0;
          If x=(a+b) Div 2 Then
            writeln('YES')
          Else writeln('NO');
        End
      Else
        writeln('NO');
    End;
End;
Begin
  assign(input,'symprime.inp');
  reset(input);
  assign(output,'symprime.out');
  rewrite(output);
  giai;
  close(input);
  close(output);
End.
