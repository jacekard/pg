function [ v ] = zad3( t )
%ZAD3 Summary of this function goes here
%   Detailed explanation goes here
u = 2000;
m0 = 150000;
q = 2700;
g = 9.81;
v=u * ln(m0/(m0-q*t)) - g*t;
end

