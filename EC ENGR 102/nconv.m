function [y, ty] = nconv(x,tx,h,th)
%
% nconv performs a numerical approximation to the
% continuous time convolution using matlab's conv()
% function
%
% [y, ty] = nconv(x,tx,h,th)
%
% Inputs:

% x -- input signal vector
% tx -- times of the samples in x
% h -- impulse response vector
% th -- times of the samples in
%
% outputs:
% y -- output signal vector,
% length(y)= length(x)+length(h)-1
% ty -- times of the samples in y
%

%Matlab conv function evaluates the convolution of two discrete time
%signals. We are using this function to approximate the convolution of two
%continuous time signals. To get the right approximation, the function is 
%multiplied by the step size (or sampling period).
y=conv(x,h)*(th(2)-th(1));

%The conv function returns the response but without times at which the 
%response is defined. Here we are computing where the convolution response
%should be defined; if x is defnied between tx(1) and tx(end) and his
%defined between th(1) and th(end), then y is defined between tx(1)+tx(end)
%and th(1)+th(end)
ty=linspace(tx(1)+th(1), tx(length(tx))+th(length(th)),length(y));

end