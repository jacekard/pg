clear all

N = [500, 1000, 3000, 6000, 12000];
density = 10;

for i = 1:5
    [Edges] = generate_network(N(i), density);
    [A,B,I,b,M] = generate_m(Edges, N(i));
    tic
    L = tril(M, -1);
    U = triu(M, 1);
    D = diag(diag(M));
    r = ones(N(i), 1);
    it = 0;
    res = M*r - b;
    
    while abs(norm(res)) > 1e-14
       res = M*r - b;
       r = -(D+L)\(U*r) + (D+L)\b;
       it = it + 1;
       err(it, i) = norm(res);
    end
    
    time_GS(i) = toc;
    iters(i) = it;
   
end
disp(time_GS)
disp(iters)
plot(N, time_GS)
semilogy(err)
%saveas (plot(N, iters),'zadF_165178_iteracje.png');
%saveas (plot(N, time_GS),'zadF_165178_Gauss-Seidel.png');
%saveas (semilogy(err),'zadF_165178_norma_residuum.png');