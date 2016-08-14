#Script to run multiple scenarios and compile the results
1;

clear all;

%FOV settings
fovmin = -pi/3;
fovmax = pi/3;
t2 = [fovmin fovmax];
rangemin = 0;
rangemax = 100;
r2 = [rangemin rangemax];


scenedir = "./scenarios";
  #load and plot the timing file
  timingfile = fullfile(scenedir,"solutiontimes.dat");
  load(timingfile);
  x = timingmatrix(:,1);
  y = timingmatrix(:,2);
  figure();
  title("All solution times");
  scatter(x,y);
  

  scenefile = fopen(fullfile(scenedir,"scenariolist.txt"));

  currscene = fgetl(scenefile);

  while currscene != -1

    if !isempty(currscene)
      
      currscenario = fullfile(scenedir,currscene);
      #Load up the graph parameters
      load (fullfile(currscenario,"graphparams"));
      
      gw = graphparams(1,1);
      gh = graphparams(1,2);
      gaz = graphparams(1,3);
      

      inputlist = fullfile(currscenario,"inputlist");
      inputfile = fopen(inputlist);
      currinput = fgetl(inputfile);
      while currinput != -1
        if !isempty(currinput)
          load (fullfile(currscenario,currinput));
        endif
        currinput = fgetl(inputfile);
      endwhile

      #Save outputs in the current scenario directory
      preparentfile = fullfile(currscenario,"preparent.dat");
      maxnprefile = fullfile(currscenario,"maxnpre.dat");
      maxtprefile = fullfile(currscenario,"maxtpre.dat");
      postparentfile = fullfile(currscenario,"postparent.dat");
      maxnpostfile = fullfile(currscenario,"maxnpost.dat");
      maxtpostfile = fullfile(currscenario,"maxtpost.dat");
      pathplotfile = fullfile(currscenario,"pathplot.dat");
      maxflowfile = fullfile(currscenario,"maxflow.dat");
        
        
      #Save the timing file
      timingfile = fullfile(scenedir,"solutiontimes.dat");
        
      #Load the results;
      load(maxnprefile);
      load(pathplotfile);
      load(maxflowfile);
        
      #plot the obstacles and results results
      px = pathplot(:,1);
      py = pathplot(:,2);
      
      if gw > 4 && gh > 4
        cl = round(min(maxnpre(:))-1):0.4:round(max(maxnpre(:))+1);
        figure('color','white');
        polarplot3d(flipud(rot90(maxnpre,1)),'plottype','contour','polargrid',{6 4},'contourlines',cl,'angularrange',[-pi/3 pi/3],'radialrange',[10 50]);
        set(gca,'dataaspectratio',[1 1 1],'view',[0 90]);
      endif
      
      figure();
      hold on;
      ftitle = strcat("Obstacles and solution: ",currscene);
      title(ftitle);
      contour(maxnpre);
      scatter(px,py);
      hold off;

      #plot a surface contour for the obstacles
      figure();
      surfc(maxnpre);
      otitle = strcat("Obstacle surface for:",currscene);
      title(otitle);
      
    endif
    currscene = fgetl(scenefile);
  endwhile


