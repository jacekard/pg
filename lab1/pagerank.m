Edges = [1,1,2,2,2,3,3,3,4,4,5,5,6,6,7 ; 4,6,3,4,5,5,6,7,5,6,4,6,4,7,6];
d = 0.85;
N = max(max(Edges));
b = ones(N,1)*(1-d)/N;
I = eye(N);
B = sparse(Edges(2,:),Edges(1,:), 1);
L = sum(B,1);
A = diag(1./L);

M = I - d*B*A;
r = M\b;
r = r/norm(r);
bar(r)
