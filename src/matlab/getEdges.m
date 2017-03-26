#Get the neighbors from a given node
function narray = getEdges (npos)
  global navgraph;
  
  narr = [];
  posedges = navgraph.edges(npos,:);
  nlist = nonzeros(posedges);
  rcount = rows(nlist);
  if rcount > 0
    for e = 1:rcount
      if nlist(e,1) != 0
        nedge = [npos,nlist(e,1)];
        narr = vertcat(narr,nedge);
      endif
    endfor
  endif

  
  #if it's not a label, check adjacent "pixels" and check label edges
  if !isLabel(npos)
    #check the previous rows
    gxy = graphXY(npos);
    ny = gxy(1,2);
    if ny > 1
      if navgraph.edges(npos-1,npos) > 0
        prevedge = [npos, npos-1];
        narr = vertcat(narr,prevedge);
      endif
    endif
  
    #check the previous column
    nx = gxy(1,1);
    if nx > 1
      if navgraph.edges(npos-navgraph.width,npos) > 0
        prevedge = [npos, npos-navgraph.width];
        narr = vertcat(narr,prevedge);
      endif
    endif
    
    glabels = navgraph.labels;
    for l = glabels
      if navgraph.edges(l,npos) != 0
        labedge = [npos, l];
        narr = vertcat(narr,labedge);
      endif
    endfor
  endif
  narray = narr;
endfunction