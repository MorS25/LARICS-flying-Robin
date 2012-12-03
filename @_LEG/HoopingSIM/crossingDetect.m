function rez = crossingDetect(vector,crossingValue)
rezult=[];
i=2;
sizze = size(vector)-1;
while(i< sizze(1))
    
    p1  = vector(i-1);
    p2  = vector(i+1);
    if( p1<crossingValue && p2>crossingValue)
        rezult = [rezult i];
        i=i+10;
    end
    if( p1>crossingValue && p2<crossingValue)
        rezult = [rezult i];
        i=i+10;
    end
    i = i+1;
end

rez = rezult;
end