% % Question 5 Part (a)
t = linspace(0, 10, 500);
% % sigma = (ln(0.5) / 10) - - - omega = pi
y = exp((-0.06931471805 + (j * pi)) .* t);
% plot(y);
% grid on;
% xlabel('Real');
% ylabel('Imag');
% title('Part A');
% % MATLAB is plotting the real and imaginary parts of the signal on the 
% % two axes, and as a result, since both parts oscillate repeatedly, and the
% % signal is a decaying signal, MATLAB plots a spiral

% % Question 5 Part (b) REAL
% z = real(y);
% plot(z);
% grid on;
% xlabel('Input');
% ylabel('REAL y(t)');
% title('Part B REAL');

% % Question 5 Part (b) IMAGINARY
% x = imag(y);
% plot(x);
% grid on;
% xlabel('Input');
% ylabel('IMAG y(t)');
% title('Part B IMAGINARY');

% % Question 5 Part (c) ABS + ANGLE
% a = abs(y);
% b = (angle(y) / (2 * pi));
% plot(a);
% hold on;
% xlabel('Input');
% ylabel('ABS & ANGLE');
% title('Absolute Value & Angle');
% plot(b);


