#Find the max nlink value for a given position
function nmax = maxNlinkAvailable(npos)
  global navgraph;
  maxedge = 0;
  edgelist = getEdges(npos);
  numrows = rows(edgelist);
  if numrows > 0
    maxedge = max(maxedge, getAvailable(npos, edgelist(1,2)));
    for nedge = 1:numrows
      v = edgelist(nedge,2);
      if !isLabel(v)
        maxedge = max(maxedge,getAvailable(npos,v));
      endif
    endfor
  endif
  nmax = maxedge;
endfunction