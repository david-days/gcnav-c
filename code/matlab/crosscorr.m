function phi=crosscorr(x,y,type,M)
% phi=crosscorr(x,y,type,M)
%
% phi(1:M)=cross correlation of vectors x and y.
% Each element of phi is computed as follows:
% phi(m)=(sum from k=1 to K {x(k)*y(k+m-1)})/K;
%        where K =length(x) and m=[1:M].
%
% type can have two values: 0 or 1:
%      0 implies y is extended with zeros if necessary.
%      1 implies y is extended periodically if necessary.
%
% M   =length of phi =number of values of phi to compute.
% See also: autocorr, crosscovar, autocovar
% Check for errors.
K=length(x);
N=length(y);
if nargin~=4
   error('Function crosscorr must have four arguments.');
elseif(type~=0 && type~=1),
   error('Third argument (type) must be either 0 or 1.');
elseif K<4
   error('Vector x must have at least 4 elements.');
elseif M<2
    error('4th argument must be at least 2')
end
% Extend both vectors x and y to length L=2*(M+K).
x=x(:)';                            %row vectors
y=y(:)';
L=2*(M+K);
x1=[x, zeros(1,L-K)];               %extend x with zeros to length L
y1=y;                               %initial vector y1=y
while length(y1)<L                  %while y1 is too short
    if type==0
        y1=[y1,zeros(1,L-N)];
    else
        y1=[y1,y1];
    end
end
y1=y1(1:L);                          %truncate y1 if necessary
% Cross-correlate using transforms - see text p.191.
phi=ifft(conj(fft(x1)).*fft(y1))/K;
phi=real(phi(1:M)');
 