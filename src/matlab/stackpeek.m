#retrieve, but not remove, the top element
function telem = stackpeek()
  global sstack;
  rval = sstack.stack(sstack.pointer);
  telem = rval;
endfunction;