#Perform bordercut max flow algorithm on global navgraph

function maxflow = borderCut
  global parents;
  global trees;
  initGCData();
  mflow = 0;
  loopflow = 0;
  do
    loopflow = 0;
    buildTrees();
    borders = findNonZeroBorders();
    loopflow = augmentBorders(borders);
    orphanBorders(borders);
    mflow = mflow + loopflow;
  until (loopflow == 0)
  #One last tree build for final structure
  buildTrees();
  maxflow = mflow;
endfunction

function augtotal = augmentBorders(blist)
  ftotal = 0.0;
  rcount = rows(blist);
  if rcount > 0
    for r = 1:rcount
      u = blist(r,1);
      v = blist(r,2);
      upath = pathToRoot(u);
      vpath = pathToRoot(v);
      bpath = [u,v];
      ucount = rows(upath);
      vcount = rows(vpath);
      #Initialize the min path availabilities
      umin = -1;
      vmin = -1;
      bmin = getAvailable(u,v);
      #Determine the minimum availability along all path segments
      if ucount > 0
        umin = pathMinimum(upath);
      endif
      if vcount > 0
        vmin = pathMinimum(vpath);
      endif
      allmin = bmin;
      if ucount > 0
        allmin = min(allmin,umin);
      endif
      if vcount > 0
        allmin = min(allmin, vmin);
      endif
      #Augment the flow of available (real) path segments
      #Augment upath
      if ucount > 0
        augmentPath(allmin, upath);
      endif
      #Augment vpath
      if vcount > 0
        augmentPath(allmin, vpath);
      endif
      #Augment the border itself
      augmentPath(allmin, bpath);
      #Add to the sum of the augmentation
      ftotal = ftotal + allmin;
    endfor
  endif
  augtotal = ftotal;
endfunction

function orphanBorders(blist)
  #For now, just go to ground zero on the tree/parent structures
  #Big performance penalty
  initGCData();
#  rcount = rows(blist);
#  if rcount > 0
#    for r = 1:rcount
#      u = blist(r,1);
#      v = blist(r,2);
#      upath = pathToRoot(u);
#      vpath = pathToRoot(v);
#      orphanPath(upath);
#      orphanPath(vpath);
#    endfor
#  endif
endfunction