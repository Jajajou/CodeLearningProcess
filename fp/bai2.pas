uses crt;
var s:string;
    i:longint;

begin
    clrscr;
    read(s);
    for i:=length(s) downto 1 do write(s[i]);
end.
