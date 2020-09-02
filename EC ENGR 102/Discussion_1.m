t = -3:0.05:3; % sequence from -3 to 3 with step 0.05
x = cos(2 * pi * t); 
y = cos(2 * pi * t + pi/3);

plot(t, x, 'r', t, y, 'b--o'); % plots models x & y
grid on;

title('Example 1');
xlabel('t(sec)');
ylabel('x, y');