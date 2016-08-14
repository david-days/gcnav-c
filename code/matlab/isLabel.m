## Determine if a position is a label or not
function retbool = isLabel(pos)
  global navgraph; 
  ebool = 0;
  for i=navgraph.labels
    ebool = ebool || pos == i;
  endfor
  retbool = ebool;
endfunction