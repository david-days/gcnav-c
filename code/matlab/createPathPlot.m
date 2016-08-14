#function create path plot
function pathxy = createPathPlot
  
  global navgraph;
  
  plist = [];
  blist = findNlinkBorders();
  bcount = rows(blist);
  for i = 1:bcount
    u = blist(i,1);
    v = blist(i,2);
    uxy = graphXY(u);
    vxy = graphXY(v);
    #interpolate
    py = (uxy(1,1)+vxy(1,1))/2;
    px = (uxy(1,2)+vxy(1,2))/2;
    ppoint = [px,py];
    plist = vertcat(plist, ppoint);
  endfor

  pathxy = plist;
endfunction