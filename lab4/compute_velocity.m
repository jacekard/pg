function [ v ] = compute_velocity( t )
%COMPUTE_VELOCITY Summary of this function goes here
%   Detailed explanation goes here
g=9.81;
m0=150000;
q=2700;
u=2000;
v=u*log(m0/(m0-q*t))-g*t;

end

