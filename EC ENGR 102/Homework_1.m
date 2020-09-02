% Question 6 part (a)
% t = -5:0.1:5;
% y = exp(-(t.^2));
% z = cos(2 * pi * t);
% x = y .* z;
% plot(t, x);
% grid on;
% xlabel('t');
% ylabel('x(t)');
% title('Question 6 Part (a)');

% Question 6 part (b)
% t = -5:0.1:5;
% y = relu(t);
% plot(t, y);
% grid on;
% xlabel('t');
% ylabel('relu(t)');
% title('Question 6 Part (b)');

% Question 6 part (c) EVEN
% t = -5:0.1:5;
% y = even(t, @relu);
% plot(t, y);
% grid on;
% xlabel('t');
% ylabel('Even relu(t)');
% title('Question 6 Part (c) EVEN');

% Question 6 part (c) ODD
% t = -5:0.1:5;
% y = odd(t, @relu);
% plot(t, y);
% grid on;
% xlabel('t');
% ylabel('Odd relu(t)');
% title('Question 6 Part (c) ODD');
