#Script to run navgraph bordercut
1;

clear all;

global navgraph;
global parents;
global trees;

gw = 16;
gh = 16;
gaz = 8.5;

navgraph = initGraph(gw,gh,gaz);
initFlowData();

#Add points
#addXYCapacity(2,2,6);
#addXYCapacity(2,3,6);
#addXYCapacity(2,4,6);
#addXYCapacity(2,5,7);
#addXYCapacity(2,6,6.5);
#addXYCapacity(2,7,6);
#addXYCapacity(2,8,5);
#addXYCapacity(12,14,3);
#addXYCapacity(1,5,2);
#near wall
addXYCapacity(8,1,5);
addXYCapacity(8,2,5);
addXYCapacity(8,3,5);
addXYCapacity(8,4,5);
addXYCapacity(8,5,5);
addXYCapacity(8,6,5);
#addXYCapacity(8,7,5);
#addXYCapacity(8,8,5);
#addXYCapacity(8,9,5);
#addXYCapacity(8,10,5);
#far wall
#addXYCapacity(14,6,5);
#addXYCapacity(14,7,5);
#addXYCapacity(14,8,5);
#addXYCapacity(14,9,5);
#addXYCapacity(14,10,5);
#addXYCapacity(14,11,5);
addXYCapacity(14,12,5);
addXYCapacity(14,13,5);
addXYCapacity(14,14,5);
addXYCapacity(14,15,5);

initGCData();

buildTrees();

#Pre-solution values
preparent = parentMatrix();
maxnpre = nlinkMatrix();
maxtpre = maximumMatrix();

tic();
maxflow = borderCut();
cuttime = toc();

#Post-solution values
postparent = parentMatrix();
maxnpost = nlinkMatrix();
maxtpost = maximumMatrix();
pathplot = pathMatrix();

#Obstacles and path
figure(1)
contour(maxnpre);
hold on;
contour(pathplot);
title('Obstacles and Path');
hold off;

#Pre-solution nlinks
figure(2)
surfc(maxnpre)
title('Pre-solution N-Links');

#Post-solution nlink values
figure(3)
surfc(maxnpost);
title('Post-solution N-Links');

figure(4);
surfc(maxtpre);
title('Pre-solution max edges');

figure(5);
surfc(maxtpost);
title('Post-Solution max edges');

maxflow
cuttime