#Return an X-Y pair given the position of a node
function xypos = graphXY(npos) 
  
  global navgraph;
  gy = mod(npos-1, navgraph.width)+1;
  gx = floor((npos-1)/navgraph.width) + 1;
  xypos = [gx, gy];
endfunction