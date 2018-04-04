clc 
clear all 
close all 


diary('diary_171969_lab3');

% Task A

N = 10;
density = 3; 
[Edges] = generate_network(N, density);
max(max(Edges))


% Task B

[A,B,I,b,M] = lab2(Edges);

A = sparse(A);  
B = sparse(B);
I = sparse(I);

save taskB_171969 A B I b

% Task C
r = M\b';
save taskC_171969 r

% Task D

clc
clear all
close all

N = [500, 1000, 3000, 6000, 12000];
density = 10;

tic
for i = 1:5
[Edges] = generate_network(N(i),density);
[A,B,I,b,M] = lab2(Edges);
r = M\b';
time_direct(i) = toc;
end

plot(N, time_direct);
title('Computational time in a function of N (Direct method)');
ylabel('Time (in seconds)');
xlabel('N');

saveas (plot(N, time_direct),'taskD_171969.png');

% Task E

clc
clear all
close all

N = [500, 1000, 3000, 6000, 12000];
density = 10;

for i = 1:5
[Edges] = generate_network(N(i),density);
[A,B,I,b,M] = lab2(Edges);
tic
L = tril(M,-1); 
U = triu(M,1); 
D = diag(diag(M));
r = zeros(N(i),1);
r = r+1;
it = 0;
res = M*r - b';
while abs(norm(res)) > 10^(-10)
    res = M*r - b';
    r = -D\(L+U)*r+D\b';
    norm(res);
    it = it+1;
end
iterations(i)=it;
time_Jacobi(i) = toc;
end

saveas (plot(N, time_Jacobi),'taskE_171969_Jacobi.png');
saveas (plot(N, iterations),'taskE_171969_iterations.png');

clc
clear all
close all

% Task F

N = [500, 1000, 3000, 6000, 12000];
density = 10;

for i = 1:5
[Edges] = generate_network(N(i),density);
[A,B,I,b,M] = lab2(Edges);
tic
L = tril(M,-1); 
U = triu(M,1); 
D = diag(diag(M));
r = zeros(N(i),1);
r = r+1;
no_it = 0;
res = M*r - b';
while abs(norm(res))> 10^(-10)
    res = M*r - b';
    r = -(D+L)\(U*r)+(D+L)\b';
    norm(res);
    no_it = no_it+1;
end
iterations(i)=no_it;
time_Gauss_Seidel(i) = toc;
end

plot(N, time_Gauss_Seidel);

plot(N, iterations);


saveas (plot(N, time_Gauss_Seidel),'taskF_171969_Gauss_Seidel.png');
saveas (plot(N, iterations),'taskF_171969_iterations.png');

diary off






