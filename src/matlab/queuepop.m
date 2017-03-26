#Return and "remove" the head element of the queue
function telem = queuepop()
  global squeue;
  helem = 0;
  if (!queueempty())
    ++squeue.head;
    helem = squeue.queue(squeue.head);
  endif
  telem = helem;
endfunction