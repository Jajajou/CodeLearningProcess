var n,i:longint; kq:real;

function giaithua(n:longint):int64;
var x:int64;
begin
    if(n=1) then
        exit(1);
    exit(n*gt(n-1));
end;

begin
    read(n);
    kq:=1;
    for i:=1 to n do int(kq,1/gt(i));
    write(kq);
end.