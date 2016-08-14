#Script to run multiple scenarios and compile the results
1;

clear all;

global navgraph;
global parents;
global trees;

scenedir = "./scenarios";

  scenefile = fopen(fullfile(scenedir,"scenariolist.txt"));

  currscene = fgetl(scenefile);

  timingmatrix = [];

  while currscene != -1

    if !isempty(currscene)
      currscenario = fullfile(scenedir,currscene);
      #Load up the graph parameters
      load (fullfile(currscenario,"graphparams"));
      printf("%s\n",currscene);
      gw = graphparams(1,1);
      gh = graphparams(1,2);
      gaz = graphparams(1,3);
      
      for loop = 1:5

        printf("%u",loop);
        navgraph = initGraph(gw,gh,gaz);
        initFlowData();
        inputlist = fullfile(currscenario,"inputlist");
        inputfile = fopen(inputlist);
        currinput = fgetl(inputfile);
        while currinput != -1
          if !isempty(currinput)
            load (fullfile(currscenario,currinput));
            applyGraphInput(inputmatrix);
          endif
          currinput = fgetl(inputfile);
        endwhile
        initGCData();
        buildTrees();
        #Pre-solution values
        preparent = parentMatrix();
        maxnpre = nlinkMatrix();
        maxtpre = maximumMatrix();
        tic();
        maxflow = borderCut();
        
        #Instrumentation
        solutiontime = toc();
        printf(" %d\n",solutiontime);
        fflush(stdout);
        timingpoint = [navgraph.nodecount, solutiontime];
        timingmatrix = vertcat(timingpoint, timingmatrix);
        
        #Post-solution values
        postparent = parentMatrix();
        maxnpost = nlinkMatrix();
        maxtpost = maximumMatrix();
        #pathplot = pathMatrix();
        pathplot = createPathPlot();
        
        #Save outputs in the current scenario directory
        preparentfile = fullfile(currscenario,"preparent.dat");
        maxnprefile = fullfile(currscenario,"maxnpre.dat");
        maxtprefile = fullfile(currscenario,"maxtpre.dat");
        postparentfile = fullfile(currscenario,"postparent.dat");
        maxnpostfile = fullfile(currscenario,"maxnpost.dat");
        maxtpostfile = fullfile(currscenario,"maxtpost.dat");
        pathplotfile = fullfile(currscenario,"pathplot.dat");
        maxflowfile = fullfile(currscenario,"maxflow.dat");
        
        save(preparentfile,'preparent');
        save(maxnprefile,'maxnpre');
        save(maxtprefile,'maxtpre');
        save(postparentfile,'postparent');
        save(maxnpostfile,'maxnpost');
        save(maxtpostfile,'maxtpost');
        save(pathplotfile,'pathplot');
        save(maxflowfile,'maxflow');
        
        #Save the timing file
        timingfile = fullfile(scenedir,"solutiontimes.dat");
        save(timingfile,'timingmatrix');
      endfor
    endif
    currscene = fgetl(scenefile);
  endwhile


