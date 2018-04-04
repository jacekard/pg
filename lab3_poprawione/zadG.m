clear all
load('Dane_Filtr_Dielektryczny_lab3_MN.mat')
% metoda bezposrednia
tic
r = M\b;
disp(toc)

% metoda jacobiego
clear all
load('Dane_Filtr_Dielektryczny_lab3_MN.mat')
N = 20000;
tic
D = diag(diag(M));
U = triu(M, 1);
L = tril(M, -1);
r = ones(N, 1);
it = 0;
res = M*r - b;
while abs(norm(res))>1e-14
    res = M*r - b;
    r = -D\(L+U)*r+D\b;
    it = it+1;
    err(it, 1) = norm(res);
end
    
disp(toc)
disp(it)
semilogy(err)

% metoda gaussa-seidela
clear all
load('Dane_Filtr_Dielektryczny_lab3_MN.mat')
N = 20000;
tic
L = tril(M, -1);
U = triu(M, 1);
D = diag(diag(M));
r = ones(N, 1);
it = 0;
res = M*r - b;
    
while abs(norm(res))>1e-14
    res = M*r - b;
    r = -(D+L)\(U*r) + (D+L)\b;
    it = it + 1;
    err(it, 1) = norm(res);
    if it == 5000
        break;
    end
end

disp(toc)
disp(it)
semilogy(err)
