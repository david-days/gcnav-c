#is the stack empty?
function emptval = stackempty()
  global sstack;
  rval = sstack.pointer == 0;
  emptval = rval;
endfunction