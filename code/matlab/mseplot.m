% create and plot MSE function
clear, clc


ff = [1.0, 0.866; 0.866, 1.0];
fd = [0.866; 0.5];

b0 = linspace(-2,4,50);
b1 = linspace(-4,4,50);
[xx,yy] = meshgrid(b0,b1);

bx = 50.0;
by = 50.0;

mse = zeros(bx,by);

for i=1:bx
  for j=1:by
    bvec = [b0(1,i),b1(1,j)];
    mse(i,j) = 1+ bvec*ff*bvec' - 2*bvec*fd;
  end
end



figure()
mesh(xx,yy,mse)
axis([-2, 4, -6, 6, 0, 16]);
view([5,-10,2]);
xlabel('b0');
ylabel('b1');
zlabel('MSE');

figure();
v = [.05 0.15 0.4 0.8 1.8];
%[c,h] = countour((b0,b1,mse,v,'k');
%grid;
contour(xx,yy,mse,v)
axis([-0.5, 4, -3, 1]);
