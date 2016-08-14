#Create a depressed path from the border results
function pathm = pathMatrix
  global navgraph;
  pplot = zeros(navgraph.width,navgraph.height);
  fpath = findNlinkBorders();
  pcount = rows(fpath);
  if pcount > 0
    for r = 1:pcount
      u = fpath(r,1);
      v = fpath(r,2);
      uxy = graphXY(u);
      vxy = graphXY(v);
      pplot(uxy(1,1),uxy(1,2)) = 1;
      pplot(vxy(1,1),vxy(1,2)) = 1;
    endfor
  endif
  pathm = pplot;
endfunction