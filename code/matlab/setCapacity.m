##Set a capacity and available flow for a given u-v edge in a given graph
function setCapacity(upos, vpos, cap)
  global navgraph;
  u = min(upos,vpos);
  v = max(upos, vpos);
  if isLabel(v)
    setTlinkCap(v, u, cap);
  else
    setNlinkCap(u,v, cap);
  endif
endfunction

function setNlinkCap(upos, vpos, cap)
  global navgraph;
  navgraph.capacities(upos, vpos) = cap;
  navgraph.available(upos, vpos) = cap;
endfunction

function setTlinkCap(glabel, node, cap)
  global navgraph;
  #Set the value in both the label's capacity position and the available position
  navgraph.capacities(glabel,node) = cap;
  navgraph.available(glabel,node) = cap;
endfunction