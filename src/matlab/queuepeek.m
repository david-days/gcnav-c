#Look at, but do not remove, the head of the queue
function qval = queuepeek()
  global squeue;
  helem = 0;
  if (!queueempty()) 
    helem = squeue.queue(squeue.head+1);
  endif
  qval = helem;
endfunction