% % Question 5 Part (a)
% tx = linspace(0, 4, 4000); %[-3:0.001:3];
% x = 2 .* rectpuls(tx - 1.5);
% 
% th = linspace(0, 4, 4000); %[-3:0.001:3];
% h = ((2 .* (th - 1)) .* (rectpuls(th - 1.5)));
% 
% [y, ty] = nconv(x, tx, h, th);
% plot(ty, y);
% grid on;
% xlabel('Time (s)');
% ylabel('y(t)');
% title('Q5 Part A');

% % Question 5 Part (b)
% tx = linspace(-2, 2, 4000); %[-3:0.1:3];
% rect1 = rectpuls(tx);
% [y, ty] = nconv(rect1, tx, rect1, tx);
% plot(ty, y);
% grid on;
% xlabel('Time (s)');
% ylabel('y(t)');
% title('Q5 Part B');

% Question 5 Part (c)
tx = linspace(-2, 2, 4000); %[-3:0.1:3];
rect1 = rectpuls(tx);
[y, ty] = nconv(rect1, tx, rect1, tx);
[z, tz] = nconv(rect1, tx, y, tx);
plot(tz, z);
grid on;
xlabel('Time (s)');
ylabel('y(t)');
title('Q5 Part C');




