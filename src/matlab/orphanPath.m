#Set the n-link components of a path to parents(1,npos) = 0
function orphanPath(pathseg)
  global parents;
  global trees;
  
  rcount = rows(pathseg);
  if rcount > 0
    for r = 1:rcount
      u = pathseg(r,1);
      v = pathseg(r,2);
      if !isLabel(u)
        parents(1,u) = 0;
        trees(1,u) = 0;
      endif
      if !isLabel(v)
        parents(1,v) = 0;
        trees(1,v) = 0;
      endif
    endfor
  endif
endfunction