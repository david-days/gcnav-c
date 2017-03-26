#Using the parents and trees array, fill in the tree structures

function buildTrees
  
  global parents;
  global trees;
  global navgraph;
  
  stepadd = 0;
  numnode = navgraph.nodecount;
  do
    stepadd = 0;
    #Walk through the parents list
    for i=1:numnode
      # If orphaned (no parent listed), check
      if parents(1,i) == 0
        nedges = getEdges(i);
        nume = rows(nedges);
        #Check all the edges
        for nn = 1:nume
          neighbor = nedges(nn,2);
          navailable = getAvailable(i,neighbor);
          #Check available flow to the neighbor, and neighbor is not an orphan
          if (navailable > 0 && trees(1,neighbor) != 0)
            parents(1,i) = neighbor;
            trees(1,i) = trees(1,neighbor);
            stepadd = 1;
            break;
          endif
        endfor
      endif
    endfor
    
  
  until (stepadd == 0)

endfunction