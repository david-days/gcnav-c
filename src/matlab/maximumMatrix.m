#Produces a max-available edge matrix
function maxmatrix = maximumMatrix

  global navgraph;
  maxm = zeros(navgraph.width,navgraph.height);
  ncount = navgraph.nodecount;
  for npos = 1:ncount
    ma = maxAvailable(npos);
    if ma > 0
      gxy = graphXY(npos);
      maxm(gxy(1,1), gxy(1,2)) = ma;
    endif
  endfor
  maxmatrix = maxm;
endfunction