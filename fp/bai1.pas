uses crt;
var s:string;

begin
    clrscr;
    read(s);
    s[1] := upcase(s[1]);
    s[length(s)] := upcase(s[length(s)]);
    write(s);
end.
