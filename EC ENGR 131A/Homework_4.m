% Problem 1 Part (a)
% subplot(1, 3, 1);
% t0 = [0:0.01:10];
% x = 1 - exp(-((t0) .^ 0.5));
% plot(x);
% grid on;
% xlabel('x');
% ylabel('F(x)');
% title('CDF for Beta = 0.5');
% xticks([0 100 200 300 400 500 600 700 800 900 1000]);
% xticklabels([0 1 2 3 4 5 6 7 8 9 10]);
% 
% subplot(1, 3, 2);
% t1 = [0:0.01:5];
% y = 1 - exp(-t1);
% plot(y);
% grid on;
% xlabel('x');
% ylabel('F(x)');
% title('CDF for Beta = 1.0');
% xticks([0 100 200 300 400 500 600 700 800 900 1000]);
% xticklabels([0 1 2 3 4 5 6 7 8 9 10]);
% 
% subplot(1, 3, 3);
% z = 1- exp(-((t1) .^ 2));
% plot(z);
% grid on;
% xlabel('x');
% ylabel('F(x)');
% title('CDF for Beta = 2.0');
% xticks([0 100 200 300 400 500 600 700 800 900 1000]);
% xticklabels([0 1 2 3 4 5 6 7 8 9 10]);

% Problem 1 Part (c)
% t = [0:0.01:10];
% y = exp(-((t) .^ 2));
% t = log(t);
% z = log(y);
% plot(t ,z);
% grid on;
% xlabel('ln(x)');
% ylabel('ln(P[X > x])');
% title('ln(P[X > x]) v. ln(x)');

