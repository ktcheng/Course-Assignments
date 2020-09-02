% % Problem 3 Part (a)
% x = [1:0.01:10];
% y = [1:0.01:10];
% [X, Y] = meshgrid(x, y);
% z = @(x, y) (1 - (1 ./ (x .^ 2))) .* (1 - (1 ./ (y .^ 2)));
% 
% p = surf(x, y, z(X, Y)); 
% set(p,'LineStyle','none');
% grid on; colorbar; xlabel('x'); ylabel('y'); zlabel('F(x, y)');
% title('Joint CDF');

% % Problem 6 Part (a)
% U1 = rand(5000, 1); % U1 = rand(5000) gives a smoother result
% U2 = rand(5000, 1); % U2 = rand(5000) gives a smoother result
% x1 = sqrt(-2 .* log(U1)) .* cos(2 * pi .* U2);
% x2 = sqrt(-2 .* log(U1)) .* sin(2 * pi .* U2);
 
% % Problem 6 Part (b)
% x = [-4:0.01:4];
% pdf = (1 / sqrt(2 * pi)) * exp(-(x .^ 2) / 2);
% 
% subplot(1, 3, 1);
% histogram(x1);grid on; title('Histogram for x1');
% subplot(1, 3, 2);
% histogram(x2); grid on; title('Histogram for x2');
% subplot(1, 3, 3);
% plot(x, pdf); grid on; xlabel('x'); ylabel('PDF'); 
% title('Normal Gaussian PDF');

% % Problem 6 Part (c)
% scatter(x1, x2); grid on; title('Scatter of X1 and X2');
% % The plot should have circular symmetry, as X1 and X2 are generated from
% % uniform RVs on the same scale, and in addition their formulae only
% % differ in either a sine or cosine. Plotting a sin v. cos should result in
% % circular behavior, which is exactly what occurs.

