% Question 5 Part (b)
N = 10;
t = [-10:0.01:10];
w = 2 * pi;
Dn = ones(1, 2 * N + 1);

for k = -N:-1
    Dn(-k) = (1j) / (k * w);
end
Dn(2 * N + 1) = (1 / 2);
for k = 1:N
    Dn(k + N) = (1j) / (k * w);
end


N = 50;
Dn1 = ones(1, 2 * N + 1);

for k = -N:-1
    Dn1(-k) = (1j) / (k * w);
end
Dn1(2 * N + 1) = (1 / 2);
for k = 1:N
    Dn1(k + N) = (1j) / (k * w);
end


N = 100;
Dn2 = ones(1, 2 * N + 1);

for k = -N:-1
    Dn2(-k) = (1j) / (k * w);
end
Dn2(2 * N + 1) = (1 / 2);
for k = 1:N
    Dn2(k + N) = (1j) / (k * w);
end

subplot(3, 1, 1);
plot(myfs(Dn, w, t));
xtick = get(gca, 'XTick');
set(gca, 'XTick', xtick, 'XTickLabel', (xtick / 100) - 3);
axis([0 600 0 1]);
xlabel('Time [-3 to 3] (s)');
ylabel('f(t)');
title('Fourier Series Approximation for N = 10');

subplot(3, 1, 2);
plot(myfs(Dn1, w, t));
xtick = get(gca, 'XTick');
set(gca, 'XTick', xtick, 'XTickLabel', (xtick / 100) - 3);
axis([0 600 0 1]);
xlabel('Time [-3 to 3] (s)');
ylabel('f(t)');
title('Fourier Series Approximation for N = 50');

subplot(3, 1, 3);
plot(myfs(Dn2, w, t));
xtick = get(gca, 'XTick');
set(gca, 'XTick', xtick, 'XTickLabel', (xtick / 100) - 3);
axis([0 600 0 1]);
xlabel('Time [-3 to 3] (s)');
ylabel('f(t)');
title('Fourier Series Approximation for N = 100');

% - - - - - - - - - - - - - - - - - - - -

% % Question 5 Part (c)
% N = 10;
% t = [-3:0.01:3];
% w = 2 * pi;
% Dn = ones(1, 2 * N + 1);
% 
% for k = -N:-1
%     Dn(-k) = (1 - exp(-2)) / (2 + k * w * 1j);
% end
% Dn(2 * N + 1) = ((1 - exp(-2)) / 2);
% for k = 1:N
%     Dn(k + N) = (1 - exp(-2)) / (2 + k * w * 1j);
% end
% 
% 
% N = 50;
% Dn1 = ones(1, 2 * N + 1);
% 
% for k = -N:-1
%     Dn1(-k) = (1 - exp(-2)) / (2 + k * w * 1j);
% end
% Dn1(2 * N + 1) = ((1 - exp(-2)) / 2);
% for k = 1:N
%     Dn1(k + N) = (1 - exp(-2)) / (2 + k * w * 1j);
% end
% 
% 
% N = 100;
% Dn2 = ones(1, 2 * N + 1);
% 
% for k = -N:-1
%     Dn2(-k) = (1 - exp(-2)) / (2 + k * w * 1j);
% end
% Dn2(2 * N + 1) = ((1 - exp(-2)) / 2);
% for k = 1:N
%     Dn2(k + N) = (1 - exp(-2)) / (2 + k * w * 1j);
% end
% 
% subplot(3, 1, 1);
% plot(myfs(Dn, w, t));
% xtick = get(gca, 'XTick');
% set(gca, 'XTick', xtick, 'XTickLabel', (xtick / 100) - 3);
% axis([0 600 0 1]);
% xlabel('Time [-3 to 3] (s)');
% ylabel('f(t)');
% title('Fourier Series Approximation for N = 10');
% 
% subplot(3, 1, 2);
% plot(myfs(Dn1, w, t));
% xtick = get(gca, 'XTick');
% set(gca, 'XTick', xtick, 'XTickLabel', (xtick / 100) - 3);
% axis([0 600 0 1]);
% xlabel('Time [-3 to 3] (s)');
% ylabel('f(t)');
% title('Fourier Series Approximation for N = 50');
% 
% subplot(3, 1, 3);
% plot(myfs(Dn2, w, t));
% xtick = get(gca, 'XTick');
% set(gca, 'XTick', xtick, 'XTickLabel', (xtick / 100) - 3);
% axis([0 600 0 1]);
% xlabel('Time [-3 to 3] (s)');
% ylabel('f(t)');
% title('Fourier Series Approximation for N = 100');
