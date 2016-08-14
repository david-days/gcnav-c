#Add capacities to a particular point
function addPositionCapacity(npos, addcap)
  global navgraph;
  
  nedges = getEdges(npos);
  rcount = rows(nedges);
  if rcount > 0
    for erow = 1:rcount
      v = nedges(erow,2);
      if !isLabel(v)
        addCapacity(npos, v, addcap);
      endif
    endfor
  endif
endfunction