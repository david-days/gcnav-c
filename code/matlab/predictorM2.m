% ex_08_08        Predictor with M=2.
1;

clear all;

k=0:14;
s=sqrt(2)*cos(2*pi*k/15+pi/4);
f=sqrt(2)*cos(2*pi*(k-2)/15+pi/4);
Phiff=autocorr_mat(f,1,2);
phifs=crosscorr(f,s,1,2);
% Optimal weights.
bopt=Phiff\phifs;
% Check on the printed solution.
g=cos(2*pi*[1:3]/15);
bopt=[g(2)-g(1)*g(3); g(3)-g(1)*g(2)]/(1-g(1)^2);
% Minimum MSE.
MSEmin=1-phifs'*bopt;
% Check on the printed solution.
MSEmin=1-(g(2)^2+g(3)^2-2*g(1)*g(2)*g(3))/(1-g(1)^2);

