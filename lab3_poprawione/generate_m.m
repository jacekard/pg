function [A,B,I,b,M] = generate_m(Edges, N)
d = 0.85;
B = sparse(Edges(2,:), Edges(1,:),1);
A = sparse(diag((1./sum(B))));
I = sparse(speye(N));
b = (1-d)/N * ones(N,1);
M = I - d*B*A;
end