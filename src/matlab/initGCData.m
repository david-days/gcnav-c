## Initialize the structures associated with calculating the max flow value and paths
function initGCData

  global parents;
  global trees;
  global navgraph;
  
  ncount = navgraph.nodecount;
  labmatrix = navgraph.labels;
  parents = zeros(1,ncount);
  trees = zeros(1,ncount);
  for i=labmatrix
    parents(1,i) = i;
    trees(1,i) = i;
  endfor
endfunction 