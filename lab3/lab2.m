function [A,B,I,b,M] = lab2(Edges)

n = size(Edges);
n = n(1);
B = sparse(Edges(n,:),Edges(1,:),1);
N = numel(max(B));
i = 1:N;
A = sparse(diag(1./sum(B(:,i))));
I = sparse(eye(N));
d = 0.85;
M = I - d*B*A;
b = zeros(1,max(size(M)));
b = b + ((1-d)/max(size(M)));
end

