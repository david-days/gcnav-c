#Given an x-y pair, return the position of that node if it is in the area
function npos = graphPos(gx, gy)
  global navgraph;
  
  npos = (gx-1)*navgraph.width+gy;
endfunction