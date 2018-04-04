function [A, B, I, b, M] = lab2_(Edges)

d = 0.85;
N = max(max(Edges));
b = ones(N,1)*(1-d)/N;
I = eye(N);
B = sparse(Edges(2,:),Edges(1,:), 1);
L = sum(B,1);
A = diag(1./L);

M = I - d*B*A;
%r = M\b;
%r = r/norm(r);
%bar(r)
end