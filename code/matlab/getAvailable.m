## Get the available flow for an edge(u,v) for a given navgraph
function eav = getAvailable(upos, vpos)
  global navgraph;
  aval = 0.0;
  u = min(upos,vpos);
  v = max(upos, vpos);
  if isLabel(v)
    aval = getTlinkAvail(v, u);
  else
    aval = getNlinkAvail(u,v);
  endif
  eav = aval;
endfunction

function navail = getNlinkAvail(upos, vpos)
  global navgraph;
  nval = 0.0;
  nval = navgraph.available(upos, vpos);
  navail = nval;
endfunction

function tavail = getTlinkAvail(glabel, node)
  global navgraph;
  tval = 0.0;
  tval = navgraph.available(glabel,node);
  tavail = tval;
endfunction