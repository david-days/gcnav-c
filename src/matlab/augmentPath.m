#Augment the flow in the path with the given value
function augmentPath(pflow, ppath)
  plength = rows(ppath);
  if pflow > 0 && plength > 0
    for r = 1:plength
      u = ppath(r,1);
      v = ppath(r,2);
      addFlow(u,v,pflow);
    endfor
  endif
endfunction