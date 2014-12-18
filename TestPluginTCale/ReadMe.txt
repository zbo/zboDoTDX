极点保留:=
局部极点:IF(极点保留=-1,L,IF(极点保留=1,H,DRAWNULL)) CIRCLEDOT COLORYELLOW;
DRAWLINE(极点保留=-1,局部极点,极点保留=1,局部极点,0)COLORLIRED;
DRAWLINE(极点保留=1,局部极点,极点保留=-1,局部极点,0)COLORYELLOW;
