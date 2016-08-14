#create an x-y-z representation of the parent matrix
function parmatrix = parentMatrix()
  global navgraph;
  global parents;
  parm = zeros(navgraph.width,navgraph.height);
  ncount = navgraph.nodecount;
  for npos = 1:ncount
    gxy = graphXY(npos);
    parm(gxy(1,1),gxy(1,2)) = parents(1,npos);
  endfor
  parmatrix = parm;

endfunction