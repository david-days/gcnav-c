#Get the max available of all the neighboring edges for a given point
function maxav = maxAvailable(npos)
  global navgraph;
  maxedge = 0;
  edgelist = getEdges(npos);
  numrows = rows(edgelist);
  if numrows > 0
    maxedge = max(maxedge, getAvailable(npos, edgelist(1,2)));
    for v = 1:numrows
      maxedge = max(maxedge,getAvailable(npos,edgelist(v,2)));
    endfor
  endif
  maxav = maxedge;
endfunction