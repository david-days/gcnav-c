#does the stack contain the given value?
function cval = stackcontains(elem)
  global sstack;
  haselem = 0;
  if (!stackempty(sstack))
    for i=1:sstack.pointer
      haselem = haselem || elem == sstack.stack(1,i);
    endfor
  endif
  cval = haselem;
endfunction