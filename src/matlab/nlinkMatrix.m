#Pull a matrix for all the nlink values of the graph
function nmatrix = nlinkMatrix
  global navgraph;
  maxm = zeros(navgraph.width,navgraph.height);
  ncount = navgraph.nodecount;
  for npos = 1:ncount
    ma = maxNlinkAvailable(npos);
    if ma > 0
      gxy = graphXY(npos);
      maxm(gxy(1,1),gxy(1,2)) = ma;
    endif
  endfor
  nmatrix = maxm;
endfunction