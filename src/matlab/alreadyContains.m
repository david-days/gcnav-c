#Check to see if a path list of values already contains the combination
function isthere = alreadyContains(u,v,blist)
  already = 0;
  brows = rows(blist);
  if brows > 0
    for b = 1:brows
      bu = blist(b,1);
      bv = blist(b,2);
      already = already || (bu == u && bv == v);
      already = already || (bu == v && bv == u);
    endfor
  endif
  isthere = already;
endfunction