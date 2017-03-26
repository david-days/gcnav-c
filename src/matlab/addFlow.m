##Set a capacity and available flow for a given u-v edge in a given graph
function addFlow(upos, vpos, addf)
  global navgraph;
  u = min(upos,vpos);
  v = max(upos, vpos);
  if isLabel(v)
    addTlinkFlow(v, u, addf);
  else
    addNlinkFlow(u,v, addf);
  endif
endfunction

function addNlinkFlow(upos, vpos, af)
  global navgraph;
  curravail = navgraph.available(upos, vpos);
  newavail = curravail - af;
  navgraph.available(upos, vpos) = newavail;
endfunction

function addTlinkFlow(glabel, node, af)
  global navgraph;
  curravail = navgraph.available(glabel, node);
  newavail = curravail - af;
  navgraph.available(glabel,node) = newavail;
endfunction