##Set a capacity and available flow for a given u-v edge in a given graph
function addCapacity(upos, vpos, addcap)
  global navgraph;
  u = min(upos,vpos);
  v = max(upos, vpos);
  if isLabel(v)
    addTlinkCap(v, u, addcap);
  else
    addNlinkCap(u,v, addcap);
  endif
endfunction

function addNlinkCap(upos, vpos, acap)
  global navgraph;
  currcap = navgraph.capacities(upos, vpos);
  newcap = currcap + acap;
  navgraph.capacities(upos, vpos) = newcap;
  navgraph.available(upos, vpos) = newcap;
endfunction

function addTlinkCap(glabel, node, acap)
  global navgraph;
  currcap = navgraph.capacities(glabel, node);
  newcap = currcap + acap;
  navgraph.capacities(glabel,node) = newcap;
  navgraph.available(glabel,node) = newcap;
endfunction