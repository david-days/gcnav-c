#push a new value into the queue
function queuepush(elem)
  global squeue;
  ++squeue.tail;
  squeue.queue(squeue.tail) = elem;
endfunction