clear all
load('Dane_Filtr_Dielektryczny_lab3_MN.mat','M','b')
% metoda bezposrednia
tic
r = M\b;
disp(toc)

% metoda jacobiego
clear all
load('Dane_Filtr_Dielektryczny_lab3_MN.mat','M','b')
N = 20000;
tic
D = diag(diag(M));
U = triu(M, 1);
L = tril(M, -1);
r = ones(N, 1);
it = 0;
res = M*r - b;
while abs(norm(res))>10^(-10)
    res = M*r - b;
    r = -D\(L+U)*r+D\b;
    it = it+1;
end
    
disp(toc)
disp(it)

% metoda gaussa-seidela
clear all
load('Dane_Filtr_Dielektryczny_lab3_MN.mat','M','b')
N = 20000;
tic
L = tril(M, -1);
U = triu(M, 1);
D = diag(diag(M));
r = ones(N, 1);
it = 0;
res = M*r - b;
    
while abs(norm(res))>10^(-10)
    res = M*r - b;
    r = -(D+L)\(U*r) + (D+L)\b;
    it = it + 1;
end

disp(toc)
disp(it)