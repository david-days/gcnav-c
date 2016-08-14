#Given a particular matrix, apply that as an input to the global navgraph object

function applyGraphInput(imatrix)

  global navgraph;

  r = rows(imatrix);
  c = columns(imatrix);
  ncount = navgraph.nodecount;
  for i=1:r
    for j=1:c
      addXYCapacity(i,j,imatrix(i,j));
    endfor
  endfor
endfunction