#Is the queue empty?
function qval = queueempty()
  global squeue;
  empval = 0;
  empval = squeue.head >= squeue.tail;
  qval = empval;
endfunction