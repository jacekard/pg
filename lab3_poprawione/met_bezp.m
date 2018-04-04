clc
clear all

% Zad A
density = 3;
N = 10;
[Edges] = generate_network(N, density);

% Zad B
[A,B,I,b,M] = generate_m(Edges, N);

save zadB_165178 A B I b

% Zad C
r = M\b;
save zadC_165178 r

% Zad D
clear all

N = [500, 1000, 3000, 6000, 12000];
density = 10;


for i = 1:5
    [Edges] = generate_network(N(i), density);
    [A,B,I,b,M] = generate_m(Edges, N(i));
    tic
    r = M\b;
    time(i) = toc;
end
disp(time)
plot(N, time);
saveas (plot(N, time),'zadD_165178.png');
