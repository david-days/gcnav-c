#For a given node, find the path to the root of the tree
#Return the path as a 2xX matrix, X = the path length

function rpath = pathToRoot(npos)

  global parents;
  
  child = npos;
  ppath = [];
  while !isLabel(child)
    parent = parents(1,child);
    pathseg = [child, parent];
    ppath = vertcat(ppath,pathseg);
    child = parent;
  endwhile
  rpath = ppath;
endfunction