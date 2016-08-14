#push a value onto the stack structure
function stackpush(elem)
  global sstack;
  ++sstack.pointer;
  sstack.stack(1,sstack.pointer) = elem;
endfunction