% Problem 2 Part (b)
u = randn(1000, 1);
y = 5 .* u;
scatter(u, y); grid on; title('Scatter of X and Y, a = 5');
% % From the graph, because our correlation coefficient has an absolute
% % value of one, we deduce that the relationship is perfectly linear

% Problem 2 Part (c)
y = -4 .* u;
scatter(u, y); grid on; title('Scatter of X and Y, a = -4');
% % Like part (b), we still have a perfectly linear relationship, albeit
% % this time our slope is negative (as a is negative)

% Problem 2 Part (d)
z = u .* u;
scatter(u, z); grid on; title('Scatter of X and Z');
% % From the graph, we see that the correlation coefficient is 0, which
% % makes sense since averaging all the slopes will give us 0, different
% % from a linear relationship, as seen in the first two parts

% Problem 2 Part (e)
w = z .* u;
scatter(u, w); grid on; title('Scatter of X and W');
% % From the graph, we see a cubic relationship between X and W, since the 
% % correlation coefficient that is neither 0 nor has an absolute value
% % of one