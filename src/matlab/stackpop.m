#pop off the top element
function telem = stackpop()
  global sstack;
  rval = sstack.stack(sstack.pointer);
  sstack.pointer = sstack.pointer - 1;
  telem = rval;
endfunction