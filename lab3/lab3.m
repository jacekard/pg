clc
clear all
diary('diary_165178_lab3');

% Zad A
N = 10;
density = 3;
[Edges] = generate_network(N, density);

% Zad B
[A,B,I,b,M] = labM(Edges);

save zadB_165178 A B I b

% Zad C
r = M\b;
save zadC_165178 r

% Zad D
clear all

d = 0.85;
N = [500, 1000, 3000, 6000, 12000];
density = 10;


for i = 1:5
    [Edges] = generate_network(N(i), density);
    [A,B,I,b,M] = lab2(Edges);
    tic
    r = M\b';
    time(i) = toc;
end
disp(time)
plot(N, time);
saveas (plot(N, time),'zadD_165178.png');

% zad E
clear all
N = [500, 1000, 3000, 6000, 12000];
density = 10;

for i = 1:5
    [Edges] = generate_network(N(i), density);
    [A,B,I,b,M] = lab2(Edges);
    tic
    D = diag(diag(M));
    U = triu(M, 1);
    L = tril(M, -1);

    r = ones(N(i), 1);
    it = 0;
    res = M*r - b';
    
    while abs(norm(res))> 10^(-14)
        res = M*r - b';
        r = -D\(L+U)*r+D\b';
        it = it+1;
    end
    
    time_J(i) = toc;
    iters(i) = it;
   
end

disp(time_J)
disp(iters)
saveas (plot(N, time_J),'zadE_165178_Jacobi.png');
saveas (plot(N, iters),'zadE_165178_iteracje.png');

% Zad F
clear all

N = [500, 1000, 3000, 6000, 12000];
density = 10;

for i = 1:5
    [Edges] = generate_network(N(i), density);
    [A,B,I,b,M] = lab2(Edges);
    tic
    L = tril(M, -1);
    U = triu(M, 1);
    D = diag(diag(M));
    r = ones(N(i), 1);
    it = 0;
    res = M*r - b';
    
    while abs(norm(res)) > 10^(-14)
       res = M*r - b';
       r = -(D+L)\(U*r) + (D+L)\b';
       it = it + 1;
    end
    
    time_GS(i) = toc;
    iters(i) = it;
   
end
disp(time_GS)
disp(iters)
saveas (plot(N, iters),'zadF_165178_iteracje.png');
saveas (plot(N, time_GS),'zadF_165178_Gauss-Seidel.png');

diary off
