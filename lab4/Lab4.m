%1
eps=1e-3;
[ans11, ans11xdiff, ans11fx, ans11it_cnt]=bisect(1,6*1e4,eps,@alg_time);
[ans12, ans12xdiff, ans12fx, ns12it_cnt]=sieczna(1,6*1e4,eps,@alg_time);

%2
eps=10^-12;
[ans21, ans21xdiff, ans21fx, ans21it_cnt]=bisect(0, 50, eps, @compute_impedance);
[ans22, ans22xdiff, ans22fx, ans22it_cnt]=sieczna(0, 50, eps, @compute_impedance);
%3
[ans31, ans31xdiff, ans31fx, ans31it_cnt]=bisect(0, 50, eps, @compute_velocity);
[ans32, ans32xdiff, ans32fx, ans32it_cnt]=sieczna(0, 50, eps, @compute_velocity);

% x approx
saveas(loglog(ans11), 'ans11.png')
saveas(loglog(ans12), 'ans12.png')

saveas(loglog(ans21), 'ans21.png')
saveas(plot(ans22), 'ans22.png')

saveas(loglog(ans31), 'ans31.png')
saveas(plot(ans32), 'ans32.png')
% x diff
saveas(loglog(ans11xdiff), 'ans11xdiff.png')
saveas(loglog(ans12xdiff), 'ans12xdiff.png')

saveas(loglog(ans21xdiff), 'ans21xdiff.png')
saveas(plot(ans22xdiff), 'ans22xdiff.png')

saveas(loglog(ans31xdiff), 'ans31xdiff.png')
saveas(plot(ans32xdiff), 'ans32xdiff.png')