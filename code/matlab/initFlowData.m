## Initialize the structures associated with calculating the max flow value and paths
function initFlowData ()

  global navgraph;
  
  initNLinks();
  initTLinks();
  
endfunction 

function initNLinks

  global navgraph;
  
  ncount = navgraph.nodecount;
  xcenter = navgraph.width/2;
  #slightly modify n-links to provide smallest connectivity on the dead-ahead axis
  for i=1:ncount
    nedges = getEdges(i);
    nume = rows(nedges);
    for j=1:nume
      nn = nedges(j,2);
      if !isLabel(nn) 
        gxy = graphXY(nn);
        ndelta = 0.01*abs(gxy(1,1) - xcenter);
        setCapacity(i,nn,0.01+ndelta);
      endif
    endfor
  endfor
endfunction

function initTLinks

  global navgraph;
  
  gaz = navgraph.azimuth;
  gwidth = navgraph.width;
  glabels = navgraph.labels;
  ncount = navgraph.nodecount;
  
  #"left" and "right" directional labels
  leftlab = glabels(1,1);
  rightlab = glabels(1,2);
  
  #max value for the labels should reach across
  labmax = 0.2*gwidth;
  
  #slope values for t-link capacities should be equal at the azimuth line
  leftdelta = -1*labmax/(gaz*2);
  rightdelta = labmax/(2*(gwidth - gaz));
  
  #right side 0-intercept (left is taken care of by origin and bounded at upper limit
  rightint = labmax - (rightdelta*gwidth);
  

  for t = 1:ncount
    posxy = graphXY(t);
    posx = posxy(1,1);
    leftcap = labmax+(posx*leftdelta);
    rightcap = rightint + (posx*rightdelta);
    if leftcap > 0
      setCapacity(leftlab, t, leftcap);
    endif
    if rightcap > 0
      setCapacity(rightlab, t, rightcap);
    endif
  endfor  

  
endfunction