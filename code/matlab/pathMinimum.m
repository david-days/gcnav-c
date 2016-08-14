#Find the minimum available capacity for a given path
#A path is defined as a collection of points between two nodes, of arbitrary total length, including 0

function minval = pathMinimum(plist)
  
  currmin = 0.0;
  plength = rows(plist);
  if plength > 0
    #Set the currmin to the first value
    currmin = getAvailable(plist(1,1),plist(1,2));
    for i = 1:plength
      loopval = getAvailable(plist(i,1),plist(i,2));
      currmin = min(currmin, loopval);
    endfor
  endif
  minval = currmin;
endfunction