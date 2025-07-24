clc
clear
close all

% Cau 1
syms x y z
a = 2; b = 4; c = 6;
f = (a*x + b*y + c*z)*asin(x*y*z);
vars = [x y z];
fprintf("Cau 1:\n");

% dao ham rieng cap 1
for i = 1:length(vars)
    fprintf(" f_%s = %s\n", vars(i), diff(f, vars(i), 1));
end

% dao ham rieng cap 2
for i = 1:length(vars)
    for j = 1:length(vars)
        fprintf(" f_%s%s = %s\n", vars(i), vars(j), diff(diff(f, vars(i), 1), vars(j), 1));
    end
end


% Cau 2
syms x y
f_a = x*sin(x+y);
f_b = x^2 + 2*y;
f_c = exp(x);
fprintf("\nCau 2:\n");

% cau a
fprintf(" a) %f\n", int(int(f_a, x, 0, pi/6), y, 0, pi/3));

% cau b
fprintf(" b) %f\n", int(int(f_b, y, x^3, x), x, 0, 1));

% cau c
% -Neu de la dx
fprintf(" c) %f\n", double(int(f_c, x, 1, 4)));
% -Neu de là ds, y = t, x = t^2
syms t
x_t = t^2; y_t = t;
dx = diff(x_t, t); dy = diff(y_t, t);
f_c_t = exp(x_t)*sqrt(dx^2 + dy^2);
fprintf(" c) %f\n", double(int(f_c_t, t, 1, 2)));

% cau d
syms t
y = t^2 + 1;
x = t;
dr = [diff(x, t), diff(y, t)];
F = [x/sqrt(x^2 + y^2), y/sqrt(x^2 + y^2)];
Tich = dot(F,dr);
fprintf(" d) %s\n", int(Tich, t, -1, 1));


% Cau 3
fprintf("\nCau 3:\n");
syms x y
a3 = 0; b3 = 20;
c3 = 0; d3 = 10;
m = 50;
n = 50;
dx = (b3-a3)/m; dy = (d3-c3)/n;
dA = dx*dy;
f_3 = x*exp(-x*y);
Riemann = 0;
for i = 1:m
    for j = 1:n
        Riemann = Riemann + subs(f_3, {x,y}, {a3+(i-1/2)*dx, c3+(j-1/2)*dy})*dA;
    end
end
fprintf(" Tong Riemann = %f\n", Riemann);
fprintf(" Kiem tra bang tich phan: %f\n", double(int(int(f_3, x, 0, 20), y, 0, 10)));


% Cau 4
fprintf("\nCau 4:\n");
syms y(x);
x_val = linspace(-10, 10, 100);

% cau a
y_sol_a = dsolve(diff(y,x,1) + y == 1, y(0) == 1);
fprintf(" a) Nghiem: %s\n", y_sol_a);
y_val_a = subs(y_sol_a, x, x_val);

%subplot(3,3,1);
figure;
plot(x_val, y_val_a);
title('Cau 4a');

% cau b
y_sol_b = dsolve((x^2 + 1)*diff(y,x) + 3*x*(y-1) == 0, y(0) == 2);
fprintf(" b) Nghiem: %s\n", y_sol_b);
y_val_b = subs(y_sol_b, x, x_val);
figure;
%subplot(3,3,2);
plot(x_val, y_val_b);
title('Cau 4b');

% cau c
y_sol_c = dsolve(diff(y,x,2) - 4*y == exp(x)*cos(x) + x^3, y(0) == 1, subs(diff(y,x),x,0) == 2);
fprintf(" c) Nghiem: %s\n", y_sol_c);
y_val_c = subs(y_sol_c, x, x_val);
figure;
%subplot(3,3,3);
plot(x_val, y_val_c);
title('Cau 4c');


% Cau 5
fprintf("\nCau 5:\n")
a = -10:.1:10;
b = -10:.1:20;
[X, Y] = meshgrid(a, b);
Z = 6*exp(-3*X.^2 - Y.^2) + X/2 + Y;
figure;
%subplot(3,3,4);
meshc(X, Y, Z);
title('Cau 5');


% Cau 6
fprintf("\nCau 6:\n");
syms x y
f = x*y - x^3/3;
[X, Y] = meshgrid(-7:7,-7:7);
P = subs(diff(f, x), {x,y}, {X,Y});
Q = subs(diff(f, y), {x,y}, {X,Y});
%subplot(3,3,5);
figure;
quiver(X, Y, P, Q);


% cau 7
fprintf("\nCau 7:\n");
syms x y
f = x^3 - 12*x*y + 8*y^3;
f_x = diff(f,x);
f_y = diff(f,y);

assume(x, 'real'); 
assume(y, 'real');
[x_dung, y_dung] = solve(f_x == 0, f_y == 0, x, y);
fprintf(" Cac diem dung:\n");
for i =1:length(x_dung)
    fprintf("  (%f, %f)\n", x_dung(i), y_dung(i));
end

f_xx = diff(f_x, x);
f_xy = diff(f_x, y);
f_yy = diff(f_y, y);
D = f_xx*f_yy - f_xy^2;
D = subs(D, {x,y}, {x_dung, y_dung});

for i =1:length(x_dung)
    f_xx_dung = double(subs(f_xx, {x,y}, {x_dung(i), y_dung(i)}));
    if double(D(i)) > 0 && f_xx_dung > 0
        fprintf(" (%f, %f) la diem cuc tieu dia phuong cua f.\n", x_dung(i), y_dung(i));
    elseif double(D(i)) > 0 && f_xx_dung < 0
        fprintf(" (%f, %f) la diem cuc dai dia phuong cua f.\n", x_dung(i), y_dung(i));
    elseif double(D(i)) < 0
        fprintf(" (%f, %f) la diem yen ngua cua f.\n", x_dung(i), y_dung(i));
    else
        fprintf(" Khong the xac dinh (%f, %f).\n", x_dung(i), y_dung(i));
    end
end
