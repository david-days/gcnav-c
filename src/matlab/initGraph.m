## Copyright (C) 2015 David
## 
## This program is free software; you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

## -*- texinfo -*- 
## @deftypefn {Function File} {@var{retval} =} initGraph (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: David <David@LOKI>
## Created: 2015-01-23

function graphstruct = initGraph (w,h,az)

  global graphWidth;
  global graphHeight;
  global graphAz;
  global Nv;
  global Vlen;
  global glabels;
  global edges;
  global capacities;
  global remaining;

  #Set values
  graphWidth = w;
  graphHeight = h;
  graphAz = az;
  Nv = w*h;
  Vlen = Nv + 2;
  glabels = [ (Nv+1),(Nv+2)];
  edges = sparse(Vlen, Nv);
  capacities = sparse(Vlen,Nv);
  remaining = sparse(Vlen, Nv);
  initEdges();
  graphstruct = struct( "width", w, "height", h, "azimuth", graphAz, "nodecount", Nv, "verticecount", Vlen, "labels", {glabels}, "edges", {edges}, "capacities", {capacities}, "available", {remaining});
  
endfunction

## Initialize the arrangement of edges
function initEdges() 
  
  global glabels;
  global Nv;
  global Vlen;
  global edges;
  global graphWidth;
  global graphHeight;
  #Set immediate neighbor nlink edges
  for n = 1:Nv
    if ((getRow(n) == getRow(n+1)) && ((n+1) <= Nv))
      edges(n,n+1) = n + 1;
    endif
  endfor
  #Set next-row-neighbor nlink edges
  for n = 1:Nv
    if ((getColumn(n) == getColumn(n+graphWidth)) && ((n+graphWidth) <= Nv))
      edges(n,n+graphWidth) = n+graphWidth;
    endif
  endfor

  #Fill tlink edges
  for l = glabels
    for v = 1:Nv;
      edges(l,v) = v;
    endfor
  endfor

endfunction

function rpos = getRow(pos) 
  global graphWidth;
  global graphHeight;
  rpos = floor((pos-1)/graphWidth) + 1;
endfunction

function cpos = getColumn(pos)
  global graphWidth;
  global graphHeight;
  cpos = mod(pos, graphHeight)+1;
endfunction