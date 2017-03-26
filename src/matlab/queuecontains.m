##Does the queue contain the given value?
function cval = queuecontains(elem)
  global squeue;
  haselem = 0;
  if (!queueempty()) 
    for i = squeue.head:squeue.tail
      haselem = haselem || squeue.queue(1,i) == elem;
    endfor  
  endif
  cval = haselem;
endfunction