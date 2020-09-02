% % Problem 2
% c = [0.2:0.001:1];
% chebyshev = (1./(3.*((c).^2))); 
% exact = (1 - c);
% plot(c, chebyshev);
% hold on;
% plot(c, exact);
% grid on; xlabel('c'); ylabel('P|X| > c');
% title('Chebyshev/Exact v. c');
% axis([0.2 1 0 10]); legend('Chebyshev', 'Exact');

% % Problem 6 Part (b)
% u = rand(5000);
% xi = (-2*log(1-u));
% t = [0:0.01:50];
% pdf = 0.5 * exp(-0.5 .* t);
% subplot(1, 2, 1);
% histogram(xi); grid on; title('Histogram of RV');
% subplot(1, 2, 2); plot(t, pdf); grid on; xlabel('x'); ylabel('PDF'); 
% title('Exponential PDF');

% % Problem 6 Part (c)
% ex = mean2(xi);
% disp(ex);


