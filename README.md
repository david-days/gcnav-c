# What GCNAV-C Is

"GCNAV-C" stands for Graph Cut NAVigation, written in C.  The goal is to create a software suite (applications and libraries) 
that will run on low-end hardware (such as the Raspberry Pi) and perform autonomous navigation functions.

The concept is based on my research published at [researchgate.net](https://www.researchgate.net/publication/281785613_Autonomous_Pathfinding_in_Dynamic_Environments_Via_Graph_Cuts). 
The theoretical basis is laid out there, but the basic concept is pretty simple:  Graph Cut algorithms find the least-cost
separation of two or more regions in a graph structure (like an image), so with some reconfiguration of the cost-basis, the 
same algorithms can find the least-cost (most efficient) path through an environment.

The central tenet is to design a system that can perform "realistic" obstacle avoidance in structured, unstructured, and mix 
environments.

# What GCNAV-C Isn't

There are many ways that artificial intelligence and machine learning have been applied to autonomous 
 navigation.  These range from obstacle recognition strategies through training and pattern recognition to heuristic rule 
 sets and high-level decision trees, with new systems being created, researched, and implemented all the time.  In that 
 respect, it's an exciting time to be working in the field of robotics.
 
 However, there are several criticisms that can be applied to most of the approaches at the time of this writing.  First, 
 many of the autonomous navigation systems are computation intensive.  In order to work real-world scenarios, large computers, 
 large data sets, or both, are required.  If the data set is not predetermined (in the form of intense mapping of the operating
  area), then a complex set of sensors is usually employed.  This usually results in a system that is expensive, putting it 
  beyond the reach of individual researchers.
  
  Another criticism that can be applied is that many of the navigation systems are domain-specific; that is, the system for a 
  self-driving car cannot be put into an aircraft or on a boat and be expected to perform adequately (or at all!).  Every time a
  new vehicle or type of vehicle is employed, an entirely new "brain" has to be developed.  This limits reuse of technologies 
  and increases the expense of research and development.
  
  In contrast, a simple human being can drive a car to an air port, fly a plane to another airport, drive a motorcycle from there
  to a dock, and then sail a boat out to sea.  Same underlying navigation system, but different vehicles and environments.  In fact, 
  many animals and insects exhibit the same ability to operate in multiple environments, from humans all the way down to fleas and gnats.
  
  **GCNAV-C is not an attempt to create a specialized autonomous navigation system for a car, a drone, or a boat.**  Rather, its purpose is to 
  build a navigation suite that can perform adequately in 2- or 3-dimensional navigation scenarios, regardless of the platform. And rather than 
  requiring high-end computational resources and sensors, the idea is to have the software suite perform for any combination of sensors that can
  supply data.