##Initialize an array-based queue
function nqueue = queueinit(qsize)
  qarr = zeros(1,qsize);
  hpointer = 0;
  tpointer = 0;
  nqueue = struct ("head",hpointer, "tail",tpointer, "queue",{qarr});
endfunction