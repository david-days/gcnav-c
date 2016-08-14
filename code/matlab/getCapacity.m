## Get the capacity for an edge(u,v) for a given navgraph
function ecap = getCapacity(upos, vpos)
  global navgraph;
  capval = 0.0;
  u = min(upos,vpos);
  v = max(upos, vpos);
  if isLabel(v)
    capval = getTlinkCap(v, u);
  else
    capval = getNlinkCap(u,v);
  endif
  ecap = capval;
endfunction

function ncap = getNlinkCap(upos, vpos)
  global navgraph;
  nval = 0.0;
  nval = navgraph.capacities(upos, vpos);
  ncap = nval;
endfunction

function tcap = getTlinkCap(glabel, node)
  global navgraph;
  tval = 0.0;
  tval = navgraph.capacities(glabel,node);
  tcap = tval;
endfunction