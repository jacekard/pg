clc
clear all

% Zad A

d = 0.85;
N = 10;
density = 3;

[Edges] = generate_network(N, 3, 165178);

% Zad B

[A,B,I,b,M] = lab2(Edges);

A = sparse(A);  
B = sparse(B);
I = sparse(I);

save zadB_165178 A B I b

% Zad C

r = M\b;

save zadC_165178 r

% Zad D 

clc
clear all
close all

d = 0.85;
N = [500, 1000, 3000, 6000, 12000];
density = 10;

tic
for i = 1:5
    [Edges] = generate_network(N, density, 165178);
    [A,B,I,b,M] = lab2(Edges);
    r = M\b;
    time(i) = toc;
end

plot(N, time);
title('Czas obliczeniowy funkcji od N (Metoda bezpoœrednia)');
ylabel('Czas [s]');
xlabel('rozmiar macierzy N');

saveas (plot(N, time),'zadD_165178.png');

% zad E
L = tril(Edges);
U = triu(Edges);
D = diag(Edges);


