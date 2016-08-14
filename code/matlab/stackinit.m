##Initialize a stack structure according to the parameter

function nstack = stackinit(stacksize)
  sarr = zeros(1,stacksize);
  spointer = 0;
  nstack = struct( , "pointer", spointer, "stack", {sarr});
endfunction