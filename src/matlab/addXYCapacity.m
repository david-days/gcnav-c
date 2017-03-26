#Add capacity to a position based on XY
function addXYCapacity(gx, gy, addcap)

  global navgraph;
  
  npos = graphPos(gx,gy);
  addPositionCapacity(npos, addcap);
endfunction