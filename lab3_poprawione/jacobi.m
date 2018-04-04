% zad E
clear all
N = [500, 1000, 3000, 6000, 12000];
density = 10;

for i = 1:5
    [Edges] = generate_network(N(i), density);
    [A,B,I,b,M] = generate_m(Edges, N(i));
    tic
    D = diag(diag(M));
    U = triu(M, 1);
    L = tril(M, -1);

    r = ones(N(i), 1)/N(i);
    it = 0;
    res = M*r - b;
    
    while abs(norm(res))> 1e-14
        res = M*r - b;
        r = -D\(L+U)*r+D\b;
        it = it+1;
        err(it, i) = norm(res);
    end
    
    time_J(i) = toc;
    iters(i) = it;
   
end

disp(time_J)
disp(iters)
plot(N, time_J)
semilogy(err)
% saveas (plot(N, time_J),'zadE_165178_jacobi.png');
% saveas (plot(N, iters),'zadE_165178_iteracje.png');
% saveas (semilogy(err),'zadE_165178_norma_residuum.png');
