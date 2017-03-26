#Find and return a list of border edges
#Border edges are defined as edges between
#nodes {u,v} in which trees[u] <> trees[v]

function gborders = findNlinkBorders()

  global navgraph;
  global trees;
  blist = [];
  ncount = navgraph.nodecount;
  for u = 1:ncount
    nedges = getEdges(u);
    ecount = rows(nedges);
    for e = 1:ecount
      v = nedges(e,2);
      if trees(1,u) != trees(1,v)
        if !alreadyContains(u,v,blist)
          if !isLabel(u) && !isLabel(v)
            bpath = [u,v];
            blist = vertcat(blist, bpath);
          endif
        endif
      endif
    endfor
  endfor
  gborders = blist;

endfunction

