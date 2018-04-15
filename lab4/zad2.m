function [ Z ] = zad2( omega )
%ZAD2 Summary of this function goes here
%   Detailed explanation goes here
    Z = 1 / (sqrt(1/725*725) + (omega * 8e-5 - (1/omega*2)^2));
end

